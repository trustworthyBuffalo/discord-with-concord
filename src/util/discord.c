#include <bot_discord.h>

#define DISCORD_EPOCH 1420070400000ULL

char *get_guild_name( u64snowflake guild_id) {

    int i = 0;
    for (;i < state.count ; i++) {
        if (state.guilds[i].id == guild_id) {
            return state.guilds[i].name;
        }
    }

    return "";
}

unsigned long discord_snowflake_to_ms_unit(uint64_t snowflakes) {
    return (snowflakes >> 22) + DISCORD_EPOCH;
}