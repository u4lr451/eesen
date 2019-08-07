#ifndef ATLAS_DR2_L0_H
#define ATLAS_DR2_L0_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_UGER2K
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);

static ATL_r2kern_t ATL_GetR2Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 8;   *minN = 4;
   *mu = 8;     *nu = 4;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 6144;
   return(ATL_UGER2K);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 608; (nb_) = 4; }

#endif  /* end protection around header file contents */
