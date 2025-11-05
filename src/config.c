#include <concord/discord.h>
#include "../include/header.h"
#include <stdio.h>

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

        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data) {
                .content = "https://tenor.com/view/smash-feng-tianwei-olympics-table-tennis-ping-pong-gif-22503629"
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