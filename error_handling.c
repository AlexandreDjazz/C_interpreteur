#include "header/include.h"

//gestion des caractères illégaux
int error_character(const char *commands) {
    const char *allowed_char = "><(){}=+*-/ ";

    for (int x = 0; commands[x] != '\0'; x++) {
        if (!isalnum(commands[x]) && !strchr(allowed_char, commands[x]))
            return -1;
    }
    return 0;
}

int check_parenthesis(const char *commands) {
    int left_parenthesis = 0;
    int right_parenthesis = 0;

    for (int x = 0; commands[x] != '\0'; x++) {
        if (commands[x] == '(')
            left_parenthesis++;
        if (commands[x] == ')')
            right_parenthesis++;
    }
    return (left_parenthesis - right_parenthesis);
}