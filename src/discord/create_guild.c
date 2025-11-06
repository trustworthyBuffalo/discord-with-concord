#include "bot_discord.h"
#include "global.h"
#include "commands.h"

struct bot_state state = {0};

// callback akan dipanggil berulang
void on_guild_create(struct discord *client, const struct discord_guild *guild) {


    if (!guild || !guild->name) {
        return;
    }

    if (state.count < MAX_GUILDS) {

        struct guild_state *next_guild = &state.guilds[state.count];

        next_guild->id = guild->id;
        strncpy(next_guild->name, guild->name, sizeof(next_guild->name));

        state.count++;


        printf("registered guild [name: %s][id: %lu]\n", next_guild->name, next_guild->id);

        // kirim pesan jika server menyediakan channel system


        if (guild->system_channel_id) {

            char msg[1024];
            sprintf(msg,"bot is online!, Hai %s", next_guild->name);

            discord_create_message(
                client,
                guild->system_channel_id,
                &(struct discord_create_message){
                    .content = msg,
                },
                NULL
            );
        };

        int i = 0;
        for (; i< cmds->count; i ++) {

            struct discord_create_guild_application_command cmd = {
                .name = cmds->arr[i].name,
                .description = cmds->arr[i].desc,
            };

            discord_create_guild_application_command(client, ready_state.id, guild->id, &cmd, NULL);
        }

        printf("command untuk guild [ %s ] siap\n", guild->name);


    }

}