#include <string.h>
#include <concord/discord.h>

#define MAX_GUILDS 4

// tool

int get_token(const char*, char*);


// service discord

void on_ready(struct discord *, const struct discord_ready *);

void on_interaction(struct discord * , const struct discord_interaction *);

void on_guild_create(struct discord *, const struct discord_guild *);


// struct


struct guild_state {
    u64snowflake id;
    char name[128];
};

struct bot_state {
    size_t count;
    struct guild_state guilds[MAX_GUILDS];

};