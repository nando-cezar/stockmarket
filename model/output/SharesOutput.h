#ifndef SHARESOUTPUT_H // include guard

    #define SHARESOUTPUT_H

    #include "../../utility/Utility.h"
    #include "../Shares.h"
    
    typedef struct detailsSharesOutput {

        char name[255];
        char sector[50];
        char signature[10];
        float price;

    } SharesOutput;

    SharesOutput searchDataShares(Shares* s);
    int quantitySelectedShares();
 
#endif