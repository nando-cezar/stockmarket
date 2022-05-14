#include "../utility/Utility.h"
#include "../model/Offer.h"
#include "../model/Shares.h"
#include "OfferView.h"
#include "SharesView.h"
#include "Menu.h"

void logo(){

    system(CLEAR);

    printf("\t\tMMMM       MMMM   IIII\n");
    printf("\t\tM:::M     M:::M   I::I\n");
    printf("\t\tM::::M   M::::M   I::I\n");
    printf("\t\tM:::::M M:::::M   I::I\n");
    printf("\t\tM::M:::M:::M::M   I::I\n");
    printf("\t\tM::MM:::::MM::M   I::I\n");
    printf("\t\tM::M M:::M M::M   I::I\n");
    printf("\t\tM::M  M:M  M::M   I::I\n");
    printf("\t\tMMMM       MMMM   IIII\n");
    printf("\n\n\t ..:: MONEY INVEST | SISTEMA FINANCEIRO ::..\n\n");

}
void header(){

    system(CLEAR);

    printf("****************************************************\n");
    printf("\t ..:: MONEY INVEST | FINANCIAL SYSTEM ::..\n");
    printf("****************************************************\n\n");
}

void menu(){

    int option;
    Shares* shares = listCreateShares();
    Offer* offers = listCreateOffer();

    dataFileShares(&shares);
    dataFileOffer(&offers, &shares);
    
    setlocale(LC_ALL, "Portuguese");

    do{
        logo();
        printf("1 - Ofertas;\n");
        printf("2 - Ações;\n");
        //printf("3 - ;\n");
        printf("4 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:mainOffer(offers, shares); break;    
            case 2:mainShares(offers, shares); break;    
            case 3:break;
            case 4:
                printf("Acesso finalizado!");
                getchar();
                break;
            default:
                printf("Opção inválida!");
                getchar();
                break;
        }
    }while(option != 4);

}