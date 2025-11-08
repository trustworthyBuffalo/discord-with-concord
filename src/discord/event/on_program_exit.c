#include "global_header.h"
#include "state.h"

void on_program_exit(struct discord *client) {

    int i = 0 ;
    for (;i < guilds.count; i++) {

        // check system channel availablity
        if (!guilds.arr[i].system_channel_id) {
            continue;
        }

        // make parames
        struct discord_create_message params = {
            .content = "gonna offline, goodbye",
        };

        // send message
        discord_create_message(
            client,
            guilds.arr[i].system_channel_id,
            &params,
            NULL
        );
        
    }
}