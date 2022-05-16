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

  /* Efetuar abstração para calculo */
  /*float a = listSearchTopSell(s->sell);
    float b = listSearchTopBuy(s->buy);
    if(a < b){
      s->price = (a + b) / 2; // cotação
      printf("%.2f", data.value);
      getchar();
    } */
  if(data.type == Buy_){
    
    float ts = listSearchTopSell(s->sell);

    if(listSearchSell(s->sell, data.value) != NULL){
      printf("Buy 1\n");
      s->price = data.value;
      if(s->sell->quantity == data.quantity){      
        s->sell = listDeleteSell(s->sell, data.value); 
      }else if(s->sell->quantity >= data.quantity){     
        s->sell->quantity -= data.quantity;
      }
    }else if(ts < data.value && ts != 0){
      printf("Buy 2\n");
      s->price = (ts + data.value) / 2;
      if(listSearchSell(s->sell, ts) != NULL){
        if(s->sell->quantity == data.quantity){      
          s->sell = listDeleteSell(s->sell, data.value); 
        }else if(s->sell->quantity >= data.quantity){     
          s->sell->quantity -= data.quantity;
        }
      }
    }else{
      printf("listInsertSortedBuy\n");
      s->buy = listInsertSortedBuy(s->buy, data.quantity, data.value);
    }

  }else{

    float tb = listSearchTopBuy(s->buy);

    if(listSearchBuy(s->buy, data.value) != NULL){
      printf("Sell  1\n");
      s->price = data.value;
      if(s->buy->quantity == data.quantity){
        s->buy = listDeleteBuy(s->buy, data.value); 
      }else if(s->buy->quantity >= data.quantity){
        s->buy->quantity -= data.quantity;
      }
    }else if(tb > data.value && tb != 0){
      s->price = (tb + data.value) / 2;
      if(listSearchBuy(s->buy, tb) != NULL){     
        if(s->buy->quantity == data.quantity){           
          s->buy = listDeleteBuy(s->buy, data.value); 
        }else if(s->buy->quantity >= data.quantity){     
          printf("Sell 2\n");
          s->buy->quantity -= data.quantity;
        }
      }
    }else{
      printf("listInsertSortedSell\n");
      s->sell = listInsertSortedSell(s->sell, data.quantity, data.value);
    } 
  } 
  /* ---------------------------- */

  return data;
}

void mainOffer(Offer *offers, Shares *shares){

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
      case 1:  insertOffer(&offers, &shares);break;
      case 2:  retrieveOffer(&offers);break;
      case 3:  break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 3);

}