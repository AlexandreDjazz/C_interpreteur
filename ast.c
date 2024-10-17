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



linkAST* build_ast(const char* calculations) {

    char *token;
    linkAST* stack[100];
    int stack_index = 0;

    //Herman
    const char *check = strchr(calculations, '=');
    if (check == NULL) {
        fprintf(stderr, "No checkession found after '='\n");
    }
    check++;


    char *calculationsCopy = strdup(check);
    token = strtok(calculationsCopy, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            double value = atof(token);
            stack[stack_index++] = create_link_number(value);
        } else {
            linkAST* right = stack[--stack_index];
            linkAST* left = stack[--stack_index];
            operatorType op;

            switch (token[0]) {
                case '+':
                    op = addOP;
                    break;
                case '-':
                    op = subOP;
                    break;
                case '*':
                    op = mulOP;
                    break;
                case '/':
                    op = divOP;
                    break;
                default:
                    fprintf(stderr, "Unknown operator: %s\n", token);
                    free(calculationsCopy);
                    exit(EXIT_FAILURE);
            }

            stack[stack_index++] = create_link_operator(op, left, right);
        }
        token = strtok(NULL, " ");
    }

    free(calculationsCopy);
    return stack[0];
}
