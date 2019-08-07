#ifndef ATL_dGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,224,448,672,896,1792,3584
 * N : 25,224,448,672,896,1792,3584
 * NB : 12,4,56,56,112,112,112
 */
#define ATL_dGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 124) (nb_) = 12; \
   else if ((n_) < 336) (nb_) = 4; \
   else if ((n_) < 784) (nb_) = 56; \
   else (nb_) = 112; \
}


#endif    /* end ifndef ATL_dGetNB_geqrf */
