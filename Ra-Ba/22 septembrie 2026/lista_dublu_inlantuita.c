#include <stdio.h>
#include <stdlib.h>
#include "lista_dublu_inlantuita_header.h"

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    search(head, 20) ? printf("Found 20\n") : printf("20 not found\n");
    search(head, 50) ? printf("Found 50\n") : printf("50 not found\n");
    insertBeforeFirstElement(&head, 5);

    printList(head);
    freeList(head);
    return 0;
}