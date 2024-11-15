#include "../../header/include.h"

void my_print(const char *commands) {
    int index = 5;
    Token token;
    token = lexer(&index, commands);

    if (token.type == TOK_PRT && token.value[0] == '(') {
        token = lexer(&index, commands);
        if (token.type == TOK_VAR) {
            int good = 0;
            for (int i = 0; i < variable_count; i++) {
                if (strcmp(token.value, variable_stock[i].name) == 0) {
                    printf("la valeur de %s est %f\n", token.value, variable_stock[i].value);
                    good = 1;
                    break;
                }
            }

            if (!good)
                fprintf(stderr, "Variable '%s' not found\n", token.value);
            token = lexer(&index, commands);

            if (token.type == TOK_PRT && token.value[0] == ')')
                return;
            fprintf(stderr, "Erreur : ')' manquant ! ");
        }
    }
    else
        fprintf(stderr, "Erreur : '(' manquant ! ");
}