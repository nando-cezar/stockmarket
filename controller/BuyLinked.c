#include "../utility/utility.h"
#include "../model/Buy.h"

Buy* listCreate(void){ return NULL; }

Buy* listInsert(Buy* l, int q, int v){ 

    Buy* new = (Buy*) malloc(sizeof(Buy));
    new->flag = Active;
    new->quantity = q;
    new->value = v;
    new->next = l;
    return new;
}

void listUpdate(Buy** l,  int q, int v){ 

    Buy* new = (Buy*) malloc(sizeof(Buy));
    new->quantity = q;
    new->value = v;
    new->next = *l;
    *l = new;
}

void listRetrieve(Buy* l){

    Buy* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d : %d\n", p->value, p->quantity);

}

int listEmpty(Buy* l){ return (l == NULL); }

Buy* listSearch(Buy* l, int v){
    Buy* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

Buy* listDelete(Buy* l, int v){

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

void listRelease(Buy *l){

    Buy* p = l;

    while(p != NULL){
        Buy* t = p->next;
        free(p);
        p = t;
    }
}

Buy* listInsertSorted(Buy* l, int v){

    Buy* new;
    Buy* ant = NULL;
    Buy* p = l;


    while(p != NULL && p->value < v){
        ant = p;
        p = p->next;
    }

    new = (Buy*) malloc(sizeof(Buy));
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