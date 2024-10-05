#include "header/include.h"

void lexer(const char *commands) {
    Token token;
    int index = 0;

    while ((token = get_Token(&index, commands)).type != TOK_EOF) {
        switch (token.type) {
            case TOK_INT:
                printf("Integer : %s\n", token.value);
            break;
            case TOK_VAR:
                printf("Variable : %s\n", token.value);
            break;
            case TOK_OPR:
                printf("Operator : %s\n", token.value);
            break;
            case TOK_EQL:
                printf("Equal : %s\n", token.value);
            break;
            case TOK_PRT:
                printf("Parenthesis : %s\n", token.value);
            break;
            case TOK_CBK:
                printf("Curly bracket : %s\n", token.value);
            break;
            default:
                break;
        }
    }
    free(token.value);
}