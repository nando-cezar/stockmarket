#ifndef VALIDATION_H // include guard

    #define VALIDATION_H

    #include "../../model/Date.h"
    
    int validateOperation(char operation);
    int validateInteger(char *str);
    float validateFloat(char *str);
    int validateDate(Date date);

#endif