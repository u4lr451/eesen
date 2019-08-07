#include "atlas_asm.h"
/*
 * This file does a 1x1 unrolled mvn_sse with these params:
 *    CL=8, ORDER=clmajor
 */
#ifndef ATL_GAS_x8664
   #error "This kernel requires x86-64 assembly!"
#endif
/*
 * Integer register assignment
 */
#define M       %rdi
#define N       %rsi
#define pA0     %rdx
#define lda     %rax
#define pX      %r8
#define pY      %r9
#define II      %rbx
#define pY0     %r11
#define Mr      %rcx
#define incAYm  %r10
#define incII   %r15
#define incAn   %r14
/*
 * SSE register assignment
 */
#define rA      %xmm0
#define ra      %xmm1
#define rY      %xmm2
#define ry      %xmm3
#define rX0     %xmm4
#define iX0     %xmm5
#define NONEPONEOFF -72
#define NONEPONE %xmm15
/*
 * macros
 */
#ifndef MOVA
   #define MOVA movups
#endif
#define movapd movaps
#define movupd movups
#define xorpd xorps
#define addpd addps
#define mulpd mulps
#define addsd addss
#define mulsd mulss
#define movsd movss
#define haddpd haddps
/*
 * Define macros controlling prefetch
 */
#ifndef PFDIST
   #define PFDIST 256
#endif
#ifndef PFADIST
   #define PFADIST PFDIST
#endif
#ifndef PFYDIST
   #define PFYDIST 64
#endif
#ifndef PFXDIST
   #define PFXDIST 64
#endif
#ifndef PFIY
   #ifdef ATL_3DNow
      #define PFIY prefetchw
   #else
      #define PFIY prefetcht0
   #endif
#endif
#ifndef PFIX
   #define PFIX prefetchnta
#endif
#ifndef PFIA
   #define PFIA prefetchnta
#endif
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #define prefA(mem) PFIA mem
#endif
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #define prefY(mem) PFIY mem
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #define prefX(mem) PFIX mem
#endif
/*
 *                      %rdi        %rsi           %rdx          %rcx
 * void ATL_UGEMV(ATL_CINT M, ATL_CINT N, const TYPE *A, ATL_CINT lda,
 *                          %r8      %r9
 *                const TYPE *X, TYPE *Y)
 */
.text
.text
.global ATL_asmdecor(ATL_UGEMV)
ALIGN64
ATL_asmdecor(ATL_UGEMV):

/*
 * Save callee-saved iregs
 */
   movq %rbp, -8(%rsp)
   movq %rbx, -16(%rsp)
   movq %r12, -24(%rsp)
   movq %r13, -32(%rsp)
   movq %r14, -40(%rsp)
   movq %r15, -48(%rsp)
/*
 * Compute M = (M/MU)*MU, Mr = M - (M/MU)*MU
 * NOTE: Mr is %rcx reg, so we can use jcx to go to cleanup loop
 */
   mov  %rcx, lda       /* move lda to assigned register, rax */
   mov  M, Mr           /* Mr = M */
   shr $3, M            /* M = M / MU */
   shl $3, M            /* M = (M/MU)*MU */
   sub M, Mr            /* Mr = M - (M/MU)*MU */
/*
 * Construct nonepone = {1.0,-1.0,1.0,-1.0}
 */
   finit
   fld1                                 /* ST =  1.0 */
   fldz                                 /* ST =  0.0 1.0 */
   fsub %st(1), %st                     /* ST = -1.0 1.0 */
   fsts NONEPONEOFF(%rsp)               /* ST= -1.0 1.0 */
   fstps NONEPONEOFF+8(%rsp)            /* ST=1.0 */
   fsts NONEPONEOFF+4(%rsp)             /* ST=1.0 */
   fstps NONEPONEOFF+12(%rsp)          /* ST=NULL, mem={1.0, -1.0, 1.0, -1.0}*/
   movapd NONEPONEOFF(%rsp), NONEPONE
/*
 * Setup constants
 */
   mov lda, incAn       /* incAn = lda */
   sub M, incAn         /* incAn = lda - (M/MU)*MU */
   sub Mr, incAn        /* incAn = lda - M */
   shl $3, incAn        /* incAn = (lda-M)*sizeof */
   shl $3, lda          /* lda *= sizeof */
   sub $-128, pA0       /* code compaction by using signed 1-byte offsets */
   sub $-128, pY        /* code compaction by using signed 1-byte offsets */
   mov pY, pY0          /* save for restore after M loops */
   mov $-64, incAYm     /* code comp: use reg rather than constant */
   mov $8*1, incII      /* code comp: use reg rather than constant */
   mov M, II
