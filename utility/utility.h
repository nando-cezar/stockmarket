#ifndef UTILITY_H // include guard

    #define UTILITY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <locale.h>
    #include <ctype.h>
    #include <math.h>
    #include <time.h>

    typedef enum flagsStatus {Inactive_ = 0, Active_} typeStatus;
    typedef enum flagsOffers {Buy_ = 0, Sell_, Null_} typeOffers;

    #define MAX_SIG 8

    #define MESSAGE_ERROR "\nFalha ao abrir o arquivo ou ponteiro!"
    #define SHARES_PATH "db/shares.txt"

    #if defined(_WIN32) || defined(_WIN64)
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
    #endif

#endif