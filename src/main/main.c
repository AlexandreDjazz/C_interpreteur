#include "../../header/include.h"

int variable_int_count=0;
VariableInt variable_int_stock[100];
int variable_string_count=0;
VariableString variable_string_stock[100];
//déclaration du tableau contenant les variables

int main(const int ac, char **av) {
    char *commands = NULL;

    if (check_arguments(ac) == -1)
        return -1;
    if (ac == 2)
        file_interpret(av[1]);
    else
        interactive_mode();

    free(commands);
    return 0;
}