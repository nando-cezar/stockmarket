#include "../utility/Utility.h"
#include "../global/function/Function.h"
#include "../global/validation/Validation.h"
#include "../model/Date.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
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

    Offer* offer = *l;
    Offer* dataOfferSearch = listCreateOffer();
    int verification;

    Date date;
    char signature[10];
    char op;

    header();
    
    int alt = filterSharesSearch();

    switch(alt){
        case 1: 
            do{     
                printf("Informe data (dd mm yyyy): ");
                scanf("%d %d %d", &date.day, &date.month, &date.year);
                getchar();
                verification = validateDate(date);
                if(!verification) printf("\nInforme data válida!\n");
            }while(!verification);
            listRetrieveOfferPerDate(offer, date.day, date.month, date.year);
            break;
        case 2: 
            do{
                printf("Informe a sigla: ");
                fgets(signature, MAX_SIG, stdin);
                removeBreakLine(signature);
                textToUpper(signature);
                dataOfferSearch = listSearchOffer(*l, signature);
                if(dataOfferSearch == NULL) printf("Informe codigo da ação válido ou não existe oferta para ação selecionada!\n");
            }while(dataOfferSearch == NULL);
            listRetrieveOfferPerSignature(offer, signature); 
            break;
        case 3: 
            do{
                printf("Informe o tipo: ");
                scanf(" %c", &op);
                getchar();
                op = toupper(op);
                verification = validateOperation(op);

                if(!verification) printf("\nInforme tipo de operação válida!\n");
            }while(!verification);
            listRetrieveOfferPerType(offer, op); 
            break;
        case 4: 
            listRetrieveOffer(*l); 
            break;
        default: 
            printf("Entrada inválida!");
            break;
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
    
    Sell* dataSell = NULL;
    Buy* dataBuy = NULL;
    Shares* sh = listCreateShares();
    sh = listSearchShares(s, data->signature);

    if(data->type == Buy_){
    
        float ts = listSearchTopSell(sh->sell);

        dataSell = listSearchSell(sh->sell, data->value);
        
        if(dataSell != NULL){
            //printf("Buy 1: %2.f\n", ts);
            sh->price = data->value;
            if(dataSell->quantity == data->quantity){ 
                sh->sell = listDeleteSell(sh->sell, data->value);
                printOfferES(data->value, ts, sh->price); 
            }else if(dataSell->quantity >= data->quantity){     
                dataSell->quantity -= data->quantity;
                sh->sell = listDeleteSell(sh->sell, data->value);
                sh->sell = listInsertSortedSell(sh->sell, dataSell->quantity, data->value);
                printOfferES(data->value, ts, sh->price); 
            }else{
                data->quantity -= dataSell->quantity;
                //sh->sell->quantity;
                //printf("listDeleteSell\n");
                sh->sell = listDeleteSell(sh->sell, data->value);
                sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
                printOfferES(data->value, ts, sh->price); 
            }
        }else if(ts < data->value && ts != 0){
            
            do{

                sh->price = (ts + data->value) / 2;

                dataSell = listSearchSell(sh->sell, ts);

                if(dataSell->quantity == data->quantity){      
                    data->quantity -= dataSell->quantity;
                    sh->sell = listDeleteSell(sh->sell, ts); 
                    printOfferES(data->value, ts, sh->price);           
                
                }else if(dataSell->quantity >= data->quantity){
                    
                    dataSell->quantity -= data->quantity;
                    sh->sell = listDeleteSell(sh->sell, data->value);
                    sh->sell = listInsertSortedSell(sh->sell, dataSell->quantity, data->value);
                    printOfferES(data->value, ts, sh->price); 
                    break;
                }else{
                    data->quantity -= dataSell->quantity;
                    //sh->sell->quantity;
                    //printf("listDeleteSell: %2.f\n", data->value);
                    sh->sell = listDeleteSell(sh->sell, ts);
                    printOfferES(data->value, ts, sh->price); 
                }

                ts = listSearchTopSell(sh->sell);
                
            }while(ts < data->value);

            if(data->quantity > 0) 
                sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
            
        }else{
            //printf("listInsertSortedBuy: %2.f\n", ts);
            sh->buy = listInsertSortedBuy(sh->buy, data->quantity, data->value);
            printOfferNO(data->value); 
        }

    }else{
        /* Copiar logica acima de forma inversa */
        float tb = listSearchTopBuy(sh->buy);

        dataBuy = listSearchBuy(sh->buy, data->value);

        if(dataBuy != NULL){
            //printf("Sell 1: %2.f\n", tb);
            sh->price = data->value;
            if(dataBuy->quantity == data->quantity){
                sh->buy = listDeleteBuy(sh->buy, data->value); 
                printOfferES(data->value, tb, sh->price); 
            }else if(dataBuy->quantity >= data->quantity){
                dataBuy->quantity -= data->quantity;
                sh->buy = listDeleteBuy(sh->buy, data->value);
                sh->buy = listInsertSortedBuy(sh->buy, dataBuy->quantity, data->value);
                printOfferES(data->value, tb, sh->price); 
            }else{
                data->quantity -= dataBuy->quantity;
                //sh->buy->quantity;
                //printf("listDeleteBuy\n");
                sh->buy = listDeleteBuy(sh->buy, data->value);
                sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
                printOfferES(data->value, tb, sh->price); 
            }
        }else if(tb > data->value && tb != 0){
            
            sh->price = (tb + data->value) / 2;
            dataBuy = listSearchBuy(sh->buy, tb);

            if(dataBuy->quantity == data->quantity){           
                sh->buy = listDeleteBuy(sh->buy, data->value); 
                printOfferES(data->value, tb, sh->price); 
            }else if(dataBuy->quantity >= data->quantity){    
                dataBuy->quantity -= data->quantity;
                sh->buy = listDeleteBuy(sh->buy, data->value);
                //sh->buy = listInsertSortedBuy(sh->buy, dataBuy->quantity, data->value);
                printOfferES(data->value, tb, sh->price); 
            }else{
                data->quantity -= dataBuy->quantity;
                //sh->buy->quantity;
                //printf("listDeleteBuy\n");
                sh->buy = listDeleteBuy(sh->buy, tb);
                sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
                printOfferES(data->value, tb, sh->price); 
            }
                
        }else{
            //printf("listInsertSortedSell: %2.f\n", tb);
            sh->sell = listInsertSortedSell(sh->sell, data->quantity, data->value);
            printOfferNO(data->value); 
        } 
    }
}

void clearVectorOffer(char *str, int count){ 
    for(int i = 0; i < count; i++){
        str[i] = '\0';
    }
}
