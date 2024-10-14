#include "header/include.h"

Token lexer(int *index, const char *commands) {
    Token token;

    while ((token = get_Token(index, commands)).type != TOK_EOF) {
        switch (token.type) {
            case TOK_INT:
                return token;
            break;
            case TOK_VAR:
                return token;
            break;
            case TOK_PLS:
            case TOK_MNS:
            case TOK_MUL:
            case TOK_DVD:
            case TOK_LOW:
            case TOK_SUP:
                return token;
            break;
            case TOK_EQL:
                return token;
            break;
            case TOK_PRT:
                return token;
            break;
            case TOK_CBK:
                return token;
            break;
            default:
                break;
        }
    }
    free(token.value);
    return token;
}