#include "header/include.h"

int main(const int ac, char **av)
{
    char *commands = NULL;

    if (ac > 2) {
        printf("Too many arguments\n");
        return -1;
    }
    if (ac == 2) {
        if ((commands = check_and_copy_file(commands, av)) == NULL)
            return -1;
    }
    else
        commands = initialize_string(commands);

    lexer(commands);
    free(commands);
    return 0;
}