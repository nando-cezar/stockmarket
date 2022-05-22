#include "../utility/Utility.h"
#include "../global/function/Function.h"
#include "../model/Offer.h"
#include "../model/input/OfferInput.h"
#include "../model/output/OfferOutput.h"
#include "../view/Menu.h"

void calculate(OfferInput *data, Shares *s);
void clearVectorOffer(char *str, int count);

void insertOffer(Offer** l, Shares** s){

    header();

    OfferInput offerInput = insertDataOffer(*s);

    *l = listInsertOffer(*l, offerInput);

    calculate(&offerInput, *s);

    getchar();
}

void retrieveOffer(Offer** l){

    Offer* offer = NULL;
    int alt = 0;

    header();
    
    alt = filterSharesSearch();

    switch(alt){
        case 1: 
            offer = *l;
            int d, m, y;
            printf("Informe data (dd mm yyyy): ");
            scanf("%d %d %d", &d, &m, &y);
            getchar();
            listRetrieveOfferPerDate(offer, d, m, y);
        break;
        case 2: 
            offer = *l;
            char signature[10];
            printf("Informe a sigla: ");
            fgets(signature, MAX_SIG, stdin);
            removeBreakLine(signature);
            textToUpper(signature);
            listRetrieveOfferPerSignature(offer, signature); 
        break;
        case 3: 
            offer = *l;
            char op;
            printf("Informe o tipo: ");
            scanf(" %c", &op);
            getchar();
            op = toupper(op);
            listRetrieveOfferPerType(offer, op); 
        break;
        case 4: listRetrieveOffer(*l); break;
        default: break;
    }
    

    getchar();
}

void dataFileOffer(Offer** l, Shares** s){

    char fileInit[512];

    OfferInput offerInput;
    Shares *sh;
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
            sh = NULL;

            if(offerInput.type == Buy_){
                sh = listSearchShares(*s, offerInput.signature);
                if(sh != NULL) sh->buy = listInsertSortedBuy(sh->buy, offerInput.quantity, offerInput.value);
                
            }else{
                sh = listSearchShares(*s, offerInput.signature);
                if(sh != NULL) sh->sell = listInsertSortedSell(sh->sell, offerInput.quantity, offerInput.value);
            }            
        }
        
        sh->buy->next = NULL;
        sh->sell->next = NULL;
        free(sh);

    }

    fclose(file);
}

/* refatorar calculate */
void calculate(OfferInput *data, Shares *s){

    Shares* sh = listCreateShares();
    sh = listSearchShares(s, data->signature);

    if(data->type == Buy_){
    
        float ts = listSearchTopSell(sh->sell);

        if(listSearchSell(sh->sell, data->value) != NULL){
            //printf("Buy 1: %2.f\n", ts);
            sh->price = data->value;
            if(sh->sell->quantity == data->quantity){      
                sh->sell = listDeleteSell(sh->sell, data->value); 
            }else if(sh->sell->quantity >= data->quantity){     
                sh->sell->quantity -= data->quantity;
            }else{
                data->quantity -= sh->sell->quantity;
                //printf("listDeleteSell\n");
                sh->sell = listDeleteSell(sh->sell, data->value);
                sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
            }
        }else if( ts < data->value && ts != 0){
            //printf("Buy 2: %2.f\n", ts);
            sh->price = (ts + data->value) / 2;
            //if(listSearchSell(sh->sell, ts) != NULL){
                if(sh->sell->quantity == data->quantity){      
                    sh->sell = listDeleteSell(sh->sell, data->value); 
                }else if(sh->sell->quantity >= data->quantity){     
                    sh->sell->quantity -= data->quantity;
                }else{
                    data->quantity -= sh->sell->quantity;
                    //printf("listDeleteSell: %2.f\n", data->value);
                    sh->sell = listDeleteSell(sh->sell, ts);
                    sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
                }
            //}
        }else{
            //printf("listInsertSortedBuy: %2.f\n", ts);
            sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
        }

    }else{

        float tb = listSearchTopBuy(sh->buy);

        if(listSearchBuy(sh->buy, data->value) != NULL){
            //printf("Sell 1: %2.f\n", tb);
            sh->price = data->value;
            if(sh->buy->quantity == data->quantity){
                sh->buy = listDeleteBuy(sh->buy, data->value); 
            }else if(sh->buy->quantity >= data->quantity){
                sh->buy->quantity -= data->quantity;
            }else{
                data->quantity -= sh->buy->quantity;
                //printf("listDeleteBuy\n");
                sh->buy = listDeleteBuy(sh->buy, data->value);
                sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
            }
        }else if(tb > data->value && tb != 0){
            printf("Sell 2: %2.f\n", tb);
            sh->price = (tb + data->value) / 2;
            //if(listSearchBuy(sh->buy, tb) != NULL){     
                if(sh->buy->quantity == data->quantity){           
                    sh->buy = listDeleteBuy(sh->buy, data->value); 
                }else if(sh->buy->quantity >= data->quantity){     
                    sh->buy->quantity -= data->quantity;
                }else{
                    data->quantity -= sh->buy->quantity;
                    //printf("listDeleteBuy\n");
                    sh->buy = listDeleteBuy(sh->buy, tb);
                    sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
                }
            //}
        }else{
            //printf("listInsertSortedSell: %2.f\n", tb);
            sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
        } 
    }
}

void clearVectorOffer(char *str, int count){ 
    for(int i = 0; i < count; i++){
        str[i] = '\0';
    }
}
