#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 2
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
void ATL_UGER2K(ATL_CINT M, ATL_CINT N, const double *X, const double *Y, 
                const double *W, const double *Z, double *A, ATL_CINT lda)
/*
 * 8x2 unrolled r2_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N2=(N/2)*2, M8=(M/8)*8, lda2=lda*2;
   ATL_INT j;

   for (j=N2; j; j -= 2, A += lda2, Y += 2)
   {
      double *A0=A, *A1=A0+lda;
      const register double y0=Y[0], z0=Z[0], y1=Y[1], z1=Z[1];
      ATL_INT i;
      prefY(Y+2+2-1);
      prefY(Z+2+2-1);
      for (i=0; i < M8; i += 8)
      {
         register double a0, a1;
         const double x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                      w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                      x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                      w7=W[i+7];

         prefX(X);
         a0 = A0[i+0];
         a0 += x0 * y0;
         a1 = A1[i+0];
         a1 += x0 * y1;
         prefX(W);
         a0 += w0 * z0;
         prefA(A0);
         A0[i+0] = a0;
         a1 += w0 * z1;
         prefA(A1);
         A1[i+0] = a1;
         a0 = A0[i+1];
         a0 += x1 * y0;
         a1 = A1[i+1];
         a1 += x1 * y1;
         a0 += w1 * z0;
         A0[i+1] = a0;
         a1 += w1 * z1;
         A1[i+1] = a1;
         a0 = A0[i+2];
         a0 += x2 * y0;
         a1 = A1[i+2];
         a1 += x2 * y1;
         a0 += w2 * z0;
         A0[i+2] = a0;
         a1 += w2 * z1;
         A1[i+2] = a1;
         a0 = A0[i+3];
         a0 += x3 * y0;
         a1 = A1[i+3];
         a1 += x3 * y1;
         a0 += w3 * z0;
         A0[i+3] = a0;
         a1 += w3 * z1;
         A1[i+3] = a1;
         a0 = A0[i+4];
         a0 += x4 * y0;
         a1 = A1[i+4];
         a1 += x4 * y1;
         a0 += w4 * z0;
         A0[i+4] = a0;
         a1 += w4 * z1;
         A1[i+4] = a1;
         a0 = A0[i+5];
         a0 += x5 * y0;
         a1 = A1[i+5];
         a1 += x5 * y1;
         a0 += w5 * z0;
         A0[i+5] = a0;
         a1 += w5 * z1;
         A1[i+5] = a1;
         a0 = A0[i+6];
         a0 += x6 * y0;
         a1 = A1[i+6];
         a1 += x6 * y1;
         a0 += w6 * z0;
         A0[i+6] = a0;
         a1 += w6 * z1;
         A1[i+6] = a1;
         a0 = A0[i+7];
         a0 += x7 * y0;
         a1 = A1[i+7];
         a1 += x7 * y1;
         a0 += w7 * z0;
         A0[i+7] = a0;
         a1 += w7 * z1;
         A1[i+7] = a1;

      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i], w0 = W[i];
         register double a0=A0[i], a1=A1[i];

         a0 += x0 * y0;
         a1 += x0 * y1;
         a0 += w0 * z0;
         A0[i] = a0;
         a1 += w0 * z1;
         A1[i] = a1;
      }
      Z += 2;
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N2; j; j--, A += lda, Y++)
   {
      double *A0=A;
      const register double y0=Y[0], z0=Z[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      prefY(Z+1+1-1);
      for (i=0; i < M8; i += 8)
      {
         register double a0;
         const double x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                      w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                      x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                      w7=W[i+7];

         prefX(X);
         a0 = A0[i+0];
         a0 += x0 * y0;
         prefX(W);
         a0 += w0 * z0;
         prefA(A0);
         A0[i+0] = a0;
         a0 = A0[i+1];
         a0 += x1 * y0;
         a0 += w1 * z0;
         A0[i+1] = a0;
         a0 = A0[i+2];
         a0 += x2 * y0;
         a0 += w2 * z0;
         A0[i+2] = a0;
         a0 = A0[i+3];
         a0 += x3 * y0;
         a0 += w3 * z0;
         A0[i+3] = a0;
         a0 = A0[i+4];
         a0 += x4 * y0;
         a0 += w4 * z0;
         A0[i+4] = a0;
         a0 = A0[i+5];
         a0 += x5 * y0;
         a0 += w5 * z0;
         A0[i+5] = a0;
         a0 = A0[i+6];
         a0 += x6 * y0;
         a0 += w6 * z0;
         A0[i+6] = a0;
         a0 = A0[i+7];
         a0 += x7 * y0;
         a0 += w7 * z0;
         A0[i+7] = a0;

      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i], w0 = W[i];
         register double a0=A0[i];

         a0 += x0 * y0;
         a0 += w0 * z0;
         A0[i] = a0;
      }
      Z++;
   }
}
