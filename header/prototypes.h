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
int interactive_mode(void);

// lexer.c
Token lexer(int *index, const char *commands);

// error_handling.c
int error_character(const char *commands);

// token.c
Token isInteger(int position, int *index, const char *commands, Token token);
Token isVariable(int position, int *index, const char *commands, Token token);
Token isOperator(int position, int *index, const char *commands, Token token);
Token isEqual(int position, int *index, const char *commands, Token token);
Token isParenthesis(int position, int *index, const char *commands, Token token);
Token isCurlyBracket(int position, int *index, const char *commands, Token token);
Token get_Token(int *index, const char *commands);

// shunting_yard.c
int operater_precedence(const char operater);
void shunting_yard(const char *commands);

#endif