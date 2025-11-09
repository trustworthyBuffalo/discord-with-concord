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
            {
                .name = "join",
                .description = "joining voice channel",
                .callback = prefix_join_voice
            },
            {
                .name = "leave",
                .description = "joining voice channel",
                .callback = prefix_leave_voice
            },
            {
                .name = "call",
                .description = "joining voice channel",
                .callback = mention_message
            },
            {
                .name = "offline",
                .description = "joining voice channel",
                .callback = prefix_offline
            },
            {
                .name = "test",
                .description = "joining voice channel",
                .callback = NULL
            },
    };
    
    prefix_commands.arr = commands;
    prefix_commands.count = sizeof(commands) / sizeof(struct prefix_command);

    printf("[OK] prefix_command\n");
}