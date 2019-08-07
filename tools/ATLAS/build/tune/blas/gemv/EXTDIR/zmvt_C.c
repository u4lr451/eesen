#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 1
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
void ATL_UGEMV(ATL_CINT M0, ATL_CINT N, const TYPE *A, ATL_CINT lda0,
               const TYPE *X, TYPE *Y)
/*
 * 4x1 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M=M0+M0, M4=((M0/4)*4)<<1,
            lda=lda0+lda0, lda1=lda*1;
   ATL_INT j;

   for (j=N1; j; j -= 1, A += lda1, Y += 2)
   {
      const double *A0=A;
      register double ry0=ATL_rzero, iy0=ATL_rzero;
      ATL_INT i;
      prefY(Y+2+2-1);
      for (i=0; i < M4; i += 8)
      {
         const register double ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2],
                               ia1_0=A0[i+3], ra2_0=A0[i+4], ia2_0=A0[i+5],
                               ra3_0=A0[i+6], ia3_0=A0[i+7];
         const register double rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                               rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 += ra1_0 * rx1;
         iy0 += ra1_0 * ix1;
         ry0 += ra2_0 * rx2;
         iy0 += ra2_0 * ix2;
         ry0 += ra3_0 * rx3;
         iy0 += ra3_0 * ix3;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry0 -= ia1_0 * ix1;
         iy0 += ia1_0 * rx1;
         ry0 -= ia2_0 * ix2;
         iy0 += ia2_0 * rx2;
         ry0 -= ia3_0 * ix3;
         iy0 += ia3_0 * rx3;
      }
      for (i=M4; i < M; i += 2)
      {
         const register double rx0 = X[i], ix0 = X[i+1];
         const register double ra0_0=A0[i], ia0_0=A0[i+1];
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
      #endif
   }
}
