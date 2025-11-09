#include "global_header.h"
#include "state.h"



void
on_voice_state_update_join(const struct discord_voice_state *st, int idx)
{
    struct guild_state *g = &guild_states.data[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->member_in_voice_list[i].available)
        {
            g->member_in_voice_list[i].available = false;
            g->member_in_voice_list[i].channel_id = st->channel_id;
            g->member_in_voice_list[i].user_id = st->user_id;

            printf("[user_event]~%s: joined voice channel\n",
                    st->member->user->username);

            return;
        }

        printf("join, user never found\n");
    }
}


void
on_voice_state_update_leave(const struct discord_voice_state *st, int idx)
{
    struct guild_state *g = &guild_states.data[idx];

    for (int i=0;i<MAX_MEMBER_VOICE_TRACK;i++)
    {
        if (g->member_in_voice_list[i].available == false &&
            g->member_in_voice_list[i].user_id == st->user_id)
        {
            g->member_in_voice_list[i].available = true;
            g->member_in_voice_list[i].channel_id = 0;
            g->member_in_voice_list[i].user_id = 0;

            printf("[user_event]~%s: leaved voice channel\n",
                    st->member->user->username);

            return;
        }

        printf("leave, user never found\n");
    }
}

void
on_voice_state_update_switch(const struct discord_voice_state *st, int idx)
{
    struct guild_state *g = &guild_states.data[idx];

    for (int i=0; i < MAX_MEMBER_VOICE_TRACK; i++)
    {
        if (g->member_in_voice_list[i].user_id == st->user_id)
        {
            on_voice_state_update_leave(
                st,
                idx
            );
            return;
        }
    }
    return;
}

void
on_voice_state_update(
    struct discord *client,
    const struct discord_voice_state *st
)
{
    if (st->member->user->bot) return;

    for (int i=0; i < guild_states.count; i++)
    {
        if (guild_states.data[i].guild_id == st->guild_id)
        {
            if (st->channel_id)
            {
                on_voice_state_update_switch(st, i);
                on_voice_state_update_join(st, i);
            }
            else
                on_voice_state_update_leave(st, i);
            
            break;
        }
    }
 
    return;
}
