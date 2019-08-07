#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 16
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
void ATL_UGEMV(ATL_CINT M, ATL_CINT N, const TYPE *A, ATL_CINT lda,
               const TYPE *X, TYPE *Y)
/*
 * 8x16 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N16=(N/16)*16, M8=(M/8)*8, lda16=lda*16;
   ATL_INT j;

   for (j=N16; j; j -= 16, A += lda16, Y += 16)
   {
      const double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda,
                   *A5=A4+lda, *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda,
                   *A10=A9+lda, *A11=A10+lda, *A12=A11+lda, *A13=A12+lda,
                   *A14=A13+lda, *A15=A14+lda;
      register double y0=ATL_rzero, y1=ATL_rzero, y2=ATL_rzero, y3=ATL_rzero,
                      y4=ATL_rzero, y5=ATL_rzero, y6=ATL_rzero, y7=ATL_rzero,
                      y8=ATL_rzero, y9=ATL_rzero, y10=ATL_rzero, y11=ATL_rzero,
                      y12=ATL_rzero, y13=ATL_rzero, y14=ATL_rzero,
                      y15=ATL_rzero;
      ATL_INT i;
      prefY(Y+16+16-1);
      for (i=0; i < M8; i += 8)
      {
         const register double x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                               x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7];

         prefX(X);
         y0 += A0[i+0] * x0;
         prefA(A0);
         y1 += A1[i+0] * x0;
         prefA(A1);
         y2 += A2[i+0] * x0;
         prefA(A2);
         y3 += A3[i+0] * x0;
         prefA(A3);
         y4 += A4[i+0] * x0;
         prefA(A4);
         y5 += A5[i+0] * x0;
         prefA(A5);
         y6 += A6[i+0] * x0;
         prefA(A6);
         y7 += A7[i+0] * x0;
         prefA(A7);
         y8 += A8[i+0] * x0;
         prefA(A8);
         y9 += A9[i+0] * x0;
         prefA(A9);
         y10 += A10[i+0] * x0;
         prefA(A10);
         y11 += A11[i+0] * x0;
         prefA(A11);
         y12 += A12[i+0] * x0;
         prefA(A12);
         y13 += A13[i+0] * x0;
         prefA(A13);
         y14 += A14[i+0] * x0;
         prefA(A14);
         y15 += A15[i+0] * x0;
         prefA(A15);
         y0 += A0[i+1] * x1;
         y1 += A1[i+1] * x1;
         y2 += A2[i+1] * x1;
         y3 += A3[i+1] * x1;
         y4 += A4[i+1] * x1;
         y5 += A5[i+1] * x1;
         y6 += A6[i+1] * x1;
         y7 += A7[i+1] * x1;
         y8 += A8[i+1] * x1;
         y9 += A9[i+1] * x1;
         y10 += A10[i+1] * x1;
         y11 += A11[i+1] * x1;
         y12 += A12[i+1] * x1;
         y13 += A13[i+1] * x1;
         y14 += A14[i+1] * x1;
         y15 += A15[i+1] * x1;
         y0 += A0[i+2] * x2;
         y1 += A1[i+2] * x2;
         y2 += A2[i+2] * x2;
         y3 += A3[i+2] * x2;
         y4 += A4[i+2] * x2;
         y5 += A5[i+2] * x2;
         y6 += A6[i+2] * x2;
         y7 += A7[i+2] * x2;
         y8 += A8[i+2] * x2;
         y9 += A9[i+2] * x2;
         y10 += A10[i+2] * x2;
         y11 += A11[i+2] * x2;
         y12 += A12[i+2] * x2;
         y13 += A13[i+2] * x2;
         y14 += A14[i+2] * x2;
         y15 += A15[i+2] * x2;
         y0 += A0[i+3] * x3;
         y1 += A1[i+3] * x3;
         y2 += A2[i+3] * x3;
         y3 += A3[i+3] * x3;
         y4 += A4[i+3] * x3;
         y5 += A5[i+3] * x3;
         y6 += A6[i+3] * x3;
         y7 += A7[i+3] * x3;
         y8 += A8[i+3] * x3;
         y9 += A9[i+3] * x3;
         y10 += A10[i+3] * x3;
         y11 += A11[i+3] * x3;
         y12 += A12[i+3] * x3;
         y13 += A13[i+3] * x3;
         y14 += A14[i+3] * x3;
         y15 += A15[i+3] * x3;
         y0 += A0[i+4] * x4;
         y1 += A1[i+4] * x4;
         y2 += A2[i+4] * x4;
         y3 += A3[i+4] * x4;
         y4 += A4[i+4] * x4;
         y5 += A5[i+4] * x4;
         y6 += A6[i+4] * x4;
         y7 += A7[i+4] * x4;
         y8 += A8[i+4] * x4;
         y9 += A9[i+4] * x4;
         y10 += A10[i+4] * x4;
         y11 += A11[i+4] * x4;
         y12 += A12[i+4] * x4;
         y13 += A13[i+4] * x4;
         y14 += A14[i+4] * x4;
         y15 += A15[i+4] * x4;
         y0 += A0[i+5] * x5;
         y1 += A1[i+5] * x5;
         y2 += A2[i+5] * x5;
         y3 += A3[i+5] * x5;
         y4 += A4[i+5] * x5;
         y5 += A5[i+5] * x5;
         y6 += A6[i+5] * x5;
         y7 += A7[i+5] * x5;
         y8 += A8[i+5] * x5;
         y9 += A9[i+5] * x5;
         y10 += A10[i+5] * x5;
         y11 += A11[i+5] * x5;
         y12 += A12[i+5] * x5;
         y13 += A13[i+5] * x5;
         y14 += A14[i+5] * x5;
         y15 += A15[i+5] * x5;
         y0 += A0[i+6] * x6;
         y1 += A1[i+6] * x6;
         y2 += A2[i+6] * x6;
         y3 += A3[i+6] * x6;
         y4 += A4[i+6] * x6;
         y5 += A5[i+6] * x6;
         y6 += A6[i+6] * x6;
         y7 += A7[i+6] * x6;
         y8 += A8[i+6] * x6;
         y9 += A9[i+6] * x6;
         y10 += A10[i+6] * x6;
         y11 += A11[i+6] * x6;
         y12 += A12[i+6] * x6;
         y13 += A13[i+6] * x6;
         y14 += A14[i+6] * x6;
         y15 += A15[i+6] * x6;
         y0 += A0[i+7] * x7;
         y1 += A1[i+7] * x7;
         y2 += A2[i+7] * x7;
         y3 += A3[i+7] * x7;
         y4 += A4[i+7] * x7;
         y5 += A5[i+7] * x7;
         y6 += A6[i+7] * x7;
         y7 += A7[i+7] * x7;
         y8 += A8[i+7] * x7;
         y9 += A9[i+7] * x7;
         y10 += A10[i+7] * x7;
         y11 += A11[i+7] * x7;
         y12 += A12[i+7] * x7;
         y13 += A13[i+7] * x7;
         y14 += A14[i+7] * x7;
         y15 += A15[i+7] * x7;
      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i];
         y0 += A0[i] * x0;
         y1 += A1[i] * x0;
         y2 += A2[i] * x0;
         y3 += A3[i] * x0;
         y4 += A4[i] * x0;
         y5 += A5[i] * x0;
         y6 += A6[i] * x0;
         y7 += A7[i] * x0;
         y8 += A8[i] * x0;
         y9 += A9[i] * x0;
         y10 += A10[i] * x0;
         y11 += A11[i] * x0;
         y12 += A12[i] * x0;
         y13 += A13[i] * x0;
         y14 += A14[i] * x0;
         y15 += A15[i] * x0;
      }
      #ifdef BETA0
         Y[0] = y0;
         Y[1] = y1;
         Y[2] = y2;
         Y[3] = y3;
         Y[4] = y4;
         Y[5] = y5;
         Y[6] = y6;
         Y[7] = y7;
         Y[8] = y8;
         Y[9] = y9;
         Y[10] = y10;
         Y[11] = y11;
         Y[12] = y12;
         Y[13] = y13;
         Y[14] = y14;
         Y[15] = y15;
      #else
         Y[0] += y0;
         Y[1] += y1;
         Y[2] += y2;
         Y[3] += y3;
         Y[4] += y4;
         Y[5] += y5;
         Y[6] += y6;
         Y[7] += y7;
         Y[8] += y8;
         Y[9] += y9;
         Y[10] += y10;
         Y[11] += y11;
         Y[12] += y12;
         Y[13] += y13;
         Y[14] += y14;
         Y[15] += y15;
      #endif
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N16; j; j--, A += lda, Y++)
   {
      const double *A0=A;
      register double y0=ATL_rzero;
      ATL_INT i;
      prefY(Y+1+1-1);
      for (i=0; i < M8; i += 8)
      {
         const register double x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                               x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7];

         prefX(X);
         y0 += A0[i+0] * x0;
         prefA(A0);
         y0 += A0[i+1] * x1;
         y0 += A0[i+2] * x2;
         y0 += A0[i+3] * x3;
         y0 += A0[i+4] * x4;
         y0 += A0[i+5] * x5;
         y0 += A0[i+6] * x6;
         y0 += A0[i+7] * x7;
      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i];
         y0 += A0[i] * x0;
      }
      #ifdef BETA0
         Y[0] = y0;
      #else
         Y[0] += y0;
      #endif
   }
}
