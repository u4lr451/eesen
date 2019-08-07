#ifndef ATL_ztGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,112,224,280,336,504,560,616,784,840,896,952,1008,1064,1568,1848,1904,1960,2016,2128,4256,8512
 * N : 25,112,224,280,336,504,560,616,784,840,896,952,1008,1064,1568,1848,1904,1960,2016,2128,4256,8512
 * NB : 7,56,56,72,80,60,144,112,112,96,128,112,112,136,112,96,136,136,160,144,128,112
 */
#define ATL_ztGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 68) (nb_) = 7; \
   else if ((n_) < 252) (nb_) = 56; \
   else if ((n_) < 308) (nb_) = 72; \
   else if ((n_) < 420) (nb_) = 80; \
   else if ((n_) < 532) (nb_) = 60; \
   else if ((n_) < 588) (nb_) = 144; \
   else if ((n_) < 812) (nb_) = 112; \
   else if ((n_) < 868) (nb_) = 96; \
   else if ((n_) < 924) (nb_) = 128; \
   else if ((n_) < 1036) (nb_) = 112; \
   else if ((n_) < 1316) (nb_) = 136; \
   else if ((n_) < 1708) (nb_) = 112; \
   else if ((n_) < 1876) (nb_) = 96; \
   else if ((n_) < 1988) (nb_) = 136; \
   else if ((n_) < 2072) (nb_) = 160; \
   else if ((n_) < 3192) (nb_) = 144; \
   else if ((n_) < 6384) (nb_) = 128; \
   else (nb_) = 112; \
}


#endif    /* end ifndef ATL_ztGetNB_geqrf */
