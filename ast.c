#include "header/include.h"


linkAST* create_link_number(double value) {

    linkAST* link = (linkAST*)malloc(sizeof(linkAST));
    numberLink* number = (numberLink*)malloc(sizeof(numberLink));

    number->value = value;

    link->type = wayNumber;
    link->number = number;
    link->operator = NULL;

    return link;
}


linkAST* create_link_operator(operatorType op, linkAST* left, linkAST* right) {

    linkAST* link = (linkAST*)malloc(sizeof(linkAST));
    operatorLink* operator = (operatorLink*)malloc(sizeof(operatorLink));


    operator->op = op;
    operator->left = left;
    operator->right = right;


    link->type = wayOperator;
    link->operator = operator;
    link->number = NULL;

    return link;
}


double checkAst(linkAST* link) {
    if (link->type == wayNumber) {

        return link->number->value;

    } else if (link->type == wayOperator) {

        double left = checkAst(link->operator->left);
        double right = checkAst(link->operator->right);


        switch (link->operator->op) {
            case addOP:
                return left + right;
            case subOP:
                return left - right;
            case mulOP:
                return left * right;
            case divOP:
                return left / right;
            default:
                fprintf(stderr, "unknown opérator\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;  
}



void freeAst(linkAST* link) {
    if (link->type == wayOperator) {
        
        freeAst(link->operator->left);
        freeAst(link->operator->right);
        
        free(link->operator);
    } else if (link->type == wayNumber) {
        
        free(link->number);
    }
    
    free(link);
}
