#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/input/OfferInput.h"
#include "../global/function/Function.h"
#include "Menu.h"

OfferInput insertDataOffer(){

  OfferInput data;

  printf("Informe ação deseja: ");
  fgets(data.signature, MAX_SIG, stdin);
  removeBreakLine(data.signature);

  printf("Informe tipo de operação: ");
  scanf(" %c", &data.type);
  getchar();

  printf("Informe quantidade: ");
  scanf("%d", &data.quantity);
  getchar();

  printf("Informe valor: ");
  scanf("%f", &data.value);
  getchar();

  //int t, char *sg, int q, int v;
  return data;
}

void mainOffer(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  Offer* offers = listCreateOffer();

  do{
    header();
    printf("1. Inserir oferta;\n"); 
    printf("2. Listar oferta especifica;\n"); 
    printf("3. Listar todas as ofertas;\n"); // Progress
    printf("4. Listar operações concluídas;\n"); //OK
    printf("5. ;\n"); //OK
    printf("6. Sair;\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  insertOffer(&offers); break;
      case 2:  retrieveOffer(&offers);break;
      case 3:  break;
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