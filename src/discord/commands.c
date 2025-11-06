#include <bot_discord.h>
#include "global.h"
#include "tool.h"
#include "command_list.h"

struct commands cmds = {0};

void add_cmd(struct command cmd) {

    if (cmds.count != MAX_COMMANDS) {
        cmds.arr[cmds.count] = cmd;
        cmds.count++;
        
        return;
    };

    printf("slot command sudah mencapat limit \n ");
}



void load_command() {
    add_cmd((struct command){
        .name = "ping",
        .desc = "Measures Message Delivery Latency",
        .status = ACTIVE,
        .callback = ping_interaction_command
    }
    );
}

void on_interaction(struct discord *client, const struct discord_interaction *event) {

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND) {

        return;
    }

    int i= 0;
    for (; i<cmds.count; i++) {
        if (strcmp( event->data->name, cmds.arr[i].name) == 0) {

            struct command c = cmds.arr[i];
            c.callback(client, event);


            return;
        }
    }
}