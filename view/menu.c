#include "../utility/utility.h"

void header(){

    system(CLEAR);

    printf("****************************************************\n");
    printf("\t ..:: MONEY INVEST | SISTEMA FINANCEIRO ::..\n");
    printf("****************************************************\n\n");
}

void menu(){

    int option;

    setlocale(LC_ALL, "Portuguese");

    do{
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
        printf("1 - Estudante;\n");
        printf("2 - Professor;\n");
        printf("3 - Disciplina;\n");
        printf("4 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:mainStudent();break;    
            case 2:mainTeacher();break;    
            case 3:mainDiscipline();break;
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