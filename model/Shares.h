#ifndef SHARES_H // include guard

    #define SHARES_H

    #include "Buy.h"
    #include "Sell.h"
    #include "../utility/Utility.h"
    
    typedef struct detailsShares {

        typeStatus flag;
        char name[255];
        char sector[50];
        char signature[10];
        struct detailsBuy *buy;
        struct detailsSell *sell;
        struct detailsShares *next;

    } Shares;

    Shares* listCreateShares(void);
    Shares* listInsertShares(Shares* l, char*n, char* st, char *sg, Buy* b, Sell* s);
    void listUpdateShares(Shares** l, char*n, char* st, char *sg, Buy* b, Sell* s);
    void listRetrieveShares(Shares* l);
    int listEmptyShares(Shares* l);
    Shares* listSearchShares(Shares* l, char *sg);
    Shares* listDeleteShares(Shares* l, char *sg);
    void listReleaseShares(Shares *l);
 
#endif

