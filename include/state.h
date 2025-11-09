#include "global_header.h"


#define MAX_ON_VOICE 100

#define MAX_GUILDS 5
#define MAX_MEMBER_VOICE_TRACK 500


#define MAX_CHAR_NAME 101 // include null char

extern struct discord_ready_state ready_state;
extern struct discord_guild_state_container guilds;
extern struct guild_state_list guild_states;

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
struct member_in_voice {
    bool available;
    u64snowflake user_id;
    u64snowflake channel_id;
};

struct bot_state {
    int status;
    u64snowflake voice_channel_id; // <- 0 when not in
};

struct guild_state {
    u64snowflake guild_id;
    char name[MAX_CHAR_NAME];

    struct member_in_voice member_in_voice_list[MAX_MEMBER_VOICE_TRACK];
    struct bot_state bot;
};

struct guild_state_list {
    // soon
    u64snowflake application_id;
    int status;

    // guild data segment
    int count;
    struct guild_state data[MAX_GUILDS];
};

// bot voice channel state
