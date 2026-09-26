/*
07. Somar os elementos de um vetor
Tipo: Vetor

Enunciado:
Faça um programa que leia 10 números inteiros e calcule a soma de todos os
elementos do vetor.
*/

#include <stdio.h>

int main(){
    int vetor[10];
    int soma = 0;

    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("Soma: %d\n", soma);

    return 0;
}
