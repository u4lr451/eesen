#ifndef ATL_sGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,504,1080,2232,4464
 * N : 25,504,1080,2232,4464
 * NB : 12,72,72,72,216
 */
#define ATL_sGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 264) (nb_) = 12; \
   else if ((n_) < 3348) (nb_) = 72; \
   else (nb_) = 216; \
}


#endif    /* end ifndef ATL_sGetNB_geqrf */
