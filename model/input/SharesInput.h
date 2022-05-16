#ifndef SHARESINPUT_H // include guard

    #define SHARESINPUT_H

    #include "../../utility/Utility.h"
    #include "../Shares.h"
    
    typedef struct detailsSharesInput {

        char name[255];
        char sector[50];
        char signature[10];
        float price;

    } SharesInput;

    //SharesInput insertDataShares(void);
 
#endif