/*2. Positivo, Negativo ou Zero — Leia um número e classifique-o como 
positivo, negativo ou zero. */

#include <stdio.h>

int main() {

    int num;

    printf("digite um numero: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("\nnumero positivo");
    }

    else if (num < 0) {
        printf("\nnumero negativo");
    }

    else {
        printf("\nnumero zero");
    }


    return 0;
}