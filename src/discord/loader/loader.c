#include "global_header.h"
#include "loader.h"



void loader() {

   printf("[..] running loader...\n");

   // load slash command
   slash_command_loader();
   prefix_command_loader();
   
   
   // another loader
   // ...


   printf("[OK] loader finished.\n");

} 