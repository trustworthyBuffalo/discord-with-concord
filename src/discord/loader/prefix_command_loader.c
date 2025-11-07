#include "global_header.h"

#include "loader.h"
#include "prefix_command_list.h"
#include "command_container_global.h"



void prefix_command_loader() {
    static struct prefix_command commands[] = { 
        
            {
                .name = "ping",
                .description = "how fast bot response.",
                .callback = prefix_ping
            },
    };
    
    prefix_commands.arr = commands;
    prefix_commands.count = sizeof(commands) / sizeof(struct prefix_command);

    printf("[OK] prefix_command\n");
}