#ifndef SELL_H // include guard

    #define SELL_H

    #include "../utility/Utility.h"
    
    typedef struct detailsSell {

        typeStatus flag;
        int quantity;
        float value;
        struct detailsSell *next;

    } Sell;

    /* Controller */
    Sell* listCreateSell(void);
    Sell* listInsertSell(Sell* l, int q, float v);
    void listUpdateSell(Sell** l, int q, float v);
    void listRetrieveSell(Sell* l);
    int listEmptySell(Sell* l);
    Sell* listSearchSell(Sell* l, int v);
    Sell* listDeleteSell(Sell* l, int v);
    void listReleaseSell(Sell *l);
    Sell* listInsertSortedSell(Sell* l, int q, float v);
 
#endif