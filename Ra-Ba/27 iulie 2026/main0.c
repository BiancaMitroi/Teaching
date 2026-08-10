// Comentariu pe un singur rand

/*
Comentariu pe
mai multe randuri
*/

// #include <iostream.h>
// #include <stdio.h>
// #include <stdlib.h>

int main(int argc, char** argv[]) {
    printf("Hello World!\n");
    printf("%s", "Hello, World\n");
    int a = 5;
    printf("%d\n", a);

    if(a > 10)
        printf("A este mai mare ca 10\n");
    else
        printf("A este mai mare ca 10\n");

    int b[5] = {1, 2, 3, 4, 5};

    int c[6];
    for(int i = 0; i < 6; i++)
        c[i] = i * 2;

    for(int i = 0; i < 5; i++)
        printf("%d\n", b[i]);

    return 0;
}
