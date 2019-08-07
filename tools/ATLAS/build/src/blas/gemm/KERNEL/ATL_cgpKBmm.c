#ifndef ATL_UCLEANK
   #define ATL_cgpKBmm ATL_cpKBmm
#endif

void ATL_cJIK0x0x65TN65x65x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x66TN66x66x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x67TN67x67x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x68TN68x68x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x69TN69x69x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x70TN70x70x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x71TN71x71x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x72TN72x72x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x73TN73x73x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x74TN74x74x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x75TN75x75x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x76TN76x76x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x77TN77x77x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x78TN78x78x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x79TN79x79x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x80TN80x80x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x0TN0x0x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
typedef void (*MMfunc)(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);

void ATL_cgpKBmm(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   static MMfunc mmfunc[ 16] = {
                         ATL_cJIK0x0x65TN65x65x0_a1_bX,
                         ATL_cJIK0x0x66TN66x66x0_a1_bX,
                         ATL_cJIK0x0x67TN67x67x0_a1_bX,
                         ATL_cJIK0x0x68TN68x68x0_a1_bX,
                         ATL_cJIK0x0x69TN69x69x0_a1_bX,
                         ATL_cJIK0x0x70TN70x70x0_a1_bX,
                         ATL_cJIK0x0x71TN71x71x0_a1_bX,
                         ATL_cJIK0x0x72TN72x72x0_a1_bX,
                         ATL_cJIK0x0x73TN73x73x0_a1_bX,
                         ATL_cJIK0x0x74TN74x74x0_a1_bX,
                         ATL_cJIK0x0x75TN75x75x0_a1_bX,
                         ATL_cJIK0x0x76TN76x76x0_a1_bX,
                         ATL_cJIK0x0x77TN77x77x0_a1_bX,
                         ATL_cJIK0x0x78TN78x78x0_a1_bX,
                         ATL_cJIK0x0x79TN79x79x0_a1_bX,
                         ATL_cJIK0x0x80TN80x80x0_a1_bX,
                        };
   MMfunc mm;

   if (K <= 64)
   {
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
   }
   else
   {
      mm = mmfunc[K-65];
      mm(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
      mm(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
      mm(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
      mm(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
   }
}
#ifndef ATL_UCLEANK
void ATL_cpKBmm_b0(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_cpKBmm_b1(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_cpKBmm_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
#endif
