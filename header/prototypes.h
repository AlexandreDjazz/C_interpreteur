#ifndef PROTOTYPES_H
#define PROTOTYPES_H


#include "structures.h"


// file.c
void fileInterpret(const char *filename);

// string.c
int my_strlen(const char *str);
char *initialize_string(char *commands);
int interactive_mode(void);

// lexer.c
Token lexer(int *index, const char *commands);

// error_handling.c
int error_character(const char *commands);
int check_parenthesis(const char *commands);

// token.c
Token isInteger(int position, int *index, const char *commands, Token token);
Token isVariable(int position, int *index, const char *commands, Token token);
Token isOperator(int position, int *index, const char *commands, Token token);
Token isEqual(int position, int *index, const char *commands, Token token);
Token isParenthesis(int position, int *index, const char *commands, Token token);
Token isCurlyBracket(int position, int *index, const char *commands, Token token);
Token isPrint(int position, int *index, Token token);
Token get_Token(int *index, const char *commands);

// shunting_yard.c
int operater_precedence(const char operater);
void shunting_yard(const char *commands);

//variable.c
void myPrint(const char *commands);

#endif