/*
 * Zero Y if beta = 0;  Has error if there is Mr and/or M isn't mul of veclen
 */
   #ifdef BETA0
       add Mr, II
      shr $1, II
      xorpd rY, rY
      LOOPZERO:
         movapd rY, -128(pY)
         add $16, pY
      dec II
      jnz LOOPZERO
      lea (M, Mr), II
      bt $0, II
      jnc DONE_ZERO_CLEAN
      movlps rY, -128(pY)
DONE_ZERO_CLEAN:
      mov pY0, pY
      mov M, II
   #endif

   ALIGN32
   LOOPN:
      movlps (pX), iX0       /* iX0 = {xxx, xxx, iX0, rX0} */
      pshufd $0x00, iX0, rX0 /* rX0 = {rX0, rX0, rX0, rX0} */
      pshufd $0x55, iX0, iX0 /* iX0 = {iX0, iX0, iX0, iX0} */
      mulps NONEPONE, iX0          /* iX0 = {iX0,-iX0, iX0,-iX0} */

      LOOPM:
         MOVA   0-128(pA0), rY         /* rY = {iA0, rA0} */
         pshufd $0xB1, rY, ry           /* ry = {rA0, iA0} */
         mulpd rX0, rY                  /* rY = {rX0*iA0, rX0*rA0} */
         addpd 0-128(pY), rY       
         mulpd iX0, ry                  /* ry = {iX0*rA0, -iX0*iA0} */

         addpd ry, rY
         movapd rY, 0-128(pY)

         MOVA   16-128(pA0), rY         /* rY = {iA0, rA0} */
         pshufd $0xB1, rY, ry           /* ry = {rA0, iA0} */
         mulpd rX0, rY                  /* rY = {rX0*iA0, rX0*rA0} */
         addpd 16-128(pY), rY       
         mulpd iX0, ry                  /* ry = {iX0*rA0, -iX0*iA0} */

         addpd ry, rY
         movapd rY, 16-128(pY)

         MOVA   32-128(pA0), rY         /* rY = {iA0, rA0} */
         pshufd $0xB1, rY, ry           /* ry = {rA0, iA0} */
         mulpd rX0, rY                  /* rY = {rX0*iA0, rX0*rA0} */
         addpd 32-128(pY), rY       
         mulpd iX0, ry                  /* ry = {iX0*rA0, -iX0*iA0} */

         addpd ry, rY
         movapd rY, 32-128(pY)

         MOVA   48-128(pA0), rY         /* rY = {iA0, rA0} */
         pshufd $0xB1, rY, ry           /* ry = {rA0, iA0} */
         mulpd rX0, rY                  /* rY = {rX0*iA0, rX0*rA0} */
         addpd 48-128(pY), rY       
         mulpd iX0, ry                  /* ry = {iX0*rA0, -iX0*iA0} */

         addpd ry, rY
         movapd rY, 48-128(pY)

         prefA(PFADIST+0(pA0))
         sub incAYm, pY
         sub incAYm, pA0
      sub incII, II
      jnz LOOPM

      #ifdef ATL_OS_OSX     /* workaround retarded OS X assembly */
         cmp $0, Mr
         jz  MCLEANED
      #else
         jecxz MCLEANED        /* skip cleanup loop if Mr == 0 */
      #endif

      mov Mr, II
      LOOPMCU:
         movlps   -128(pA0), rY         /* rY = {iA0, rA0} */
         pshufd $0x11, rY, ry           /* ry = {rA0, iA0} */
         mulpd rX0, rY                  /* rY = {rX0*iA0, rX0*rA0} */
         movddup -128(pY), rA
         addps rA, rY
         mulpd iX0, ry                  /* ry = {iX0*rA0, -iX0*iA0} */
         addpd ry, rY
         movlps rY, -128(pY)
         add $8, pY
         add $8, pA0
      dec II
      jnz LOOPMCU

MCLEANED:
      prefX(1*8+PFXDIST(pX))
      add $1*8, pX
      add incAn, pA0
      mov pY0, pY
      mov M, II
   sub $1, N
   jnz LOOPN
/*
 * EPILOGUE: restore registers and return
 */
   movq -8(%rsp), %rbp
   movq -16(%rsp), %rbx
   movq -24(%rsp), %r12
   movq -32(%rsp), %r13
   movq -40(%rsp), %r14
   movq -48(%rsp), %r15
   ret