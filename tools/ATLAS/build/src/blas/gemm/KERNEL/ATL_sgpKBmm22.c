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
static void ATL_sJIK0x0x22TN1x1x22_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=22, 
 * lda=22, ldb=22, ldc=0, mu=1, nu=1, ku=22, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (22*(Mb));
   const float *stN = B + (22*(Nb));
   #define incAk 22
   const int incAm = 0, incAn = -(22*(Mb));
   #define incBk 22
   const int incBm = -22, incBn = 22;
   const int incAk0 = ((incAk) / 22), incBk0 = ((incBk) / 22);
   #define incCm 1
   const int incCn = (ldc) - (Mb);
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float m0, m1;
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

/*
 *       Completely unrolled K-loop
 */
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += m1;
         m1 = rA0 * rB0;
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
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[13];
         rB0 = pB0[13];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[15];
         rB0 = pB0[15];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[17];
         rB0 = pB0[17];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[19];
         rB0 = pB0[19];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[21];
         rB0 = pB0[21];
/*
 *       Drain pipe on last iteration of K-loop
 */
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rC0_0 += m0;
         rC0_0 += m1;
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
void ATL_sJIK0x0x22TN22x22x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=22, 
 * lda=22, ldb=22, ldc=0, mu=6, nu=1, ku=22, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const int Mb = (M/6)*6;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (22*(Mb));
   const float *stN = B + (22*(Nb));
   #define incAk 22
   const int incAm = 110, incAn = -(22*(Mb));
   #define incBk 22
   const int incBm = -22, incBn = 22;
   const int incAk0 = ((incAk) / 22), incBk0 = ((incBk) / 22);
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
            rA1 = pA0[22];
            m1 = rA1 * rB0;
            rA2 = pA0[44];
            m2 = rA2 * rB0;
            rA3 = pA0[66];
            m3 = rA3 * rB0;
            rA4 = pA0[88];

/*
 *          Completely unrolled K-loop
 */
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rA5 = pA0[110];
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[23];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[45];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[67];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[89];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[111];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[24];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[46];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[68];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[90];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[112];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[25];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[47];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[69];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[91];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[113];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[26];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[48];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[70];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[92];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[114];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[27];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[49];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[71];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[93];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[115];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[28];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[50];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[72];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[94];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[116];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[29];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[51];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[73];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[95];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[117];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[30];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[52];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[74];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[96];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[118];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[31];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[53];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[75];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[97];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[119];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[32];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[54];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[76];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[98];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[120];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[33];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[55];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[77];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[99];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[121];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[12];
            rB0 = pB0[12];
            rA1 = pA0[34];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[56];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[78];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[100];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[122];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[13];
            rB0 = pB0[13];
            rA1 = pA0[35];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[57];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[79];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[101];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[123];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[14];
            rB0 = pB0[14];
            rA1 = pA0[36];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[58];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[80];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[102];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[124];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[15];
            rB0 = pB0[15];
            rA1 = pA0[37];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[59];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[81];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[103];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[125];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[16];
            rB0 = pB0[16];
            rA1 = pA0[38];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[60];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[82];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[104];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[126];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[17];
            rB0 = pB0[17];
            rA1 = pA0[39];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[61];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[83];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[105];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[127];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[18];
            rB0 = pB0[18];
            rA1 = pA0[40];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[62];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[84];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[106];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[128];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[19];
            rB0 = pB0[19];
            rA1 = pA0[41];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[63];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[85];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[107];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[129];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[20];
            rB0 = pB0[20];
            rA1 = pA0[42];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[64];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[86];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[108];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[130];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[21];
            rB0 = pB0[21];
            rA1 = pA0[43];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[65];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[87];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[109];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[131];
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
      ATL_sJIK0x0x22TN1x1x22_a1_bX(k, N, 22, alpha, ca + (22*(Mb)), lda, cb, ldb, beta, cc + (Mb), ldc);
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
