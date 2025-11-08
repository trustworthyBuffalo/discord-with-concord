#include "global_header.h"
#include "state.h"


void prefix_join_voice(struct discord *client, const struct discord_message *msg) {

    char *resp = "You not in the voice channel bro";

    int i = 0;
    for (; i < users_on_voice.count ; i++) {

        if ( users_on_voice.array[i].id == msg->author->id &&
                users_on_voice.array[i].voice_channel_id != 0) {
            resp = "ok just wait...";
        
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

}