#include "global_header.h"


void not_implemented(struct discord *client, const struct discord_interaction *event) {

    struct discord_interaction_response params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(struct discord_interaction_callback_data) {
            .content = "wups!, this interaction not implemented yet",
        },
    };

   discord_create_interaction_response(
    client,
    event->id,
    event->token,
    &params,
    NULL
   );
}