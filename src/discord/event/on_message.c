#include "global_header.h"
#include "event.h"
#include "discord_tools.h"


#include <concord/discord.h>
#define DEFAULT_PREFIX "!"



void log_on_message(const struct discord_message *);

void on_message(struct discord *client, const struct discord_message *msg) {
   
    log_on_message(msg);    


    if (msg->author->bot ) {
        return;
    }


    // TODO: 
    // Get prefix by database ...
    // get_prefix() by author or by guild id

    if (strncmp(msg->content, DEFAULT_PREFIX, strlen(DEFAULT_PREFIX)) != 0) {
        return;
    }

    // call handler
    prefix_command_handler(client, msg); 
}


void log_on_message(const struct discord_message *msg) {

    printf("message: %s\n", msg->content);
}
