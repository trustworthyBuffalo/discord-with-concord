#include "global_header.h"


// list

void prefix_ping(struct discord *, const struct discord_message *);
void prefix_join_voice(struct discord *, const struct discord_message *);
void prefix_leave_voice(struct discord *, const struct discord_message *);
void prefix_offline(struct discord *, const struct discord_message *);

void mention_message(struct discord *, const struct discord_message *);

// not implemented command response callback

void prefix_not_implemented(struct discord *, const struct discord_message *);
