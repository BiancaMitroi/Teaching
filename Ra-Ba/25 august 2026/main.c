#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

void insert_arbore(node* node, int value){
    if(node != NULL)
        if(value < node->value){
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

node* search(node* node, int value){
    if(node != NULL){
        if(value == node->value){
            return node;
        } else if(node->left != NULL && value < node->value){ 
            search(node->left, value);
        } else if(node->right != NULL && node->value <= value){
            search(node->right, value);
        } else {
            return NULL;
        }
    } else
        return NULL;
}

node* succesor(node* root, int value){
    node* nod = search(root, value);
    if(nod == NULL || nod->right == NULL)
        return NULL;
    else{
        node* p = nod->right;
        while(p->left != NULL)
            p = p->left;
        return p;
    }
}

node* ante_succesor(node* root, int value){
    node* nod = search(root, value);
    if(nod == NULL || nod->right == NULL)
        return NULL;
    else{
        node* p = nod->right;
        while(p->left->left != NULL)
            p = p->left;
        return p;
    }
}

void remove_arbore(node* root, int value){
    node* nod = search(root, value); // nodul pe care vrem sa-l stergem
    node* succ = succesor(nod, value); // nodul succesor
    node* ante_succ = ante_succesor(nod, value); // parintele succesorului - trebuie sa-i actualizam referinta la null dupa ce stergem frunza succesor
    if(nod != NULL && succ != NULL){
        nod->value = succ->value;
        free(succ);
        ante_succ->left = NULL;
    }
}

int main(int argc, char** argv){
    node* root = malloc(sizeof(node));
    root->value = 7;
    root->left = NULL;
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
    node* element = search(root, 8);
    printf("%d\n", element->value);
    node* succ = succesor(root, 8);
    if(succ != NULL)
        printf("%d\n", succ->value);
    else
        printf("Nu exista succesor\n");
    remove_arbore(root, 8);
    printf("Arbore inordine:\n");
    show_arbore_inordine(root, 0);
    free_arbore(root);
    return 0;
}