#include "global_header.h"
#include "state.h"
#include "generator.h"


void
leaving_voice(
    struct discord *client,
    const struct discord_message *msg
)
{
    discord_disconnect_guild_member(
        client,
        msg->guild_id,
        ready_state.id,
        NULL,
        NULL 
    );
    return;
}


void
prefix_leave_voice(struct discord *client, const struct discord_message *msg)
{
    struct guild_state *st = NULL;

    // checking message from which guild
    for (int i=0; i < guild_states.count; i++)
    {
        if (guild_states.data[i].guild_id == msg->guild_id)
        {
            st = &guild_states.data[i];
        }
    }

    if(!st)
    {
        create_message_generator(
            client,
            msg->guild_id,
            "hmm... somthing wrong"
        );
        return;
    }

    if(!st->bot.voice_channel_id)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "wdymean hmm? i'm not in a voice"
        );
        return;
    }

    struct member_in_voice *miv = NULL;
    for (int i=0; i < MAX_MEMBER_VOICE_TRACK; i++)
    {
        if (st->member_in_voice_list[i].user_id == msg->author->id)
        {
            miv = &st->member_in_voice_list[i];
            break;
        }
    }

    if(!miv)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "what a brave man, you have to come to me first"
        );
        return;
    }

    if(miv->channel_id == st->bot.voice_channel_id)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "alright then, good by"
        );

        leaving_voice(
            client,
            msg
        );

        // updating bot state
        st->bot.voice_channel_id = 0;
        return;
    }
    else
    {
        create_message_generator(
            client,
            msg->channel_id,
            "you are in another voice, come here first"
        );
        return;
    }
}

