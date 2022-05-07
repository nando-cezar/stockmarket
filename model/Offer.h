#ifndef OFFER_H // include guard

    #define OFFER_H

    typedef struct detailsOffer {

        int flag;
        int type;
        int quantity;
        float value;
        char signature[10];
        struct detailsOffer *next;

    } Offer;

    /* Controller */
    Offer* listCreateOffer(void);
    Offer* listInsertOffer(Offer* l, int t, char *sg, int q, int v);
    void listUpdateOffer(Offer** l,  int t, char *sg, int q, int v);
    void listRetrieveOffer(Offer* l);
    int listEmptyOffer(Offer* l);
    Offer* listSearchOffer(Offer* l, int v);
    Offer* listDeleteOffer(Offer* l, int v);
    void listReleaseOffer(Offer *l);
    Offer* listInsertSortedOffer(Offer* l, int v);

    /* Service */
    void insertOffer(Offer** l);
    void retrieveOffer(Offer** l);
 
#endif