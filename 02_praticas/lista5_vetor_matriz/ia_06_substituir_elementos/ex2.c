/*
2. Substituir um valor escolhido
Nível: Intermediário
Assunto: Substituir elementos

Enunciado:
Leia 15 números inteiros.

Depois, leia um valor antigo e um valor novo.

Substitua todas as ocorrências do valor antigo pelo valor novo,

exiba o vetor resultante e informe quantas substituições foram realizadas.
*/

#include <stdio.h>
#define TAM 15

int main(void) {
    int v[TAM];
    int antigo;
    int novo;
    int substituicoes = 0;

    for (int i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("Valor antigo: ");
    scanf("%d", &antigo);

    printf("Valor novo: ");
    scanf("%d", &novo);

    for (int i = 0; i < TAM; i++) {
        if (v[i] == antigo) {
            v[i] = novo;
            substituicoes++;
        }
    }

    printf("\nVetor resultante:\n");

    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\nSubstituições realizadas: %d\n", substituicoes);

    return 0;
}
