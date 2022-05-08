#include "../utility/utility.h"
#include "../model/Offer.h"

Offer* listCreateOffer(void){ return NULL; }

Offer* listInsertOffer(Offer* l, OfferInput offerInput){ 

    Offer* new = (Offer*) malloc(sizeof(Offer));
    new->flag = Active_;
    new->type = offerInput.type;
    strcpy(new->signature, offerInput.signature);
    new->quantity = offerInput.quantity;
    new->value = offerInput.value;
    new->next = l;
    return new;
}

void listUpdateOffer(Offer** l,  OfferInput offerInput){ 

    Offer* new = (Offer*) malloc(sizeof(Offer));
    new->type = offerInput.type;
    strcpy(new->signature, offerInput.signature);
    new->quantity = offerInput.quantity;
    new->value = offerInput.value;
    new->next = *l;
    *l = new;
}

void listRetrieveOffer(Offer* l){

    Offer* p;

    for(p = l; p != NULL; p = p->next) printf("%s = %.2f : %d\n", p->signature, p->value, p->quantity);

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

void dataFile(){

    char fileInit[500];

    char fullName[255];
    char sector[50];
    char signature[10];

    int count;

    FILE *file = fopen("db/shares.txt", "r");

    if(file == NULL){
        printf(MESSAGE_ERROR);
        exit(1);
    }else{

        while(fgets(fileInit, 255, file) != NULL){
            count = 0;
            //printf(">> %s", fileInit);
            printf("\n");
            for(int i = 0; i < strlen(fileInit); i++){
                if(fileInit[i] != ':'){
                    fullName[i] = fileInit[i];
                    printf("%c", fullName[i]);
                    count++;
                }else{
                    break;
                }
            }
            printf("\n");
            for(int i = count+1; i < strlen(fileInit); i++){
                if(fileInit[i] != ':'){
                    sector[i] = fileInit[i];
                    printf("%c", sector[i]);
                    count++;
                }else{
                    break;
                }
            }
            printf("\n");
            for(int i = count+2; i < strlen(fileInit); i++){
                signature[i] = fileInit[i];
                printf("%c", signature[i]);
            }
        }
    }


    fclose(file);
}