#include "../utility/Utility.h"
#include "../model/Sell.h"

Sell* listCreateSell(void){ return NULL; }

Sell* listInsertSell(Sell* l, int q, float v){ 

    Sell* new = (Sell*) malloc(sizeof(Sell));
    new->flag = Active_;
    new->quantity = q;
    new->value = v;
    new->next = l;
    return new;
}

void listUpdateSell(Sell** l,  int q, float v){ 

    Sell* new = (Sell*) malloc(sizeof(Sell));
    new->quantity = q;
    new->value = v;
    new->next = *l;
    *l = new;
}

void listRetrieveSell(Sell* l){

    Sell* p;

    if(l != NULL) printf("\nOfertas de venda em aberto:\n\n");
    else printf("\nNão contém ofertas de venda para esta ação!\n\n");
    for(p = l; p != NULL; p = p->next) printf("R$ %.2f | %03d\n", p->value, p->quantity);

}

int listEmptySell(Sell* l){ return (l == NULL); }

Sell* listSearchSell(Sell* l, float v){
    Sell* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

float listSearchTopSell(Sell* l){
    Sell* p = NULL;
    float value = 0;

    for(p = l; p != NULL; p = p->next){
        value = p->value;
        break;
    }
        
    return value;
}

Sell* listDeleteSell(Sell* l, float v){

    Sell* ant = NULL;
    Sell* p = l;

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

void listReleaseSell(Sell *l){

    Sell* p = l;

    while(p != NULL){
        Sell* t = p->next;
        free(p);
        p = t;
    }
}

Sell* listInsertSortedSell(Sell* l, int q, float v){

    Sell* new;
    Sell* ant = NULL;
    Sell* p = l;


    while(p != NULL && p->value < v){
        ant = p;
        p = p->next;
    }

    new = (Sell*) malloc(sizeof(Sell));
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