#ifndef INTERPRETEUR_AST_H
#define INTERPRETEUR_AST_H


typedef enum {
    wayNumber,
    wayOperator
} TypeLink;


typedef enum {
    addOP,
    subOP,
    mulOP,
    divOP
} OperatorType;


typedef struct {
    double value;
} NumberLink;


typedef struct {
    OperatorType op;
    struct linkAST* right;
    struct linkAST* left;
} OperatorLink;


typedef struct linkAST {
    TypeLink type;
    NumberLink* number;
    OperatorLink* operator;
} LinkAST;


LinkAST* create_link_number(double value);
LinkAST* create_link_operator(OperatorType op, LinkAST* left, LinkAST* right);
double check_ast(LinkAST* link);
void free_ast(LinkAST* link);
float get_variable_value(const char *name);
void print_ast(LinkAST* node, int indent);
char* replace_variables_with_values(char *calculations);
LinkAST* build_ast(const char* calculations);

#endif
