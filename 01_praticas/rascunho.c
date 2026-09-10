#include <stdio.h>

void dobrar(int n) {        // recebe CÓPIA
    n = n * 2;              // só altera a cópia local
    printf("Dentro: %d\n", n);
}

int main(void) {
    int x;
    printf("passe um valor: ");
    scanf("%d", &x);
    dobrar(&x);              // passa cópia de x
    printf("Fora: %d\n", x); // ainda é 5
    return 0;
}
/* 

gcc -Wall lista2_ex6.c -o lista2_ex6

*/