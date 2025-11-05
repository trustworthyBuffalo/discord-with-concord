#include "../include/header.h"

#define MAX_GUILDS 4

struct guild_state {
    u64snowflake id;
    char name[128];
};

struct bot_state {
    size_t count;
    struct guild_state guilds[MAX_GUILDS];

} state = {0};


// callback akan dipanggil berulang
void on_guild_create(struct discord *client, const struct discord_guild *guild) {


    if (!guild || !guild->name) {
        return;
    }

    if (state.count < MAX_GUILDS) {

        struct guild_state *next_guild = &state.guilds[state.count];

        next_guild->id = guild->id;
        strncpy(next_guild->name, guild->name, sizeof(next_guild->name));

        state.count++;


        printf("registered guild [name: %s][id: %lu]\n", next_guild->name, next_guild->id);

        // kirim pesan jika server menyediakan channel system


        if (guild->system_channel_id) {

            char msg[1024];
            sprintf(msg,"Hallo member member %s, saya siap untuk bekerja~", next_guild->name);

            discord_create_message(
                client,
                guild->system_channel_id,
                &(struct discord_create_message){
                    .content = msg,
                },
                NULL
            );
        };

    }

}