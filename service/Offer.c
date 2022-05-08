#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/input/OfferInput.h"

void insertOffer(Offer** l){

    OfferInput offerInput = insertDataOffer();

    *l = listInsertOffer(*l, offerInput);

    //listRetrieveOffer(*l);

    getchar();
}

void retrieveOffer(Offer** l){

    listRetrieveOffer(*l);

    getchar();
}

