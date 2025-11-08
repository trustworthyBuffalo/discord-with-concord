#include "global_header.h"


void on_channel_create(struct discord *client, const struct discord_channel *ch) {

    switch (ch->type)
    {
    case DISCORD_CHANNEL_GUILD_VOICE :
    
        printf("channel voice %s created\n", ch->name);
        break;
        
    case DISCORD_CHANNEL_GUILD_TEXT :
        break;

    default:
        break;
    }
    
}