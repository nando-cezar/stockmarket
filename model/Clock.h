#ifndef CLOCK_H // include guard

    #define CLOCK_H

    #include "../utility/Utility.h"
    
    typedef struct detailsClock {
 
        int tm_mday;
        int tm_mon;
        int tm_year;
        int tm_hour;
        int tm_min;
        int tm_sec;

    } Clock;
 
#endif
