/*
1. Somar dois vetores
Nível: Fácil
Assunto: Soma de dois vetores em um terceiro

Enunciado:
Leia dois vetores A e B, cada um com 5 números inteiros. Crie um terceiro vetor
C em que cada elemento seja a soma dos elementos correspondentes de A e B.
Exiba o vetor C.
*/

#include <stdio.h>
#define tam 5

int main(){

    int a[tam];
    int b[tam];
    int c[tam];

    for(int i = 0; i < tam; i++){
        printf("\n");
        printf("vetor a: v[%d]: ", i);
        scanf("%d", &a[i]);
        }
        printf("\n");
    for(int i = 0; i < tam; i++){
        printf("vetor b: v[%d]: ", i);
        scanf("%d", &b[i]);
    }

    printf("\n---soma dos vetores---\n");

   for(int i = 0; i < tam; i++){
        c[i] = a[i] + b[i];
        printf("vetor novo: c[%d]: %d\n", i, c[i]);
        }


    return 0;
}
