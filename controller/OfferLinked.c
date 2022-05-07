#include "../utility/utility.h"
#include "../model/Offer.h"

Offer* listCreate(void){ return NULL; }

Offer* listInsert(Offer* l, int t, char *sg, int q, int v){ 

    Offer* new = (Offer*) malloc(sizeof(Offer));
    new->flag = Active;
    new->type = t;
    strcpy(new->signature, sg);
    new->quantity = q;
    new->value = v;
    new->next = l;
    return new;
}

void listUpdate(Offer** l,  int t, char *sg, int q, int v){ 

    Offer* new = (Offer*) malloc(sizeof(Offer));
    new->type = t;
    strcpy(new->signature, sg);
    new->quantity = q;
    new->value = v;
    new->next = *l;
    *l = new;
}

void listRetrieve(Offer* l){

    Offer* p;

    for(p = l; p != NULL; p = p->next) printf("%s = %d : %d\n", p->signature, p->value, p->quantity);

}

int listEmpty(Offer* l){ return (l == NULL); }

Offer* listSearch(Offer* l, int v){
    Offer* p;
    for(p = l; p != NULL; p = p->next){
        if(p->value == v) return p;
    }
    return NULL;
}

Offer* listDelete(Offer* l, int v){

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

void listRelease(Offer *l){

    Offer* p = l;

    while(p != NULL){
        Offer* t = p->next;
        free(p);
        p = t;
    }
}

Offer* listInsertSorted(Offer* l, int v){

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