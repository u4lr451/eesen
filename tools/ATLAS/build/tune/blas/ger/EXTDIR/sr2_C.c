#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 8
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
void ATL_UGER2K(ATL_CINT M, ATL_CINT N, const float *X, const float *Y, 
                const float *W, const float *Z, float *A, ATL_CINT lda)
/*
 * 16x8 unrolled r2_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N8=(N/8)*8, M16=(M/16)*16, lda8=lda*8;
   ATL_INT j;

   for (j=N8; j; j -= 8, A += lda8, Y += 8)
   {
      float *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda, *A5=A4+lda,
            *A6=A5+lda, *A7=A6+lda;
      const register float y0=Y[0], z0=Z[0], y1=Y[1], z1=Z[1], y2=Y[2], z2=Z[2],
                           y3=Y[3], z3=Z[3], y4=Y[4], z4=Z[4], y5=Y[5], z5=Z[5],
                           y6=Y[6], z6=Z[6], y7=Y[7], z7=Z[7];
      ATL_INT i;
      prefY(Y+8+8-1);
      prefY(Z+8+8-1);
      for (i=0; i < M16; i += 16)
      {
         register float a0, a1, a2, a3, a4, a5, a6, a7;
         const float x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                     w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                     x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                     w7=W[i+7], x8=X[i+8], w8=W[i+8], x9=X[i+9], w9=W[i+9],
                     x10=X[i+10], w10=W[i+10], x11=X[i+11], w11=W[i+11],
                     x12=X[i+12], w12=W[i+12], x13=X[i+13], w13=W[i+13],
                     x14=X[i+14], w14=W[i+14], x15=X[i+15], w15=W[i+15];

         prefX(X);
         a0 = A0[i+0];
         a0 += x0 * y0;
         a1 = A1[i+0];
         a1 += x0 * y1;
         a2 = A2[i+0];
         a2 += x0 * y2;
         a3 = A3[i+0];
         a3 += x0 * y3;
         a4 = A4[i+0];
         a4 += x0 * y4;
         a5 = A5[i+0];
         a5 += x0 * y5;
         a6 = A6[i+0];
         a6 += x0 * y6;
         a7 = A7[i+0];
         a7 += x0 * y7;
         prefX(W);
         a0 += w0 * z0;
         prefA(A0);
         A0[i+0] = a0;
         a1 += w0 * z1;
         prefA(A1);
         A1[i+0] = a1;
         a2 += w0 * z2;
         prefA(A2);
         A2[i+0] = a2;
         a3 += w0 * z3;
         prefA(A3);
         A3[i+0] = a3;
         a4 += w0 * z4;
         prefA(A4);
         A4[i+0] = a4;
         a5 += w0 * z5;
         prefA(A5);
         A5[i+0] = a5;
         a6 += w0 * z6;
         prefA(A6);
         A6[i+0] = a6;
         a7 += w0 * z7;
         prefA(A7);
         A7[i+0] = a7;
         a0 = A0[i+1];
         a0 += x1 * y0;
         a1 = A1[i+1];
         a1 += x1 * y1;
         a2 = A2[i+1];
         a2 += x1 * y2;
         a3 = A3[i+1];
         a3 += x1 * y3;
         a4 = A4[i+1];
         a4 += x1 * y4;
         a5 = A5[i+1];
         a5 += x1 * y5;
         a6 = A6[i+1];
         a6 += x1 * y6;
         a7 = A7[i+1];
         a7 += x1 * y7;
         a0 += w1 * z0;
         A0[i+1] = a0;
         a1 += w1 * z1;
         A1[i+1] = a1;
         a2 += w1 * z2;
         A2[i+1] = a2;
         a3 += w1 * z3;
         A3[i+1] = a3;
         a4 += w1 * z4;
         A4[i+1] = a4;
         a5 += w1 * z5;
         A5[i+1] = a5;
         a6 += w1 * z6;
         A6[i+1] = a6;
         a7 += w1 * z7;
         A7[i+1] = a7;
         a0 = A0[i+2];
         a0 += x2 * y0;
         a1 = A1[i+2];
         a1 += x2 * y1;
         a2 = A2[i+2];
         a2 += x2 * y2;
         a3 = A3[i+2];
         a3 += x2 * y3;
         a4 = A4[i+2];
         a4 += x2 * y4;
         a5 = A5[i+2];
         a5 += x2 * y5;
         a6 = A6[i+2];
         a6 += x2 * y6;
         a7 = A7[i+2];
         a7 += x2 * y7;
         a0 += w2 * z0;
         A0[i+2] = a0;
         a1 += w2 * z1;
         A1[i+2] = a1;
         a2 += w2 * z2;
         A2[i+2] = a2;
         a3 += w2 * z3;
         A3[i+2] = a3;
         a4 += w2 * z4;
         A4[i+2] = a4;
         a5 += w2 * z5;
         A5[i+2] = a5;
         a6 += w2 * z6;
         A6[i+2] = a6;
         a7 += w2 * z7;
         A7[i+2] = a7;
         a0 = A0[i+3];
         a0 += x3 * y0;
         a1 = A1[i+3];
         a1 += x3 * y1;
         a2 = A2[i+3];
         a2 += x3 * y2;
         a3 = A3[i+3];
         a3 += x3 * y3;
         a4 = A4[i+3];
         a4 += x3 * y4;
         a5 = A5[i+3];
         a5 += x3 * y5;
         a6 = A6[i+3];
         a6 += x3 * y6;
         a7 = A7[i+3];
         a7 += x3 * y7;
         a0 += w3 * z0;
         A0[i+3] = a0;
         a1 += w3 * z1;
         A1[i+3] = a1;
         a2 += w3 * z2;
         A2[i+3] = a2;
         a3 += w3 * z3;
         A3[i+3] = a3;
         a4 += w3 * z4;
         A4[i+3] = a4;
         a5 += w3 * z5;
         A5[i+3] = a5;
         a6 += w3 * z6;
         A6[i+3] = a6;
         a7 += w3 * z7;
         A7[i+3] = a7;
         a0 = A0[i+4];
         a0 += x4 * y0;
         a1 = A1[i+4];
         a1 += x4 * y1;
         a2 = A2[i+4];
         a2 += x4 * y2;
         a3 = A3[i+4];
         a3 += x4 * y3;
         a4 = A4[i+4];
         a4 += x4 * y4;
         a5 = A5[i+4];
         a5 += x4 * y5;
         a6 = A6[i+4];
         a6 += x4 * y6;
         a7 = A7[i+4];
         a7 += x4 * y7;
         a0 += w4 * z0;
         A0[i+4] = a0;
         a1 += w4 * z1;
         A1[i+4] = a1;
         a2 += w4 * z2;
         A2[i+4] = a2;
         a3 += w4 * z3;
         A3[i+4] = a3;
         a4 += w4 * z4;
         A4[i+4] = a4;
         a5 += w4 * z5;
         A5[i+4] = a5;
         a6 += w4 * z6;
         A6[i+4] = a6;
         a7 += w4 * z7;
         A7[i+4] = a7;
         a0 = A0[i+5];
         a0 += x5 * y0;
         a1 = A1[i+5];
         a1 += x5 * y1;
         a2 = A2[i+5];
         a2 += x5 * y2;
         a3 = A3[i+5];
         a3 += x5 * y3;
         a4 = A4[i+5];
         a4 += x5 * y4;
         a5 = A5[i+5];
         a5 += x5 * y5;
         a6 = A6[i+5];
         a6 += x5 * y6;
         a7 = A7[i+5];
         a7 += x5 * y7;
         a0 += w5 * z0;
         A0[i+5] = a0;
         a1 += w5 * z1;
         A1[i+5] = a1;
         a2 += w5 * z2;
         A2[i+5] = a2;
         a3 += w5 * z3;
         A3[i+5] = a3;
         a4 += w5 * z4;
         A4[i+5] = a4;
         a5 += w5 * z5;
         A5[i+5] = a5;
         a6 += w5 * z6;
         A6[i+5] = a6;
         a7 += w5 * z7;
         A7[i+5] = a7;
         a0 = A0[i+6];
         a0 += x6 * y0;
         a1 = A1[i+6];
         a1 += x6 * y1;
         a2 = A2[i+6];
         a2 += x6 * y2;
         a3 = A3[i+6];
         a3 += x6 * y3;
         a4 = A4[i+6];
         a4 += x6 * y4;
         a5 = A5[i+6];
         a5 += x6 * y5;
         a6 = A6[i+6];
         a6 += x6 * y6;
         a7 = A7[i+6];
         a7 += x6 * y7;
         a0 += w6 * z0;
         A0[i+6] = a0;
         a1 += w6 * z1;
         A1[i+6] = a1;
         a2 += w6 * z2;
         A2[i+6] = a2;
         a3 += w6 * z3;
         A3[i+6] = a3;
         a4 += w6 * z4;
         A4[i+6] = a4;
         a5 += w6 * z5;
         A5[i+6] = a5;
         a6 += w6 * z6;
         A6[i+6] = a6;
         a7 += w6 * z7;
         A7[i+6] = a7;
         a0 = A0[i+7];
         a0 += x7 * y0;
         a1 = A1[i+7];
         a1 += x7 * y1;
         a2 = A2[i+7];
         a2 += x7 * y2;
         a3 = A3[i+7];
         a3 += x7 * y3;
         a4 = A4[i+7];
         a4 += x7 * y4;
         a5 = A5[i+7];
         a5 += x7 * y5;
         a6 = A6[i+7];
         a6 += x7 * y6;
         a7 = A7[i+7];
         a7 += x7 * y7;
         a0 += w7 * z0;
         A0[i+7] = a0;
         a1 += w7 * z1;
         A1[i+7] = a1;
         a2 += w7 * z2;
         A2[i+7] = a2;
         a3 += w7 * z3;
         A3[i+7] = a3;
         a4 += w7 * z4;
         A4[i+7] = a4;
         a5 += w7 * z5;
         A5[i+7] = a5;
         a6 += w7 * z6;
         A6[i+7] = a6;
         a7 += w7 * z7;
         A7[i+7] = a7;
         a0 = A0[i+8];
         a0 += x8 * y0;
         a1 = A1[i+8];
         a1 += x8 * y1;
         a2 = A2[i+8];
         a2 += x8 * y2;
         a3 = A3[i+8];
         a3 += x8 * y3;
         a4 = A4[i+8];
         a4 += x8 * y4;
         a5 = A5[i+8];
         a5 += x8 * y5;
         a6 = A6[i+8];
         a6 += x8 * y6;
         a7 = A7[i+8];
         a7 += x8 * y7;
         a0 += w8 * z0;
         A0[i+8] = a0;
         a1 += w8 * z1;
         A1[i+8] = a1;
         a2 += w8 * z2;
         A2[i+8] = a2;
         a3 += w8 * z3;
         A3[i+8] = a3;
         a4 += w8 * z4;
         A4[i+8] = a4;
         a5 += w8 * z5;
         A5[i+8] = a5;
         a6 += w8 * z6;
         A6[i+8] = a6;
         a7 += w8 * z7;
         A7[i+8] = a7;
         a0 = A0[i+9];
         a0 += x9 * y0;
         a1 = A1[i+9];
         a1 += x9 * y1;
         a2 = A2[i+9];
         a2 += x9 * y2;
         a3 = A3[i+9];
         a3 += x9 * y3;
         a4 = A4[i+9];
         a4 += x9 * y4;
         a5 = A5[i+9];
         a5 += x9 * y5;
         a6 = A6[i+9];
         a6 += x9 * y6;
         a7 = A7[i+9];
         a7 += x9 * y7;
         a0 += w9 * z0;
         A0[i+9] = a0;
         a1 += w9 * z1;
         A1[i+9] = a1;
         a2 += w9 * z2;
         A2[i+9] = a2;
         a3 += w9 * z3;
         A3[i+9] = a3;
         a4 += w9 * z4;
         A4[i+9] = a4;
         a5 += w9 * z5;
         A5[i+9] = a5;
         a6 += w9 * z6;
         A6[i+9] = a6;
         a7 += w9 * z7;
         A7[i+9] = a7;
         a0 = A0[i+10];
         a0 += x10 * y0;
         a1 = A1[i+10];
         a1 += x10 * y1;
         a2 = A2[i+10];
         a2 += x10 * y2;
         a3 = A3[i+10];
         a3 += x10 * y3;
         a4 = A4[i+10];
         a4 += x10 * y4;
         a5 = A5[i+10];
         a5 += x10 * y5;
         a6 = A6[i+10];
         a6 += x10 * y6;
         a7 = A7[i+10];
         a7 += x10 * y7;
         a0 += w10 * z0;
         A0[i+10] = a0;
         a1 += w10 * z1;
         A1[i+10] = a1;
         a2 += w10 * z2;
         A2[i+10] = a2;
         a3 += w10 * z3;
         A3[i+10] = a3;
         a4 += w10 * z4;
         A4[i+10] = a4;
         a5 += w10 * z5;
         A5[i+10] = a5;
         a6 += w10 * z6;
         A6[i+10] = a6;
         a7 += w10 * z7;
         A7[i+10] = a7;
         a0 = A0[i+11];
         a0 += x11 * y0;
         a1 = A1[i+11];
         a1 += x11 * y1;
         a2 = A2[i+11];
         a2 += x11 * y2;
         a3 = A3[i+11];
         a3 += x11 * y3;
         a4 = A4[i+11];
         a4 += x11 * y4;
         a5 = A5[i+11];
         a5 += x11 * y5;
         a6 = A6[i+11];
         a6 += x11 * y6;
         a7 = A7[i+11];
         a7 += x11 * y7;
         a0 += w11 * z0;
         A0[i+11] = a0;
         a1 += w11 * z1;
         A1[i+11] = a1;
         a2 += w11 * z2;
         A2[i+11] = a2;
         a3 += w11 * z3;
         A3[i+11] = a3;
         a4 += w11 * z4;
         A4[i+11] = a4;
         a5 += w11 * z5;
         A5[i+11] = a5;
         a6 += w11 * z6;
         A6[i+11] = a6;
         a7 += w11 * z7;
         A7[i+11] = a7;
         a0 = A0[i+12];
         a0 += x12 * y0;
         a1 = A1[i+12];
         a1 += x12 * y1;
         a2 = A2[i+12];
         a2 += x12 * y2;
         a3 = A3[i+12];
         a3 += x12 * y3;
         a4 = A4[i+12];
         a4 += x12 * y4;
         a5 = A5[i+12];
         a5 += x12 * y5;
         a6 = A6[i+12];
         a6 += x12 * y6;
         a7 = A7[i+12];
         a7 += x12 * y7;
         a0 += w12 * z0;
         A0[i+12] = a0;
         a1 += w12 * z1;
         A1[i+12] = a1;
         a2 += w12 * z2;
         A2[i+12] = a2;
         a3 += w12 * z3;
         A3[i+12] = a3;
         a4 += w12 * z4;
         A4[i+12] = a4;
         a5 += w12 * z5;
         A5[i+12] = a5;
         a6 += w12 * z6;
         A6[i+12] = a6;
         a7 += w12 * z7;
         A7[i+12] = a7;
         a0 = A0[i+13];
         a0 += x13 * y0;
         a1 = A1[i+13];
         a1 += x13 * y1;
         a2 = A2[i+13];
         a2 += x13 * y2;
         a3 = A3[i+13];
         a3 += x13 * y3;
         a4 = A4[i+13];
         a4 += x13 * y4;
         a5 = A5[i+13];
         a5 += x13 * y5;
         a6 = A6[i+13];
         a6 += x13 * y6;
         a7 = A7[i+13];
         a7 += x13 * y7;
         a0 += w13 * z0;
         A0[i+13] = a0;
         a1 += w13 * z1;
         A1[i+13] = a1;
         a2 += w13 * z2;
         A2[i+13] = a2;
         a3 += w13 * z3;
         A3[i+13] = a3;
         a4 += w13 * z4;
         A4[i+13] = a4;
         a5 += w13 * z5;
         A5[i+13] = a5;
         a6 += w13 * z6;
         A6[i+13] = a6;
         a7 += w13 * z7;
         A7[i+13] = a7;
         a0 = A0[i+14];
         a0 += x14 * y0;
         a1 = A1[i+14];
         a1 += x14 * y1;
         a2 = A2[i+14];
         a2 += x14 * y2;
         a3 = A3[i+14];
         a3 += x14 * y3;
         a4 = A4[i+14];
         a4 += x14 * y4;
         a5 = A5[i+14];
         a5 += x14 * y5;
         a6 = A6[i+14];
         a6 += x14 * y6;
         a7 = A7[i+14];
         a7 += x14 * y7;
         a0 += w14 * z0;
         A0[i+14] = a0;
         a1 += w14 * z1;
         A1[i+14] = a1;
         a2 += w14 * z2;
         A2[i+14] = a2;
         a3 += w14 * z3;
         A3[i+14] = a3;
         a4 += w14 * z4;
         A4[i+14] = a4;
         a5 += w14 * z5;
         A5[i+14] = a5;
         a6 += w14 * z6;
         A6[i+14] = a6;
         a7 += w14 * z7;
         A7[i+14] = a7;
         a0 = A0[i+15];
         a0 += x15 * y0;
         a1 = A1[i+15];
         a1 += x15 * y1;
         a2 = A2[i+15];
         a2 += x15 * y2;
         a3 = A3[i+15];
         a3 += x15 * y3;
         a4 = A4[i+15];
         a4 += x15 * y4;
         a5 = A5[i+15];
         a5 += x15 * y5;
         a6 = A6[i+15];
         a6 += x15 * y6;
         a7 = A7[i+15];
         a7 += x15 * y7;
         a0 += w15 * z0;
         A0[i+15] = a0;
         a1 += w15 * z1;
         A1[i+15] = a1;
         a2 += w15 * z2;
         A2[i+15] = a2;
         a3 += w15 * z3;
         A3[i+15] = a3;
         a4 += w15 * z4;
         A4[i+15] = a4;
         a5 += w15 * z5;
         A5[i+15] = a5;
         a6 += w15 * z6;
         A6[i+15] = a6;
         a7 += w15 * z7;
         A7[i+15] = a7;

      }
      for (i=M16; i < M; i++)
      {
         const register float x0 = X[i], w0 = W[i];
         register float a0=A0[i], a1=A1[i], a2=A2[i], a3=A3[i], a4=A4[i],
                        a5=A5[i], a6=A6[i], a7=A7[i];

         a0 += x0 * y0;
         a1 += x0 * y1;
         a2 += x0 * y2;
         a3 += x0 * y3;
         a4 += x0 * y4;
         a5 += x0 * y5;
         a6 += x0 * y6;
         a7 += x0 * y7;
         a0 += w0 * z0;
         A0[i] = a0;
         a1 += w0 * z1;
         A1[i] = a1;
         a2 += w0 * z2;
         A2[i] = a2;
         a3 += w0 * z3;
         A3[i] = a3;
         a4 += w0 * z4;
         A4[i] = a4;
         a5 += w0 * z5;
         A5[i] = a5;
         a6 += w0 * z6;
         A6[i] = a6;
         a7 += w0 * z7;
         A7[i] = a7;
      }
      Z += 8;
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N8; j; j--, A += lda, Y++)
   {
      float *A0=A;
      const register float y0=Y[0], z0=Z[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      prefY(Z+1+1-1);
      for (i=0; i < M16; i += 16)
      {
         register float a0;
         const float x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                     w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                     x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                     w7=W[i+7], x8=X[i+8], w8=W[i+8], x9=X[i+9], w9=W[i+9],
                     x10=X[i+10], w10=W[i+10], x11=X[i+11], w11=W[i+11],
                     x12=X[i+12], w12=W[i+12], x13=X[i+13], w13=W[i+13],
                     x14=X[i+14], w14=W[i+14], x15=X[i+15], w15=W[i+15];

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
         a0 = A0[i+8];
         a0 += x8 * y0;
         a0 += w8 * z0;
         A0[i+8] = a0;
         a0 = A0[i+9];
         a0 += x9 * y0;
         a0 += w9 * z0;
         A0[i+9] = a0;
         a0 = A0[i+10];
         a0 += x10 * y0;
         a0 += w10 * z0;
         A0[i+10] = a0;
         a0 = A0[i+11];
         a0 += x11 * y0;
         a0 += w11 * z0;
         A0[i+11] = a0;
         a0 = A0[i+12];
         a0 += x12 * y0;
         a0 += w12 * z0;
         A0[i+12] = a0;
         a0 = A0[i+13];
         a0 += x13 * y0;
         a0 += w13 * z0;
         A0[i+13] = a0;
         a0 = A0[i+14];
         a0 += x14 * y0;
         a0 += w14 * z0;
         A0[i+14] = a0;
         a0 = A0[i+15];
         a0 += x15 * y0;
         a0 += w15 * z0;
         A0[i+15] = a0;

      }
      for (i=M16; i < M; i++)
      {
         const register float x0 = X[i], w0 = W[i];
         register float a0=A0[i];

         a0 += x0 * y0;
         a0 += w0 * z0;
         A0[i] = a0;
      }
      Z++;
   }
}
