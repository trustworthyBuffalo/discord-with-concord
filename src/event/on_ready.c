#include "global_header.h"
#include "state.h"

struct discord_ready_state ready_state = {
    .status = 0,
    .id = 0
};

void on_ready(struct discord *client, const struct discord_ready *event) {

    printf("[..] bot ready set state ...\n");

    ready_state.id = event->application->id;
    ready_state.status = 1;

    printf("[OK] discord ready state\n");
    printf("[>>] log:\n");
}