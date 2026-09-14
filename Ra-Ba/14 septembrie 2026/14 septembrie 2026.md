## Heap

- parintele oricarui nod de la pozitia i in vectorul alocat se afla la pozitia i/2 (se ia catul impartirii intregi)
- Max-heap = se pot adauga elemente in heap in ordine descrescatoare
- Analog Min-heap
- Inaltimea unui nod = distanta de la nod pana la cea mai indepartata frunza
- Inaltimea heap-ului = inaltimea radacinii

Pentru figura, avem: (heap-size = 10, heap-length = 16)

i = 1

l = indicele copilului stanga (2)
r = indicele copilului dreapta (3)

2 > 10 & 3 > 1
    largest = 2
3 > 10 & 5 > 3
    largest = 3
3 != 1
    interschimbare(1 si 5 sau intre nodurile de pe pozitiile 1 si 3 in cadrul vectorului de heap)

Se coboara nodul
- Se poate construi heapul si de la frunze la parinte
- Pentru a mentine structura de max-heap, avem n apeluri de max-heapify, iar algoritmul dureaza logn => O(nlogn)
- Heapsort
- inserare, stergere
- Mergesort, insertionsort, quicksort - scheme/animatii
- programare dinamica