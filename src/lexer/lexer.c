#include "../../header/include.h"

//création de token
Token lexer(int *index, const char *commands) {
    Token token;

    while ((token = get_token(index, commands)).type != TOK_EOF)
        return token;

    free(token.value);
    return token;
}