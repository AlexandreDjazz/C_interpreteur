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

// remplace les espaces par des multiplications dans les calculs
void spaceToMultiply(char *commands) {
    int j = 0;
    int len = my_strlen(commands);
    char* output = malloc(sizeof(char) * (len * 2 + 1));

    for (int x = 0; x < len; x++) {
        j++;
        if (commands[x] == ' ') {
            Token token = lexer(&j, commands);
            if(token.type == TOK_PRT || token.type == TOK_INT) {
                output[x] = '*';
            }else {
                output[x] = commands[x];
            }
        } else {
            output[x] = commands[x];
        }
    }

    output[j] = '\0';

    strcpy(commands, output);  // Copie le resultat final dans la string
    free(output);
    printf("%s\n", commands);
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
            //test
                spaceToMultiply(commands);
            shunting_yard(commands);
    }
    free(commands);
    return 0;
}