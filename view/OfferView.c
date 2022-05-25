#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
#include "../model/input/OfferInput.h"
#include "../global/function/Function.h"
#include "../global/validation/Validation.h"
#include "OfferView.h"
#include "Menu.h"

OfferInput insertDataOffer(Shares* s){

  OfferInput data;
  Shares* dataSharesSearch = listCreateShares();
  char op;
  int verification;

  do{
    
    printf("Informe ação que deseja: ");
    fgets(data.signature, MAX_SIG, stdin);
    removeBreakLine(data.signature);
    
    textToUpper(data.signature);

    dataSharesSearch = listSearchShares(s, data.signature);

    if(dataSharesSearch == NULL) printf("Informe codigo da ação válido!\n");
    else printf("\nO papel %s, foi selecionado com sucesso!\n\n", dataSharesSearch->name);
 
  }while(dataSharesSearch == NULL);      

  do{

    printf("Informe tipo de operação (C. compra | V. venda): ");
    scanf(" %c", &op);
    getchar();
    
    verification = validateOperation(op);

    if(!verification) printf("\nInforme tipo de operação válida!\n");
    else data.type = toupper(op);

    if(data.type == 'C') data.type = Buy_;
    else data.type = Sell_;
    
  }while(!verification);
  
  printf("Informe quantidade (#..): ");
  data.quantity = validateInteger("Informe uma quantidade válida!\nInforme quantidade: ");
  getchar();

  printf("Informe valor (##..,##): ");
  data.value = validateFloat("Informe um valor válido!\nInforme valor: ");
  getchar();

  return data;
}

int filterSharesSearch(){

  int alt = 0;

  printf("Informe qual opção de filtro.\n\n1 - Data\n2 - Sigla\n3 - Tipo(Compra/Venda)\n4 - Sem filtro\n\nSelecione: ");
  scanf("%d", &alt);
  getchar();
  
  return alt;
}

void mainOffer(Offer **offers, Shares **shares){

  int option;

  setlocale(LC_ALL, "Portuguese");
  
  do{

    header();
    
    printf("1. Inserir oferta;\n"); 
    printf("2. Listar histórico de ofertas;\n"); 
    printf("3. Voltar ao menu principal;\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  insertOffer(offers, shares);break;
      case 2:  retrieveOffer(offers);break;
      case 3:  break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 3);

}