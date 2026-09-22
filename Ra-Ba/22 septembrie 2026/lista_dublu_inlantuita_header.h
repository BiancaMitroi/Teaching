#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data); // antete de functii
void printList(Node* head);
void freeList(Node* head);
Node* search(Node* head, int key);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, Node* delNode);
void insertBeforeFirstElement(Node** head, int data);
