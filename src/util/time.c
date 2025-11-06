#include "global_header.h"


unsigned long get_now_time_ms() {

    struct timeval tv;

    if (gettimeofday(&tv, NULL) != 0) {
        return 0;
    }

    unsigned long time_ms = 
        ((unsigned long)tv.tv_sec * 1000) 
      + (unsigned long)tv.tv_usec / 1000;

    return time_ms;
}