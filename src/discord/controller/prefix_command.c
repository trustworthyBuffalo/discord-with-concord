#include "global_header.h"
#include "loader.h"

#define DEFAULT_PREFIX "!"

struct prefix_command_container prefix_commands = {0};

void prefix_command_handler(struct discord *client, const struct discord_message *msg) {

    // not like this, find \0 or whitespace for the first word 
    char *command = msg->content + strlen(DEFAULT_PREFIX);

    // TODO:
    //===== command filter
    // - get the first word as command
    

    int i = 0;
    for (; i < prefix_commands.count; i++) {

        struct prefix_command cmd = prefix_commands.arr[i];

        if (strcmp(command, cmd.name) == 0) {

            //TODO: stripe the command from message content

            // run callback, it will handle response and argument if there is any
            cmd.callback(client, msg);
            return;
        }
    }

}