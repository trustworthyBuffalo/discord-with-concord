#include "global_header.h"

// On ready
void on_ready(struct discord *, const struct discord_ready *);


// Interaction and handler
void on_interaction(struct discord *, const struct discord_interaction *);

void slash_command_handler(struct discord *, const struct discord_interaction *);

void on_guild_create(struct discord *, const struct discord_guild *);


// message create
void on_message(struct discord *, const struct discord_message *);

void prefix_command_handler(struct discord *, const struct discord_message *);

// voice channel update
void on_voice_state_update(struct discord *, const struct discord_voice_state *);


// guild channel event
void on_channel_create(struct discord *, const struct discord_channel *);


// when program exit /  terminated
void on_program_exit(struct discord *);