#include "header/include.h"


// Initialiser la pile
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Vérifier si la pile est vide
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Vérifier si la pile est pleine
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Empiler un élément
void push(Stack *stack, char op) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = op;
    }
}

// Dépiler un élément
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

// Consulter le sommet de la pile sans le dépiler
char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}



// Fonction pour déterminer la priorité d'un opérateur
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0; // Pas un opérateur
}