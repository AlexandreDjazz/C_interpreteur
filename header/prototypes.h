#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "structures.h"

// file.c
void file_interpret(const char *file_name);

// string.c
char *initialize_string(char *commands);
int interactive_mode(void);

// lexer.c
Token lexer(int *index, const char *commands);

// error_handling.c
int check_error_character(const char *commands);
int check_only_special_characters(const char *commands);
int check_arguments(const int ac);
int check_operator_usage(const char *commands);
int check_parenthesis(const char *commands);
int check_commands_error(char const *commands);

// token.c
Token is_integer(int position, int *index, const char *commands, Token token);
Token is_double_quote(int position, int *index, const char *commands, Token token);
Token is_variable(int position, int *index, const char *commands, Token token);
Token is_iperator(int position, int *index, const char *commands, Token token);
Token is_equal(int position, int *index, const char *commands, Token token);
Token is_parenthesis(int position, int *index, const char *commands, Token token);
Token is_curlyBracket(int position, int *index, const char *commands, Token token);
Token is_print(int position, int *index, Token token);
Token get_token(int *index, const char *commands);

// shunting_yard.c
int operater_precedence(const char operater);
void shunting_yard(const char *commands);

//print.c
void my_print(const char *commands);
void change_variable_int(const char* name, const float value);
void change_variable_string(const char* name, const char* value);

//ast.c

LinkAST* create_link_number(const double value);
LinkAST* create_link_operator(const OperatorType op, LinkAST* left, LinkAST* right);
double check_ast(const LinkAST* link);
void free_ast(LinkAST* link);
float get_variable_value(const char *name);
void print_ast(const LinkAST* node, const int indent);
char* replace_variables_with_values(char *calculations);
LinkAST* build_ast(const char* calculations);

//ast.c

LinkAST* create_link_number(const double value);
LinkAST* create_link_operator(const OperatorType op, LinkAST* left, LinkAST* right);
double check_ast(const LinkAST* link);
void free_ast(LinkAST* link);
float get_variable_value(const char *name);
void print_ast(const LinkAST* node, const int indent);
char* replace_variables_with_values(char *calculations);
LinkAST* build_ast(const char* calculations);

#endif