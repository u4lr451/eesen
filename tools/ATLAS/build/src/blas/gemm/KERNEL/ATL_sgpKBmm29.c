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
static void ATL_sJIK0x0x29TN1x1x29_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=29, 
 * lda=29, ldb=29, ldc=0, mu=1, nu=1, ku=29, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (29*(Mb));
   const float *stN = B + (29*(Nb));
   #define incAk 29
   const int incAm = 0, incAn = -(29*(Mb));
   #define incBk 29
   const int incBm = -29, incBn = 29;
   const int incAk0 = ((incAk) / 29), incBk0 = ((incBk) / 29);
   #define incCm 1
   const int incCn = (ldc) - (Mb);
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float m0;
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

/*
 *       Completely unrolled K-loop
 */
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[13];
         rB0 = pB0[13];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[15];
         rB0 = pB0[15];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[17];
         rB0 = pB0[17];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[19];
         rB0 = pB0[19];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[21];
         rB0 = pB0[21];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[22];
         rB0 = pB0[22];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[23];
         rB0 = pB0[23];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[24];
         rB0 = pB0[24];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[25];
         rB0 = pB0[25];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[26];
         rB0 = pB0[26];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[27];
         rB0 = pB0[27];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[28];
         rB0 = pB0[28];
/*
 *       Drain pipe on last iteration of K-loop
 */
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rC0_0 += m0;
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
void ATL_sJIK0x0x29TN29x29x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=29, 
 * lda=29, ldb=29, ldc=0, mu=6, nu=1, ku=29, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const int Mb = (M/6)*6;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (29*(Mb));
   const float *stN = B + (29*(Nb));
   #define incAk 29
   const int incAm = 145, incAn = -(29*(Mb));
   #define incBk 29
   const int incBm = -29, incBn = 29;
   const int incAk0 = ((incAk) / 29), incBk0 = ((incBk) / 29);
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
            rA1 = pA0[29];
            m1 = rA1 * rB0;
            rA2 = pA0[58];
            m2 = rA2 * rB0;
            rA3 = pA0[87];
            m3 = rA3 * rB0;
            rA4 = pA0[116];

/*
 *          Completely unrolled K-loop
 */
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rA5 = pA0[145];
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[30];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[59];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[88];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[117];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[146];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[31];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[60];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[89];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[118];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[147];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[32];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[61];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[90];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[119];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[148];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[33];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[62];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[91];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[120];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[149];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[34];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[63];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[92];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[121];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[150];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[35];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[64];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[93];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[122];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[151];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[36];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[65];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[94];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[123];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[152];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[37];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[66];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[95];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[124];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[153];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[38];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[67];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[96];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[125];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[154];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[39];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[68];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[97];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[126];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[155];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[40];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[69];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[98];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[127];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[156];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[12];
            rB0 = pB0[12];
            rA1 = pA0[41];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[70];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[99];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[128];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[157];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[13];
            rB0 = pB0[13];
            rA1 = pA0[42];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[71];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[100];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[129];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[158];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[14];
            rB0 = pB0[14];
            rA1 = pA0[43];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[72];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[101];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[130];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[159];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[15];
            rB0 = pB0[15];
            rA1 = pA0[44];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[73];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[102];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[131];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[160];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[16];
            rB0 = pB0[16];
            rA1 = pA0[45];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[74];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[103];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[132];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[161];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[17];
            rB0 = pB0[17];
            rA1 = pA0[46];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[75];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[104];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[133];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[162];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[18];
            rB0 = pB0[18];
            rA1 = pA0[47];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[76];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[105];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[134];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[163];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[19];
            rB0 = pB0[19];
            rA1 = pA0[48];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[77];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[106];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[135];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[164];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[20];
            rB0 = pB0[20];
            rA1 = pA0[49];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[78];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[107];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[136];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[165];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[21];
            rB0 = pB0[21];
            rA1 = pA0[50];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[79];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[108];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[137];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[166];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[22];
            rB0 = pB0[22];
            rA1 = pA0[51];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[80];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[109];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[138];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[167];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[23];
            rB0 = pB0[23];
            rA1 = pA0[52];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[81];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[110];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[139];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[168];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[24];
            rB0 = pB0[24];
            rA1 = pA0[53];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[82];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[111];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[140];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[169];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[25];
            rB0 = pB0[25];
            rA1 = pA0[54];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[83];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[112];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[141];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[170];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[26];
            rB0 = pB0[26];
            rA1 = pA0[55];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[84];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[113];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[142];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[171];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[27];
            rB0 = pB0[27];
            rA1 = pA0[56];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[85];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[114];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[143];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[172];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[28];
            rB0 = pB0[28];
            rA1 = pA0[57];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[86];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[115];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[144];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[173];
/*
 *          Drain pipe on last iteration of K-loop
 */
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rC2_0 += m2;
            rC3_0 += m3;
            rC4_0 += m0;
            rC5_0 += m1;
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
      ATL_sJIK0x0x29TN1x1x29_a1_bX(k, N, 29, alpha, ca + (29*(Mb)), lda, cb, ldb, beta, cc + (Mb), ldc);
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
