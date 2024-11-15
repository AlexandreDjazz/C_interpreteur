#include "../../header/include.h"

//gestion des priorités
int operater_precedence(const char operater) {
    if (operater == '+' || operater == '-')
        return 1;
    if (operater == '*' || operater == '/')
        return 2;
    return 0;
}

void shunting_yard(const char *commands) {
    Token token;
    int index = 0;
    int index_algo = 0;
    char *algo = malloc(sizeof(char) * (strlen(commands) + 1));
    char *stack = malloc(sizeof(char) * 200);
    int stack_size = 0;
    int check = 0;
    char *var_nom = malloc(sizeof(char) * (strlen(commands) + 1));

    while ((token = lexer(&index, commands)).type != TOK_EOF) {
        if (token.type == TOK_PRINT) {
            my_print(commands);
            return;
        }

        //si token est variable ou entier, envoie dans la sortie
        if (token.type == TOK_INT || token.type == TOK_VAR) {
            for (int pos_tok = 0; token.value[pos_tok] != '\0'; pos_tok++) {
                algo[index_algo++] = token.value[pos_tok];
            }
            algo[index_algo++] = ' ';
        }

        //prendre la premier variable comme variable à modifier
        if(token.type == TOK_VAR && check==0) {
            strcpy(var_nom, token.value);
            check++;
        }

        //envoie de = à l'AST
        if(token.type == TOK_EQL) {
            algo[index_algo++] = '=';
            algo[index_algo++] = ' ';
        }

        //si paranthese ouvrante, ajout dans la pile / sinon on dépile si fermante
        if (token.type == TOK_PRT) {
            if (token.value[0] == '(')
                stack[stack_size++] = token.value[0];
            else {
                while (stack_size > 0 && stack[stack_size - 1] != '(') {
                    algo[index_algo++] = stack[--stack_size];
                    algo[index_algo++] = ' ';
                }
                stack_size--;
            }
        }

        //gestion des opérateurs (voir schéma wikipédia)
        if (token.type == TOK_PLS || token.type == TOK_MNS || token.type == TOK_MUL || token.type == TOK_DVD) {
            const int precedence = operater_precedence(token.value[0]);
            while (stack_size > 0 && operater_precedence(stack[stack_size - 1]) >= precedence) {
                algo[index_algo++] = stack[--stack_size];
                algo[index_algo++] = ' ';
            }
            stack[stack_size++] = token.value[0];
        }
    }

    //vidage de la stack
    while (stack_size > 0) {
        algo[index_algo++] = stack[--stack_size];
        algo[index_algo++] = ' ';
    }
    algo[index_algo] = '\0';

    LinkAST* ast = build_ast(algo);
    const double result = check_ast(ast);

    //création de la variable dans la structure ou modification de sa valeur
    int verif = 0;
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variable_stock[i].name, var_nom) == 0) {
            variable_stock[i].value = result;
            verif=1;
        }
    }
    if (!verif) {
        strcpy(variable_stock[variable_count].name, var_nom);
        variable_stock[variable_count].value = result;
        variable_count++;
    }

    free(algo);
    free(stack);
    free_ast(ast);
    free(var_nom);
}

