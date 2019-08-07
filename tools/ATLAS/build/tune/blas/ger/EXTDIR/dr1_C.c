#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 1
#endif
#ifndef PFXDIST
   #define PFXDIST 0
#endif
#ifndef PFADIST
   #define PFADIST 0
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
void ATL_UGERK(ATL_CINT M, ATL_CINT N, const double *X, const double *Y, 
               double *A, ATL_CINT lda)
/*
 * 8x1 unrolled r1_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M8=(M/8)*8, lda1=lda*1;
   ATL_INT j;

   for (j=N1; j; j -= 1, A += lda1, Y += 1)
   {
      double *A0=A;
      const register double y0=Y[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      for (i=0; i < M8; i += 8)
      {
         const register double x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                               x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7];

         prefX(X);
         A0[i+0] += y0 * x0;
         prefA(A0);
         A0[i+1] += y0 * x1;
         A0[i+2] += y0 * x2;
         A0[i+3] += y0 * x3;
         A0[i+4] += y0 * x4;
         A0[i+5] += y0 * x5;
         A0[i+6] += y0 * x6;
         A0[i+7] += y0 * x7;
      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i];
         A0[i] += y0 * x0;
      }
   }
}
