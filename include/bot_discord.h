
#pragma once
#include <concord/discord.h>

#define MAX_GUILDS 5


// global variable
extern struct bot_state state;


// service discord

void on_ready(struct discord *, const struct discord_ready *);

void on_interaction(struct discord * , const struct discord_interaction *);

void on_guild_create(struct discord *, const struct discord_guild *);

void load_command();

// Guild
struct guild_state {
    u64snowflake id;
    char name[128];
};

struct bot_state {
    size_t count;
    struct guild_state guilds[MAX_GUILDS];

};

struct discord_ready_state {
    u64snowflake id;
    int has_ready;
};

extern struct discord_ready_state ready_state;