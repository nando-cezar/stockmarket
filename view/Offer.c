#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/input/OfferInput.h"
#include "../global/function/Function.h"
#include "../global/validation/Validation.h"
#include "Menu.h"

OfferInput insertDataOffer(){

  OfferInput data;
  int verification, verificationSignature = 0;

  do{

    do{
      printf("Informe ação deseja: ");
      fgets(data.signature, MAX_SIG, stdin);
      removeBreakLine(data.signature);

      verification = validateSignature(data.signature);

    if(!verification)
      printf("\nInforme codigo da ação válido!\n");

    }while(!verification);

    verificationSignature = isExistingSignature(data.signature);

    if(!verificationSignature){  /* Logic implement */ }
    else{ textToUpper(data.signature); }
      
  }while (!verificationSignature);
      

  do{
    printf("Informe tipo de operação: ");
    scanf(" %c", &data.type);
    getchar();
    
    verification = validateOperation(data.type);

    if(!verification)
      printf("\nInforme tipo de operação válida!\n");
    else
      data.type = toupper(data.type);

  }while(!verification);

  do{
    
    printf("Informe quantidade: ");
    scanf("%d", &data.quantity);
    getchar();
    
    verification = validateNumber(data.quantity);

    if(!verification)
      printf("\nInforme tipo de operação válida!\n");

  }while(!verification);

  do{
    
    printf("Informe valor: ");
    scanf("%f", &data.value);
    getchar();
    
    verification = validateNumber(data.value);

    if(!verification)
      printf("\nInforme tipo de operação válida!\n");

  }while(!verification);

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
    printf("3. Listar todas as ofertas;\n"); 
    printf("4. Listar operações concluídas;\n"); 
    //printf("5. ;\n"); 
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