#include "global_header.h"
#include "state.h"
#include "generator.h"


void
joining_voice(
    struct discord *client,
    const struct discord_message *msg,
    u64snowflake voice_channel_id
)
{
    discord_update_voice_state(
        client,
        &(struct discord_update_voice_state) {
            .channel_id = voice_channel_id,
            .guild_id = msg->guild_id,
            .self_deaf = true,
            .self_mute = false
        }
    );
    return;
}

void
prefix_join_voice(struct discord *client, const struct discord_message *msg)
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
            "baka yo, you ain't in voice channel"
        );
        return;
    }

    struct bot_state *bot = &(st->bot);
    if (!bot->voice_channel_id)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "cotto mate ..."
        );
        
        joining_voice(
            client,
            msg,
            miv->channel_id
        );

        // updating bot state
        st->bot.voice_channel_id = miv->channel_id;
        
        return;
    }

    if (bot->voice_channel_id == miv->channel_id)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "BAKAAA!!, we are in the same voice channel"
        );
        return;
    }
    
    if (bot->voice_channel_id)
    {
        create_message_generator(
            client,
            msg->channel_id,
            "gommen, in voice right now"
        );
        return;
    }
}