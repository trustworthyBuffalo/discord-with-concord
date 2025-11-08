#include "global_header.h"


void prefix_join_voice(struct discord *client, const struct discord_message *msg) {


    struct discord_create_message params = {
        .content = "joining channel *pretending",
    };

    discord_create_message(
        client,
        msg->channel_id,
        &params,
        NULL
    );
}