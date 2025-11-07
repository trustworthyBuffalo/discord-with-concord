#include "global_header.h"
#include "event.h"


char *discord_interaction_type[] = {
    "DISCORD_INTERACTION_PING",
    "DISCORD_INTERACTION_APPLICATION_COMMAND",
    "DISCORD_INTERACTION_MESSAGE_COMPONENT",
    "DISCORD_INTERACTION_COMMAND_AUTOCOMPLETE",
    "DISCORD_INTERACTION_SUBMIT",
};


void on_interaction(struct discord *client, const struct discord_interaction *event) {

    char *username_g = event->member->user->username;
    char *interaction_type = discord_interaction_type[event->type];


    switch (event->type) {
    case DISCORD_INTERACTION_APPLICATION_COMMAND:

        printf("%s commits %s\n", username_g, interaction_type);

        slash_command_handler(client, event); 
        break;
   
    case DISCORD_INTERACTION_MESSAGE_COMPONENT:
        printf("u >");
        break;
        
    
    default:
        
        break;
    }

}
