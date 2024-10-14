#include "header/include.h"

int operater_precedence(const char operater) {
    if (operater == '+' || operater == '-') {
        return 1;
    }
    if (operater == '*' || operater == '/') {
        return 2;
    }
    return 0;
}

void shunting_yard(const char *commands) {
    Token token;
    int index = 0;
    int index_algo = 0;
    char *algo = malloc(sizeof(char) * (strlen(commands) + 1));
    char *stack = malloc(sizeof(char) * 200);
    int stack_size = 0;

    while ((token = lexer(&index, commands)).type != TOK_EOF) {
        if (token.type == TOK_INT || token.type == TOK_VAR) {
            for (int pos_tok = 0; token.value[pos_tok] != '\0'; pos_tok++) {
                algo[index_algo++] = token.value[pos_tok];
            }
            algo[index_algo++] = ' ';
        }

        if (token.type == TOK_PRT) {
            if (token.value[0] == '(')
                stack[stack_size++] = token.value[0];
            else {
                while (stack_size > 0 && stack[stack_size - 1] != '(') {
                    algo[index_algo++] = stack[--stack_size];
                    algo[index_algo++] = ' ';
                }
                stack_size--;
            }
        }

        if (token.type == TOK_PLS || token.type == TOK_MNS || token.type == TOK_MUL || token.type == TOK_DVD) {
            const int precedence = operater_precedence(token.value[0]);
            while (stack_size > 0 && operater_precedence(stack[stack_size - 1]) >= precedence) {
                algo[index_algo++] = stack[--stack_size];
                algo[index_algo++] = ' ';
            }
            stack[stack_size++] = token.value[0];
        }
    }
    stack[stack_size] = '\0';
    for (int x = stack_size - 1; x >= 0; x--) {
        algo[index_algo++] = stack[x];
        algo[index_algo++] = ' ';
    }
    algo[index_algo] = '\0';
    printf("Postfix Expression: %s\n", algo);
    free(algo);
    free(stack);
}