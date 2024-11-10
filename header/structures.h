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

//structure variable
typedef struct
{
    char name[10];
    float value;
} Variable;

#endif