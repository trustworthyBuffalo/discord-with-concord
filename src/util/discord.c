#include <bot_discord.h>



char *get_guild_name( u64snowflake guild_id) {

    int i = 0;
    for (;i < state.count ; i++) {
        if (state.guilds[i].id == guild_id) {
            return state.guilds[i].name;
        }
    }

    return "";
}