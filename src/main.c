#include "../include/header.h"


int main() {


    char token[1024];
    if (get_token("../token", token) == -1) {
        return -1;
    }

    struct discord *client = discord_init(token);
    discord_set_on_ready(client, &on_ready);

    // register response for command //

    discord_run(client);

    return 0;
}