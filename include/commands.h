#pragma once

#define COMMAND_ARGS struct discord *client, const struct discord_interaction *event

#define MAX_COMMANDS 10

#include "global.h"



// list of commands
void ping_interaction_command( COMMAND_ARGS );


struct command {
    char *name;
    char *desc;
    enum Status status;

    void(*callback)(struct discord *client, const struct discord_interaction *event);

};

struct commands {
    int count;
    struct command arr[MAX_COMMANDS];
};


