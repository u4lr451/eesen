#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_zJIK32x32x32TN0x0x0_aX_b0
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=32, NB=32, KB=32, 
 * lda=0, ldb=0, ldc=0, mu=2, nu=4, ku=32, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const double *stM = A + (((lda) << 6));
   const double *stN = B + (((ldb) << 6));
   const double *pfA = A + M;
   const double BetaAlpha = beta / alpha;
   #define incAk 64
   const int incAm = ((((((lda) << 1)) - 32) << 1)), incAn = -(((lda) << 6));
   #define incBk 64
   const int incBm = -64, incBn = (((ldb) << 3));
   #define incCm 4
   const int incCn = (((ldc) << 3)) - 64;
   double *pC0=C, *pC1=pC0+(((ldc) << 1)), *pC2=pC1+(((ldc) << 1)), *pC3=pC2+(((ldc) << 1));
   const double *pA0=A, *pA1=pA0+(((lda) << 1));
   const double *pB0=B, *pB1=pB0+(((ldb) << 1)), *pB2=pB1+(((ldb) << 1)), *pB3=pB2+(((ldb) << 1));
   register int k;
   register double rA0, rA1;
   register double rB0, rB1, rB2, rB3;
   register double rC0_0, rC1_0, rC0_1, rC1_1, rC0_2, rC1_2, rC0_3, rC1_3;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+8);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+24);
      pfA += lda;
      do /* M-loop */
      {
         ATL_pfl1W(pC0);
         ATL_pfl1W(pC1);
         ATL_pfl1W(pC2);
         ATL_pfl1W(pC3);
         rA0 = *pA0;
         rB0 = *pB0;
         rC0_0 = rA0 * rB0;
         rA1 = *pA1;
         rB1 = *pB1;
         rC1_0 = rA1 * rB0;
         rB2 = *pB2;
         rB3 = *pB3;
         rC0_1 = rA0 * rB1;
         rC1_1 = rA1 * rB1;
         rC0_2 = rA0 * rB2;
         rC1_2 = rA1 * rB2;
         rC0_3 = rA0 * rB3;
         rC1_3 = rA1 * rB3;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[2];
         rB1 = pB1[2];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[2];
         rB3 = pB3[2];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[4];
         rB1 = pB1[4];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[4];
         rB3 = pB3[4];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[6];
         rB1 = pB1[6];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[6];
         rB3 = pB3[6];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[8];
         rB1 = pB1[8];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[8];
         rB3 = pB3[8];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[10];
         rB1 = pB1[10];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[10];
         rB3 = pB3[10];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[12];
         rB1 = pB1[12];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[12];
         rB3 = pB3[12];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[14];
         rB1 = pB1[14];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[14];
         rB3 = pB3[14];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[16];
         rB1 = pB1[16];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[16];
         rB3 = pB3[16];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[18];
         rB1 = pB1[18];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[18];
         rB3 = pB3[18];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[20];
         rB1 = pB1[20];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[20];
         rB3 = pB3[20];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[22];
         rB0 = pB0[22];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[22];
         rB1 = pB1[22];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[22];
         rB3 = pB3[22];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[24];
         rB0 = pB0[24];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[24];
         rB1 = pB1[24];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[24];
         rB3 = pB3[24];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[26];
         rB0 = pB0[26];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[26];
         rB1 = pB1[26];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[26];
         rB3 = pB3[26];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[28];
         rB0 = pB0[28];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[28];
         rB1 = pB1[28];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[28];
         rB3 = pB3[28];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[30];
         rB0 = pB0[30];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[30];
         rB1 = pB1[30];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[30];
         rB3 = pB3[30];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[32];
         rB0 = pB0[32];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[32];
         rB1 = pB1[32];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[32];
         rB3 = pB3[32];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[34];
         rB0 = pB0[34];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[34];
         rB1 = pB1[34];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[34];
         rB3 = pB3[34];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[36];
         rB0 = pB0[36];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[36];
         rB1 = pB1[36];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[36];
         rB3 = pB3[36];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[38];
         rB0 = pB0[38];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[38];
         rB1 = pB1[38];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[38];
         rB3 = pB3[38];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[40];
         rB0 = pB0[40];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[40];
         rB1 = pB1[40];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[40];
         rB3 = pB3[40];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[42];
         rB0 = pB0[42];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[42];
         rB1 = pB1[42];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[42];
         rB3 = pB3[42];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[44];
         rB0 = pB0[44];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[44];
         rB1 = pB1[44];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[44];
         rB3 = pB3[44];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[46];
         rB0 = pB0[46];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[46];
         rB1 = pB1[46];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[46];
         rB3 = pB3[46];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[48];
         rB0 = pB0[48];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[48];
         rB1 = pB1[48];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[48];
         rB3 = pB3[48];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[50];
         rB0 = pB0[50];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[50];
         rB1 = pB1[50];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[50];
         rB3 = pB3[50];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[52];
         rB0 = pB0[52];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[52];
         rB1 = pB1[52];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[52];
         rB3 = pB3[52];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[54];
         rB0 = pB0[54];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[54];
         rB1 = pB1[54];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[54];
         rB3 = pB3[54];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[56];
         rB0 = pB0[56];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[56];
         rB1 = pB1[56];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[56];
         rB3 = pB3[56];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[58];
         rB0 = pB0[58];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[58];
         rB1 = pB1[58];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[58];
         rB3 = pB3[58];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[60];
         rB0 = pB0[60];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[60];
         rB1 = pB1[60];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[60];
         rB3 = pB3[60];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rA0 = pA0[62];
         rB0 = pB0[62];
         rC0_0 += rA0 * rB0;
         rA1 = pA1[62];
         rB1 = pB1[62];
         rC1_0 += rA1 * rB0;
         rB2 = pB2[62];
         rB3 = pB3[62];
         rC0_1 += rA0 * rB1;
         rC1_1 += rA1 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         pA0 += incAk;
         pA1 += incAk;
         pB0 += incBk;
         pB1 += incBk;
         pB2 += incBk;
         pB3 += incBk;
         rB0 = alpha;
         rC0_0 *= rB0;
         rC0_1 *= rB0;
         rC0_2 *= rB0;
         rC0_3 *= rB0;
         rC1_0 *= rB0;
         rC1_1 *= rB0;
         rC1_2 *= rB0;
         rC1_3 *= rB0;
         *pC0 = rC0_0;
         pC0[2] = rC1_0;
         *pC1 = rC0_1;
         pC1[2] = rC1_1;
         *pC2 = rC0_2;
         pC2[2] = rC1_2;
         *pC3 = rC0_3;
         pC3[2] = rC1_3;
         pC0 += incCm;
         pC1 += incCm;
         pC2 += incCm;
         pC3 += incCm;
         pA0 += incAm;
         pA1 += incAm;
         pB0 += incBm;
         pB1 += incBm;
         pB2 += incBm;
         pB3 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pC2 += incCn;
      pC3 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pB0 += incBn;
      pB1 += incBn;
      pB2 += incBn;
      pB3 += incBn;
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
