#include "../utility/Utility.h"
#include "../global/function/Function.h"
#include "../model/Shares.h"
#include "../model/output/SharesOutput.h"
#include "../view/Menu.h"

void retrieveShares(Shares** s){

    header();

    listRetrieveShares(*s);

    getchar();
}

void retrieveSpecificShares(Shares** s){

    header();

    Shares *shares = NULL;
    SharesOutput sharesOutput = searchDataShares(*s);
    
    shares = listSearchShares(*s, sharesOutput.signature);
    
    listRetrieveBuy(shares->buy);
    listRetrieveSell(shares->sell);

    getchar();
}

void clearVectorShares(char *str, int count){ 
    for(int i=0; i < count; i++){
        str[i] = '\0';
    }
}

void dataFileShares(Shares** s){

    char fileInit[512];

    SharesInput sharesInput;

    int counter;

    FILE *file = fopen("db/shares.txt", "r");

    if(file == NULL){
        printf(MESSAGE_ERROR);
        exit(1);
    }else{

        while(fgets(fileInit, 512, file) != NULL){
            counter = 0;
            clearVectorShares(sharesInput.name, 255);
            clearVectorShares(sharesInput.sector, 50);
            clearVectorShares(sharesInput.signature, 10);

            for(int i = 0, j = 0; i < strlen(fileInit); i++){
                if(fileInit[i] != ':'){
                    sharesInput.name[j] = fileInit[i];
                    j++;
                    counter++;
                }else{
                    break;
                }
            }

            for(int i = counter+1, j = 0; i < strlen(fileInit); i++){
                if(fileInit[i] != ':'){
                    sharesInput.sector[j] = fileInit[i];
                    j++;
                    counter++;
                }else{
                    break;
                }
            }
            for(int i = counter+2, j = 0; i < strlen(fileInit); i++, j++){
                sharesInput.signature[j] = fileInit[i];
            }

            removeSpace(sharesInput.signature);

            *s = listInsertShares(*s, sharesInput);
        }

    }


    fclose(file);
}

