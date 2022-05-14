#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
#include "../model/output/SharesOutput.h"
#include "../global/function/Function.h"
#include "../global/validation/Validation.h"
#include "SharesView.h"
#include "Menu.h"

SharesOutput searchDataShares(Shares* s){

  SharesOutput data;
  Shares* dataSharesSearch = listCreateShares();

  do{
    
    printf("Informe ação que deseja: ");
    fgets(data.signature, MAX_SIG, stdin);
    removeBreakLine(data.signature);
    
    textToUpper(data.signature);

    dataSharesSearch = listSearchShares(s, data.signature);

    if(dataSharesSearch == NULL) printf("Informe codigo da ação válido!\n");
    else printf("\nO papel %s, foi selecionado com sucesso!\n\n", dataSharesSearch->name);
    
  }while(dataSharesSearch == NULL);      

  return data;
}

void mainShares(Offer *offers, Shares *shares){

  int option;

  setlocale(LC_ALL, "Portuguese");
  
  do{

    header();
    
    printf("1. Listar ações;\n"); 
    printf("2. Detalhar ação;\n"); 
    printf("3. Voltar ao menu principal;\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  retrieveShares(&shares);break;
      case 2:  retrieveSpecificShares(&shares);break;
      case 3:  break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 3);

}