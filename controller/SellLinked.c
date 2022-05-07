#include "../utility/utility.h"
#include "../model/Sell.h"

Sell* listCreate(void){ return NULL; }

Sell* listInsert(Sell* l, int q, int v){ 

    Sell* new = (Sell*) malloc(sizeof(Sell));
    new->flag = Active;
    new->quantity = q;
    new->value = v;
    new->next = l;
    return new;
}

void listUpdate(Sell** l,  int q, int v){ 

    Sell* new = (Sell*) malloc(sizeof(Sell));
    new->quantity = q;
    new->value = v;
    new->next = *l;
    *l = new;
}

void listRetrieve(Sell* l){

    Sell* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d : %d\n", p->value, p->quantity);

}

int listEmpty(Sell* l){ return (l == NULL); }

Sell* listSearch(Sell* l, int v){
    Sell* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

Sell* listDelete(Sell* l, int v){

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

void listRelease(Sell *l){

    Sell* p = l;

    while(p != NULL){
        Sell* t = p->next;
        free(p);
        p = t;
    }
}

Sell* listInsertSorted(Sell* l, int v){

    Sell* new;
    Sell* ant = NULL;
    Sell* p = l;


    while(p != NULL && p->value < v){
        ant = p;
        p = p->next;
    }

    new = (Sell*) malloc(sizeof(Sell));
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