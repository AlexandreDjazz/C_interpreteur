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

    printf("Enter instructions: \n");
    fgets(instruction, (int)length, stdin);
    size = my_strlen(instruction);
    commands = malloc(sizeof(char) * size + 1);

    for (int x = 0; x < size; x++)
        commands[x] = instruction[x];
    commands[size] = '\0';

    return commands;
}