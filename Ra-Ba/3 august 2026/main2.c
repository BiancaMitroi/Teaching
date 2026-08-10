#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct{
	int val;
	struct my_struct* next;
}my_struct;

int main(int argc, char** argv){
	int* a = malloc(3*sizeof(int));
	for(int i = 0; i < 3; i++)
		a[i] = i + 1;
	my_struct* first = malloc(sizeof(my_struct));
	my_struct* second = malloc(sizeof(my_struct));
	my_struct* third = malloc(sizeof(my_struct));
	first->val = 1;
	first->next = second;
	second->val = 2;
	second->next = third;
	third->val = 3;
	third->next = NULL;
	//insert last
	// pe vector deja alocat dinamic cu 3 elemente
	a = realloc(a, 4*sizeof(int));
	a[3] = 4;
	printf("Afisare vector:\n");
	for(int i = 0; i < 4; i++)
		printf("%d\n", a[i]);
	my_struct* fourth = malloc(sizeof(my_struct));
	third->next = fourth;
	fourth->val = 4;
	fourth->next = NULL;
	my_struct* p = first;
	printf("Afisare lista:\n");
	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}
}
