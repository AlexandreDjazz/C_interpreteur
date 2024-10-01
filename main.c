#include "interpreter.h"

int main(const int ac, char **av)
{
    char *commands = NULL;

    if (ac > 2) {
        printf("Too many arguments\n");
        return -1;
    }

    else if (ac == 2) {
        if ((commands = check_and_copy_file(commands, av)) == NULL) {
            free(commands);
            return -1;
        }
    }
    printf("%s\n", commands); //vérif lecture et copie fichier ok

    //else
        // read terminal

    return 0;
}