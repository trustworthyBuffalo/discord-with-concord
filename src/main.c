#include "global_header.h"
#include "config.h"
#include "event.h"

#include "loader.h"


int main() {


    struct discord *client = get_discord_client();
    if (!client) {
        return EXIT_FAILURE;
    }

    // load all resources
    loader();

    // set all event callback
    discord_set_on_ready(client, on_ready);
    discord_set_on_interaction_create(client, on_interaction);
    discord_set_on_guild_create(client, on_guild_create);

    // hope run well...
    discord_run(client);

    return EXIT_SUCCESS;
}