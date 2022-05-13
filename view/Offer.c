#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
#include "../model/input/OfferInput.h"
#include "../global/function/Function.h"
#include "../global/validation/Validation.h"
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

    s = listSearchShares(s, data.signature);
    dataSharesSearch = s;

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

  if(data.type == Buy_){
    printf("listSearchSell\n");
    if(listSearchSell(s->sell, data.value) != NULL){
      if(s->sell->quantity == data.quantity){
        printf("listDeleteSell\n");
        s->sell = listDeleteSell(s->sell, data.value); 
      }else if(s->sell->quantity >= data.quantity){
        s->sell->quantity -= data.quantity;
      }
    }else{
      printf("listInsertSortedBuy\n");
      s->buy = listInsertSortedBuy(s->buy, data.quantity, data.value);
    }
  }else{
    printf("listSearchBuy\n");
    if(listSearchBuy(s->buy, data.value) != NULL){
      if(s->buy->quantity == data.quantity){
        printf("listDeleteBuy\n");
        s->buy = listDeleteBuy(s->buy, data.value); 
      }else if(s->buy->quantity >= data.quantity){
        s->buy->quantity -= data.quantity;
      }
    }else{
      printf("listInsertSortedSell\n");
      s->sell = listInsertSortedSell(s->sell, data.quantity, data.value);
    } 
  } 

  return data;
}

void mainOffer(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  Shares* shares = listCreateShares();
  Offer* offers = listCreateOffer();

  dataFileShares(&shares);
  dataFileOffer(&offers, &shares);
  
  listRetrieveShares(shares);
  
  do{

    header();
    
    printf("1. Inserir oferta;\n"); 
    printf("2. Listar oferta especifica;\n"); 
    printf("3. Listar todas as ofertas;\n"); 
    printf("4. Efetuar operação;\n"); 
    //printf("5. Listar operações concluídas;\n"); 
    printf("6. Sair;\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  insertOffer(&offers, &shares); break;
      case 2:  listRetrieveShares(shares);break;
      case 3:  retrieveOffer(&offers);break;
      case 4:  break;
      case 5:  break;
      case 6:  break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 6);

}