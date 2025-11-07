#include "global_header.h"

#include "discord_tools.h"
#include "util.h"


unsigned long get_ping_time(uint64_t snowflake) {


    uint64_t msg_time_ms = get_time_from_snowflake_ms(snowflake);
    uint64_t now_time_ms = get_now_time_ms();

    uint64_t ping_time_ms = now_time_ms - msg_time_ms;

    return ping_time_ms;
}



void slash_ping(struct discord *client, const struct discord_interaction *event) {

    unsigned long ping_time_ms = get_ping_time(event->id);

    char resp[100];
    sprintf(resp, "pong! -> (%lu ms)", ping_time_ms);


    struct discord_interaction_response params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(struct discord_interaction_callback_data) {
            .content = resp,
        },
    };

    discord_create_interaction_response(client, event->id, event->token, &params, NULL);
    
}


void prefix_ping(struct discord *client, const struct discord_message *msg) {

    unsigned long ping_time = get_ping_time(msg->id);

    char response[1024];

    sprintf(response, "pong! -> (%lu ms)", ping_time);

    discord_create_message(
        client,
        msg->channel_id,
        &(struct discord_create_message){
            .content = response,
            .message_reference = &(struct discord_message_reference) {
                .message_id = msg->id,
                .channel_id = msg->channel_id,
                .guild_id = msg->guild_id,
                .fail_if_not_exists = false
            }
        },
        NULL
    );
}