#include "global_header.h"
#include "state.h"

struct discord_user_on_voice_state_container users_on_voice = {0};

void on_voice_state_update(struct discord *client, const struct discord_voice_state *st) {

    uint64_t channel_id = st->channel_id;
    char *username = st->member->user->username;

    if (channel_id > 0) {
        printf("user %s join voice\n", username);

        int i = 0;
        for (; i < users_on_voice.count ; i++) {

            if (st->member->user->id == users_on_voice.array[i].id) {

                users_on_voice.array[i].voice_channel_id = st->channel_id;
                return;
            }
        }

        if (users_on_voice.count < MAX_ON_VOICE) {

            struct discord_user_on_voice_state new_user = {
                .name = username,
                .id = st->member->user->id,
                .voice_channel_id = channel_id
            };

            users_on_voice.array[users_on_voice.count] = new_user;
            users_on_voice.count++;
        }
    }
    else {

        printf("user %s leaved voice\n", username);

        int i = 0;
        for (; i < users_on_voice.count ; i++) {

            if (st->member->user->id == users_on_voice.array[i].id) {

                users_on_voice.array[i].voice_channel_id = channel_id;
                return;
            }
        }
    }



    return;
}