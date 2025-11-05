#include <concord/discord.h>
#include "../include/header.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GUILD_ID 1412656143213400094


struct command_desc {
    char *name;
    char *desc;
    bool status;
};

struct command_desc commands[] = {
    {"ping", "Ping command", true},
    {"hallo", "greeting", true},
    {"me", "display information about you", true}
    
};


int index_generate(int max) {

    srand(time(NULL));

    int r = rand() % max;
   
    return r;
}

extern struct bot_state state;

char *get_guild_name( u64snowflake guild_id) {

    int i = 0;
    for (;i < state.count ; i++) {
        if (state.guilds[i].id == guild_id) {
            return state.guilds[i].name;
        }
    }

    return "";
}


// on ready we register all of our commands
void on_ready(struct discord *client, const struct discord_ready *event) {

    printf("mejalan kan bot %s\n", event->user->username);
    printf("bot ready...\n");

}

void on_interaction(struct discord *client, const struct discord_interaction *event) {

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND) {

        return;
    }

    // jika command diminta melalui '/'
    if (strcmp(event->data->name, "ping") == 0) {

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

    else if (strcmp(event->data->name, "me") == 0) {

        struct discord_user *user = event->member->user;

        char msg[1024];
        sprintf(msg, "hallo %s#%s\n", user->username, user->discriminator);


        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data) {
                .content = msg
            },
        };

        discord_create_interaction_response(client, event->id, event->token, &params, NULL);
    }
}