#include "../../utility/utility.h"
#include "../function/function.h"
#include "validation.h"

int validateOperation(char operation){

    if(
        operation == 'B' || 
        operation == 'b' ||
        operation == 'S' || 
        operation == 's' 
    ){
        return 1;
    }
    return 0;
}

int validateSignature(char *signature){
    return 1;
}

int isExistingSignature(char *signature){ 
    return 1;
}

int validateNumber(int number){
    return 1;
}