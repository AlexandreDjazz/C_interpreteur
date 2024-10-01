#include "interpreter.h"

long get_Size_File(FILE *str) {

    long size = 0;

    fseek(str, 0, SEEK_END);
    size = ftell(str);
    fseek(str, 0, SEEK_SET);

    return size;
}

char *copy_file(char *commands, FILE *file_commands) {

    unsigned int i = 0;
    char c;

    while ((c = (char)fgetc(file_commands)) != EOF)
        commands[i++] = c;
    commands[i] = '\0';

    return commands;
}

char *check_and_copy_file(char *commands, char **av) {

    long size = 0;

    FILE *file_commands = fopen(av[1], "r");
    if (file_commands == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    size = get_Size_File(file_commands);
    commands = malloc(sizeof(char) * (size + 1));
    commands = copy_file(commands, file_commands);
    fclose(file_commands);

    return commands;
}