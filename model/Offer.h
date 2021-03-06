#ifndef OFFER_H // include guard

    #define OFFER_H

    #include "../utility/Utility.h"
    
    #include "input/OfferInput.h"
    #include "Shares.h"
    #include "Clock.h"

    typedef struct detailsOffer {

        typeStatus flag;
        typeOffers type;
        int quantity;
        float value;
        char signature[10];
        struct detailsClock clock;
        struct detailsOffer *next;

    } Offer;

    /* Controller */
    Offer*  listCreateOffer(void);
    Offer*  listInsertOffer(Offer* l, OfferInput offerInput);
    void    listUpdateOffer(Offer** l, OfferInput offerInput);
    void    listRetrieveOfferPerSignature(Offer* l, char *sg);
    void    listRetrieveOfferPerType(Offer* l, char tp);
    void    listRetrieveOfferPerDate(Offer* l, int d, int m, int y);
    void    listRetrieveOffer(Offer* l);
    int     listEmptyOffer(Offer* l);
    Offer*  listSearchOffer(Offer* l, char *sg);
    Offer*  listDeleteOffer(Offer* l, int v);
    void    listReleaseOffer(Offer *l);

    /* Service */
    void    insertOffer(Offer** l, Shares** s);
    void    retrieveOffer(Offer** l);
    
    /* Data */
    void    dataFileOffer(Offer** l, Shares** s);
 
#endif