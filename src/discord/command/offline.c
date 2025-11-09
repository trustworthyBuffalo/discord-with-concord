#include "global_header.h"
#include "generator.h"
#include "state.h"

#define DEV 849471759660351488L

void
goodbye(
    struct discord *client,
    struct discord_response *resp,
    const struct discord_message *ret
)
{
    printf("bot offline.\n");

    exit(EXIT_SUCCESS);
}

void
prefix_offline(struct discord *client, const struct discord_message *msg)
{
    if (msg->author->id != DEV)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "well you not a dev, i won't listen, hmpff"
        );
        return;
    }

    // make it leave voice channel in every servers
    for (int i=0; i < guild_states.count; i++)
    {
        if (guild_states.data[i].bot.voice_channel_id)
        {
            discord_disconnect_guild_member(
                client,
                guild_states.data[i].guild_id,
                ready_state.id,
                NULL,
                NULL
            );
        }
    }


    // last message, :')
    discord_create_message(
        client,
        msg->channel_id,
        &(struct discord_create_message) {
            .content = "alright then, i'll be offline, see ya everyone :wave:",
        },
        &(struct discord_ret_message) {
            .done = goodbye,
        }
    );
}