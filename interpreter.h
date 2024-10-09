#ifndef interpreter_h
#define interpreter_h

#include <stdio.h>
#include <stdlib.h>


// file.c
long get_Size_File(FILE *str);
char *copy_file(char *commands, FILE *file_commands);
char *check_and_copy_file(char *commands, char **av);



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


#endif


