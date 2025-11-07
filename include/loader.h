
// main loader
void loader();

void prefix_command_loader();
void slash_command_loader();

//==========================
// slash command


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

//====================================
// prefix command


struct prefix_command {
    char *name;
    char *description;
    void(* callback) (struct discord *, const struct discord_message *);
};

struct prefix_command_container {
    int count;
    struct prefix_command *arr;
};