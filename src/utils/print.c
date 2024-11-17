#include "../../header/include.h"

void my_print(const char *commands) {
    int index = 5;
    Token token;
    token = lexer(&index, commands);
    int count = 0;

    for (int x = 0; commands[x]; x++) {
        if (commands[x] == '-')
            count++;
    }

    if (count > 1) {
        fprintf(stderr, "Too many - operator in : \"%s\"\n", commands);
        return;
    }

    if (token.type == TOK_PRT && token.value[0] == '(') {
        token = lexer(&index, commands);
        if (token.type == TOK_MNS) {
            printf("%s", token.value);
            token = lexer(&index, commands);
        }

        if (token.type == TOK_INT)
            printf("%s\n", token.value);
        else if (token.type == TOK_DBQ)
            printf("%s\n", token.value);
        else if (token.type == TOK_VAR) {
            int valid = 0;
            for (int i = 0; i < variable_count; i++) {
                if (strcmp(token.value, variable_stock[i].name) == 0) {
                    if (variable_stock[i].value == (int)variable_stock[i].value)
                        printf("La valeur de %s est %d\n", token.value, (int)variable_stock[i].value);
                    else
                        printf("La valeur de %s est %.3g\n", token.value, variable_stock[i].value);
                    valid = 1;
                    break;
                }
            }

            if (!valid)
                fprintf(stderr, "Variable '%s' not found\n", token.value);
            token = lexer(&index, commands);

            if (token.type == TOK_PRT && token.value[0] == ')')
                return;
            fprintf(stderr, "Error : ')' missing ! \n");
        }
    }
    else
        fprintf(stderr, "Error : '(' missing ! \n");
}