#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
void ATL_sJIK60x60x60TN0x0x0_a1_b0
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=60, NB=60, KB=60, 
 * lda=0, ldb=0, ldc=0, mu=6, nu=1, ku=60, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.0)
 */
{
   const float *stM = A + (60*(lda));
   const float *stN = B + (60*(ldb));
   #define incAk 60
   const int incAm = ((((lda) << 2)+((lda) << 1)) - 60), incAn = -(60*(lda));
   #define incBk 60
   const int incBm = -60, incBn = (ldb);
   const int incAk0 = ((incAk) / 60), incBk0 = ((incBk) / 60);
   #define incCm 6
   const int incCn = (ldc) - 60;
   float *pC0=C;
   const float *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda), *pA3=pA2+(lda), *pA4=pA3+(lda), *pA5=pA4+(lda);
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2, rA3, rA4, rA5;
   register float rB0;
   register float m0, m1, m2, m3;
   register float rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
/*
 *       Start pipeline
 */
         rA0 = *pA0;
         rB0 = *pB0;
         m0 = rA0 * rB0;
         rA1 = *pA1;
         m1 = rA1 * rB0;
         rA2 = *pA2;
         m2 = rA2 * rB0;
         rA3 = *pA3;
         m3 = rA3 * rB0;
         rA4 = *pA4;

