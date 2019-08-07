#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
static void ATL_sJIK0x0x12TN1x1x12_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=12, 
 * lda=12, ldb=12, ldc=0, mu=1, nu=1, ku=12, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (((Mb) << 3)+((Mb) << 2));
   const float *stN = B + (((Nb) << 3)+((Nb) << 2));
   #define incAk 12
   const int incAm = 0, incAn = -(((Mb) << 3)+((Mb) << 2));
   #define incBk 12
   const int incBm = -12, incBn = 12;
   const int incAk0 = ((incAk) / 12), incBk0 = ((incBk) / 12);
   #define incCm 1
   const int incCn = (ldc) - (Mb);
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float m0, m1, m2, m3;
   register float rC0_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
/*
 *       Start pipeline
 */
         rA0 = *pA0;
         rB0 = *pB0;
         m0 = rA0 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         m1 = rA0 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         m2 = rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         m3 = rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];

/*
 *       Completely unrolled K-loop
 */
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += m2;
         m2 = rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += m3;
         m3 = rA0 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += m2;
         m2 = rA0 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
/*
 *       Drain pipe on last iteration of K-loop
 */
         rC0_0 += m3;
         m3 = rA0 * rB0;
         rC0_0 += m0;
         rC0_0 += m1;
         rC0_0 += m2;
         rC0_0 += m3;
         pA0 += incAk;
         pB0 += incBk;
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
void ATL_sJIK0x0x12TN12x12x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=12, 
 * lda=12, ldb=12, ldc=0, mu=6, nu=1, ku=12, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const int Mb = (M/6)*6;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 3)+((Mb) << 2));
   const float *stN = B + (((Nb) << 3)+((Nb) << 2));
   #define incAk 12
   const int incAm = 60, incAn = -(((Mb) << 3)+((Mb) << 2));
   #define incBk 12
   const int incBm = -12, incBn = 12;
   const int incAk0 = ((incAk) / 12), incBk0 = ((incBk) / 12);
   #define incCm 6
   const int incCn = (ldc) - (Mb);
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2, rA3, rA4, rA5;
   register float rB0;
   register float m0, m1, m2, m3;
   register float rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         do /* M-loop */
         {
            rA0 = beta;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[1];
            rC1_0 *= rA0;
            rC2_0 = pC0[2];
            rC2_0 *= rA0;
            rC3_0 = pC0[3];
            rC3_0 *= rA0;
            rC4_0 = pC0[4];
            rC4_0 *= rA0;
            rC5_0 = pC0[5];
            rC5_0 *= rA0;
/*
 *          Start pipeline
 */
            rA0 = *pA0;
            rB0 = *pB0;
            m0 = rA0 * rB0;
            rA1 = pA0[12];
            m1 = rA1 * rB0;
            rA2 = pA0[24];
            m2 = rA2 * rB0;
            rA3 = pA0[36];
            m3 = rA3 * rB0;
            rA4 = pA0[48];

/*
 *          Completely unrolled K-loop
 */
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rA5 = pA0[60];
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[13];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[25];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[37];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[49];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[61];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[14];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[26];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[38];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[50];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[62];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[15];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[27];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[39];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[51];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[63];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[16];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[28];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[40];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[52];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[64];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[17];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[29];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[41];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[53];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[65];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[18];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[30];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[42];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[54];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[66];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[19];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[31];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[43];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[55];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[67];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[20];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[32];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[44];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[56];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[68];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[21];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[33];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[45];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[57];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[69];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[22];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[34];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[46];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[58];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[70];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[23];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[35];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[47];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[59];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[71];
/*
 *          Drain pipe on last iteration of K-loop
 */
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rC2_0 += m0;
            rC3_0 += m1;
            rC4_0 += m2;
            rC5_0 += m3;
            pA0 += incAk;
            pB0 += incBk;
            *pC0 = rC0_0;
            pC0[1] = rC1_0;
            pC0[2] = rC2_0;
            pC0[3] = rC3_0;
            pC0[4] = rC4_0;
            pC0[5] = rC5_0;
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
   if (k=M-Mb)
      ATL_sJIK0x0x12TN1x1x12_a1_bX(k, N, 12, alpha, ca + (((Mb) << 3)+((Mb) << 2)), lda, cb, ldb, beta, cc + (Mb), ldc);
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
