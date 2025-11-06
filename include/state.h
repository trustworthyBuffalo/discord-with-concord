#include "global_header.h"


#define MAX_GUILDS 10

extern struct discord_ready_state ready_state;
extern struct discord_guild_state_container guilds;


struct discord_ready_state {
    int status;
    
    // as snowflake
    uint64_t id;
};



struct discord_guild_state{
    char  *name;
    uint64_t id;
};

struct discord_guild_state_container {
    int count;
    struct discord_guild_state arr[10];
};