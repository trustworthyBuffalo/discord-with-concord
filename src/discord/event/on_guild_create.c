#include "global_header.h"

#include "state.h"
#include "command_container_global.h"
#include "loader.h"

#define DEV_GUILD 1412656143213400094
#define TEST_SLASH_COMMAND "test"


struct discord_guild_state_container guilds = {0};

u64snowflake voice_channel_id = 0;

void voice_state_init(struct discord *client, struct discord_response *resp, const struct discord_guild_member *ret) {


    if (users_on_voice.count < MAX_ON_VOICE) {
        struct discord_user_on_voice_state user = {
            .id = ret->user->id,
            .name = ret->user->username,
            .voice_channel_id = voice_channel_id
        };

        users_on_voice.array[users_on_voice.count] = user;
        users_on_voice.count++;
    }

}

void
on_guild_create(struct discord *client, const struct discord_guild *guild){


    if (guilds.count < MAX_GUILDS) {

        // register guild

        struct discord_guild_state next_guild = {
            .id = guild->id,
        };

        strcpy(next_guild.name, guild->name);

        // register its system id if thereis any
        if (guild->system_channel_id) {

            next_guild.system_channel_id = guild->system_channel_id;
        }

        guilds.arr[guilds.count] = next_guild;
        guilds.count++;


        // register command in new guild

        int i = 0;
        for (; i < slash_commands.count; i ++) {

            // if there is a test command and not guild dev, just ignore
            if (strcmp(slash_commands.arr[i].name, TEST_SLASH_COMMAND) == 0 
                && guild->id != DEV_GUILD) {

                    continue;
                }

            struct discord_create_guild_application_command cmd = {
               .name = slash_commands.arr[i].name,
               .description = slash_commands.arr[i].description, 
            };

            discord_create_guild_application_command(client, ready_state.id, guild->id, &cmd, NULL);
        }


        // get voice channls state
        if (guild->voice_states && guild->voice_states->size > 0) {

            for (int i=0; i<guild->voice_states->size; i++) {

                voice_channel_id = guild->voice_states->array[i].channel_id;

                discord_get_guild_member(   client, guild->id,
                                            guild->voice_states->array[i].user_id,
                                            &(struct discord_ret_guild_member) {
                                                .done = voice_state_init,
                                            });

            }
        }

        //  TODO: channel system bisa NULL
        // interaction 
        if (guild->id == DEV_GUILD) {

            discord_create_message(
                client,
                guild->system_channel_id,
                &(struct discord_create_message) {
                    .content = "hai dev!"
                },
                NULL
            );
        }
    }

}