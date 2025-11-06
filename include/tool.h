#pragma once

#include "global.h"



int get_token(const char *, char *);


int index_generate(int);

//==


char *get_guild_name( u64snowflake );
unsigned long discord_snowflake_to_ms_unit( uint64_t ); 
unsigned long get_current_time_in_ms( void );