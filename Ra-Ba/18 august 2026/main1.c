#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element {
    int value;
    struct element* next;
} element;

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

#define DIMENSIUNE 7 // inainte de procesare

// int DIM = 7; // in timpul procesarii programului

int hash(int value, int dimensiune){
    return value % dimensiune;
}

// functii valabile pe un vector de int-uri
void show(int tabela[], int dimensiune){
    for(int i = 0; i < dimensiune; i++)
        printf("%d ", tabela[i]);
    printf("\n");
}

void insert(int tabela[], int value, int dimensiune){
    int pos = hash(value, dimensiune);
    int pos_init = pos; // pozitia de la care pornim cu cautarea
    if(tabela[pos] == 0)
        tabela[pos] = value;
    else{
        bool ok = false;
        do{
            if(tabela[pos] == 0){
                ok = true;
                break;
            }
            pos = hash(pos + 1, dimensiune);
        }while(pos != pos_init);
        if(ok)
            tabela[pos] = value; // daca s-a gasit o pozitie libera, inseram acolo, altfel nu se insereaza nimic in tabela
    }
}

// functii pentru vector de liste
void init_tabela_liste(element* tabela_liste[], int dimensiune){
    for(int i = 0; i < dimensiune; i++){
        tabela_liste[i] = malloc(sizeof(element));
        tabela_liste[i]->value = 0;
        tabela_liste[i]->next = NULL;
    } // initializam fiecare element din vector cu capete de lista simplu inlantuita
}

void show_tabela_liste(element* tabela_liste[], int dimensiune){
    printf("Tabela de dispersie care contine elemente de tip element:\n");
    for(int i = 0; i < dimensiune; i++){
        element* p = tabela_liste[i]; // pentru fiecare element din tabela, afisam lista de pe acea pozitie
        while(p != NULL){
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");
    }
}

void insert_tabela_liste(element* tabela_liste[], int value, int dimensiune){
    int pos = hash(value, dimensiune);
    if(tabela_liste[pos]->value == 0)
        tabela_liste[pos]->value = value;
    else{ // adaugam la coada listei in caz de coliziuni
        element* p = tabela_liste[pos];
        while(p->next != NULL)
            p = p->next;
        p->next = malloc(sizeof(element));
        p->next->value = value;
        p->next->next = NULL;
    }
}

void free_tabela_liste(element* tabela_liste[], int dimensiune){
    for(int i = 0; i < dimensiune; i++){
        element* p = tabela_liste[i];
        element* q = p;
        while(p != NULL){
            q = p;
            p = p->next; // !!!!!
            free(q);
        }
    }
}
// operatii pe arbore
void insert_arbore(node* node, int value){
    if(node != NULL)
        if(value < node->value){ // trebuie pastrata referinta la nodul curent, nu putem transmite la functie o referinta care este nula, deoarece se face o copie catre aceasta. In afara functiei nu se poate accesa ce-am modificat
            if(node->left == NULL){
                node->left = malloc(sizeof(node));
                node->left->value = value;
                node->left->left = NULL;
                node->left->right = NULL;
            } else{
                insert_arbore(node->left, value);
            }
        } else if(node->value <= value){
            if(node->right == NULL){
                node->right = malloc(sizeof(node));
                node->right->value = value;
                node->right->left = NULL;
                node->right->right = NULL;
            } else{
                insert_arbore(node->right, value);
            }
        }
}

void free_arbore(node* node){
    if(node != NULL){
        free_arbore(node->left);
        free_arbore(node->right);
    }
    free(node); // nodul curent se va dezaloca ultimul
}

void show_arbore_inordine(node* node, int level){
    if(node != NULL){
        int current_level = level;
        show_arbore_inordine(node->left, level + 1);
        while(current_level != 0){
            printf("*"); current_level--;
        } // nodurile care sunt pe acelasi nivel sunt copiii celui de pe nivelul precedeent
        printf("%d\n", node->value);
        show_arbore_inordine(node->right, level + 1);
    }
}

int main(int argc, char** argv){
    // tabela de dispersie implementata cu vector alocat static
    int tabela[DIMENSIUNE] = {0};
    show(tabela, DIMENSIUNE);
    // inserare a valorii 22 in tabela
    printf("%d\n", hash(22, DIMENSIUNE));
    insert(tabela, 22, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 32, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 15, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 16, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 33, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 34, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 35, DIMENSIUNE);
    show(tabela, DIMENSIUNE);
    insert(tabela, 36, DIMENSIUNE);
    show(tabela, DIMENSIUNE);

    // tabela de dispersie implementata cu un vector de liste simplu inlantuite
    element* tabela_liste[DIMENSIUNE];
    init_tabela_liste(tabela_liste, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 22, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 32, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 15, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 18, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 17, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    insert_tabela_liste(tabela_liste, 25, DIMENSIUNE);
    show_tabela_liste(tabela_liste, DIMENSIUNE);
    free_tabela_liste(tabela_liste, DIMENSIUNE);
    // operatii pe arbore
    node* root = malloc(sizeof(node));
    root->value = 7;
    root-> left = NULL;
    root->right = NULL;
    insert_arbore(root, 6);
    insert_arbore(root, 4);
    insert_arbore(root, 5);
    insert_arbore(root, 8);
    insert_arbore(root, 10);
    insert_arbore(root, 9);
    insert_arbore(root, 3);
    printf("Arbore inordine:\n");
    show_arbore_inordine(root, 0);
    printf("\n");
    free_arbore(root);
    return 0;
}