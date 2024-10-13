#include "header/include.h"

int error_character(const char *commands) {
    const char *allowed_char = "><(){}=+*-/ ";

    for (int x = 0; commands[x] != '\0'; x++) {
        if (!isalnum(commands[x]) && !strchr(allowed_char, commands[x]))
            return -1;
    }
    return 0;
}