/*
 *       Completely unrolled K-loop
 */
         rC0_0 = m0;
         m0 = rA4 * rB0;
         rA5 = *pA5;
         rC1_0 = m1;
         m1 = rA5 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         rA1 = pA1[1];
         rC2_0 = m2;
         m2 = rA0 * rB0;
         rA2 = pA2[1];
         rC3_0 = m3;
         m3 = rA1 * rB0;
         rA3 = pA3[1];
         rC4_0 = m0;
         m0 = rA2 * rB0;
         rA4 = pA4[1];
         rC5_0 = m1;
         m1 = rA3 * rB0;
         rA5 = pA5[1];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rA1 = pA1[2];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[2];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[2];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[2];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[2];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rA1 = pA1[3];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[3];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[3];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[3];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[3];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rA1 = pA1[4];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[4];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[4];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[4];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[4];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rA1 = pA1[5];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[5];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[5];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[5];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[5];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rA1 = pA1[6];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[6];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[6];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[6];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[6];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rA1 = pA1[7];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[7];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[7];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[7];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[7];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rA1 = pA1[8];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[8];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[8];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[8];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[8];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rA1 = pA1[9];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[9];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[9];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[9];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[9];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rA1 = pA1[10];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[10];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[10];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[10];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[10];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
         rA1 = pA1[11];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[11];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[11];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[11];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[11];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rA1 = pA1[12];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[12];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[12];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[12];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[12];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[13];
         rB0 = pB0[13];
         rA1 = pA1[13];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[13];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[13];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[13];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[13];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rA1 = pA1[14];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[14];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[14];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[14];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[14];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[15];
         rB0 = pB0[15];
         rA1 = pA1[15];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[15];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[15];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[15];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[15];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rA1 = pA1[16];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[16];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[16];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[16];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[16];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[17];
         rB0 = pB0[17];
         rA1 = pA1[17];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[17];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[17];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[17];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[17];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rA1 = pA1[18];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[18];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[18];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[18];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[18];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[19];
         rB0 = pB0[19];
         rA1 = pA1[19];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[19];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[19];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[19];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[19];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rA1 = pA1[20];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[20];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[20];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[20];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[20];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[21];
         rB0 = pB0[21];
         rA1 = pA1[21];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[21];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[21];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[21];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[21];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[22];
         rB0 = pB0[22];
         rA1 = pA1[22];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[22];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[22];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[22];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[22];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[23];
         rB0 = pB0[23];
         rA1 = pA1[23];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[23];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[23];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[23];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[23];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[24];
         rB0 = pB0[24];
         rA1 = pA1[24];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[24];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[24];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[24];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[24];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[25];
         rB0 = pB0[25];
         rA1 = pA1[25];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[25];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[25];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[25];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[25];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[26];
         rB0 = pB0[26];
         rA1 = pA1[26];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[26];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[26];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[26];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[26];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[27];
         rB0 = pB0[27];
         rA1 = pA1[27];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[27];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[27];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[27];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[27];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[28];
         rB0 = pB0[28];
         rA1 = pA1[28];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[28];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[28];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[28];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[28];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[29];
         rB0 = pB0[29];
         rA1 = pA1[29];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[29];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[29];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[29];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[29];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[30];
         rB0 = pB0[30];
         rA1 = pA1[30];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[30];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[30];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[30];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[30];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[31];
         rB0 = pB0[31];
         rA1 = pA1[31];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[31];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[31];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[31];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[31];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[32];
         rB0 = pB0[32];
         rA1 = pA1[32];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[32];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[32];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[32];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[32];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[33];
         rB0 = pB0[33];
         rA1 = pA1[33];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[33];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[33];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[33];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[33];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[34];
         rB0 = pB0[34];
         rA1 = pA1[34];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[34];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[34];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[34];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[34];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[35];
         rB0 = pB0[35];
         rA1 = pA1[35];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[35];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[35];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[35];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[35];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[36];
         rB0 = pB0[36];
         rA1 = pA1[36];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[36];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[36];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[36];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[36];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[37];
         rB0 = pB0[37];
         rA1 = pA1[37];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[37];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[37];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[37];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[37];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[38];
         rB0 = pB0[38];
         rA1 = pA1[38];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[38];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[38];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[38];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[38];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[39];
         rB0 = pB0[39];
         rA1 = pA1[39];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[39];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[39];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[39];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[39];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[40];
         rB0 = pB0[40];
         rA1 = pA1[40];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[40];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[40];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[40];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[40];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[41];
         rB0 = pB0[41];
         rA1 = pA1[41];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[41];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[41];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[41];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[41];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[42];
         rB0 = pB0[42];
         rA1 = pA1[42];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[42];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[42];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[42];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[42];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[43];
         rB0 = pB0[43];
         rA1 = pA1[43];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[43];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[43];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[43];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[43];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[44];
         rB0 = pB0[44];
         rA1 = pA1[44];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[44];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[44];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[44];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[44];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[45];
         rB0 = pB0[45];
         rA1 = pA1[45];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[45];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[45];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[45];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[45];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[46];
         rB0 = pB0[46];
         rA1 = pA1[46];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[46];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[46];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[46];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[46];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[47];
         rB0 = pB0[47];
         rA1 = pA1[47];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[47];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[47];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[47];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[47];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[48];
         rB0 = pB0[48];
         rA1 = pA1[48];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[48];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[48];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[48];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[48];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[49];
         rB0 = pB0[49];
         rA1 = pA1[49];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[49];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[49];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[49];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[49];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[50];
         rB0 = pB0[50];
         rA1 = pA1[50];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[50];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[50];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[50];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[50];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[51];
         rB0 = pB0[51];
         rA1 = pA1[51];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[51];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[51];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[51];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[51];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[52];
         rB0 = pB0[52];
         rA1 = pA1[52];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[52];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[52];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[52];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[52];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[53];
         rB0 = pB0[53];
         rA1 = pA1[53];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[53];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[53];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[53];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[53];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[54];
         rB0 = pB0[54];
         rA1 = pA1[54];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[54];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[54];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[54];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[54];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[55];
         rB0 = pB0[55];
         rA1 = pA1[55];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[55];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[55];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[55];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[55];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[56];
         rB0 = pB0[56];
         rA1 = pA1[56];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[56];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[56];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[56];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[56];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[57];
         rB0 = pB0[57];
         rA1 = pA1[57];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[57];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[57];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[57];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[57];
         rC0_0 += m2;
         m2 = rA4 * rB0;
         rC1_0 += m3;
         m3 = rA5 * rB0;
         rA0 = pA0[58];
         rB0 = pB0[58];
         rA1 = pA1[58];
         rC2_0 += m0;
         m0 = rA0 * rB0;
         rA2 = pA2[58];
         rC3_0 += m1;
         m1 = rA1 * rB0;
         rA3 = pA3[58];
         rC4_0 += m2;
         m2 = rA2 * rB0;
         rA4 = pA4[58];
         rC5_0 += m3;
         m3 = rA3 * rB0;
         rA5 = pA5[58];
         rC0_0 += m0;
         m0 = rA4 * rB0;
         rC1_0 += m1;
         m1 = rA5 * rB0;
         rA0 = pA0[59];
         rB0 = pB0[59];
         rA1 = pA1[59];
         rC2_0 += m2;
         m2 = rA0 * rB0;
         rA2 = pA2[59];
         rC3_0 += m3;
         m3 = rA1 * rB0;
         rA3 = pA3[59];
         rC4_0 += m0;
         m0 = rA2 * rB0;
         rA4 = pA4[59];
         rC5_0 += m1;
         m1 = rA3 * rB0;
         rA5 = pA5[59];
/*
 *       Drain pipe on last iteration of K-loop
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
         pA1 += incAk;
         pA2 += incAk;
         pA3 += incAk;
         pA4 += incAk;
         pA5 += incAk;
         pB0 += incBk;
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
         pC0[2] = rC2_0;
         pC0[3] = rC3_0;
         pC0[4] = rC4_0;
         pC0[5] = rC5_0;
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
