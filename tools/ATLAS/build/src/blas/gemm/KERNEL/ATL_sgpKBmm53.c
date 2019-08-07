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
static void ATL_sJIK0x0x53TN1x1x53_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=53, 
 * lda=53, ldb=53, ldc=0, mu=1, nu=1, ku=53, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (53*(Mb));
   const float *stN = B + (53*(Nb));
   #define incAk 53
   const int incAm = 0, incAn = -(53*(Mb));
   #define incBk 53
   const int incBm = -53, incBn = 53;
   const int incAk0 = ((incAk) / 53), incBk0 = ((incBk) / 53);
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
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[29];
         rB0 = pB0[29];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[30];
         rB0 = pB0[30];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[31];
         rB0 = pB0[31];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[32];
         rB0 = pB0[32];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[33];
         rB0 = pB0[33];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[34];
         rB0 = pB0[34];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[35];
         rB0 = pB0[35];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[36];
         rB0 = pB0[36];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[37];
         rB0 = pB0[37];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[38];
         rB0 = pB0[38];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[39];
         rB0 = pB0[39];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[40];
         rB0 = pB0[40];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[41];
         rB0 = pB0[41];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[42];
         rB0 = pB0[42];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[43];
         rB0 = pB0[43];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[44];
         rB0 = pB0[44];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[45];
         rB0 = pB0[45];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[46];
         rB0 = pB0[46];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[47];
         rB0 = pB0[47];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[48];
         rB0 = pB0[48];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[49];
         rB0 = pB0[49];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[50];
         rB0 = pB0[50];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[51];
         rB0 = pB0[51];
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[52];
         rB0 = pB0[52];
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
void ATL_sJIK0x0x53TN53x53x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=53, 
 * lda=53, ldb=53, ldc=0, mu=6, nu=1, ku=53, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const int Mb = (M/6)*6;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (53*(Mb));
   const float *stN = B + (53*(Nb));
   #define incAk 53
   const int incAm = 265, incAn = -(53*(Mb));
   #define incBk 53
   const int incBm = -53, incBn = 53;
   const int incAk0 = ((incAk) / 53), incBk0 = ((incBk) / 53);
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
            rA1 = pA0[53];
            m1 = rA1 * rB0;
            rA2 = pA0[106];
            m2 = rA2 * rB0;
            rA3 = pA0[159];
            m3 = rA3 * rB0;
            rA4 = pA0[212];

