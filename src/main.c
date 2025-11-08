#include "global_header.h"
#include "config.h"
#include "event.h"

#include "loader.h"

#include <stdlib.h>



int main() {



    struct discord *client = get_discord_client();
    if (!client) {
        return EXIT_FAILURE;
    }

    // resgieste event when program exit
    // on_exit(on_program_exit, client);

    // load all resources

    loader();

    // set all event callback

    discord_add_intents(
        client
        , DISCORD_GATEWAY_GUILD_MESSAGES
        | DISCORD_GATEWAY_GUILDS
        | DISCORD_GATEWAY_GUILD_WEBHOOKS
        | DISCORD_GATEWAY_MESSAGE_CONTENT
        | DISCORD_GATEWAY_DIRECT_MESSAGES
        | DISCORD_GATEWAY_GUILD_VOICE_STATES); //<-- voice channel intent

    discord_set_on_ready(client, on_ready);
    discord_set_on_guild_create(client, on_guild_create);

    discord_set_on_voice_state_update(client, on_voice_state_update);
    discord_set_on_message_create(client, on_message);
    discord_set_on_interaction_create(client, on_interaction);

    // channel_crud
    discord_set_on_channel_create(client, on_channel_create);


    // hope run well...
    discord_run(client);
    discord_cleanup(client);

    return EXIT_SUCCESS;
}