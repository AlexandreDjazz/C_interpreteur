//
// Created by alexa on 14/10/2024.
//

#ifndef INTERPRETEUR_AST_H
#define INTERPRETEUR_AST_H

#endif //INTERPRETEUR_AST_H

//ast.c

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
