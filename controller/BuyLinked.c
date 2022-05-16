#include "../utility/Utility.h"
#include "../model/Buy.h"

Buy* listCreateBuy(void){ return NULL; }

Buy* listInsertBuy(Buy* l, int q, float v){ 

    Buy* new = (Buy*) malloc(sizeof(Buy));
    new->flag = Active_;
    new->quantity = q;
    new->value = v;
    new->next = l;
    return new;
}

void listUpdateBuy(Buy** l,  int q, float v){ 

    Buy* new = (Buy*) malloc(sizeof(Buy));
    new->quantity = q;
    new->value = v;
    new->next = *l;
    *l = new;
}

void listRetrieveBuy(Buy* l){

    Buy* p;
    
    if(l != NULL) printf("\nOfertas de compra em aberto:\n\n");
    else printf("\nNão contém ofertas de compra para esta ação!\n\n");
    for(p = l; p != NULL; p = p->next) printf("R$ %.2f | %03d\n", p->value, p->quantity);

}

int listEmptyBuy(Buy* l){ return (l == NULL); }

Buy* listSearchBuy(Buy* l, float v){
    Buy* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

float listSearchTopBuy(Buy* l){
    Buy* p = NULL;
    float value = 0;

    for(p = l; p != NULL; p = p->next){
        value = p->value;
        break;
    }

    return value;
}

Buy* listDeleteBuy(Buy* l, float v){

    Buy* ant = NULL;
    Buy* p = l;

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

void listReleaseBuy(Buy *l){

    Buy* p = l;

    while(p != NULL){
        Buy* t = p->next;
        free(p);
        p = t;
    }
}

Buy* listInsertSortedBuy(Buy* l, int q, float v){

    Buy* new;
    Buy* ant = NULL;
    Buy* p = l;


    while(p != NULL && p->value > v){
        ant = p;
        p = p->next;
    }

    new = (Buy*) malloc(sizeof(Buy));
    new->value = v;
    new->quantity = q;

    if(ant == NULL){

        new->next = l;
        l = new;

    }else{
        new->next = ant->next;
        ant->next = new;
    }
    return l;
}