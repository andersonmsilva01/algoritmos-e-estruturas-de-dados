/*
1. Incrementar por referência

Crie a função incrementar(int *numero). Ela deve aumentar em 1 o valor da
variável recebida por referência.

No main(), leia um número inteiro, mostre seu valor antes da chamada,
chame a função e mostre o valor depois.
*/

#include <stdio.h>

void incrementar(int *numero) {
 *numero = *numero + 1;
}

int main(void) {
    
    int n;
    printf("digite um numero: ");
    scanf("%d",&n);
    printf("\nnumero antes da funcao: %d \n", n);

    incrementar(&n);
    printf("depois da funcao: %d\n", n);


    return 0;
}
