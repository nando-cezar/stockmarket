#include "../utility/Utility.h"
#include "../model/Offer.h"

Offer* listCreateOffer(void){ return NULL; }

Offer* listInsertOffer(Offer* l, OfferInput offerInput){ 

    time_t seconds;
    struct tm *p;
    Offer* new = (Offer*) malloc(sizeof(Offer));

    new->flag = Active_;
    new->type = offerInput.type;
    strcpy(new->signature, offerInput.signature);
    new->quantity = offerInput.quantity;
    new->value = offerInput.value;
    time(&seconds);
    p = localtime(&seconds);
    new->clock = p;
    new->next = l;

    return new;
}

void listUpdateOffer(Offer** l,  OfferInput offerInput){ 

    time_t seconds;
    struct tm *p;
    Offer* new = (Offer*) malloc(sizeof(Offer));

    new->type = offerInput.type;
    strcpy(new->signature, offerInput.signature);
    new->quantity = offerInput.quantity;
    new->value = offerInput.value;
    time(&seconds);
    p = localtime(&seconds);
    new->clock = p;

    new->next = *l;
    *l = new;
}

void listRetrieveOffer(Offer* l){

    Offer* p;

    printf("\n\tHISTORICO DE COMPRA\n\n");
    for(p = l; p != NULL; p = p->next)
        if(p->type == Buy_)
            printf(
                "| %s | %d | %d | %.2f | %d/%d/%d - %d:%d:%d\n", 
                p->signature, 
                p->type, 
                p->quantity, 
                p->value, 
                p->clock->tm_mday,
                p->clock->tm_mon+1,
                p->clock->tm_year+1900,
                p->clock->tm_hour,
                p->clock->tm_min,
                p->clock->tm_sec
            );

    printf("\n\tHISTORICO DE VENDA\n\n");
    for(p = l; p != NULL; p = p->next)
        if(p->type == Sell_)
            printf(
                "| %s | %d | %d | %.2f | %d/%d/%d - %d:%d:%d\n", 
                p->signature, 
                p->type, 
                p->quantity, 
                p->value, 
                p->clock->tm_mday,
                p->clock->tm_mon+1,
                p->clock->tm_year+1900,
                p->clock->tm_hour,
                p->clock->tm_min,
                p->clock->tm_sec
            );

}

int listEmptyOffer(Offer* l){ return (l == NULL); }

Offer* listSearchOffer(Offer* l, int v){
    Offer* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

Offer* listDeleteOffer(Offer* l, int v){

    Offer* ant = NULL;
    Offer* p = l;

    while(p != NULL && p->value != v){
        ant = p;
        p = p->next;
    }

    if(p == NULL) return l;

    if(ant == NULL) l = p->next;
    else ant->next = p->next;

    free(p);
    return l;
}

void listReleaseOffer(Offer *l){

    Offer* p = l;

    while(p != NULL){
        Offer* t = p->next;
        free(p);
        p = t;
    }
}

Offer* listInsertSortedOffer(Offer* l, int v){

    Offer* new;
    Offer* ant = NULL;
    Offer* p = l;


    while(p != NULL && p->value < v){
        ant = p;
        p = p->next;
    }

    new = (Offer*) malloc(sizeof(Offer));
    new->value = v;

    if(ant == NULL){

        new->next = l;
        l = new;

    }else{
        new->next = ant->next;
        ant->next = new;
    }
    return l;
}