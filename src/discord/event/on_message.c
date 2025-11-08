#include "global_header.h"
#include "event.h"
#include "discord_tools.h"
#include "state.h"


#define DEFAULT_PREFIX "!"


void log_on_message(const struct discord_message *);

void on_message(struct discord *client, const struct discord_message *msg) {
   


    if (msg->author->bot) {
        return;
    }

    log_on_message(msg);    

    // for now this bot not response dm;
    if (!msg->guild_id) return;


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

    char *username = msg->author->username;

    printf("(%s)\n", username);
}
