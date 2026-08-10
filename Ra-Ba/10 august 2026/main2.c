#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int value;
    struct element* next;
} element;

int main(int argc, char** argv){
    int* vector = malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++)
        vector[i] = i + 1;
    
    element* first = malloc(sizeof(element));
    first->value = 1;

    element* last = malloc(sizeof(element));
    last->value = 6;
    last->next = NULL;

    element* p = first;
    int contor = 3;

    while(contor != 0){

        element* current = malloc(sizeof(element));
        current->value = contor;

        p->next = current;
        p = current;
        contor--;
    }
    p->next = last;

    // inserare dupa pozitia 1 (sau dupa al doilea element)

    contor = 1;
    p = first;
    while(contor != 2 && p != NULL){
        p = p->next;
        contor++;
    }

    element* next = p->next != NULL ? p->next : NULL; 

    element* inserted = malloc(sizeof(element));
    p->next = inserted;
    inserted->value = 9;
    inserted->next = next;

    // inserare in lista pe prima pozitie

    element* insertedFirst = malloc(sizeof(element));
    insertedFirst->value = 7;
    insertedFirst->next = first;
    first = insertedFirst;

    // stergerea din lista a primei pozitii
    first = first->next;
    free(insertedFirst);

    vector = realloc(vector, 6*sizeof(int));
    vector[5] = 8;

    for(int i = 5; i > 2; i--){
        vector[i] = vector[i - 1];
    }
    vector[2] = 10;

  // afisare
    printf("Vector: ");
    for(int i = 0; i < 6; i++)
        printf("%d ", vector[i]);
    printf("\n");

    p = first;
    printf("Lista: ");
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
    // eliberare memorie
    p = first;
    element* q = first;
    while(p != NULL){
        q = p;
        p = p->next; // !!!!!
        free(q);
    }
    free(vector);
    return 0;
}