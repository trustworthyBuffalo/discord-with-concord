#include "global_header.h"
#include "state.h"


void prefix_leave_voice(struct discord *client, const struct discord_message *msg) {


    // checking client in voice or not
    // TODO: client can in mony voice in the same time, remake this later
    if (users_on_voice.count > 0) {
        
        for (int i=0; i < users_on_voice.count; i++) {
            
            if (users_on_voice.array[i].id == ready_state.id 
                && users_on_voice.array[i].voice_channel_id != 0) {
                    
                    // send response 
                    discord_create_message(
                        client,
                        msg->channel_id,
                        &(struct discord_create_message) {
                            .content = "aight bro, i'm leaving :wave:"
                        },
                        NULL
                    );


                    // then leaving
                    discord_disconnect_guild_member(
                        client,
                        msg->guild_id,
                        ready_state.id,
                        NULL,
                        NULL
                    );

                    return;
            }
        }

        discord_create_message(
            client,
            msg->channel_id,
            &(struct discord_create_message) {
                .content = "hold on, brow-. I an't in any voice"
            },
            NULL
        );

        return;
    }
}

