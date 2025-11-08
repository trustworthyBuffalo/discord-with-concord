#include "global_header.h"


#define MAX_GUILDS 10
#define MAX_ON_VOICE 100

extern struct discord_ready_state ready_state;
extern struct discord_guild_state_container guilds;
extern struct discord_user_on_voice_state_container users_on_voice;



// ready bot state
struct discord_ready_state {
    int status;
    
    // as snowflake
    uint64_t id;

};


// guild state
struct discord_guild_state{
    char  name[100];
    uint64_t id;

    uint16_t system_channel_id;

};

struct discord_guild_state_container {
    int count;
    struct discord_guild_state arr[10];
};

// on voice channel state
struct discord_user_on_voice_state {

    char *name;
    // snowflake
    uint64_t id;
    uint64_t voice_channel_id;
};

struct discord_user_on_voice_state_container {
    int count;
    struct discord_user_on_voice_state array[MAX_ON_VOICE];
};