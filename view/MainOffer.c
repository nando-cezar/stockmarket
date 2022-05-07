#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "Menu.h"

void mainOffer(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  Offer* offers = listCreateOffer();

  do{
    header();
    printf("1. Inserir oferta;\n"); 
    printf("2. Recuperar ofertas;\n"); 
    //printf("3. ;\n"); // Progress
    //printf("4. ;\n"); //OK
    //printf("5. ;\n"); //OK
    //printf("6. Sair;\n");
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