#include "global.h"

#include "bot_discord.h"
#include "tool.h"



void ping_interaction_command(struct discord *client, struct discord_interaction *event) {


        char * guild_name = get_guild_name(event->guild_id);

        printf("req: [%s]:%s -> /ping\n", guild_name,event->member->user->username);


        char *link_gifs[] = {
                "https://tenor.com/bGAnV.gif",
                "https://tenor.com/bEcUu.gif",
                "https://tenor.com/2oGV.gif"
        };

        int id = index_generate(3);

        char msg[1024];
        sprintf(msg, "PONG!!!\n%s", link_gifs[id]);



        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data) {
                .content = msg
            },
        };

        discord_create_interaction_response(client, event->id, event->token, &params, NULL);
}