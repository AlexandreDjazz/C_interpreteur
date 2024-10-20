#include "header/include.h"

//remplir la structure avec la valeur reçu
linkAST* create_link_number(double value) {

    linkAST* link = (linkAST*)malloc(sizeof(linkAST));
    numberLink* number = (numberLink*)malloc(sizeof(numberLink));

    number->value = value;

    link->type = wayNumber;
    link->number = number;
    link->operator = NULL;

    return link;
}

//enregister les opérateurs
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

//caculateur
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

//------------------------------------------------------------------------------------------------------------------------
// libere la mémoire
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

//------------------------------------------------------------------------------------------------------------------------

//envoie nom de la variabl pour récup sa valeur
float get_variable_value(const char *name) {

    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variableStock[i].name, name) == 0) {
            return variableStock[i].value;
        }
    }
    fprintf(stderr, "Variable '%s' not found\n", name);
    exit(EXIT_FAILURE);
}

//------------------------------------------------------------------------------------------------------------------------

//changer la variable en valeur
char* replace_variables_with_values(char *calculations) {
    char *result = malloc(strlen(calculations) * 10);
    result[0] = '\0';

    char *token = strtok(calculations, " ");
    while (token != NULL) {

        if ((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z')) {

            float value = get_variable_value(token);

            char value_str[20];
            sprintf(value_str, "%f", value);
            strcat(result, value_str);
        } else {
            strcat(result, token);
        }
        strcat(result, " ");
        token = strtok(NULL, " ");
    }

    return result;
}

//------------------------------------------------------------------------------------------------------------------------

//l'addition de toutes les fonctions
linkAST* build_ast(const char* calculations) {
    char *token;
    linkAST* stack[100];
    int stack_index = 0;
    char *check;

    if (strchr(calculations, '=') != NULL) { 
        check = strchr(calculations, '=') + 1;
    } else {
        check = calculations;
    }

    char *calculationsCopy = strdup(check);


    char *expression_with_values = replace_variables_with_values(calculationsCopy);

    token = strtok(expression_with_values, " ");
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

    free(expression_with_values);
    free(calculationsCopy);
    return stack[0];
}

//------------------------------------------------------------------------------------------------------------------------