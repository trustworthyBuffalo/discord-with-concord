#include "global_header.h"


void
mention_message(
    struct discord *client,
    const struct discord_message *msg
)
{
    char resp[100];
    sprintf(resp, "<@%ld>", msg->author->id);

    struct discord_create_message params = {
        .content = resp,
    };

    discord_create_message(
        client,
        msg->channel_id,
        &params,
        NULL
    );

    return;
}
