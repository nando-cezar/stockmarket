#include "../utility/Utility.h"
#include "Offer.h"

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

    setlocale(LC_ALL, "Portuguese");

    do{
        logo();
        printf("1 - Oferta;\n");
        //printf("2 - Professor;\n");
        //printf("3 - Disciplina;\n");
        printf("4 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:mainOffer();break;    
            case 2:break;    
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