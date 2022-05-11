#ifndef CLOCK_H // include guard

    #define CLOCK_H

    #include "../utility/Utility.h"
    #include "Time.h"
    
    typedef struct detailsClock {

        int tm_sec;  
        int tm_min;   
        int tm_hour;
        int tm_mday; 
        int tm_mon;   
        int tm_year;  
        int tm_wday;  
        int tm_yday;  
        int tm_isdst; 

    } Clock;
 
#endif

