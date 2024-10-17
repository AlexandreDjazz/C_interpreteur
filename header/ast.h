#ifndef INTERPRETEUR_AST_H
#define INTERPRETEUR_AST_H


typedef enum {
    wayNumber,
    wayOperator
} Typelink;

typedef enum {
    addOP,
    subOP,
    mulOP,
    divOP
} operatorType;



typedef struct {
    double value;
} numberLink;


typedef struct {
    operatorType op;
    struct linkAST* right;
    struct linkAST* left;
} operatorLink;


typedef struct linkAST {
    Typelink type;
    numberLink* number;
    operatorLink* operator;
} linkAST;






linkAST* create_link_number(double value);
linkAST* create_link_operator(operatorType op, linkAST* left, linkAST* right);
double checkAst(linkAST* link);
void freeAst(linkAST* link);
linkAST* build_ast(const char* algo);

#endif
