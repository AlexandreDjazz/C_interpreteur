#include "header/include.h"

int variable_count=0;
Variable variable_stock[100];
//déclaration du tableau contenant les variables


int main(const int ac, char **av) {
    char *commands = NULL;
    if (ac > 2) {
        printf("Too many arguments\n");
        return -1;
    }
    if (ac == 2) {
        file_interpret(av[1]);
    }
    else
        interactive_mode();

    free(commands);
    return 0;
}