#ifndef OFFER_H // include guard

    #define OFFER_H

    #include "../utility/Utility.h"
    
    #include "input/OfferInput.h"
    #include "Shares.h"

    typedef struct detailsOffer {

        typeStatus flag;
        typeOffers type;
        int quantity;
        float value;
        char signature[10];
        struct tm *clock;
        struct detailsOffer *next;

    } Offer;

    /* Controller */
    Offer*  listCreateOffer(void);
    Offer*  listInsertOffer(Offer* l, OfferInput offerInput);
    void    listUpdateOffer(Offer** l, OfferInput offerInput);
    void    listRetrieveOffer(Offer* l);
    int     listEmptyOffer(Offer* l);
    Offer*  listSearchOffer(Offer* l, int v);
    Offer*  listDeleteOffer(Offer* l, int v);
    void    listReleaseOffer(Offer *l);

    /* Service */
    void    insertOffer(Offer** l, Shares** s);
    void    retrieveOffer(Offer** l);
    
    /* Data */
    void    dataFileOffer(Offer** l, Shares** s);
 
#endif