#include "global_header.h"
#include "loader.h"
#include "slash_command_list.h"
#include "command_container_global.h"

// get command list
// insert to slash_commands;

void slash_command_loader() {
    static struct slash_command commands[] = { 
        
            {
                .name = "ping",
                .description = "how fast bot response.",
                .callback = slash_ping,
            },
            {
                .name = "me",
                .description = "show your info",
                .callback = NULL,
            },
            {
                .name = "test",
                .description = "test new feature",
                .callback = NULL,
            },
    };
    
    slash_commands.arr = commands;
    slash_commands.count = sizeof(commands) / sizeof(struct slash_command);

    printf("[OK] slash_command\n");
}
