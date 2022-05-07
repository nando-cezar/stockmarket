#ifndef BUY_H // include guard

    #define BUY_H

    typedef struct detailsBuy {

        int flag;
        float value;
        int quantity;
        struct detailsBuy *next;

    } Buy;

    Buy* listCreate(void);
    Buy* listInsert(Buy* l, int q, int v);
    void listUpdate(Buy** l, int q, int v);
    void listRetrieve(Buy* l);
    int listEmpty(Buy* l);
    Buy* listSearch(Buy* l, int v);
    Buy* listDelete(Buy* l, int v);
    void listRelease(Buy *l);
    Buy* listInsertSorted(Buy* l, int v);
 
#endif