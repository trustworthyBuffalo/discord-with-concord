#include "global_header.h"
#include "config.h"
#include "event.h"

#include "loader.h"


int main() {


    struct discord *client = get_discord_client();
    if (!client) {
        return EXIT_FAILURE;
    }

    // init usaing config

    // struct discord *client = discord_init("config.json");

    // load all resources
    loader();

    // set all event callback
    discord_set_on_ready(client, on_ready);

    discord_add_intents(
        client,
        DISCORD_GATEWAY_GUILD_MESSAGES
        | DISCORD_GATEWAY_MESSAGE_CONTENT
        | DISCORD_GATEWAY_DIRECT_MESSAGES);

    discord_set_on_guild_create(client, on_guild_create);
    discord_set_on_message_create(client, on_message);
    discord_set_on_interaction_create(client, on_interaction);

    // hope run well...
    discord_run(client);
    discord_cleanup(client);

    return EXIT_SUCCESS;
}