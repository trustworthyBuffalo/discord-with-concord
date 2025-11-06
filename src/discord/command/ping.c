#include "global_header.h"

#include "discord_tools.h"
#include "util.h"



void slash_ping(struct discord *client, const struct discord_interaction *event) {

    uint64_t msg_time_ms = get_time_from_snowflake_ms(event->id);
    uint64_t now_time_ms = get_now_time_ms();

    uint64_t range_time_ms = now_time_ms - msg_time_ms;

    char resp[100];
    sprintf(resp, "pong! -> (%lu ms)", range_time_ms);


    struct discord_interaction_response params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(struct discord_interaction_callback_data) {
            .content = resp,
        },
    };

    discord_create_interaction_response(client, event->id, event->token, &params, NULL);
    
}