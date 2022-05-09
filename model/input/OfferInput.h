#ifndef OFFERINPUT_H // include guard

    #define OFFERINPUT_H

    #include "../../utility/Utility.h"
    #include "../Shares.h"

    typedef struct detailsOfferInput {

        typeOffers type;
        int quantity;
        float value;
        char signature[10];

    } OfferInput;

    OfferInput insertDataOffer(Shares* s);
 
#endif