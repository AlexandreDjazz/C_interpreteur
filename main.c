#include "header/include.h"

int variableCount=0;
Variable variableStock[100];

int main(const int ac, char **av) {
    char *commands = NULL;


    if (ac > 2) {
        printf("Too many arguments\n");
        return -1;
    }
    if (ac == 2) {
        if ((commands = check_and_copy_file(commands, av)) == NULL)
            return -1;
        shunting_yard(commands);
    }
    else
        interactive_mode();

    free(commands);
    return 0;
}