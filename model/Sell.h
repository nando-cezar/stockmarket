#ifndef SELL_H // include guard

    #define SELL_H

    typedef struct detailsSell {

        int flag;
        float value;
        int quantity;
        struct detailsSell *next;

    } Sell;

    Sell* listCreate(void);
    Sell* listInsert(Sell* l, int q, int v);
    void listUpdate(Sell** l, int q, int v);
    void listRetrieve(Sell* l);
    int listEmpty(Sell* l);
    Sell* listSearch(Sell* l, int v);
    Sell* listDelete(Sell* l, int v);
    void listRelease(Sell *l);
    Sell* listInsertSorted(Sell* l, int v);
 
#endif