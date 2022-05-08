#include "../utility/utility.h"
#include "../model/Shares.h"
#include "../model/Buy.h"
#include "../model/Sell.h"

Shares* listCreateShares(void){ return NULL; }

Shares* listInsertShares(Shares* l, char*n, char* st, char *sg, Buy* b, Sell* s){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active_;
    strcpy(new->signature, sg);
    new->buy = b;
    new->sell = s;
    new->next = l;
    return new;
}

void listUpdateShares(Shares** l, char*n, char* st, char *sg, Buy* b, Sell* s){ 

    Shares* new = (Shares*) malloc(sizeof(Shares));
    new->flag = Active_;
    strcpy(new->signature, sg);
    new->buy = b;
    new->sell = s;
    new->next = *l;
    *l = new;
}

void listRetrieveShares(Shares* l){

    Shares* p;

    for(p = l; p != NULL; p = p->next) printf("info = %d\n", p->signature);

}

int listEmptyShares(Shares* l){ return (l == NULL); }

Shares* listSearchShares(Shares* l, char *sg){
    Shares* p;
    for(p = l; p != NULL; p = p->next){
        if(strcmp(p->signature, sg)) return p;
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

/*void dataFile(){

    int name[255];
    int sector[50];

    FILE *file = fopen("db/shares.txt", "r");

    if(file == NULL){
        printf(MESSAGE_ERROR);
        exit(1);
    }else{

        while(!feof(file)){
            fscanf(file, "%s :%s", name, sector);
            printf("%s - %s", name, sector);
        }
    }

    fclose(file);
}*/