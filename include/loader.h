
// main loader
void loader();


//==========================
// slash command


void slash_command_loader();

struct slash_command {
    char *name;
    char *description;
    void (* callback)(struct discord *, const struct discord_interaction *);
};

struct slash_command_container {
    int count;
    struct slash_command *arr;
};


//
//====================================
