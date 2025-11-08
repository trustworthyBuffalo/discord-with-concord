#include "global_header.h"


struct discord_embed params_embed = {
        .author = &(struct discord_embed_author) {
            .name = "yumiodd",
            .icon_url = "https://i.pinimg.com/236x/cc/f6/14/ccf61435c016d73c95d1ed1fed5fd2f8.jpg",
        },
        .image = &(struct discord_embed_image) {
            .url = "https://media.tenor.com/yt8XciQ0b-IAAAAM/eto-bleh.gif",
        },
        .title = "oops! not implemented yet :joy_cat:"
    };

void slash_not_implemented(struct discord *client, const struct discord_interaction *event) {

    struct discord_interaction_response params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(struct discord_interaction_callback_data) {
            .embeds = &(struct discord_embeds) {
                .size = 1,
                .array = &params_embed,
            }
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


void prefix_not_implemented(struct discord *client, const struct discord_message *msg) {


    struct discord_create_message params = {
        .embeds = &(struct discord_embeds) {
            .size = 1,
            .array = &params_embed,
        }
    };

    discord_create_message(
        client,
        msg->channel_id,
        &params,
        NULL
    );
}