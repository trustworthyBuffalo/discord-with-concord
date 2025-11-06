#include "global.h"

#include "bot_discord.h"
#include "tool.h"
#include <time.h>


void ping_interaction_command(struct discord *client, struct discord_interaction *event) {


        char * guild_name = get_guild_name(event->guild_id);



        char *link_gifs[] = {
                "https://tenor.com/bGAnV.gif",
                "https://tenor.com/bEcUu.gif",
                "https://tenor.com/2oGV.gif"
        };

        int id = index_generate(3);

        // measure time
        uint64_t event_id = event->id;
        unsigned long msg_time_ms = discord_snowflake_to_ms_unit(event_id);
        unsigned long now_time_ms = get_current_time_in_ms();
        unsigned long duration_ms = now_time_ms - msg_time_ms;

        // to client 
        char msg[1024];
        sprintf(msg, "PONG!!! -> (%lu ms)\n%s", duration_ms, link_gifs[id]);

        // to log
        printf("req: [%s]:%s -> /ping (%lu ms)\n", guild_name, event->member->user->username, duration_ms);

        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data) {
                .content = msg
            },
        };

        discord_create_interaction_response(client, event->id, event->token, &params, NULL);
}