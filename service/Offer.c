#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/input/OfferInput.h"
#include "../view/Menu.h"

void insertOffer(Offer** l){

    header();

    OfferInput offerInput = insertDataOffer();

    *l = listInsertOffer(*l, offerInput);

    dataFile();
    //listRetrieveOffer(*l);

    getchar();
}

void retrieveOffer(Offer** l){

    header();

    listRetrieveOffer(*l);

    getchar();
}

