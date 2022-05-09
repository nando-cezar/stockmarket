#ifndef SHARES_H // include guard

    #define SHARES_H

    #include "../utility/Utility.h"

    #include "input/SharesInput.h"
    #include "Buy.h"
    #include "Sell.h"
    
    typedef struct detailsShares {

        typeStatus flag;
        char name[255];
        char sector[50];
        char signature[10];
        struct detailsBuy *buy;
        struct detailsSell *sell;
        struct detailsShares *next;

    } Shares;

    /* Controller */
    Shares* listCreateShares(void);
    Shares* listInsertShares(Shares* l, SharesInput sharesInput);
    void listUpdateShares(Shares** l, SharesInput sharesInput);
    void listRetrieveShares(Shares* l);
    int listEmptyShares(Shares* l);
    Shares* listSearchShares(Shares* l, char *sg);
    Shares* listDeleteShares(Shares* l, char *sg);
    void listReleaseShares(Shares *l);

    /* Service */
    void dataFileShares(Shares* l);
 
#endif