/*
 *          Completely unrolled K-loop
 */
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rA5 = pA0[265];
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[54];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[107];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[160];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[213];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[266];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[55];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[108];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[161];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[214];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[267];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[56];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[109];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[162];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[215];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[268];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[57];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[110];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[163];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[216];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[269];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[58];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[111];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[164];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[217];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[270];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[59];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[112];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[165];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[218];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[271];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[60];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[113];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[166];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[219];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[272];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[61];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[114];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[167];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[220];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[273];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[62];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[115];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[168];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[221];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[274];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[63];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[116];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[169];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[222];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[275];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[64];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[117];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[170];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[223];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[276];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[12];
            rB0 = pB0[12];
            rA1 = pA0[65];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[118];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[171];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[224];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[277];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[13];
            rB0 = pB0[13];
            rA1 = pA0[66];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[119];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[172];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[225];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[278];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[14];
            rB0 = pB0[14];
            rA1 = pA0[67];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[120];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[173];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[226];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[279];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[15];
            rB0 = pB0[15];
            rA1 = pA0[68];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[121];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[174];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[227];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[280];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[16];
            rB0 = pB0[16];
            rA1 = pA0[69];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[122];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[175];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[228];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[281];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[17];
            rB0 = pB0[17];
            rA1 = pA0[70];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[123];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[176];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[229];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[282];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[18];
            rB0 = pB0[18];
            rA1 = pA0[71];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[124];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[177];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[230];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[283];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[19];
            rB0 = pB0[19];
            rA1 = pA0[72];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[125];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[178];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[231];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[284];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[20];
            rB0 = pB0[20];
            rA1 = pA0[73];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[126];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[179];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[232];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[285];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[21];
            rB0 = pB0[21];
            rA1 = pA0[74];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[127];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[180];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[233];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[286];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[22];
            rB0 = pB0[22];
            rA1 = pA0[75];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[128];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[181];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[234];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[287];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[23];
            rB0 = pB0[23];
            rA1 = pA0[76];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[129];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[182];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[235];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[288];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[24];
            rB0 = pB0[24];
            rA1 = pA0[77];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[130];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[183];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[236];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[289];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[25];
            rB0 = pB0[25];
            rA1 = pA0[78];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[131];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[184];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[237];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[290];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[26];
            rB0 = pB0[26];
            rA1 = pA0[79];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[132];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[185];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[238];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[291];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[27];
            rB0 = pB0[27];
            rA1 = pA0[80];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[133];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[186];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[239];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[292];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[28];
            rB0 = pB0[28];
            rA1 = pA0[81];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[134];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[187];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[240];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[293];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[29];
            rB0 = pB0[29];
            rA1 = pA0[82];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[135];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[188];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[241];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[294];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[30];
            rB0 = pB0[30];
            rA1 = pA0[83];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[136];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[189];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[242];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[295];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[31];
            rB0 = pB0[31];
            rA1 = pA0[84];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[137];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[190];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[243];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[296];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[32];
            rB0 = pB0[32];
            rA1 = pA0[85];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[138];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[191];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[244];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[297];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[33];
            rB0 = pB0[33];
            rA1 = pA0[86];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[139];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[192];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[245];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[298];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[34];
            rB0 = pB0[34];
            rA1 = pA0[87];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[140];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[193];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[246];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[299];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[35];
            rB0 = pB0[35];
            rA1 = pA0[88];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[141];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[194];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[247];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[300];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[36];
            rB0 = pB0[36];
            rA1 = pA0[89];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[142];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[195];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[248];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[301];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[37];
            rB0 = pB0[37];
            rA1 = pA0[90];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[143];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[196];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[249];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[302];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[38];
            rB0 = pB0[38];
            rA1 = pA0[91];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[144];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[197];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[250];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[303];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[39];
            rB0 = pB0[39];
            rA1 = pA0[92];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[145];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[198];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[251];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[304];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[40];
            rB0 = pB0[40];
            rA1 = pA0[93];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[146];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[199];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[252];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[305];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[41];
            rB0 = pB0[41];
            rA1 = pA0[94];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[147];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[200];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[253];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[306];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[42];
            rB0 = pB0[42];
            rA1 = pA0[95];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[148];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[201];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[254];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[307];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[43];
            rB0 = pB0[43];
            rA1 = pA0[96];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[149];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[202];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[255];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[308];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[44];
            rB0 = pB0[44];
            rA1 = pA0[97];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[150];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[203];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[256];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[309];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[45];
            rB0 = pB0[45];
            rA1 = pA0[98];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[151];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[204];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[257];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[310];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[46];
            rB0 = pB0[46];
            rA1 = pA0[99];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[152];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[205];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[258];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[311];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[47];
            rB0 = pB0[47];
            rA1 = pA0[100];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[153];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[206];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[259];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[312];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[48];
            rB0 = pB0[48];
            rA1 = pA0[101];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[154];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[207];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[260];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[313];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[49];
            rB0 = pB0[49];
            rA1 = pA0[102];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[155];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[208];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[261];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[314];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[50];
            rB0 = pB0[50];
            rA1 = pA0[103];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[156];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[209];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[262];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[315];
            rC0_0 += m0;
            m0 = rA4 * rB0;
            rC1_0 += m1;
            m1 = rA5 * rB0;
            rA0 = pA0[51];
            rB0 = pB0[51];
            rA1 = pA0[104];
            rC2_0 += m2;
            m2 = rA0 * rB0;
            rA2 = pA0[157];
            rC3_0 += m3;
            m3 = rA1 * rB0;
            rA3 = pA0[210];
            rC4_0 += m0;
            m0 = rA2 * rB0;
            rA4 = pA0[263];
            rC5_0 += m1;
            m1 = rA3 * rB0;
            rA5 = pA0[316];
            rC0_0 += m2;
            m2 = rA4 * rB0;
            rC1_0 += m3;
            m3 = rA5 * rB0;
            rA0 = pA0[52];
            rB0 = pB0[52];
            rA1 = pA0[105];
            rC2_0 += m0;
            m0 = rA0 * rB0;
            rA2 = pA0[158];
            rC3_0 += m1;
            m1 = rA1 * rB0;
            rA3 = pA0[211];
            rC4_0 += m2;
            m2 = rA2 * rB0;
            rA4 = pA0[264];
            rC5_0 += m3;
            m3 = rA3 * rB0;
            rA5 = pA0[317];
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
      ATL_sJIK0x0x53TN1x1x53_a1_bX(k, N, 53, alpha, ca + (53*(Mb)), lda, cb, ldb, beta, cc + (Mb), ldc);
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
