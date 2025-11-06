#include "global_header.h"

struct discord *get_discord_client() {

    char *token = getenv("TOKEN");
    if (token == NULL) {
        perror("get discord client");
        return NULL;
    }

    struct discord *client = discord_init(token);

    return client;
}