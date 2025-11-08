#include "global_header.h"



void on_voice_state_update(struct discord *client, const struct discord_voice_state *st) {

    char *username = st->member->user->username;
    uint64_t id = st->channel_id;

    if (id > 0) {

        printf("user %s joined voice, id: %ld\n", username, id);
    } else {

        printf("user %s leaved voice, id: %ld\n", username, id);
    }

    return;
}