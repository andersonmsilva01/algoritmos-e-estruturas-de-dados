/*
1. Somar todos os elementos de um vetor
Nível: Fácil
Assunto: Soma de todos os elementos

Enunciado:
Leia 10 números inteiros, armazene-os em um vetor e exiba a soma de todos os
elementos.
*/

#include <stdio.h>

int main(){

    int v[10];
    int n = 10;
    int soma = 0;

    for(int i = 0; i < n; i++){
        printf("v[%d]: ",i);
        scanf("%d", &v[i]);

        soma += v[i];

    }

    printf("\nsoma do vetor: %d\n",soma);


    return 0;
}

/*
CORREÇÃO: CORRETO.
15-17: O vetor, o tamanho e o acumulador foram declarados corretamente. A soma
começa em zero, que é o valor adequado para um acumulador de adição.
19-25: O laço lê as 10 posições válidas, de v[0] até v[9], e acrescenta cada
valor ao acumulador.
27: A soma final é exibida depois que todos os elementos foram processados.
Geral: A tentativa atende completamente ao enunciado.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[10];
    int n = 10;
    int soma = 0;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
        soma += v[i];
    }

    printf("\nSoma do vetor: %d\n", soma);

    return 0;
}
*/
