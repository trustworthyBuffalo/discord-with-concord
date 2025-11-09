#include "global_header.h"
#include "state.h"




void
prefix_join_voice_check_in_voice(   struct discord *client,
                                    const struct discord_message *msg,
                                    int idx)
{
    struct track_guild_member_voice *g = &guild_member_voices_state.array[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->array[i].user_id == msg->author->id)
        {
            printf("[debug]: user ~%s in voice\n", msg->author->username);
            return;
        }
    }

    printf("[debug]: user ~%s not in voice.\n", msg->author->username); return;
}


void
prefix_join_voice(struct discord *client, const struct discord_message *msg)
{

    // checking message from which guild
    for (int i=0;i<guild_member_voices_state.count;i++)
    {
        if (guild_member_voices_state.array[i].guild_id == msg->guild_id)
        {
            prefix_join_voice_check_in_voice(client, msg, i);
            return;
        }
    }

}