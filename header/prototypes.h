#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "include.h"
#include "structures.h"

// file.c
long get_file_size(FILE *str);
char *copy_file(char *commands, FILE *file_commands);
char *check_and_copy_file(char *commands, char **av);

// string.c
int my_strlen(const char *str);
char *initialize_string(char *commands);

// lexer.c
void lexer(const char *commands);

// token.c
Token isInteger(int position, int *index, const char *commands, Token token);
Token isVariable(int position, int *index, const char *commands, Token token);
Token isOperator(int position, int *index, const char *commands, Token token);
Token isEqual(int position, int *index, const char *commands, Token token);
Token isParenthesis(int position, int *index, const char *commands, Token token);
Token isCurlyBracket(int position, int *index, const char *commands, Token token);
Token get_Token(int *index, const char *commands);

Stack* createStack(int capacity);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, char op);
char pop(Stack* stack);
char peek(Stack* stack);
int precedence(char op);

void shuntingYard(const char* expression);

#endif