#include <string.h>
#include <concord/discord.h>


// tool

int get_token(const char*, char*);


// service discord

void on_ready(struct discord *, const struct discord_ready *);