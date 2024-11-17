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
    TOK_DBQ, // double quote
    TOK_EOF, // end of file
<<<<<<< Updated upstream
    TOK_PRINT // print
=======
    TOK_PRINT, // print
    TOK_STRING // string
>>>>>>> Stashed changes
};

typedef enum KEYWORD KEYWORD;
enum KEYWORD {
    IF,
    ELSE,
    WHILE,
    FOR
};
<<<<<<< Updated upstream

typedef struct {
    char *value;
    TokenType type;
} Token;

typedef struct
{
    char name[100];
=======

typedef struct {
    char *value;
    TokenType type;
} Token;

typedef struct
{
    char* name;
>>>>>>> Stashed changes
    float value;
} VariableInt;

typedef struct
{
    char* name;
    char* value;
} VariableString;

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