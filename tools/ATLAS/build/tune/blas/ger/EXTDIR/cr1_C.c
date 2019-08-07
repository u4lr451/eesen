#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 1
#endif
#ifndef PFXDIST
   #define PFXDIST 256
#endif
#ifndef PFADIST
   #define PFADIST 256
#endif

#if !defined(ATL_3DNow) && !defined(ATL_SSE1) && \
    (PFADIST != 0 || PFXDIST != 0 || PFYDIST != 0)
   #include "atlas_prefetch.h"
#endif

#if defined(ATL_3DNow) || defined(ATL_SSE1)
   #ifndef PFIY
      #define PFIY prefetchnta
   #endif
   #ifndef PFIX
      #define PFIX prefetchnta
   #endif
   #ifndef PFIA
      #ifdef ATL_3DNow
         #define PFIA prefetchw
      #else
         #define PFIA prefetcht0
      #endif
   #endif
#endif
/*
 * X & A are prefetched in M loop PF[A,X]DIST (in bytes) ahead
 */
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefA(mem) __asm__ __volatile__ \
         (Mstr(PFIA) " %0" : : "m" (*(((char *)(mem))+PFADIST)))
   #else
      #if PFLVL == 2
         #define prefA(mem) ATL_pfl2W(((char*)mem)+PFADIST)
      #else
         #define prefA(mem) ATL_pfl1W(((char*)mem)+PFADIST)
      #endif
   #endif
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefX(mem) __asm__ __volatile__ \
         (Mstr(PFIX) " %0" : : "m" (*(((char *)(mem))+PFXDIST)))
   #else
      #if PFLVL == 2
         #define prefX(mem) ATL_pfl2R(((char*)mem)+PFXDIST)
      #else
         #define prefX(mem) ATL_pfl1R(((char*)mem)+PFXDIST)
      #endif
   #endif
#endif
/*
 * Y is prefetched in N-loop, and always fetches next NU piece
 */
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefY(mem) \
         __asm__ __volatile__ (Mstr(PFIY) " %0" : : "m" (*(((char *)(mem)))))
   #else
      #if PFLVL == 2
         #define prefY(mem) ATL_pfl2R(mem)
      #else
         #define prefY(mem) ATL_pfl1R(mem)
      #endif
   #endif
#endif
#ifndef ATL_CINT
   #define ATL_CINT const int
#endif
#ifndef ATL_INT
   #define ATL_INT int
#endif
void ATL_UGERK(ATL_CINT M0, ATL_CINT N, const float *X, const float *Y, 
               float *A, ATL_CINT lda0)
/*
 * 8x1 unrolled r1_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M=M0+M0, M8=((M0/8)*8)<<1,
            lda=lda0+lda0, lda1=lda*1;
   ATL_INT j;

   for (j=N1; j; j -= 1, A += lda1, Y += 2)
   {
      float *A0=A;
      const register float ry0=Y[0], iy0=Y[1];
      ATL_INT i;
      prefY(Y+2+2-1);
      for (i=0; i < M8; i += 16)
      {
         const register float rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                              rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7],
                              rx4=X[i+8], ix4=X[i+9], rx5=X[i+10], ix5=X[i+11],
                              rx6=X[i+12], ix6=X[i+13], rx7=X[i+14],
                              ix7=X[i+15];

         prefX(X);
         A0[i+0] += ry0*rx0 - iy0*ix0;
         prefA(A0);
         A0[i+0+1] += ry0*ix0 + iy0*rx0;
         A0[i+2] += ry0*rx1 - iy0*ix1;
         A0[i+2+1] += ry0*ix1 + iy0*rx1;
         A0[i+4] += ry0*rx2 - iy0*ix2;
         A0[i+4+1] += ry0*ix2 + iy0*rx2;
         A0[i+6] += ry0*rx3 - iy0*ix3;
         A0[i+6+1] += ry0*ix3 + iy0*rx3;
         A0[i+8] += ry0*rx4 - iy0*ix4;
         A0[i+8+1] += ry0*ix4 + iy0*rx4;
         A0[i+10] += ry0*rx5 - iy0*ix5;
         A0[i+10+1] += ry0*ix5 + iy0*rx5;
         A0[i+12] += ry0*rx6 - iy0*ix6;
         A0[i+12+1] += ry0*ix6 + iy0*rx6;
         A0[i+14] += ry0*rx7 - iy0*ix7;
         A0[i+14+1] += ry0*ix7 + iy0*rx7;
      }
      for (i=M8; i < M; i += 2)
      {
         const register float rx0 = X[i], ix0 = X[i+1];
         A0[i] += ry0 * rx0 - iy0 * ix0;
         A0[i+1] += ry0 * ix0 + iy0 * rx0;
      }
   }
}
