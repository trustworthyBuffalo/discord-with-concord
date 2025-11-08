#include "global_header.h"
#include "loader.h"
#include "slash_command_list.h"



struct slash_command_container slash_commands = {0};

void slash_command_handler(struct discord *client, const struct discord_interaction *event) {

    char *command_name = event->data->name;


    int i = 0;
    for (; i < slash_commands.count; i++) {

        struct slash_command cmd = slash_commands.arr[i];

        if (strcmp(command_name, cmd.name) == 0) {

            // check the callback notif
            if (!cmd.callback) {
                slash_not_implemented(client, event); 
                return;
            }

            // run callback
            cmd.callback(client, event);
            return;
        }
    }

}