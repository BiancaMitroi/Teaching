#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

#define SIZE 10 // good practice to define a constant for the stack size
// int size = 10; - variabila globala, este vazuta de toate functiile din cadrul fisierului

int main() {
    int* stack = createStack(SIZE);
    int top = -1; // index of the top element in the stack
    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);
    printStack(stack, top);
    pop(stack, &top);
    printStack(stack, top);
    freeStack(stack);
    return 0;
}