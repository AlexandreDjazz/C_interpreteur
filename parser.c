#include "header/include.h"

void shuntingYard(const char* expression) {
    Stack *operatorStack = createStack(100);
    char output[100]; // Stockage pour la sortie en NPI
    int k = 0;
    Token token;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        token = get_Token(&i, expression);

        // Si le token est un entier, on l'ajoute à la sortie
        if (token.type == TOK_INT) {
            output[k++] = c;
        }
        // Si c'est une parenthèse ouvrante, on l'empile
        else if (c == '(') {
            push(operatorStack, c);
        }
        // Si c'est une parenthèse fermante, on depile jusqu'a rencontrer une parenthese ouvrante
        else if (c == ')') {
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') {
                output[k++] = pop(operatorStack);
            }
            pop(operatorStack); // Depiler la parenthese ouvrante
        }

        else if (token.type == TOK_OPR) {
            // On depile les operateurs de priorite supérieure ou egale et on les ajoute à la sortie pour respecter l'ordre des priorite
            while (!isEmpty(operatorStack) && precedence(peek(operatorStack)) >= precedence(c)) {
                output[k++] = pop(operatorStack);
            }
            push(operatorStack, c);  // operateur courant
        }
    }

    // Vider la pile des opérateurs restants
    while (!isEmpty(operatorStack)) {
        output[k++] = pop(operatorStack);
    }

    output[k] = '\0'; // Terminer la chaîne de sortie
    printf("Postfix Expression: %s\n", output);

    free(operatorStack->data);
    free(operatorStack);
}
