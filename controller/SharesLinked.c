#include "../utility/Utility.h"
#include "../model/Shares.h"
#include "../model/Buy.h"
#include "../model/Sell.h"

Shares* listCreateShares(void){ return NULL; }

Shares* listInsertShares(Shares* l, SharesInput sharesInput){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active_;
    strcpy(new->name, sharesInput.name);
    strcpy(new->sector, sharesInput.sector);
    strcpy(new->signature, sharesInput.signature);
    new->buy = listCreateBuy();
    new->sell = listCreateSell();
    new->next = l;
    return new;
}

void listUpdateShares(Shares** l, SharesInput sharesInput){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active_;
    strcpy(new->name, sharesInput.name);
    strcpy(new->sector, sharesInput.sector);
    strcpy(new->signature, sharesInput.signature);
    new->buy = listCreateBuy();
    new->sell = listCreateSell();
    new->next = *l;
    *l = new;
}

void listRetrieveShares(Shares* l){

    Shares* p = NULL;
    Buy* b = NULL;
    Sell* s = NULL;
    
    for(p = l; p != NULL; p = p->next){
        printf("\nNome = %s\nSetor = %s\nSigla = %s\n", p->name, p->sector, p->signature);
        if(p->buy != NULL){
            printf("BUY\n");
            for(b = p->buy; b != NULL; b = b->next){
                printf("Quantidade: %d | Valor: %.2f\n", b->quantity, b->value);
                getchar();
            }
        }
        if(p->sell != NULL){
            printf("SELL\n");
            for(s = p->sell; s != NULL; s = s->next){
                printf("Quantidade: %d | Valor: %.2f\n", s->quantity, s->value);
                getchar();
            }
        }
        getchar();
    } 

}

int listEmptyShares(Shares* l){ return (l == NULL); }

Shares* listSearchShares(Shares* l, char *sg){
    Shares* p;
    for(p = l; p != NULL; p = p->next){
        if(strcmp(p->signature, sg) == 0) return p;
    }
    return NULL;
}

Shares* listDeleteShares(Shares* l, char *sg){

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

void listReleaseShares(Shares *l){

    Shares* p = l;

    while(p != NULL){
        Shares* t = p->next;
        free(p);
        p = t;
    }
}