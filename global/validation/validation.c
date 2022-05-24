#include "../../utility/Utility.h"
#include "../function/Function.h"
#include "../../model/Date.h"
#include "Validation.h"

int validateDay(int day, int month, int year);
int isFutureDate(int day, int month, int year);

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

int validateDate(Date date){
   
    if(date.year < 1900) return 0;
    else if(date.month <= 0 || date.month > 12 ) return 0;
    else if(date.day <= 0 || date.day > 31) return 0;
    else if(isFutureDate(date.day, date.month, date.year)) return 0;
    else if(validateDay( date.day, date.month, date.year)) return 0;
    else return 1;
}


int validateDay(int day, int month, int year){

    int isLeapYear;

    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) isLeapYear = 1;
    else isLeapYear = 0;

    if(
        month == 1 || 
        month == 3 ||
        month == 5 || 
        month == 7 ||
        month == 8 || 
        month == 10||
        month == 12
    ){
        if(day > 31) return 1;
        else return 0;
         
    }else if(month == 2 && isLeapYear ){
        if(day > 29) return 1;
        else return 0;          
    }else if(month == 2){
        if(day > 28) return 1;
        else return 0;
    }else{
        if(day > 30) return 1;
        else return 0;
    }

}

int isFutureDate(int day, int month, int year){
    struct tm *p;
    time_t seconds;

    time(&seconds);
    p = localtime(&seconds);

    if(year > p->tm_year + 1900) return 1;
    else if(year == p->tm_year + 1900 && month > p->tm_mon + 1) return 1;
    else if(year == p->tm_year + 1900 && month == p->tm_mon + 1 && day>p->tm_mday) return 1;
    else return 0;

}
