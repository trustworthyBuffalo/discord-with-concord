#include "global_header.h"

#include "state.h"
#include "command_container_global.h"
#include "loader.h"

#define DEV_GUILD 1412656143213400094
#define TEST_SLASH_COMMAND "test"


struct discord_guild_state_container guilds = {0};
struct guild_state_list guild_states = {0};

void
on_guild_create_init_track_guild( struct discord *client,
                                    struct guild_state *t)
{
    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
        t->member_in_voice_list[i].available = true;

    return;
}


void
on_guild_create_set_user_in_voice(   struct discord *client,
                                    struct discord_voice_states *states,
                                    struct guild_state *track)
{
    for (int i = 0; i < states->size; i++)
    {
        track->member_in_voice_list[i].available = false;
        track->member_in_voice_list[i].channel_id = states->array[i].channel_id;
        track->member_in_voice_list[i].user_id = states->array[i].user_id;
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

        if (guild_states.count < MAX_GUILD_TRACK)
        {

            guild_states
                .data[guild_states.count].guild_id = guild->id;

            on_guild_create_init_track_guild
                (client,
                &guild_states
                    .data[guild_states.count]); 

            if (guild->voice_states && guild->voice_states->size > 0)
            {
                on_guild_create_set_user_in_voice(
                            client,
                            guild->voice_states,
                            &(guild_states
                                .data[guild_states.count])
                            );
            }

            guild_states.count++;
        }
        else
        {
            printf("[warning]: MAX GUILD TRACK reached\n");
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
