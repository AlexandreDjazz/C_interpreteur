#include "header/include.h"

int my_strlen(const char *str) {
    int length = 0;

    for (; str[length] != '\0'; length++);

    return length;
}

char *initialize_string(char *commands) {
    const size_t length = 1000;
    char instruction[length];
    int size = 0;

    fgets(instruction, (int)length, stdin);
    size = my_strlen(instruction);
    commands = malloc(sizeof(char) * (size + 1));

    for (int x = 0; x < size; x++)
        commands[x] = instruction[x];
    commands[size] = '\0';

    return commands;
}

int interactive_mode(void) {
    char *commands = NULL;

    printf("Tap instructions or \"exit\" to quit\n");
    while (1) {
        printf(">>");

        commands = initialize_string(commands);
        commands[strcspn(commands, "\n")] = 0;

        if (!strcmp(commands, "exit") || !strcmp(commands, "EXIT"))
            break;
        if (error_character(commands) == -1)
            printf("Wrong character detected\n");
        else
            lexer(commands);
    }
    free(commands);
    return 0;
}