#include "global_header.h"

int main () {
    
    char string[] = "sudo apt updated";
    char *delimiter = " ";

    char *token = strtok(string, delimiter);

    while(token != NULL) {
        printf("token: %s\n", token);

        printf("string: %s\n");

        token = strtok(NULL, delimiter);
    }

    return 0;
}