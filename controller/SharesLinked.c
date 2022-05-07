#include "../utility/utility.h"
#include "../model/Shares.h"
#include "../model/Buy.h"
#include "../model/Sell.h"

Shares* listCreate(void){ return NULL; }

Shares* listInsert(Shares* l, char *sg, Buy* b, Sell* s){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active;
    strcpy(new->signature, sg);
    new->buy = b;
    new->sell = s;
    new->next = l;
    return new;
}

void listUpdate(Shares** l, char *sg, Buy* b, Sell* s){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active;
    strcpy(new->signature, sg);
    new->buy = b;
    new->sell = s;
    new->next = *l;
    *l = new;
}

void listRetrieve(Shares* l){

    Shares* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d\n", p->signature);

}

int listEmpty(Shares* l){ return (l == NULL); }

Shares* listSearch(Shares* l, char *sg){
    Shares* p;
    for(p = l; p != NULL; p = p->next){
        if(strcmp(p->signature, sg)) return p;
    }
    return NULL;
}

Shares* listDelete(Shares* l, char *sg){

    Shares* ant = NULL;
    Shares* p = l;

    while(p != NULL && strcmp(p->signature, sg) != 1){
        ant = p;
        p = p->next;
    }

    if(p == NULL) return l;

    if(ant == NULL) l = p->next;
    else ant->next = p->next;

    free(p);
    return l;
}

void listRelease(Shares *l){

    Shares* p = l;

    while(p != NULL){
        Shares* t = p->next;
        free(p);
        p = t;
    }
}