#include "header/include.h"


void myPrint(const char *commands) {
    int index=5;
    Token token;
    while ((token = lexer(&index, commands)).type != TOK_EOF) {
        if(token.type == TOK_VAR) {
            int good=0;
            for (int i = 0; i < variableCount; i++) {
                if (strcmp(token.value, variableStock[i].name) == 0){
                    printf("la valeur de %s est %f\n", token.value, variableStock[i].value);
                    good = 1;
                    break;
                }
            }
            if(!good){
                fprintf(stderr, "Variable '%s' not found\n", token.value);
                exit(EXIT_FAILURE);
            }

        }

    }
}