#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[10];
    int value;
} Variable;

Variable variableStock[100];
int variableAmount = 0;

char *noSpace(const char *input)
{
    int l = strlen(input);
    char *new = malloc(l + 1);
    int j = 0;
    for (int i = 0; i < l; i++)
    {
        if (*(input + i) != ' ')
        {
            *(new + j) = *(input + i);
            j++;
        }
    }
    *(new + j) = '\0';
    return new;
}

void print(const char *new)
{
    char *varNom = malloc(11);
    int i = 6;
        while (*(new + i) != '\0' && *(new + i) != ')' && *(new + i) != '(')
        {
            varNom[i - 6] = new[i];
            i++;
        }
        varNom[i - 6] = '\0';

        int good = 0;
        for (int k = 0; k < variableAmount; k++)
        {
            if (strcmp(varNom, variableStock[k].name) == 0)
            {
                printf("la valeur de %s est %d", varNom, variableStock[k].value);
                good = 1;
            }
        }
        if (!good)
        {
            printf("Cette variable n'as pas de valeur");
        }
        free(varNom);
}

void interpret(const char *input)
{
    char *new = noSpace(input);
    char *varNom = malloc(11);
    if (strncmp("print", new, 5) == 0)
    {
        print(new);
    }
    else
    {
        
        int value = 0;
        int i = 0;

        while (*(new + i) != '=')
        {
            varNom[i] = new[i];
            i++;
        }
        varNom[i] = '\0';

        if (new[i] == '=')
        {
            i++;
            while (*(new + i) != '\0' && isdigit(*(new + i)))
            {
                value = value * 10 + (*(new + i) - 48);
                i++;
            }
        }
        // printf("Variable %s assignee a %d\n", varNom, value);
        strcpy(variableStock[variableAmount].name, varNom);
        variableStock[variableAmount].value = value;
        variableAmount++;
    }
    free(new);
    free(varNom);
}

void main()
{
    interpret("abc = 1337");
    // printf("Valeur de x : %d\n", (int)(varTable[0].value)); // Affiche la valeur de x
    interpret("x = 10");
    // printf("Valeur de y : %d\n", (int)(varTable[1].value)); // Affiche la valeur de y
    interpret("print(y)");
    
}
// Dans votre fonction main()
/*
interpret("x = 10");
interpret("y = x + 5");
interpret("print(y)");  // Doit afficher 15
interpret("a = 3 + 4 * 2");  // Doit donner a = 11
interpret("b = (1 + 2) * (3 - 1)");  // Doit donner b = 6
interpret("print(a)");  // Doit afficher 11
interpret("print(b)");  // Doit afficher 6
*/
