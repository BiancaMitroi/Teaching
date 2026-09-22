#include <stdio.h>
#include <stdlib.h>


int* createStack(int size);
void push(int* stack, int* top, int value);
void pop(int* stack, int* top);
void printStack(int* stack, int top);
void freeStack(int* stack);