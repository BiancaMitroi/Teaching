#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct{
	int val;
	struct my_struct* next;
}my_struct;

int suma(int a, int b){
	return a + b;
}

void initialize(int* e){
	e[0] = 14;
	e[1] = 22;
	e[2] = 35;
	return;
}

void show(int* e){
	printf("%d\n", (*e));
	if((*e) == 35)
		return;
	show(e+1);
}

int main(int argc, int **argv){
//	int *d = malloc(5 * sizeof(int));
//	for(int i = 0; i < 5; i++){
//		d[i] = i;
//		printf("%d\n", d[i]);
//	}
//	free(d);
//	printf("%d\n", sizeof(long long int));
	
	my_struct* first = malloc(sizeof(my_struct));
	my_struct* second = malloc(sizeof(my_struct));
	my_struct* third = malloc(sizeof(my_struct));
	(*first).val = 5;
	(*first).next = second;
	(*second).val = 6;
	(*second).next = third;
	(*third).val = 7;
	(*third).next = NULL; // 00000000 - 4 octeti
	my_struct *p = first;
	while(p != NULL){
		printf("%d\n", (*p).val);
		p =(*p).next;
	}
	free(first);
	free(second);
	free(third);
	printf("%d\n", suma(5, 7));
	int e[3];
	initialize(e);
//	for(int i = 0; i < 3; i++)
//		printf("%d\n", e[i]);
	show(e);
	return 0;
}
