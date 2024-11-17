#include "../../header/include.h"

char *initialize_string(char *commands)
{
    const size_t length = 1024;
    char instruction[length];

    fgets(instruction, (int)length, stdin);
    commands = strdup(instruction);
    return commands;
}

int interactive_mode(void)
{
    char *commands = NULL;

    printf("Tap instructions or \"exit\" to quit\n");
    while (1)
    {
        printf(">> ");

        commands = initialize_string(commands);
        if (commands[0] == '\n')
            continue;
        commands[strcspn(commands, "\n")] = 0;

        if (!strcmp(commands, "exit") || !strcmp(commands, "EXIT"))
            break;
        if (!strcmp(commands, "exot"))
        {
            printf("You spelled it wrong, but it happened to me 1000 times.");
            break;
        }
        if (check_commands_error(commands))
            continue;
        shunting_yard(commands);
    }
    free(commands);
    return 0;
}