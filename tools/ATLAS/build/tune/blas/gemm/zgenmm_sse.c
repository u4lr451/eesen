#ifdef BETA0
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 4
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   __m128d temp0;  
   __m128d temp1;  
   __builtin_prefetch( B, PF_READONLY, PF_DEF );
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchACols =  (void*)(A + 36*KB); 
   register void const *prefetchB =  (void*)(B + 36*ldb);
   __builtin_prefetch( prefetchACols, PF_READONLY, PF_DEF );
   __builtin_prefetch( prefetchB, PF_READONLY, PF_DEF );
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-36; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-36+I_UNROLL; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 36) );
         A2 = _mm_load_pd( MMCAST(A0_off + 72) );
         A3 = _mm_load_pd( MMCAST(A0_off + 108) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         
         /* K_Unrolling: 2 */
         A0 = _mm_load_pd( MMCAST(A0_off + 2) );
         A1 = _mm_load_pd( MMCAST(A0_off + 38) );
         A2 = _mm_load_pd( MMCAST(A0_off + 74) );
         A3 = _mm_load_pd( MMCAST(A0_off + 110) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 2) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_pd( MMCAST(A0_off + 4) );
         A1 = _mm_load_pd( MMCAST(A0_off + 40) );
         A2 = _mm_load_pd( MMCAST(A0_off + 76) );
         A3 = _mm_load_pd( MMCAST(A0_off + 112) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 4) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 6 */
         A0 = _mm_load_pd( MMCAST(A0_off + 6) );
         A1 = _mm_load_pd( MMCAST(A0_off + 42) );
         A2 = _mm_load_pd( MMCAST(A0_off + 78) );
         A3 = _mm_load_pd( MMCAST(A0_off + 114) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 6) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 8 */
         A0 = _mm_load_pd( MMCAST(A0_off + 8) );
         A1 = _mm_load_pd( MMCAST(A0_off + 44) );
         A2 = _mm_load_pd( MMCAST(A0_off + 80) );
         A3 = _mm_load_pd( MMCAST(A0_off + 116) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 8) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 10 */
         A0 = _mm_load_pd( MMCAST(A0_off + 10) );
         A1 = _mm_load_pd( MMCAST(A0_off + 46) );
         A2 = _mm_load_pd( MMCAST(A0_off + 82) );
         A3 = _mm_load_pd( MMCAST(A0_off + 118) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 10) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 12 */
         A0 = _mm_load_pd( MMCAST(A0_off + 12) );
         A1 = _mm_load_pd( MMCAST(A0_off + 48) );
         A2 = _mm_load_pd( MMCAST(A0_off + 84) );
         A3 = _mm_load_pd( MMCAST(A0_off + 120) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 12) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 14 */
         A0 = _mm_load_pd( MMCAST(A0_off + 14) );
         A1 = _mm_load_pd( MMCAST(A0_off + 50) );
         A2 = _mm_load_pd( MMCAST(A0_off + 86) );
         A3 = _mm_load_pd( MMCAST(A0_off + 122) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 14) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 16 */
         A0 = _mm_load_pd( MMCAST(A0_off + 16) );
         A1 = _mm_load_pd( MMCAST(A0_off + 52) );
         A2 = _mm_load_pd( MMCAST(A0_off + 88) );
         A3 = _mm_load_pd( MMCAST(A0_off + 124) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 16) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 18 */
         A0 = _mm_load_pd( MMCAST(A0_off + 18) );
         A1 = _mm_load_pd( MMCAST(A0_off + 54) );
         A2 = _mm_load_pd( MMCAST(A0_off + 90) );
         A3 = _mm_load_pd( MMCAST(A0_off + 126) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 18) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 20 */
         A0 = _mm_load_pd( MMCAST(A0_off + 20) );
         A1 = _mm_load_pd( MMCAST(A0_off + 56) );
         A2 = _mm_load_pd( MMCAST(A0_off + 92) );
         A3 = _mm_load_pd( MMCAST(A0_off + 128) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 20) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 22 */
         A0 = _mm_load_pd( MMCAST(A0_off + 22) );
         A1 = _mm_load_pd( MMCAST(A0_off + 58) );
         A2 = _mm_load_pd( MMCAST(A0_off + 94) );
         A3 = _mm_load_pd( MMCAST(A0_off + 130) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 22) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 24 */
         A0 = _mm_load_pd( MMCAST(A0_off + 24) );
         A1 = _mm_load_pd( MMCAST(A0_off + 60) );
         A2 = _mm_load_pd( MMCAST(A0_off + 96) );
         A3 = _mm_load_pd( MMCAST(A0_off + 132) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 24) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 26 */
         A0 = _mm_load_pd( MMCAST(A0_off + 26) );
         A1 = _mm_load_pd( MMCAST(A0_off + 62) );
         A2 = _mm_load_pd( MMCAST(A0_off + 98) );
         A3 = _mm_load_pd( MMCAST(A0_off + 134) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 26) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 28 */
         A0 = _mm_load_pd( MMCAST(A0_off + 28) );
         A1 = _mm_load_pd( MMCAST(A0_off + 64) );
         A2 = _mm_load_pd( MMCAST(A0_off + 100) );
         A3 = _mm_load_pd( MMCAST(A0_off + 136) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 28) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 30 */
         A0 = _mm_load_pd( MMCAST(A0_off + 30) );
         A1 = _mm_load_pd( MMCAST(A0_off + 66) );
         A2 = _mm_load_pd( MMCAST(A0_off + 102) );
         A3 = _mm_load_pd( MMCAST(A0_off + 138) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 30) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 32 */
         A0 = _mm_load_pd( MMCAST(A0_off + 32) );
         A1 = _mm_load_pd( MMCAST(A0_off + 68) );
         A2 = _mm_load_pd( MMCAST(A0_off + 104) );
         A3 = _mm_load_pd( MMCAST(A0_off + 140) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 32) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 34 */
         A0 = _mm_load_pd( MMCAST(A0_off + 34) );
         A1 = _mm_load_pd( MMCAST(A0_off + 70) );
         A2 = _mm_load_pd( MMCAST(A0_off + 106) );
         A3 = _mm_load_pd( MMCAST(A0_off + 142) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 34) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
         /* Combine scalar expansion back to scalar */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* Applying Beta */
         /* No beta will be appied */
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_sd( cPtrI0+0, c0_0 );
         temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+2, temp );

         _mm_store_sd( cPtrI0+4, c0_2 );
         temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+6, temp );

         cPtrI0 += 2*I_UNROLL;
         

         prefetchACols += 4*KB;
      } /* End i/MB loop */

      /* K_Unrolling0 */
      A0 = _mm_load_pd( MMCAST(A0_off) );
      A1 = _mm_load_pd( MMCAST(A0_off + 36) );
      A2 = _mm_load_pd( MMCAST(A0_off + 72) );
      A3 = _mm_load_pd( MMCAST(A0_off + 108) );
      B0 = _mm_load_pd( MMCAST(B0_off) );
      c0_0 = B0;
      c0_0 = _mm_mul_pd( A0, c0_0 );
      c0_1 = B0;
      c0_1 = _mm_mul_pd( A1, c0_1 );
      c0_2 = B0;
      c0_2 = _mm_mul_pd( A2, c0_2 );
      c0_3 = B0;
      c0_3 = _mm_mul_pd( A3, c0_3 );
      
      /* K_Unrolling: 2 */
      A0 = _mm_load_pd( MMCAST(A0_off + 2) );
      A1 = _mm_load_pd( MMCAST(A0_off + 38) );
      A2 = _mm_load_pd( MMCAST(A0_off + 74) );
      A3 = _mm_load_pd( MMCAST(A0_off + 110) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 2) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 0,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 4 */
      A0 = _mm_load_pd( MMCAST(A0_off + 4) );
      A1 = _mm_load_pd( MMCAST(A0_off + 40) );
      A2 = _mm_load_pd( MMCAST(A0_off + 76) );
      A3 = _mm_load_pd( MMCAST(A0_off + 112) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 4) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 57,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 6 */
      A0 = _mm_load_pd( MMCAST(A0_off + 6) );
      A1 = _mm_load_pd( MMCAST(A0_off + 42) );
      A2 = _mm_load_pd( MMCAST(A0_off + 78) );
      A3 = _mm_load_pd( MMCAST(A0_off + 114) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 6) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 114,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 8 */
      A0 = _mm_load_pd( MMCAST(A0_off + 8) );
      A1 = _mm_load_pd( MMCAST(A0_off + 44) );
      A2 = _mm_load_pd( MMCAST(A0_off + 80) );
      A3 = _mm_load_pd( MMCAST(A0_off + 116) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 8) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 171,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 10 */
      A0 = _mm_load_pd( MMCAST(A0_off + 10) );
      A1 = _mm_load_pd( MMCAST(A0_off + 46) );
      A2 = _mm_load_pd( MMCAST(A0_off + 82) );
      A3 = _mm_load_pd( MMCAST(A0_off + 118) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 10) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 228,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 12 */
      A0 = _mm_load_pd( MMCAST(A0_off + 12) );
      A1 = _mm_load_pd( MMCAST(A0_off + 48) );
      A2 = _mm_load_pd( MMCAST(A0_off + 84) );
      A3 = _mm_load_pd( MMCAST(A0_off + 120) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 12) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 14 */
      A0 = _mm_load_pd( MMCAST(A0_off + 14) );
      A1 = _mm_load_pd( MMCAST(A0_off + 50) );
      A2 = _mm_load_pd( MMCAST(A0_off + 86) );
      A3 = _mm_load_pd( MMCAST(A0_off + 122) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 14) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 16 */
      A0 = _mm_load_pd( MMCAST(A0_off + 16) );
      A1 = _mm_load_pd( MMCAST(A0_off + 52) );
      A2 = _mm_load_pd( MMCAST(A0_off + 88) );
      A3 = _mm_load_pd( MMCAST(A0_off + 124) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 16) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 18 */
      A0 = _mm_load_pd( MMCAST(A0_off + 18) );
      A1 = _mm_load_pd( MMCAST(A0_off + 54) );
      A2 = _mm_load_pd( MMCAST(A0_off + 90) );
      A3 = _mm_load_pd( MMCAST(A0_off + 126) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 18) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 20 */
      A0 = _mm_load_pd( MMCAST(A0_off + 20) );
      A1 = _mm_load_pd( MMCAST(A0_off + 56) );
      A2 = _mm_load_pd( MMCAST(A0_off + 92) );
      A3 = _mm_load_pd( MMCAST(A0_off + 128) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 20) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 22 */
      A0 = _mm_load_pd( MMCAST(A0_off + 22) );
      A1 = _mm_load_pd( MMCAST(A0_off + 58) );
      A2 = _mm_load_pd( MMCAST(A0_off + 94) );
      A3 = _mm_load_pd( MMCAST(A0_off + 130) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 22) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 24 */
      A0 = _mm_load_pd( MMCAST(A0_off + 24) );
      A1 = _mm_load_pd( MMCAST(A0_off + 60) );
      A2 = _mm_load_pd( MMCAST(A0_off + 96) );
      A3 = _mm_load_pd( MMCAST(A0_off + 132) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 24) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 26 */
      A0 = _mm_load_pd( MMCAST(A0_off + 26) );
      A1 = _mm_load_pd( MMCAST(A0_off + 62) );
      A2 = _mm_load_pd( MMCAST(A0_off + 98) );
      A3 = _mm_load_pd( MMCAST(A0_off + 134) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 26) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 28 */
      A0 = _mm_load_pd( MMCAST(A0_off + 28) );
      A1 = _mm_load_pd( MMCAST(A0_off + 64) );
      A2 = _mm_load_pd( MMCAST(A0_off + 100) );
      A3 = _mm_load_pd( MMCAST(A0_off + 136) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 28) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 30 */
      A0 = _mm_load_pd( MMCAST(A0_off + 30) );
      A1 = _mm_load_pd( MMCAST(A0_off + 66) );
      A2 = _mm_load_pd( MMCAST(A0_off + 102) );
      A3 = _mm_load_pd( MMCAST(A0_off + 138) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 30) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 32 */
      A0 = _mm_load_pd( MMCAST(A0_off + 32) );
      A1 = _mm_load_pd( MMCAST(A0_off + 68) );
      A2 = _mm_load_pd( MMCAST(A0_off + 104) );
      A3 = _mm_load_pd( MMCAST(A0_off + 140) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 32) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 34 */
      A0 = _mm_load_pd( MMCAST(A0_off + 34) );
      A1 = _mm_load_pd( MMCAST(A0_off + 70) );
      A2 = _mm_load_pd( MMCAST(A0_off + 106) );
      A3 = _mm_load_pd( MMCAST(A0_off + 142) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 34) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
      prefetchB += J_UNROLL*KB*8;
      /* Combine scalar expansion back to scalar */
      c0_0 = _mm_hadd_pd( c0_0, c0_1 );
      c0_2 = _mm_hadd_pd( c0_2, c0_3 );
      /* Applying Beta */
      /* No beta will be appied */
      /* Move pointers to next iteration */  
      A0_off += unroll_a;
      
      /* Store results back to memory  */
      _mm_store_sd( cPtrI0+0, c0_0 );
      temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+2, temp );

      _mm_store_sd( cPtrI0+4, c0_2 );
      temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+6, temp );

      cPtrI0 += 2*I_UNROLL;
      

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#elif defined(BETAX)
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 4
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3;
   /* Vector register to hold C*beta */
   __m128d bc0_0, bc0_2, bc0_3;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   __m128d temp0;  
   __m128d temp1;  
   __builtin_prefetch( B, PF_READONLY, PF_DEF );
   const __m128d betaV = _mm_set1_pd( beta ); 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchACols =  (void*)(A + 36*KB); 
   register void const *prefetchB =  (void*)(B + 36*ldb);
   __builtin_prefetch( prefetchACols, PF_READONLY, PF_DEF );
   __builtin_prefetch( prefetchB, PF_READONLY, PF_DEF );
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-36; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-36+I_UNROLL; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 36) );
         A2 = _mm_load_pd( MMCAST(A0_off + 72) );
         A3 = _mm_load_pd( MMCAST(A0_off + 108) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         
         /* K_Unrolling: 2 */
         A0 = _mm_load_pd( MMCAST(A0_off + 2) );
         A1 = _mm_load_pd( MMCAST(A0_off + 38) );
         A2 = _mm_load_pd( MMCAST(A0_off + 74) );
         A3 = _mm_load_pd( MMCAST(A0_off + 110) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 2) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_pd( MMCAST(A0_off + 4) );
         A1 = _mm_load_pd( MMCAST(A0_off + 40) );
         A2 = _mm_load_pd( MMCAST(A0_off + 76) );
         A3 = _mm_load_pd( MMCAST(A0_off + 112) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 4) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 6 */
         A0 = _mm_load_pd( MMCAST(A0_off + 6) );
         A1 = _mm_load_pd( MMCAST(A0_off + 42) );
         A2 = _mm_load_pd( MMCAST(A0_off + 78) );
         A3 = _mm_load_pd( MMCAST(A0_off + 114) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 6) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 8 */
         A0 = _mm_load_pd( MMCAST(A0_off + 8) );
         A1 = _mm_load_pd( MMCAST(A0_off + 44) );
         A2 = _mm_load_pd( MMCAST(A0_off + 80) );
         A3 = _mm_load_pd( MMCAST(A0_off + 116) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 8) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 10 */
         A0 = _mm_load_pd( MMCAST(A0_off + 10) );
         A1 = _mm_load_pd( MMCAST(A0_off + 46) );
         A2 = _mm_load_pd( MMCAST(A0_off + 82) );
         A3 = _mm_load_pd( MMCAST(A0_off + 118) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 10) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 12 */
         A0 = _mm_load_pd( MMCAST(A0_off + 12) );
         A1 = _mm_load_pd( MMCAST(A0_off + 48) );
         A2 = _mm_load_pd( MMCAST(A0_off + 84) );
         A3 = _mm_load_pd( MMCAST(A0_off + 120) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 12) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 14 */
         A0 = _mm_load_pd( MMCAST(A0_off + 14) );
         A1 = _mm_load_pd( MMCAST(A0_off + 50) );
         A2 = _mm_load_pd( MMCAST(A0_off + 86) );
         A3 = _mm_load_pd( MMCAST(A0_off + 122) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 14) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 16 */
         A0 = _mm_load_pd( MMCAST(A0_off + 16) );
         A1 = _mm_load_pd( MMCAST(A0_off + 52) );
         A2 = _mm_load_pd( MMCAST(A0_off + 88) );
         A3 = _mm_load_pd( MMCAST(A0_off + 124) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 16) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 18 */
         A0 = _mm_load_pd( MMCAST(A0_off + 18) );
         A1 = _mm_load_pd( MMCAST(A0_off + 54) );
         A2 = _mm_load_pd( MMCAST(A0_off + 90) );
         A3 = _mm_load_pd( MMCAST(A0_off + 126) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 18) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 20 */
         A0 = _mm_load_pd( MMCAST(A0_off + 20) );
         A1 = _mm_load_pd( MMCAST(A0_off + 56) );
         A2 = _mm_load_pd( MMCAST(A0_off + 92) );
         A3 = _mm_load_pd( MMCAST(A0_off + 128) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 20) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 22 */
         A0 = _mm_load_pd( MMCAST(A0_off + 22) );
         A1 = _mm_load_pd( MMCAST(A0_off + 58) );
         A2 = _mm_load_pd( MMCAST(A0_off + 94) );
         A3 = _mm_load_pd( MMCAST(A0_off + 130) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 22) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 24 */
         A0 = _mm_load_pd( MMCAST(A0_off + 24) );
         A1 = _mm_load_pd( MMCAST(A0_off + 60) );
         A2 = _mm_load_pd( MMCAST(A0_off + 96) );
         A3 = _mm_load_pd( MMCAST(A0_off + 132) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 24) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 26 */
         A0 = _mm_load_pd( MMCAST(A0_off + 26) );
         A1 = _mm_load_pd( MMCAST(A0_off + 62) );
         A2 = _mm_load_pd( MMCAST(A0_off + 98) );
         A3 = _mm_load_pd( MMCAST(A0_off + 134) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 26) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 28 */
         A0 = _mm_load_pd( MMCAST(A0_off + 28) );
         A1 = _mm_load_pd( MMCAST(A0_off + 64) );
         A2 = _mm_load_pd( MMCAST(A0_off + 100) );
         A3 = _mm_load_pd( MMCAST(A0_off + 136) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 28) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 30 */
         A0 = _mm_load_pd( MMCAST(A0_off + 30) );
         A1 = _mm_load_pd( MMCAST(A0_off + 66) );
         A2 = _mm_load_pd( MMCAST(A0_off + 102) );
         A3 = _mm_load_pd( MMCAST(A0_off + 138) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 30) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 32 */
         A0 = _mm_load_pd( MMCAST(A0_off + 32) );
         A1 = _mm_load_pd( MMCAST(A0_off + 68) );
         A2 = _mm_load_pd( MMCAST(A0_off + 104) );
         A3 = _mm_load_pd( MMCAST(A0_off + 140) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 32) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 34 */
         A0 = _mm_load_pd( MMCAST(A0_off + 34) );
         A1 = _mm_load_pd( MMCAST(A0_off + 70) );
         A2 = _mm_load_pd( MMCAST(A0_off + 106) );
         A3 = _mm_load_pd( MMCAST(A0_off + 142) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 34) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
         /* Combine scalar expansion back to scalar */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            temp0 = _mm_load_sd( cPtrI0 + 0 );
            temp1 = _mm_load_sd( cPtrI0 + 2 );
            bc0_0 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
            bc0_0 = _mm_mul_pd( betaV, bc0_0 );
            temp0 = _mm_load_sd( cPtrI0 + 4 );
            temp1 = _mm_load_sd( cPtrI0 + 6 );
            bc0_2 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
            bc0_2 = _mm_mul_pd( betaV, bc0_2 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_pd( bc0_0, c0_0 );
            c0_2 = _mm_add_pd( bc0_2, c0_2 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_sd( cPtrI0+0, c0_0 );
         temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+2, temp );

         _mm_store_sd( cPtrI0+4, c0_2 );
         temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+6, temp );

         cPtrI0 += 2*I_UNROLL;
         

         prefetchACols += 4*KB;
      } /* End i/MB loop */

      /* K_Unrolling0 */
      A0 = _mm_load_pd( MMCAST(A0_off) );
      A1 = _mm_load_pd( MMCAST(A0_off + 36) );
      A2 = _mm_load_pd( MMCAST(A0_off + 72) );
      A3 = _mm_load_pd( MMCAST(A0_off + 108) );
      B0 = _mm_load_pd( MMCAST(B0_off) );
      c0_0 = B0;
      c0_0 = _mm_mul_pd( A0, c0_0 );
      c0_1 = B0;
      c0_1 = _mm_mul_pd( A1, c0_1 );
      c0_2 = B0;
      c0_2 = _mm_mul_pd( A2, c0_2 );
      c0_3 = B0;
      c0_3 = _mm_mul_pd( A3, c0_3 );
      
      /* K_Unrolling: 2 */
      A0 = _mm_load_pd( MMCAST(A0_off + 2) );
      A1 = _mm_load_pd( MMCAST(A0_off + 38) );
      A2 = _mm_load_pd( MMCAST(A0_off + 74) );
      A3 = _mm_load_pd( MMCAST(A0_off + 110) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 2) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 0,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 4 */
      A0 = _mm_load_pd( MMCAST(A0_off + 4) );
      A1 = _mm_load_pd( MMCAST(A0_off + 40) );
      A2 = _mm_load_pd( MMCAST(A0_off + 76) );
      A3 = _mm_load_pd( MMCAST(A0_off + 112) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 4) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 57,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 6 */
      A0 = _mm_load_pd( MMCAST(A0_off + 6) );
      A1 = _mm_load_pd( MMCAST(A0_off + 42) );
      A2 = _mm_load_pd( MMCAST(A0_off + 78) );
      A3 = _mm_load_pd( MMCAST(A0_off + 114) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 6) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 114,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 8 */
      A0 = _mm_load_pd( MMCAST(A0_off + 8) );
      A1 = _mm_load_pd( MMCAST(A0_off + 44) );
      A2 = _mm_load_pd( MMCAST(A0_off + 80) );
      A3 = _mm_load_pd( MMCAST(A0_off + 116) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 8) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 171,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 10 */
      A0 = _mm_load_pd( MMCAST(A0_off + 10) );
      A1 = _mm_load_pd( MMCAST(A0_off + 46) );
      A2 = _mm_load_pd( MMCAST(A0_off + 82) );
      A3 = _mm_load_pd( MMCAST(A0_off + 118) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 10) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 228,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 12 */
      A0 = _mm_load_pd( MMCAST(A0_off + 12) );
      A1 = _mm_load_pd( MMCAST(A0_off + 48) );
      A2 = _mm_load_pd( MMCAST(A0_off + 84) );
      A3 = _mm_load_pd( MMCAST(A0_off + 120) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 12) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 14 */
      A0 = _mm_load_pd( MMCAST(A0_off + 14) );
      A1 = _mm_load_pd( MMCAST(A0_off + 50) );
      A2 = _mm_load_pd( MMCAST(A0_off + 86) );
      A3 = _mm_load_pd( MMCAST(A0_off + 122) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 14) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 16 */
      A0 = _mm_load_pd( MMCAST(A0_off + 16) );
      A1 = _mm_load_pd( MMCAST(A0_off + 52) );
      A2 = _mm_load_pd( MMCAST(A0_off + 88) );
      A3 = _mm_load_pd( MMCAST(A0_off + 124) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 16) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 18 */
      A0 = _mm_load_pd( MMCAST(A0_off + 18) );
      A1 = _mm_load_pd( MMCAST(A0_off + 54) );
      A2 = _mm_load_pd( MMCAST(A0_off + 90) );
      A3 = _mm_load_pd( MMCAST(A0_off + 126) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 18) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 20 */
      A0 = _mm_load_pd( MMCAST(A0_off + 20) );
      A1 = _mm_load_pd( MMCAST(A0_off + 56) );
      A2 = _mm_load_pd( MMCAST(A0_off + 92) );
      A3 = _mm_load_pd( MMCAST(A0_off + 128) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 20) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 22 */
      A0 = _mm_load_pd( MMCAST(A0_off + 22) );
      A1 = _mm_load_pd( MMCAST(A0_off + 58) );
      A2 = _mm_load_pd( MMCAST(A0_off + 94) );
      A3 = _mm_load_pd( MMCAST(A0_off + 130) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 22) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 24 */
      A0 = _mm_load_pd( MMCAST(A0_off + 24) );
      A1 = _mm_load_pd( MMCAST(A0_off + 60) );
      A2 = _mm_load_pd( MMCAST(A0_off + 96) );
      A3 = _mm_load_pd( MMCAST(A0_off + 132) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 24) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 26 */
      A0 = _mm_load_pd( MMCAST(A0_off + 26) );
      A1 = _mm_load_pd( MMCAST(A0_off + 62) );
      A2 = _mm_load_pd( MMCAST(A0_off + 98) );
      A3 = _mm_load_pd( MMCAST(A0_off + 134) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 26) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 28 */
      A0 = _mm_load_pd( MMCAST(A0_off + 28) );
      A1 = _mm_load_pd( MMCAST(A0_off + 64) );
      A2 = _mm_load_pd( MMCAST(A0_off + 100) );
      A3 = _mm_load_pd( MMCAST(A0_off + 136) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 28) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 30 */
      A0 = _mm_load_pd( MMCAST(A0_off + 30) );
      A1 = _mm_load_pd( MMCAST(A0_off + 66) );
      A2 = _mm_load_pd( MMCAST(A0_off + 102) );
      A3 = _mm_load_pd( MMCAST(A0_off + 138) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 30) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 32 */
      A0 = _mm_load_pd( MMCAST(A0_off + 32) );
      A1 = _mm_load_pd( MMCAST(A0_off + 68) );
      A2 = _mm_load_pd( MMCAST(A0_off + 104) );
      A3 = _mm_load_pd( MMCAST(A0_off + 140) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 32) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 34 */
      A0 = _mm_load_pd( MMCAST(A0_off + 34) );
      A1 = _mm_load_pd( MMCAST(A0_off + 70) );
      A2 = _mm_load_pd( MMCAST(A0_off + 106) );
      A3 = _mm_load_pd( MMCAST(A0_off + 142) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 34) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
      prefetchB += J_UNROLL*KB*8;
      /* Combine scalar expansion back to scalar */
      c0_0 = _mm_hadd_pd( c0_0, c0_1 );
      c0_2 = _mm_hadd_pd( c0_2, c0_3 );
      /* Applying Beta */
         /* Apply Beta Factor */
         /* Load C from memory */
         temp0 = _mm_load_sd( cPtrI0 + 0 );
         temp1 = _mm_load_sd( cPtrI0 + 2 );
         bc0_0 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
         bc0_0 = _mm_mul_pd( betaV, bc0_0 );
         temp0 = _mm_load_sd( cPtrI0 + 4 );
         temp1 = _mm_load_sd( cPtrI0 + 6 );
         bc0_2 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
         bc0_2 = _mm_mul_pd( betaV, bc0_2 );
         /* C = (beta*C) + (matrix multiply) */
         c0_0 = _mm_add_pd( bc0_0, c0_0 );
         c0_2 = _mm_add_pd( bc0_2, c0_2 );
      /* Move pointers to next iteration */  
      A0_off += unroll_a;
      
      /* Store results back to memory  */
      _mm_store_sd( cPtrI0+0, c0_0 );
      temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+2, temp );

      _mm_store_sd( cPtrI0+4, c0_2 );
      temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+6, temp );

      cPtrI0 += 2*I_UNROLL;
      

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#else
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 4
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3;
   /* Vector register to hold C*beta */
   __m128d bc0_0, bc0_2, bc0_3;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   __m128d temp0;  
   __m128d temp1;  
   __builtin_prefetch( B, PF_READONLY, PF_DEF );
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchACols =  (void*)(A + 36*KB); 
   register void const *prefetchB =  (void*)(B + 36*ldb);
   __builtin_prefetch( prefetchACols, PF_READONLY, PF_DEF );
   __builtin_prefetch( prefetchB, PF_READONLY, PF_DEF );
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-36; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-36+I_UNROLL; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 36) );
         A2 = _mm_load_pd( MMCAST(A0_off + 72) );
         A3 = _mm_load_pd( MMCAST(A0_off + 108) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         
         /* K_Unrolling: 2 */
         A0 = _mm_load_pd( MMCAST(A0_off + 2) );
         A1 = _mm_load_pd( MMCAST(A0_off + 38) );
         A2 = _mm_load_pd( MMCAST(A0_off + 74) );
         A3 = _mm_load_pd( MMCAST(A0_off + 110) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 2) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_pd( MMCAST(A0_off + 4) );
         A1 = _mm_load_pd( MMCAST(A0_off + 40) );
         A2 = _mm_load_pd( MMCAST(A0_off + 76) );
         A3 = _mm_load_pd( MMCAST(A0_off + 112) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 4) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 6 */
         A0 = _mm_load_pd( MMCAST(A0_off + 6) );
         A1 = _mm_load_pd( MMCAST(A0_off + 42) );
         A2 = _mm_load_pd( MMCAST(A0_off + 78) );
         A3 = _mm_load_pd( MMCAST(A0_off + 114) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 6) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 8 */
         A0 = _mm_load_pd( MMCAST(A0_off + 8) );
         A1 = _mm_load_pd( MMCAST(A0_off + 44) );
         A2 = _mm_load_pd( MMCAST(A0_off + 80) );
         A3 = _mm_load_pd( MMCAST(A0_off + 116) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 8) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 10 */
         A0 = _mm_load_pd( MMCAST(A0_off + 10) );
         A1 = _mm_load_pd( MMCAST(A0_off + 46) );
         A2 = _mm_load_pd( MMCAST(A0_off + 82) );
         A3 = _mm_load_pd( MMCAST(A0_off + 118) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 10) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 12 */
         A0 = _mm_load_pd( MMCAST(A0_off + 12) );
         A1 = _mm_load_pd( MMCAST(A0_off + 48) );
         A2 = _mm_load_pd( MMCAST(A0_off + 84) );
         A3 = _mm_load_pd( MMCAST(A0_off + 120) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 12) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 14 */
         A0 = _mm_load_pd( MMCAST(A0_off + 14) );
         A1 = _mm_load_pd( MMCAST(A0_off + 50) );
         A2 = _mm_load_pd( MMCAST(A0_off + 86) );
         A3 = _mm_load_pd( MMCAST(A0_off + 122) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 14) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 16 */
         A0 = _mm_load_pd( MMCAST(A0_off + 16) );
         A1 = _mm_load_pd( MMCAST(A0_off + 52) );
         A2 = _mm_load_pd( MMCAST(A0_off + 88) );
         A3 = _mm_load_pd( MMCAST(A0_off + 124) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 16) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 18 */
         A0 = _mm_load_pd( MMCAST(A0_off + 18) );
         A1 = _mm_load_pd( MMCAST(A0_off + 54) );
         A2 = _mm_load_pd( MMCAST(A0_off + 90) );
         A3 = _mm_load_pd( MMCAST(A0_off + 126) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 18) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 20 */
         A0 = _mm_load_pd( MMCAST(A0_off + 20) );
         A1 = _mm_load_pd( MMCAST(A0_off + 56) );
         A2 = _mm_load_pd( MMCAST(A0_off + 92) );
         A3 = _mm_load_pd( MMCAST(A0_off + 128) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 20) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 22 */
         A0 = _mm_load_pd( MMCAST(A0_off + 22) );
         A1 = _mm_load_pd( MMCAST(A0_off + 58) );
         A2 = _mm_load_pd( MMCAST(A0_off + 94) );
         A3 = _mm_load_pd( MMCAST(A0_off + 130) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 22) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 24 */
         A0 = _mm_load_pd( MMCAST(A0_off + 24) );
         A1 = _mm_load_pd( MMCAST(A0_off + 60) );
         A2 = _mm_load_pd( MMCAST(A0_off + 96) );
         A3 = _mm_load_pd( MMCAST(A0_off + 132) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 24) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 26 */
         A0 = _mm_load_pd( MMCAST(A0_off + 26) );
         A1 = _mm_load_pd( MMCAST(A0_off + 62) );
         A2 = _mm_load_pd( MMCAST(A0_off + 98) );
         A3 = _mm_load_pd( MMCAST(A0_off + 134) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 26) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
         /* K_Unrolling: 28 */
         A0 = _mm_load_pd( MMCAST(A0_off + 28) );
         A1 = _mm_load_pd( MMCAST(A0_off + 64) );
         A2 = _mm_load_pd( MMCAST(A0_off + 100) );
         A3 = _mm_load_pd( MMCAST(A0_off + 136) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 28) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
         /* K_Unrolling: 30 */
         A0 = _mm_load_pd( MMCAST(A0_off + 30) );
         A1 = _mm_load_pd( MMCAST(A0_off + 66) );
         A2 = _mm_load_pd( MMCAST(A0_off + 102) );
         A3 = _mm_load_pd( MMCAST(A0_off + 138) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 30) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
         /* K_Unrolling: 32 */
         A0 = _mm_load_pd( MMCAST(A0_off + 32) );
         A1 = _mm_load_pd( MMCAST(A0_off + 68) );
         A2 = _mm_load_pd( MMCAST(A0_off + 104) );
         A3 = _mm_load_pd( MMCAST(A0_off + 140) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 32) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
         /* K_Unrolling: 34 */
         A0 = _mm_load_pd( MMCAST(A0_off + 34) );
         A1 = _mm_load_pd( MMCAST(A0_off + 70) );
         A2 = _mm_load_pd( MMCAST(A0_off + 106) );
         A3 = _mm_load_pd( MMCAST(A0_off + 142) );
         
         B0 = _mm_load_pd( MMCAST(B0_off + 34) );
         A0 = _mm_mul_pd( B0, A0 );
         c0_0 = _mm_add_pd( A0, c0_0 );
         A1 = _mm_mul_pd( B0, A1 );
         c0_1 = _mm_add_pd( A1, c0_1 );
         A2 = _mm_mul_pd( B0, A2 );
         c0_2 = _mm_add_pd( A2, c0_2 );
         A3 = _mm_mul_pd( B0, A3 );
         c0_3 = _mm_add_pd( A3, c0_3 );
         __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
         /* Combine scalar expansion back to scalar */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            temp0 = _mm_load_sd( cPtrI0 + 0 );
            temp1 = _mm_load_sd( cPtrI0 + 2 );
            bc0_0 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
            temp0 = _mm_load_sd( cPtrI0 + 4 );
            temp1 = _mm_load_sd( cPtrI0 + 6 );
            bc0_2 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_pd( bc0_0, c0_0 );
            c0_2 = _mm_add_pd( bc0_2, c0_2 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_sd( cPtrI0+0, c0_0 );
         temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+2, temp );

         _mm_store_sd( cPtrI0+4, c0_2 );
         temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
         _mm_store_sd( cPtrI0+6, temp );

         cPtrI0 += 2*I_UNROLL;
         

         prefetchACols += 4*KB;
      } /* End i/MB loop */

      /* K_Unrolling0 */
      A0 = _mm_load_pd( MMCAST(A0_off) );
      A1 = _mm_load_pd( MMCAST(A0_off + 36) );
      A2 = _mm_load_pd( MMCAST(A0_off + 72) );
      A3 = _mm_load_pd( MMCAST(A0_off + 108) );
      B0 = _mm_load_pd( MMCAST(B0_off) );
      c0_0 = B0;
      c0_0 = _mm_mul_pd( A0, c0_0 );
      c0_1 = B0;
      c0_1 = _mm_mul_pd( A1, c0_1 );
      c0_2 = B0;
      c0_2 = _mm_mul_pd( A2, c0_2 );
      c0_3 = B0;
      c0_3 = _mm_mul_pd( A3, c0_3 );
      
      /* K_Unrolling: 2 */
      A0 = _mm_load_pd( MMCAST(A0_off + 2) );
      A1 = _mm_load_pd( MMCAST(A0_off + 38) );
      A2 = _mm_load_pd( MMCAST(A0_off + 74) );
      A3 = _mm_load_pd( MMCAST(A0_off + 110) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 2) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 0,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 4 */
      A0 = _mm_load_pd( MMCAST(A0_off + 4) );
      A1 = _mm_load_pd( MMCAST(A0_off + 40) );
      A2 = _mm_load_pd( MMCAST(A0_off + 76) );
      A3 = _mm_load_pd( MMCAST(A0_off + 112) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 4) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 57,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 6 */
      A0 = _mm_load_pd( MMCAST(A0_off + 6) );
      A1 = _mm_load_pd( MMCAST(A0_off + 42) );
      A2 = _mm_load_pd( MMCAST(A0_off + 78) );
      A3 = _mm_load_pd( MMCAST(A0_off + 114) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 6) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 114,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 8 */
      A0 = _mm_load_pd( MMCAST(A0_off + 8) );
      A1 = _mm_load_pd( MMCAST(A0_off + 44) );
      A2 = _mm_load_pd( MMCAST(A0_off + 80) );
      A3 = _mm_load_pd( MMCAST(A0_off + 116) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 8) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 171,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+0+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 10 */
      A0 = _mm_load_pd( MMCAST(A0_off + 10) );
      A1 = _mm_load_pd( MMCAST(A0_off + 46) );
      A2 = _mm_load_pd( MMCAST(A0_off + 82) );
      A3 = _mm_load_pd( MMCAST(A0_off + 118) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 10) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchB + 0 + 228,PF_READONLY, PF_DEF);
      __builtin_prefetch( prefetchACols+64+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 12 */
      A0 = _mm_load_pd( MMCAST(A0_off + 12) );
      A1 = _mm_load_pd( MMCAST(A0_off + 48) );
      A2 = _mm_load_pd( MMCAST(A0_off + 84) );
      A3 = _mm_load_pd( MMCAST(A0_off + 120) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 12) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 14 */
      A0 = _mm_load_pd( MMCAST(A0_off + 14) );
      A1 = _mm_load_pd( MMCAST(A0_off + 50) );
      A2 = _mm_load_pd( MMCAST(A0_off + 86) );
      A3 = _mm_load_pd( MMCAST(A0_off + 122) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 14) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 16 */
      A0 = _mm_load_pd( MMCAST(A0_off + 16) );
      A1 = _mm_load_pd( MMCAST(A0_off + 52) );
      A2 = _mm_load_pd( MMCAST(A0_off + 88) );
      A3 = _mm_load_pd( MMCAST(A0_off + 124) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 16) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+64+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 18 */
      A0 = _mm_load_pd( MMCAST(A0_off + 18) );
      A1 = _mm_load_pd( MMCAST(A0_off + 54) );
      A2 = _mm_load_pd( MMCAST(A0_off + 90) );
      A3 = _mm_load_pd( MMCAST(A0_off + 126) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 18) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 20 */
      A0 = _mm_load_pd( MMCAST(A0_off + 20) );
      A1 = _mm_load_pd( MMCAST(A0_off + 56) );
      A2 = _mm_load_pd( MMCAST(A0_off + 92) );
      A3 = _mm_load_pd( MMCAST(A0_off + 128) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 20) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 22 */
      A0 = _mm_load_pd( MMCAST(A0_off + 22) );
      A1 = _mm_load_pd( MMCAST(A0_off + 58) );
      A2 = _mm_load_pd( MMCAST(A0_off + 94) );
      A3 = _mm_load_pd( MMCAST(A0_off + 130) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 22) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 24 */
      A0 = _mm_load_pd( MMCAST(A0_off + 24) );
      A1 = _mm_load_pd( MMCAST(A0_off + 60) );
      A2 = _mm_load_pd( MMCAST(A0_off + 96) );
      A3 = _mm_load_pd( MMCAST(A0_off + 132) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 24) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+128+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 26 */
      A0 = _mm_load_pd( MMCAST(A0_off + 26) );
      A1 = _mm_load_pd( MMCAST(A0_off + 62) );
      A2 = _mm_load_pd( MMCAST(A0_off + 98) );
      A3 = _mm_load_pd( MMCAST(A0_off + 134) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 26) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*0,PF_READONLY, PF_DEF );
      /* K_Unrolling: 28 */
      A0 = _mm_load_pd( MMCAST(A0_off + 28) );
      A1 = _mm_load_pd( MMCAST(A0_off + 64) );
      A2 = _mm_load_pd( MMCAST(A0_off + 100) );
      A3 = _mm_load_pd( MMCAST(A0_off + 136) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 28) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*8,PF_READONLY, PF_DEF );
      /* K_Unrolling: 30 */
      A0 = _mm_load_pd( MMCAST(A0_off + 30) );
      A1 = _mm_load_pd( MMCAST(A0_off + 66) );
      A2 = _mm_load_pd( MMCAST(A0_off + 102) );
      A3 = _mm_load_pd( MMCAST(A0_off + 138) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 30) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*16,PF_READONLY, PF_DEF );
      /* K_Unrolling: 32 */
      A0 = _mm_load_pd( MMCAST(A0_off + 32) );
      A1 = _mm_load_pd( MMCAST(A0_off + 68) );
      A2 = _mm_load_pd( MMCAST(A0_off + 104) );
      A3 = _mm_load_pd( MMCAST(A0_off + 140) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 32) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+192+KB*24,PF_READONLY, PF_DEF );
      /* K_Unrolling: 34 */
      A0 = _mm_load_pd( MMCAST(A0_off + 34) );
      A1 = _mm_load_pd( MMCAST(A0_off + 70) );
      A2 = _mm_load_pd( MMCAST(A0_off + 106) );
      A3 = _mm_load_pd( MMCAST(A0_off + 142) );
      
      B0 = _mm_load_pd( MMCAST(B0_off + 34) );
      A0 = _mm_mul_pd( B0, A0 );
      c0_0 = _mm_add_pd( A0, c0_0 );
      A1 = _mm_mul_pd( B0, A1 );
      c0_1 = _mm_add_pd( A1, c0_1 );
      A2 = _mm_mul_pd( B0, A2 );
      c0_2 = _mm_add_pd( A2, c0_2 );
      A3 = _mm_mul_pd( B0, A3 );
      c0_3 = _mm_add_pd( A3, c0_3 );
      __builtin_prefetch( prefetchACols+256+KB*0,PF_READONLY, PF_DEF );
      prefetchB += J_UNROLL*KB*8;
      /* Combine scalar expansion back to scalar */
      c0_0 = _mm_hadd_pd( c0_0, c0_1 );
      c0_2 = _mm_hadd_pd( c0_2, c0_3 );
      /* Applying Beta */
         /* Apply Beta Factor */
         /* Load C from memory */
         temp0 = _mm_load_sd( cPtrI0 + 0 );
         temp1 = _mm_load_sd( cPtrI0 + 2 );
         bc0_0 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
         temp0 = _mm_load_sd( cPtrI0 + 4 );
         temp1 = _mm_load_sd( cPtrI0 + 6 );
         bc0_2 = _mm_shuffle_pd( temp0, temp1,_MM_SHUFFLE2(0, 0 )  );
         /* C = (beta*C) + (matrix multiply) */
         c0_0 = _mm_add_pd( bc0_0, c0_0 );
         c0_2 = _mm_add_pd( bc0_2, c0_2 );
      /* Move pointers to next iteration */  
      A0_off += unroll_a;
      
      /* Store results back to memory  */
      _mm_store_sd( cPtrI0+0, c0_0 );
      temp = _mm_shuffle_pd( c0_0, c0_0,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+2, temp );

      _mm_store_sd( cPtrI0+4, c0_2 );
      temp = _mm_shuffle_pd( c0_2, c0_2,_MM_SHUFFLE2(1,1));
      _mm_store_sd( cPtrI0+6, temp );

      cPtrI0 += 2*I_UNROLL;
      

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#endif
