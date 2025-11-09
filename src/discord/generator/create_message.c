#include "global_header.h"


void
create_message_generator(   struct discord *client,
                            u64snowflake channel_id,
                            char *content
                        )
{
    struct discord_create_message params = {
        .content = content,
    };

    discord_create_message(client, channel_id, &params, NULL );

    return;
}