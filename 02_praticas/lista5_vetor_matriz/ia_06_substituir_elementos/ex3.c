/*
3. Trocar o maior e o menor valor entre si
Nível: Difícil
Assunto: Substituir elementos

Enunciado:
Leia 20 números inteiros, encontre o maior e o menor valor e substitua todas as ocorrências do maior pelo menor e todas as ocorrências do menor pelo maior.

Garanta que uma substituição não seja processada novamente e exiba o resultado.
*/

#include <stdio.h>
#define TAM 20

int main(void) {
    int v[TAM];
    int maior;
    int menor;

// preenchimento
    for (int i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }
// passagem dos valores do 1º indice, para maior e menor
    maior = v[0];
    menor = v[0];

// loop para saber qual é o maior e menor valor realmente
    for (int i = 1; i < TAM; i++) {

        if (v[i] > maior) {
            maior = v[i];
        }

        if (v[i] < menor) {
            menor = v[i];
        }
    }
// percorrendo o array de novo
    for (int i = 0; i < TAM; i++) {

// condicao para saber quais indices repetem o maior e atribuir o valor menor nele
        if (v[i] == maior) {
            v[i] = menor;
        }
// condicao para saber quais indices repetem o menor e atribuir o valor maior nele
        else if (v[i] == menor) {
            v[i] = maior;
        }
    }

    printf("\nVetor resultante:\n");
//percorrendo o array de novo, já com as trocas
    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}
