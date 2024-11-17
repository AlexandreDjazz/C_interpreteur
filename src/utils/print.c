#include "../../header/include.h"

void my_print(const char *commands) {
    int index = 5;
    int valid = 0;
    Token token;
    token = lexer(&index, commands);

    if (token.type == TOK_PRT && token.value[0] == '(') {
        token = lexer(&index, commands);
        if (token.type == TOK_MNS) {
            printf("%s", token.value);
            token = lexer(&index, commands);
        }

        if (token.type == TOK_INT)
            printf("%s\n", token.value);
        else if (token.type == TOK_STRING)
            printf("%s\n", token.value);
        else if (token.type == TOK_VAR) {
            for (int i = 0; i < variable_int_count; i++) {
                if (strcmp(token.value, variable_int_stock[i].name) == 0) {
                    if (variable_int_stock[i].value == (int)variable_int_stock[i].value)
                        printf("La valeur de %s est %d\n", token.value, (int)variable_int_stock[i].value);
                    else
                        printf("La valeur de %s est %.3g\n", token.value, variable_int_stock[i].value);
                    valid = 1;
                    break;
                }
            }

            for (int i = 0; i < variable_string_count; i++) {
                if (strcmp(token.value, variable_string_stock[i].name) == 0) {
                    printf("La valeur de %s est %s\n", token.value, variable_string_stock[i].value);
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


void change_variable_int(const char* name, const float value) {
    for (int i = 0; i < variable_int_count; i++) {
        if (strcmp(variable_int_stock[i].name, name) == 0) {
            variable_int_stock[i].value = value;
            return;
        }
    }
    if(variable_int_count < 100) {
        variable_int_stock[variable_int_count].name = strdup(name);
        variable_int_stock[variable_int_count].value = value;
        variable_int_count++;
    }
    else{
        printf("limite du nombre de variable atteinte\n");
    }
}

void change_variable_string(const char* name, const char* value) {
    for (int i = 0; i < variable_string_count; i++) {
        if (strcmp(variable_string_stock[i].name, name) == 0) {
            variable_string_stock[i].value = strdup(value);
            return;
        }
    }
    if(variable_string_count < 100) {
        variable_string_stock[variable_string_count].name = strdup(name);
        variable_string_stock[variable_string_count].value = strdup(value);
        variable_string_count++;
    }
    else{
        printf("limite du nombre de variable atteinte\n");
    }
}