#include <concord/discord.h>
#include "../include/header.h"


#define GUILD_ID 1412656143213400094


struct command_desc {
    char *name;
    char *desc;
};

struct command_desc commands[] = {
    {"ping", "Ping command"},
    {"hallog", "greeting"},
};


// on ready we register all of our commands
void on_ready(struct discord *client, const struct discord_ready *event) {

    size_t command_len = sizeof(commands) / sizeof(struct command_desc);
    int i = 0;
    
    for (; i<command_len; i++) {
        
        struct discord_create_guild_application_command params = {
            .name = commands[i].name,
            .description = commands[i].desc
        };

        discord_create_guild_application_command(client, event->application->id, GUILD_ID, &params, NULL);
    }

}

