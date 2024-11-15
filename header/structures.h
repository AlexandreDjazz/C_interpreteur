#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum TokenType TokenType;
enum TokenType {
    TOK_VAR, // variable
    TOK_EQL, // equal
    TOK_INT, // integer
    TOK_PLS, // plus
    TOK_MNS, // minus
    TOK_MUL, // multiply
    TOK_DVD, // divide
    TOK_LOW, // lower
    TOK_SUP, // superior
    TOK_PRT, // parenthesis
    TOK_CBK, // curly bracket
    TOK_EOF,  // end of file
    TOK_PRINT // print
};

typedef struct Token Token;
struct Token {
    char *value;
    TokenType type;
};

typedef struct
{
    char name[10];
    float value;
} Variable;

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

#endif