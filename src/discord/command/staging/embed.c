#include "global_header.h"


void slash_embed(struct discord *client, const struct discord_interaction *event) {

    struct discord_embed embed_resp = {
        .author = &(struct discord_embed_author) {
            .icon_url = "https://i.pinimg.com/236x/cc/f6/14/ccf61435c016d73c95d1ed1fed5fd2f8.jpg",
            .name = "yumiodd ^^",
        },
        .title = "test",
        .description = "testing",
        .footer = &(struct discord_embed_footer) {
            .icon_url = "https://i.pinimg.com/236x/cc/f6/14/ccf61435c016d73c95d1ed1fed5fd2f8.jpg",
            .text = "cumungut :3"
        },
        .image = &(struct discord_embed_image) {
            .url = "",
            .height = 30,
            .width = 30
        },
    };

    struct discord_interaction_response params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(struct discord_interaction_callback_data) {
            .embeds = &(struct discord_embeds) {
                .size = 1,
                .array = &embed_resp,
            },
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