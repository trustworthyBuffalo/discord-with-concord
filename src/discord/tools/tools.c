#include "global_header.h"

#define DISCORD_EPOCH 1420070400000


unsigned long get_time_from_snowflake_ms(uint64_t snowflakes) {

   uint64_t time_s = (snowflakes >> 22) + DISCORD_EPOCH; 

   return time_s;
}