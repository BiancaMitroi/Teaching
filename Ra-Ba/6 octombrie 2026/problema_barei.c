#include <stdio.h>
#include <stdlib.h>

// p - vectorul de preturi in functie de lungimea barei, indecsii = lungimiile barei, p[i] = pretul barei de lungime i
// r - vectorul de rezultate partiale, pentru un anumit tip de taiere/partitionare a barei netaiate, avem un anumit pret pe care il putem obtine, indecsii = poisibilitatile de taiere luate in ordine, r[0] = pretul pe bara netaiata (de exemplu), r[1] = pretul cand am taiat doar o bucata de lungime 1 din bara etc.

#define N 5 

int memoized_cut_rod_aux(int p[], int n, int r[]){
    int q; // costul ce urmeaza a fi stocat in tabela de rezultate partiale
    if(r[n] >= 0) // verificam daca am populat toata tabela de rezultate partiale. Daca da, inseamna ca am ajuns la o modalitate optima de partitionare a barei de lungime n
        return r[n];
    if(n == 0)
        q = 0;
    else{
        q = -1;
        for(int i = 1; i <= n; i++){
            int q_aux = p[i] + memoized_cut_rod_aux(p, n - i, r);
            q = q > q_aux ? q : q_aux;
        }
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(int p[], int n, int r[]){
    for(int i = 0; i <= n; i++)
        r[i] = -1;
    return memoized_cut_rod_aux(p, n, r);
}

int main(){
    int p[N + 1] = {0, 1, 5, 8, 9, 11};
    int r[N + 1];
    printf("Pretul cel mai bun pe care il pot obtine in urma taierii barei de lungime %d este: %d\n", N, memoized_cut_rod(p, N, r));
    printf("Vectorul de rezultate partiale:\n");
    for(int i = 0; i <= N; i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}