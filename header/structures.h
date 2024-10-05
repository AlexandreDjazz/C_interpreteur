#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "prototypes.h"
#include "include.h"

typedef enum TokenType TokenType;
enum TokenType {
    TOK_VAR, // variable
    TOK_EQL, // equal
    TOK_INT, // integer
    TOK_OPR, // operator
    TOK_PRT, // parenthesis
    TOK_CBK, // curly bracket
    TOK_EOF  // end of file
};

typedef struct Token Token;
struct Token {
    char *value;
    TokenType type;
};

#endif