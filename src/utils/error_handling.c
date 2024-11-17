#include "../../header/include.h"

int check_error_character(const char *commands) {
    const char *allowed_char = "\"><(){}=+*-/._ ";

    for (int x = 0; commands[x] != '\0'; x++) {
        if (!isalnum(commands[x]) && !strchr(allowed_char, commands[x]))
            return -1;
    }
    return 0;
}

int check_only_special_characters(const char *commands) {
    const char *allowed_char = "><(){}=+-*/";

    for (int x = 0; commands[x] != '\0'; x++) {
        if (isalnum(commands[x]))
            return 0;

        if (!strchr(allowed_char, commands[x]))
            return 0;
    }

    return -1;
}

int check_arguments(const int ac) {
    if (ac > 2) {
        fprintf(stderr, "Too many arguments\n");
        return -1;
    }
    return 0;
}

int check_operator_usage(const char *commands) {
    const char *operators = "+-*/";

    for (int x = 0; commands[x] != '\0'; x++) {
        if (strchr(operators, commands[x])) {
            if (commands[x + 1] == '\0' ||
                (!isalnum(commands[x + 1]) && commands[x + 1] != commands[x] && commands[x + 1] != '=' && commands[x + 1] != ' ')) {
                return -1;
                }
        }
        if (commands[x] == '=') {
            if (commands[x + 1] == '\0' || (!isalnum(commands[x + 1]) && commands[x + 1] != ' ' && commands[x + 1] != '('))
                return -1;
            if (commands[x + 1] == ' ' && commands[x + 2] == '\0' && !isalnum(commands[x + 2]) && commands[x + 2] != '(')
                return -1;
        }
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

int check_commands_error(char const *commands) {
    if (check_error_character(commands)) {
<<<<<<< Updated upstream
        printf("Wrong character detected\n");
        return -1;
    }
    if (check_parenthesis(commands)) {
        printf("Incorrect use of parentheses\n");
        return -1;
    }
    if (check_only_special_characters(commands)) {
        printf("Only special characters\n");
        return -1;
    }
    if (check_operator_usage(commands)) {
        printf("Bad operator usage\n");
=======
        fprintf(stderr,"Wrong character detected\n");
        return -1;
    }
    if (check_parenthesis(commands)) {
        fprintf(stderr,"Incorrect use of parentheses\n");
        return -1;
    }
    if (check_only_special_characters(commands)) {
        fprintf(stderr,"Only special characters\n");
        return -1;
    }
    if (check_operator_usage(commands)) {
        fprintf(stderr,"Bad operator usage\n");
>>>>>>> Stashed changes
        return -1;
    }
    return 0;
}