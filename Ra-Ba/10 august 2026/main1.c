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

    // inserare de element pe ultima pozitie

    element* append = malloc(sizeof(element));
    last->next = append;
    append->value = 7;
    append->next = NULL;
    // pentru a mentine la curent last-ul
    // last = append;

    vector = realloc(vector, 6*sizeof(int));
    vector[5] = 8;

    // cautare de ultim element 

    printf("Ultimul element din vector: %d\n", vector[4]);
    printf("Ultimul element din lista cand stim referinta lui este: \%d\n", last->value);
    printf("Ultimul element din lista atunci cand nu stim referinta lui este: ");
    p = first;
    while(p->next != NULL){
        p = p->next;
    }
    printf("%d\n", p->value);
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