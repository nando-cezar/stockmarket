#ifndef OFFEROUTPUT_H // include guard

    #define OFFEROUTPUT_H

    #include "../../utility/Utility.h"
    #include "../Shares.h"

    typedef struct detailsOfferOutput {

        typeOffers type;
        int quantity;
        float value;
        char signature[10];

    } OfferOutput;

    OfferOutput searchDataOffers(void);
    int filterSharesSearch();
    void printOfferES(float value, float topValue, float c);
    void printOfferNO(float value);
 
#endif