#include "global_header.h"


#define MAX_GUILDS 10
#define MAX_ON_VOICE 100

#define MAX_GUILD_TRACK 5
#define MAX_MEMBER_VOICE_TRACK 500


#define MAX_CHAR_NAME 101 // include null char

extern struct discord_ready_state ready_state;
extern struct discord_guild_state_container guilds;
extern struct track_guild_member_voices guild_member_voices_state;

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
struct track_member_voice {
    bool available;
    u64snowflake user_id;
    u64snowflake channel_id;
};

struct track_guild_member_voice {
    u64snowflake guild_id;
    struct track_member_voice array[MAX_MEMBER_VOICE_TRACK];
};

struct track_guild_member_voices {
    int count;
    struct track_guild_member_voice array[MAX_GUILD_TRACK];
};

// bot voice channel state
