#include "../../utility/utility.h"
#include "../function/function.h"
#include "validation.h"

int validateOperation(char operation){

    if(
        operation == 'C' || 
        operation == 'c' ||
        operation == 'V' || 
        operation == 'v' 
    ){
        return 1;
    }
    return 0;
}

int validateInteger(){

    int value;
    while (scanf("%d", &value) != 1){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("Informe uma quantidade válida!\nInforme quantidade: ");
    }
    return value;
}

float validateFloat(){

    float value;
    while (scanf("%f", &value) != 1){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("Informe um valor válido!\nInforme valor: ");
    }
    return value;
}