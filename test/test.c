#include <stdio.h>
#include <sys/time.h>
#include <time.h>


unsigned long get_current_time_in_ms() {

    struct timeval tv;

    gettimeofday(&tv, NULL);

    unsigned long miliseconds = (unsigned long)tv.tv_sec * 1000 + (unsigned long)tv.tv_usec / 1000;

    return miliseconds;

}

int main() {
    printf("miliseconds of now: %lu\n", get_current_time_in_ms());
    
    time_t time_sec = get_current_time_in_ms() / 1000;
    printf("in string foermat %s\n", ctime(&time_sec));
    

    return 0;
}
