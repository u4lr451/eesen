#ifndef ATL_stGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,144,288,360,432,576,648,720,792,864,1224,1800,1872,1944,2088,2448,2736,2880,2952,3024,3168,3312,3672,4968,5256,5400,5472,5544,6192,7416,8640,10000
 * N : 25,144,288,360,432,576,648,720,792,864,1224,1800,1872,1944,2088,2448,2736,2880,2952,3024,3168,3312,3672,4968,5256,5400,5472,5544,6192,7416,8640,10000
 * NB : 1,72,72,72,76,92,176,176,192,184,176,160,144,208,192,192,192,128,200,200,136,208,208,208,208,208,360,360,360,360,360,432
 */
#define ATL_stGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 84) (nb_) = 1; \
   else if ((n_) < 396) (nb_) = 72; \
   else if ((n_) < 504) (nb_) = 76; \
   else if ((n_) < 612) (nb_) = 92; \
   else if ((n_) < 756) (nb_) = 176; \
   else if ((n_) < 828) (nb_) = 192; \
   else if ((n_) < 1044) (nb_) = 184; \
   else if ((n_) < 1512) (nb_) = 176; \
   else if ((n_) < 1836) (nb_) = 160; \
   else if ((n_) < 1908) (nb_) = 144; \
   else if ((n_) < 2016) (nb_) = 208; \
   else if ((n_) < 2808) (nb_) = 192; \
   else if ((n_) < 2916) (nb_) = 128; \
   else if ((n_) < 3096) (nb_) = 200; \
   else if ((n_) < 3240) (nb_) = 136; \
   else if ((n_) < 5436) (nb_) = 208; \
   else if ((n_) < 9320) (nb_) = 360; \
   else (nb_) = 432; \
}


#endif    /* end ifndef ATL_stGetNB_geqrf */
