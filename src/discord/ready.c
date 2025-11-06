#include <bot_discord.h>
#include <commands.h>

// will set state of ready flag, contains application's id
struct discord_ready_state ready_state = {0};

// on ready we register all of our commands
void on_ready(struct discord *client, const struct discord_ready *event) {


    printf("mejalan kan bot %s\n", event->user->username);
    printf("bot ready...\n");

    ready_state.has_ready = 1;
    ready_state.id = event->application->id;

    printf("ready state ready..");

    
}
