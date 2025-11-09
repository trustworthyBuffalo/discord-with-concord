#include "global_header.h"
#include "state.h"


struct track_guild_member_voices guild_member_voices_state = {0};

void
on_voice_state_update_join(const struct discord_voice_state *st, int idx)
{
    struct track_guild_member_voice *g = &guild_member_voices_state.array[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->array[i].available)
        {
            g->array[i].available = false;
            g->array[i].channel_id = st->channel_id;
            g->array[i].user_id = st->user_id;

            printf("[user_event]~%s: joined voice channel\n",
                    st->member->user->username);

            return;
        }

        printf("join, user never found");
    }
}


void
on_voice_state_update_leave(const struct discord_voice_state *st, int idx)
{
    struct track_guild_member_voice *g = &guild_member_voices_state.array[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->array[i].available == false &&
            g->array[i].user_id == st->user_id)
        {
            g->array[i].available = true;
            g->array[i].channel_id = 0;
            g->array[i].user_id = 0;

            printf("[user_event]~%s: leaved voice channel\n",
                    st->member->user->username);

            return;
        }

        printf("leave, user never found");
    }
}

void
on_voice_state_update(  struct discord *client,
                        const struct discord_voice_state *st)
{
    for (int i=0; i < guild_member_voices_state.count; i++)
    {
        if (guild_member_voices_state.array[i].guild_id == st->guild_id)
        {
            if (st->channel_id)
                on_voice_state_update_join(st, i);
            else
                on_voice_state_update_leave(st, i);
            
            break;
        }
    }
 
    return;
}
