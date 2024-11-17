#include "../../header/include.h"

//remplir la structure avec la valeur reçu
LinkAST* create_link_number(const double value) {

    LinkAST* link = (LinkAST*)malloc(sizeof(LinkAST));
    NumberLink* number = (NumberLink*)malloc(sizeof(NumberLink));
    number->value = value;

    link->type = wayNumber;
    link->number = number;
    link->operator = NULL;

    return link;
}

//enregister les opérateurs
LinkAST* create_link_operator(const OperatorType op, LinkAST* left, LinkAST* right) {

    LinkAST* link = (LinkAST*)malloc(sizeof(LinkAST));
    OperatorLink* operator = (OperatorLink*)malloc(sizeof(OperatorLink));

    operator->op = op;
    operator->left = left;
    operator->right = right;

    link->type = wayOperator;
    link->operator = operator;
    link->number = NULL;

    return link;
}

//caculateur
double check_ast(const LinkAST* link) {
    if (link->type == wayNumber)
        return link->number->value;

    const double left = check_ast(link->operator->left);
    const double right = check_ast(link->operator->right);

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
            return -10001;
    }
}

// libere la mémoire
void free_ast(LinkAST* link) {
    if (link->type == wayOperator) {
        free_ast(link->operator->left);
        free_ast(link->operator->right);
        free(link->operator);
    } else if (link->type == wayNumber)
        free(link->number);
    free(link);
}

//envoie nom de la variabl pour récup sa valeur
float get_variable_value(const char *name) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variable_stock[i].name, name) == 0)
            return variable_stock[i].value;
    }
    fprintf(stderr, "Variable '%s' not found\n", name);
    return 0.0;
}

//affiche l'arbre AST
void print_ast(const LinkAST* node, const int indent) {
    if (node == NULL)
        return;

    for (int i = 0; i < indent; i++)
        printf("    ");

    if (node->type == wayOperator) {
        printf("%c\n",
               (node->operator->op == addOP) ? '+' :
               (node->operator->op == subOP) ? '-' :
               (node->operator->op == mulOP) ? '*' :
               (node->operator->op == divOP) ? '/' : '?');

        // Appel récursif sur les sous-arbres gauche et droit
        print_ast(node->operator->left, indent + 1);
        print_ast(node->operator->right, indent + 1);

    } else if (node->type == wayNumber) {
        if (node->number->value == (int)node->number->value)
            printf("%d\n", (int)node->number->value);
        else
            printf("%.3g\n", node->number->value);
    }
}

//changer la variable en valeur
char* replace_variables_with_values(char *calculations) {
    char *result = malloc(strlen(calculations) * 10);
    result[0] = '\0';
    const char *token = strtok(calculations, " ");

    while (token != NULL) {
        if (isalpha(token[0])) {
            const float value = get_variable_value(token);
            char value_str[20];
            sprintf(value_str, "%f", value);
            strcat(result, value_str);
        }
        else
            strcat(result, token);
        strcat(result, " ");
        token = strtok(NULL, " ");
    }
    return result;
}

//l'addition de toutes les fonctions
LinkAST* build_ast(const char* calculations) {
    char *token;
    LinkAST* stack[100];
    int stack_index = 0;
    const char *check;

    if (strchr(calculations, '=') != NULL)
        check = strchr(calculations, '=') + 1;
    else
        check = calculations;

    char *calculations_copy = strdup(check);
    char *expression_with_values = replace_variables_with_values(calculations_copy);
    token = strtok(expression_with_values, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            const double value = atof(token);
            stack[stack_index++] = create_link_number(value);
        } else {
            LinkAST* right = stack[--stack_index];
            LinkAST* left = stack[--stack_index];
            OperatorType op;

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
                    free(calculations_copy);
                    exit(EXIT_FAILURE);
            }
            stack[stack_index++] = create_link_operator(op, left, right);
        }
        token = strtok(NULL, " ");
    }

    free(expression_with_values);
    free(calculations_copy);
    LinkAST* root = stack[0];
    printf("____________________\nAST :\n");
    print_ast(root,0);
    printf("____________________\n");

    return root;
}