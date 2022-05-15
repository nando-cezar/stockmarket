#include "../utility/Utility.h"
#include "../model/input/OfferInput.h"
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
    new->clock.tm_mday  = p->tm_mday;
    new->clock.tm_mon   = p->tm_mon;
    new->clock.tm_year  = p->tm_year;
    new->clock.tm_hour  = p->tm_hour;
    new->clock.tm_min   = p->tm_min;
    new->clock.tm_sec   = p->tm_sec;
    printf("%d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
    getchar();
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
    new->clock.tm_mday  = p->tm_mday;
    new->clock.tm_mon   = p->tm_mon;
    new->clock.tm_year  = p->tm_year;
    new->clock.tm_hour  = p->tm_hour;
    new->clock.tm_min   = p->tm_min;
    new->clock.tm_sec   = p->tm_sec;
    new->next = *l;
    *l = new;
}

void listRetrieveOffer(Offer* l){

    Offer* p;

    printf("\n* HISTORICO DE COMPRA\n\n");
    for(p = l; p != NULL; p = p->next)
        if(p->type == Buy_)
            printf(
                "> %s | %d | %03d | R$ %.2f | %02d/%02d/%d - %02d:%02d:%02d\n", 
                p->signature, 
                p->type, 
                p->quantity, 
                p->value, 
                p->clock.tm_mday,
                p->clock.tm_mon+1,
                p->clock.tm_year+1900,
                p->clock.tm_hour,
                p->clock.tm_min,
                p->clock.tm_sec
            );

    printf("\n* HISTORICO DE VENDA\n\n");
    for(p = l; p != NULL; p = p->next)
        if(p->type == Sell_)
            printf(
                "> %s | %d | %03d | R$ %.2f | %02d/%02d/%d - %02d:%02d:%02d\n", 
                p->signature, 
                p->type, 
                p->quantity, 
                p->value, 
                p->clock.tm_mday,
                p->clock.tm_mon+1,
                p->clock.tm_year+1900,
                p->clock.tm_hour,
                p->clock.tm_min,
                p->clock.tm_sec
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