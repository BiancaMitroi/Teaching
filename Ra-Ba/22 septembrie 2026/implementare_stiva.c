#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

#define SIZE 10 // good practice to define a constant for the stack size
// int size = 10; - variabila globala, este vazuta de toate functiile din cadrul fisierului

int* createStack(int size) {
    int* arr = (int*)malloc(size * sizeof(int)); // variabila locala, este vazuta doar in cadrul functiei
    if (!arr) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

void push(int* stack, int* top, int value) {
    // Check if the stack is full
    if (*top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++(*top)] = value;
}

void pop(int* stack, int* top) {
    // Check if the stack is empty
    if (*top < 0) {
        printf("Stack underflow\n");
        return;
    }
    (*top)--;
}

void printStack(int* stack, int top) {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void freeStack(int* stack) {
    free(stack);
}