#include <stdio.h>


int main(void) {

    int a[3] = {1,2,3};
    int b[3] = {1,2,3};
    int c[3];

    for (int i = 0; i < 3; i++) {
        c[i] = a[i] + b[i];
    }

    printf("Vetor resultante:\n");

    for (int i = 0; i < 3; i++) {
        printf("%d \n",c[i]);
    }

    printf("\n");

    return 0;
}

/* 
gcc -Wall lista2_ex6.c -o lista2_ex6

*/