#include "global_header.h"

#include "state.h"
#include "command_container_global.h"
#include "loader.h"



struct discord_guild_state_container guilds = {0};


void on_guild_create(struct discord *client, const struct discord_guild *guild) {


    if (guilds.count < MAX_GUILDS) {

        // register guild

        struct discord_guild_state next_guild = {
            .id = guild->id,
            .name = guild->name
        };

        guilds.arr[guilds.count] = next_guild;
        guilds.count++;


        // register command in new guild

        int i = 0;
        for (; i < slash_commands.count; i ++) {

            struct discord_create_guild_application_command cmd = {
               .name = slash_commands.arr[i].name,
               .description = slash_commands.arr[i].description, 
            };

            discord_create_guild_application_command(client, ready_state.id, guild->id, &cmd, NULL);
        }
    }

}