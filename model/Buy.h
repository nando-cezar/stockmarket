#ifndef BUY_H // include guard

    #define BUY_H

    #include "../utility/Utility.h"
    
    typedef struct detailsBuy {

        typeStatus flag;
        int quantity;
        float value;
        struct detailsBuy *next;

    } Buy;

    Buy* listCreateBuy(void);
    Buy* listInsertBuy(Buy* l, int q, int v);
    void listUpdateBuy(Buy** l, int q, int v);
    void listRetrieveBuy(Buy* l);
    int listEmptyBuy(Buy* l);
    Buy* listSearchBuy(Buy* l, int v);
    Buy* listDeleteBuy(Buy* l, int v);
    void listReleaseBuy(Buy *l);
    Buy* listInsertSorted(Buy* l, int v);
 
#endif