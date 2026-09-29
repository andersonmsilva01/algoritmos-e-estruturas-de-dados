/*
5. Par ou ímpar em sequência
Imprima todos os números pares de 1 a 50.
*/

#include <stdio.h>

int main(void){

 for (int numero = 2; numero <= 50; numero += 2) {
    printf("numeros pares: %d\n", numero);
 }

    return 0;
}

