#include "header/include.h"



Token isInteger(int position, int *index, const char *commands, Token token) {
    int x = 0;
    while (commands[position] >= '0' && commands[position] <= '9' ) {
        token.value = realloc(token.value, sizeof(char) * x + 1);
        token.value[x] = commands[position];
        position++;
        x++;
    }
    token.value[x] = '\0';
    token.type = TOK_INT;
    *index = position;
    return token;
}

Token isVariable(int position, int *index, const char *commands, Token token) {
    int x = 0;
    while ((commands[position] >= 'A' && commands[position] <= 'Z') ||
           (commands[position] >= 'a' && commands[position] <= 'z')) {
        token.value = realloc(token.value, sizeof(char) * x + 1);
        token.value[x] = commands[position];
        position++;
        x++;
    }
    token.value[x] = '\0';
    token.type = TOK_VAR;
    *index = position;
    return token;
}

Token isOperator(int position, int *index, const char *commands, Token token) {
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

Token isEqual(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_EQL;
    position++;
    *index = position;
    return token;
}

Token isParenthesis(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_PRT;
    position++;
    *index = position;
    return token;
}

Token isCurlyBracket(int position, int *index, const char *commands, Token token) {
    token.value = realloc(token.value, sizeof(char) * 2);
    token.value[0] = commands[position];
    token.value[1] = '\0';
    token.type = TOK_CBK;
    position++;
    *index = position;
    return token;
}

Token get_Token(int *index, const char *commands) {
    Token token = {NULL, TOK_EOF};
    int position = *index;
    token.value = malloc(sizeof(char));

    while (commands[position] == ' ')
        position++;
    if (commands[position] >= '0' && commands[position] <= '9' )
        return token = isInteger(position, index, commands, token);
    if ((commands[position] >= 'A' && commands[position] <= 'Z') || (commands[position] >= 'a' && commands[position] <= 'z'))
        return token = isVariable(position, index, commands, token);
    if ((commands[position] == '+') || (commands[position] == '-') || (commands[position] == '*') ||
        (commands[position] == '/') || (commands[position] == '>') || (commands[position] == '<'))
        return token = isOperator(position, index, commands, token);
    if (commands[position] == '(' || commands[position] == ')')
        return token = isParenthesis(position, index, commands, token);
    if (commands[position] == '{' || commands[position] == '}')
        return token = isCurlyBracket(position, index, commands, token);
    if (commands[position] == '=')
        return token = isEqual(position, index, commands, token);

    token.value = NULL;
    token.type = TOK_EOF;
    *index = position;
    return token;
}