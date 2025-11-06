#include "global_header.h"

// On ready
void on_ready(struct discord *, const struct discord_ready *);


// Interaction and handler
void on_interaction(struct discord *, const struct discord_interaction *);

void slash_command_handler(struct discord *, const struct discord_interaction *);

void on_guild_create(struct discord *, const struct discord_guild *);