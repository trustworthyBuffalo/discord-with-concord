#include "global_header.h"
#include "state.h"


void prefix_join_voice(struct discord *client, const struct discord_message *msg) {

    char *resp = "You not in the voice channel bro";
    int in_voice = 0;
    u64snowflake voice_channel_id = 0;

    int i = 0;
    for (; i < users_on_voice.count ; i++) {

        if ( users_on_voice.array[i].id == msg->author->id &&
                users_on_voice.array[i].voice_channel_id != 0) {

            // TODO: jika bot sudah masuk, stop di sini

            resp = "ok just wait...";
            in_voice = 1;
            voice_channel_id = users_on_voice.array[i].voice_channel_id;

            printf("%ld\n", voice_channel_id);
            break;
        
        }
    }

    struct discord_create_message params = {
        .content = resp,
    };


    discord_create_message(
        client,
        msg->channel_id,
        &params,
        NULL
    );

    if (in_voice) {

        // join voice channel
        discord_update_voice_state(
            client,
            &(struct discord_update_voice_state) {
                .guild_id = msg->guild_id,
                .channel_id = voice_channel_id,
                .self_mute = true,
                .self_deaf = false
            }
        );


    }

}