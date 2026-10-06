#include <stdio.h>
#include <stdlib.h>

unsigned int suma(unsigned int n){
    if(n == 1) // conditia de oprire
        return 1;
    else
        return n + suma(n - 1);
}

int main(){
    printf("Suma primelor n numere naturale: %d\n", suma(4));
    return 0;
}