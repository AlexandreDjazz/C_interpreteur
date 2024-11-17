#include "../../header/include.h"

Token is_integer(int position, int *index, const char *commands, Token token) {
    int x = 0;

    if (commands[position] == '-') {
        position++;
        x++;
        token.value[0] = '-';
    }
    while (isdigit(commands[position]) || commands[position] == '.') {
        token.value = realloc(token.value, sizeof(char) * (x + 1));
        token.value[x] = commands[position];
        position++;
        x++;
    }
    token.value[x] = '\0';
    token.type = TOK_INT;
    *index = position;
    return token;
}

Token is_double_quote(int position, int *index, const char *commands, Token token) {
    int x = 0;
    position++;
    while (commands[position] != '"') {
        token.value = realloc(token.value, sizeof(char) * (x + 1));
        token.value[x] = commands[position];
        position++;
        x++;
    }
    token.value[x] = '\0';
    token.type = TOK_DBQ;
    *index = position;
    return token;
}

Token is_variable(int position, int *index, const char *commands, Token token) {
    int x = 0;
    const char *allowed_char = "-_0123456789";

    while (isalpha(commands[position]) || strchr(allowed_char, commands[position])) {
        token.value = realloc(token.value, sizeof(char) * (x + 1));
        token.value[x] = commands[position];
        position++;
        x++;
    }
    token.value[x] = '\0';
    token.type = TOK_VAR;
    *index = position;
    return token;
}

Token is_operator(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';

    switch (token.value[0]) {
        case '+':
            token.type = TOK_PLS;
        break;
        case '-':
            token.type = TOK_MNS;
        break;
        case '*':
            token.type = TOK_MUL;
        break;
        case '/':
            token.type = TOK_DVD;
        break;
        case '<':
            token.type = TOK_LOW;
        break;
        case '>':
            token.type = TOK_SUP;
        break;
        default:
            break;
    }
    position++;
    *index = position;
    return token;
}

Token is_equal(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_EQL;
    position++;
    *index = position;
    return token;
}

Token is_parenthesis(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_PRT;
    position++;
    *index = position;
    return token;
}

Token is_curlyBracket(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_CBK;
    position++;
    *index = position;
    return token;
}

Token is_print(int position, int *index, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value = "print\0";
    token.type = TOK_PRINT;
    position += 5;
    *index = position;
    return token;
}

Token get_token(int *index, const char *commands) {
    Token token = {NULL, TOK_EOF};
    int position = *index;
    const char *operators = "+-*/<>";
    token.value = malloc(sizeof(char));

    while (commands[position] == ' ')
        position++;
    if (commands[position] == '"')
        return token = is_double_quote(position, index, commands, token);
    if (strncmp(commands, "print", 5) == 0 && position == 0)
        return token = is_print(position, index, token);
    if (isdigit(commands[position]) || (commands[position] == '-' && isdigit(commands[position + 1])))
        return token = is_integer(position, index, commands, token);
    if (isalpha(commands[position]) || commands[position] == '_')
        return token = is_variable(position, index, commands, token);
    if (commands[position] == '(' || commands[position] == ')')
        return token = is_parenthesis(position, index, commands, token);
    if (commands[position] == '{' || commands[position] == '}')
        return token = is_curlyBracket(position, index, commands, token);
    if (commands[position] == '=')
        return token = is_equal(position, index, commands, token);
    if (strchr(operators, commands[position]))
        return token = is_operator(position, index, commands, token);

    token.value = NULL;
    token.type = TOK_EOF;
    *index = position;
    return token;
}