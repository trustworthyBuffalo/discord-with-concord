#include "global_header.h"
#include "event.h"
#include "discord_tools.h"


#include <concord/discord.h>
#define DEFAULT_PREFIX "!"

char *type_msg[] = {"DM", "GUILD", "OTHER"};

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

    char *author_name = msg->author->username;
    char *content;
    char *type;
    
    // check attatchment
    if (msg->attachments && msg->attachments->size > 0) {

        content = msg->attachments->array->content_type;
    } else {

        content = msg->content;
    }

    if (!msg->guild_id) {
        type = type_msg[0];
    }

    else  if (msg->guild_id) {
        type = type_msg[1];
    }

    else {
        type = type_msg[2];
    }

    printf("[%s](%s): %s\n", type, author_name,  content);
}
