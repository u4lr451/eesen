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
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   __m128 temp0;  
   __m128 temp1;  
   __m128 temp2;  
   __m128 temp3;  
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 72*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (4 * 1 * KB * 4) / 72;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-72; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-72; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 144) );
         A3 = _mm_load_ps( MMCAST(A0_off + 216) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 148) );
         A3 = _mm_load_ps( MMCAST(A0_off + 220) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 152) );
         A3 = _mm_load_ps( MMCAST(A0_off + 224) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 156) );
         A3 = _mm_load_ps( MMCAST(A0_off + 228) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 88) );
         A2 = _mm_load_ps( MMCAST(A0_off + 160) );
         A3 = _mm_load_ps( MMCAST(A0_off + 232) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 92) );
         A2 = _mm_load_ps( MMCAST(A0_off + 164) );
         A3 = _mm_load_ps( MMCAST(A0_off + 236) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 96) );
         A2 = _mm_load_ps( MMCAST(A0_off + 168) );
         A3 = _mm_load_ps( MMCAST(A0_off + 240) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 100) );
         A2 = _mm_load_ps( MMCAST(A0_off + 172) );
         A3 = _mm_load_ps( MMCAST(A0_off + 244) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 104) );
         A2 = _mm_load_ps( MMCAST(A0_off + 176) );
         A3 = _mm_load_ps( MMCAST(A0_off + 248) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* k unroll factor: 36 */
         for( k=36; k<72; k+=36)
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST(A0_off + 72 + k));
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST(A0_off + 144 + k));
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST(A0_off + 216 + k));
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 4 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+4) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+4) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+4) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+4) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+4) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 8 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+8) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+8) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+8) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+8) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+8) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 12 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+12) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+12) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+12) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+12) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+12) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 16 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+16) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+16) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+16) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+16) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+16) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 20 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+20) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+20) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+20) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+20) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+20) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 24 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+24) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+24) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+24) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+24) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+24) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 28 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+28) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+28) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+28) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+28) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+28) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 32 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+32) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+32) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+32) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+32) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+32) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
         }
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         /* Applying Beta */
         /* No beta will be appied */
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         temp = c0_0;
         _mm_store_ss( cPtrI0+0, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(1,1,1,1));
         _mm_store_ss( cPtrI0+2, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(2,2,2,2));
         _mm_store_ss( cPtrI0+4, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(3,3,3,3));
         _mm_store_ss( cPtrI0+6, temp );
         cPtrI0 += 2*I_UNROLL;
         

      } /* End i/MB loop */

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
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3;
   /* Vector register to hold C*beta */
   __m128 bc0_0, bc0_1, bc0_2, bc0_3;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   __m128 temp0;  
   __m128 temp1;  
   __m128 temp2;  
   __m128 temp3;  
   const __m128 betaV = _mm_set1_ps( beta ); 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 72*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (4 * 1 * KB * 4) / 72;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-72; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-72; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 144) );
         A3 = _mm_load_ps( MMCAST(A0_off + 216) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 148) );
         A3 = _mm_load_ps( MMCAST(A0_off + 220) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 152) );
         A3 = _mm_load_ps( MMCAST(A0_off + 224) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 156) );
         A3 = _mm_load_ps( MMCAST(A0_off + 228) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 88) );
         A2 = _mm_load_ps( MMCAST(A0_off + 160) );
         A3 = _mm_load_ps( MMCAST(A0_off + 232) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 92) );
         A2 = _mm_load_ps( MMCAST(A0_off + 164) );
         A3 = _mm_load_ps( MMCAST(A0_off + 236) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 96) );
         A2 = _mm_load_ps( MMCAST(A0_off + 168) );
         A3 = _mm_load_ps( MMCAST(A0_off + 240) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 100) );
         A2 = _mm_load_ps( MMCAST(A0_off + 172) );
         A3 = _mm_load_ps( MMCAST(A0_off + 244) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 104) );
         A2 = _mm_load_ps( MMCAST(A0_off + 176) );
         A3 = _mm_load_ps( MMCAST(A0_off + 248) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* k unroll factor: 36 */
         for( k=36; k<72; k+=36)
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST(A0_off + 72 + k));
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST(A0_off + 144 + k));
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST(A0_off + 216 + k));
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 4 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+4) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+4) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+4) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+4) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+4) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 8 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+8) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+8) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+8) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+8) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+8) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 12 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+12) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+12) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+12) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+12) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+12) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 16 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+16) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+16) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+16) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+16) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+16) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 20 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+20) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+20) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+20) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+20) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+20) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 24 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+24) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+24) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+24) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+24) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+24) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 28 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+28) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+28) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+28) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+28) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+28) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 32 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+32) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+32) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+32) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+32) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+32) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
         }
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            temp0 = _mm_load_ss( cPtrI0 + 0 );
            temp1 = _mm_load_ss( cPtrI0 + 2 );
            temp2 = _mm_load_ss( cPtrI0 + 4 );
            temp3 = _mm_load_ss( cPtrI0 + 6 );
            temp0 = _mm_unpacklo_ps( temp0, temp1 );
            temp2 = _mm_unpacklo_ps( temp2, temp3 );
            bc0_0 = _mm_movelh_ps( temp0, temp2 );
            bc0_0 = _mm_mul_ps( betaV, bc0_0 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ps( bc0_0, c0_0 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         temp = c0_0;
         _mm_store_ss( cPtrI0+0, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(1,1,1,1));
         _mm_store_ss( cPtrI0+2, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(2,2,2,2));
         _mm_store_ss( cPtrI0+4, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(3,3,3,3));
         _mm_store_ss( cPtrI0+6, temp );
         cPtrI0 += 2*I_UNROLL;
         

      } /* End i/MB loop */

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
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3;
   /* Vector register to hold C*beta */
   __m128 bc0_0, bc0_1, bc0_2, bc0_3;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   __m128 temp0;  
   __m128 temp1;  
   __m128 temp2;  
   __m128 temp3;  
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 72*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (4 * 1 * KB * 4) / 72;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-72; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-72; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 144) );
         A3 = _mm_load_ps( MMCAST(A0_off + 216) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 148) );
         A3 = _mm_load_ps( MMCAST(A0_off + 220) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 152) );
         A3 = _mm_load_ps( MMCAST(A0_off + 224) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 156) );
         A3 = _mm_load_ps( MMCAST(A0_off + 228) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 88) );
         A2 = _mm_load_ps( MMCAST(A0_off + 160) );
         A3 = _mm_load_ps( MMCAST(A0_off + 232) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 92) );
         A2 = _mm_load_ps( MMCAST(A0_off + 164) );
         A3 = _mm_load_ps( MMCAST(A0_off + 236) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 96) );
         A2 = _mm_load_ps( MMCAST(A0_off + 168) );
         A3 = _mm_load_ps( MMCAST(A0_off + 240) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 100) );
         A2 = _mm_load_ps( MMCAST(A0_off + 172) );
         A3 = _mm_load_ps( MMCAST(A0_off + 244) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 104) );
         A2 = _mm_load_ps( MMCAST(A0_off + 176) );
         A3 = _mm_load_ps( MMCAST(A0_off + 248) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         /* k unroll factor: 36 */
         for( k=36; k<72; k+=36)
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST(A0_off + 72 + k));
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST(A0_off + 144 + k));
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST(A0_off + 216 + k));
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 4 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+4) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+4) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+4) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+4) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+4) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 8 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+8) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+8) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+8) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+8) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+8) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 12 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+12) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+12) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+12) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+12) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+12) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 16 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+16) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+16) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+16) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+16) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+16) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 20 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+20) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+20) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+20) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+20) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+20) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 24 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+24) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+24) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+24) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+24) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+24) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 28 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+28) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+28) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+28) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+28) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+28) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            /* k_partialUnrolling: 32 */
            B0 = _mm_load_ps( MMCAST( B0_off + (k+32) ) );
            A0 = _mm_load_ps( MMCAST( A0_off + (k+32) ) );
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST( A0_off + 72 + (k+32) ) );
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST( A0_off + 144 + (k+32) ) );
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST( A0_off + 216 + (k+32) ) );
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
         }
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            temp0 = _mm_load_ss( cPtrI0 + 0 );
            temp1 = _mm_load_ss( cPtrI0 + 2 );
            temp2 = _mm_load_ss( cPtrI0 + 4 );
            temp3 = _mm_load_ss( cPtrI0 + 6 );
            temp0 = _mm_unpacklo_ps( temp0, temp1 );
            temp2 = _mm_unpacklo_ps( temp2, temp3 );
            bc0_0 = _mm_movelh_ps( temp0, temp2 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ps( bc0_0, c0_0 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         temp = c0_0;
         _mm_store_ss( cPtrI0+0, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(1,1,1,1));
         _mm_store_ss( cPtrI0+2, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(2,2,2,2));
         _mm_store_ss( cPtrI0+4, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(3,3,3,3));
         _mm_store_ss( cPtrI0+6, temp );
         cPtrI0 += 2*I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#endif