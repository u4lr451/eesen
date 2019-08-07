#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_cJIK0x0x0TN1x1x1_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=0, 
 * lda=0, ldb=0, ldc=0, mu=1, nu=1, ku=1, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   #define Mb M
   #define Nb N
   #define Kb K
   const float *stM = A + (lda*Mb);
   const float *stN = B + (ldb*Nb);
   const float *pfA = A + M;
   #define incAk 1
   const int incAm = ((lda) - Kb), incAn = -(Mb*lda);
   #define incBk 1
   const int incBm = -(Kb), incBn = (ldb);
   #define incCm 2
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float rC0_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      pfA += lda;
      do /* M-loop */
      {
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         for (k=0; k < K; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
         }
         *pC0 = rC0_0;
         pC0 += incCm;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
void ATL_cJIK0x0x0TN0x0x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=0, 
 * lda=0, ldb=0, ldc=0, mu=6, nu=1, ku=1, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const int Mb = (M/6)*6;
   #define Nb N
   #define Kb K
   const int Kloop = K - 1;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (lda*Mb);
   const float *stN = B + (ldb*Nb);
   const float *pfA = A + M;
   #define incAk 1
   const int incAm = ((((lda) << 2)+((lda) << 1)) - Kb), incAn = -(Mb*lda);
   #define incBk 1
   const int incBm = -(Kb), incBn = (ldb);
   #define incAk0 incAk
   #define incBk0 incBk
   #define incCm 12
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda), *pA3=pA2+(lda), *pA4=pA3+(lda), *pA5=pA4+(lda);
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2, rA3, rA4, rA5;
   register float rB0;
   register float m0, m1, m2;
   register float rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         ATL_pfl1R(pfA+0);
         ATL_pfl1R(pfA+16);
         pfA += lda;
         do /* M-loop */
         {
            rA0 = beta;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[2];
            rC1_0 *= rA0;
            rC2_0 = pC0[4];
            rC2_0 *= rA0;
            rC3_0 = pC0[6];
            rC3_0 *= rA0;
            rC4_0 = pC0[8];
            rC4_0 *= rA0;
            rC5_0 = pC0[10];
            rC5_0 *= rA0;
/*
 *          Start pipeline
 */
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = *pA1;
            m0 = rA0 * rB0;
            rA2 = *pA2;
            rA3 = *pA3;
            rA4 = *pA4;
            m1 = rA1 * rB0;
            rA5 = *pA5;
            m2 = rA2 * rB0;

            for (k=0; k < Kloop; k++) /* easy loop to unroll */
            {
               rC0_0 += m0;
               m0 = rA3 * rB0;
               rC1_0 += m1;
               m1 = rA4 * rB0;
               rC2_0 += m2;
               m2 = rA5 * rB0;
               rA0 = pA0[1];
               rB0 = pB0[1];
               rA1 = pA1[1];
               rA2 = pA2[1];
               rA3 = pA3[1];
               rA4 = pA4[1];
               rC3_0 += m0;
               m0 = rA0 * rB0;
               rA5 = pA5[1];
               rC4_0 += m1;
               m1 = rA1 * rB0;
               rC5_0 += m2;
               m2 = rA2 * rB0;
               pA0 += incAk;
               pA1 += incAk;
               pA2 += incAk;
               pA3 += incAk;
               pA4 += incAk;
               pA5 += incAk;
               pB0 += incBk;
            } /* end K-loop */
/*
 *          Drain pipe on last iteration of K-loop
 */
            rC0_0 += m0;
            m0 = rA3 * rB0;
            rC1_0 += m1;
            m1 = rA4 * rB0;
            rC2_0 += m2;
            m2 = rA5 * rB0;
            rC3_0 += m0;
            rC4_0 += m1;
            rC5_0 += m2;
            pA0 += incAk0;
            pA1 += incAk0;
            pA2 += incAk0;
            pA3 += incAk0;
            pA4 += incAk0;
            pA5 += incAk0;
            pB0 += incBk0;
            *pC0 = rC0_0;
            pC0[2] = rC1_0;
            pC0[4] = rC2_0;
            pC0[6] = rC3_0;
            pC0[8] = rC4_0;
            pC0[10] = rC5_0;
            pC0 += incCm;
            pA0 += incAm;
            pA1 += incAm;
            pA2 += incAm;
            pA3 += incAm;
            pA4 += incAm;
            pA5 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pA0 += incAn;
         pA1 += incAn;
         pA2 += incAn;
         pA3 += incAn;
         pA4 += incAn;
         pA5 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=M-Mb)
      ATL_cJIK0x0x0TN1x1x1_a1_bX(k, N, K, alpha, ca + (Mb*lda), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif