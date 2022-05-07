#include "../utility/Utility.h"
#include "../model/Offer.h"

void insertOffer(Offer** l){

    *l = listInsertOffer(*l, 0, "MGLU3", 500, 5.00);
    *l = listInsertOffer(*l, 0, "MGLU3", 500, 5.00);
    *l = listInsertOffer(*l, 0, "MGLU3", 500, 5.00);

    listRetrieveOffer(*l);

    getchar();
}

void retrieveOffer(Offer** l){

    listRetrieveOffer(*l);

    getchar();
}

