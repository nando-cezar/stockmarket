#ifndef SHARES_H // include guard

    #define SHARES_H

    typedef struct detailsShares {

        int flag;
        char signature[10];
        struct detailsBuy *buy;
        struct detailsSell *sell;
        struct detailsShares *next;

    } Shares;

    Shares* listCreate(void);
    Shares* listInsert(Shares* l, char *sg, Buy* b, Sell* s);
    void listUpdate(Shares** l, char *sg, Buy* b, Sell* s);
    void listRetrieve(Shares* l);
    int listEmpty(Shares* l);
    Shares* listSearch(Shares* l, char *sg);
    Shares* listDelete(Shares* l, char *sg);
    void listRelease(Shares *l);
 
#endif

