#include "global_header.h"
#include "state.h"
#include "generator.h"



void
prefix_join_voice_check_in_voice(   struct discord *client,
                                    const struct discord_message *msg,
                                    int idx)
{
    struct guild_state *g = &guild_states.data[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->member_in_voice_list[i].user_id == msg->author->id)
        {
            char *resp = "aight wait a sec";
            create_message_generator(client, msg->channel_id, resp);

            printf("[debug]: user ~%s in voice\n", msg->author->username);

            return;
        }
    }

    char *resp = "stupid, you're not in a voice";
    create_message_generator(client, msg->channel_id, resp);

    printf("[debug]: user ~%s not in voice.\n", msg->author->username); return;
}


void
prefix_join_voice(struct discord *client, const struct discord_message *msg)
{

    // checking message from which guild
    for (int i=0;i<guild_states.count;i++)
    {
        if (guild_states.data[i].guild_id == msg->guild_id)
        {
            prefix_join_voice_check_in_voice(client, msg, i);
            return;
        }
    }

}