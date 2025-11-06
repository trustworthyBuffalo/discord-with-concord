#include "global.h"
#include <sys/time.h>


int get_token(const char *token_path, char *buf) {
   
    int token_fd;
    char c;

    token_fd = open(token_path, O_RDONLY);
    if (token_fd == -1) {
        return -1;
    }

    int i = 0;
    while (read(token_fd, &c, 1) == 1) {
        buf[i] = c;
        i++; 
    }

    buf[i] = '\0';

    if (close(token_fd) == -1) {
        return -1;
    }

    return 0;
}


int index_generate(int max) {

    srand(time(NULL));

    int r = rand() % max;
   
    return r;
}

unsigned long get_current_time_in_ms() {

    struct timeval tv;

    gettimeofday(&tv, NULL);

    unsigned long miliseconds = (unsigned long)tv.tv_sec * 1000 + (unsigned long)tv.tv_usec / 1000;

    return miliseconds;

}