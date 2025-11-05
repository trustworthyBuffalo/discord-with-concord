#include "global.h"


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