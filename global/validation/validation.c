#include "../../utility/Utility.h"
#include "../function/Function.h"
#include "Validation.h"

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

int validateInteger(char *str){

    int value;
    while (scanf("%d", &value) != 1){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf(str);
    }
    return value;
}

float validateFloat(char *str){

    float value;
    while (scanf("%f", &value) != 1){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf(str);
    }
    return value;
}
