#include "../utility/Utility.h"
#include "../global/function/Function.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
#include "../model/input/OfferInput.h"
#include "../view/Menu.h"

void insertOffer(Offer** l, Shares** s){

    header();

    OfferInput offerInput = insertDataOffer(*s);

    *l = listInsertOffer(*l, offerInput);

    getchar();
}

void retrieveOffer(Offer** l){

    header();

    listRetrieveOffer(*l);

    getchar();
}

void clearVectorOffer(char *str, int count){ 
    for(int i=0; i < count; i++){
        str[i] = '\0';
    }
}

void dataFileOffer(Offer** l, Shares** s){

    char fileInit[512];

    OfferInput offerInput;

    int counter;

    FILE *file = fopen("db/offer.txt", "r");

    if(file == NULL){
        printf(MESSAGE_ERROR);
        exit(1);
    }else{

        while(fgets(fileInit, 512, file) != NULL){
            
            counter = 0;
            clearVectorOffer(offerInput.signature, 10);
            offerInput.type = Null_;
            offerInput.quantity = 0;
            offerInput.value = 0;

            for(int i = 0, j = 0; i < strlen(fileInit); i++){
                if(fileInit[i] != ':'){  
                    offerInput.signature[j] = fileInit[i];
                    j++;
                    counter++;
                }else{
                    break;
                }
            }

            for(int i = counter+1; i < strlen(fileInit); i++){ 
                if(fileInit[i] != ':'){
                    counter++;
                    offerInput.type = pow(fileInit[i] - '0', 1);
                }else{
                    break;
                }
            }

            for(int i = counter+2, n = 0, w = counter+2; i < strlen(fileInit); i++){ 
                if(fileInit[i] != ':'){
                    counter++;
                    n++;
                }else{
                    for(int j = n; j > 0; j--){
                        if(fileInit[w] - '0' > 0){
                            offerInput.quantity += ((fileInit[w] - '0') * (int)(pow(10, j-1) + 0.5));
                            w++;
                        }
                    }
                    break;
                }
            }

            int n = 0, w = counter+3;

            for(int i = counter+3; i < strlen(fileInit)-1; i++){
                if(fileInit[i] != ':'){
                    counter++;
                    n++;
                }else{
                    break;
                }
            }

            for(int j = n; j > 0; j--){
                if(fileInit[w] - '0' > 0){
                    offerInput.value += ((fileInit[w] - '0') * (int)(pow(10, j-1) + 0.5));
                    w++;
                }
            }

            removeSpace(offerInput.signature);

            *l = listInsertOffer(*l, offerInput);

            if(offerInput.type == Buy_){
                listSearchShares(*s, offerInput.signature)->buy = listInsertBuy((*s)->buy, offerInput.quantity, offerInput.value);
                /*printf("--> TESTE BUY\n");
                listRetrieveBuy(listSearchShares(*s, offerInput.signature)->buy);*/
            }else{
                listSearchShares(*s, offerInput.signature)->sell = listInsertSell((*s)->sell, offerInput.quantity, offerInput.value);
                /*printf("--> TESTE SELL\n");
                listRetrieveSell(listSearchShares(*s, offerInput.signature)->sell);*/
            }
            
            /*getchar();
            getchar();*/
            
        }

    }

    fclose(file);
}

