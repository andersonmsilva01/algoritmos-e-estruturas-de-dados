/*
3. Somar vetores de tamanhos diferentes
Nível: Difícil
Assunto: Soma de dois vetores em um terceiro

Enunciado:
Leia os tamanhos de dois vetores de inteiros, ambos entre 1 e 20, e depois seus elementos.

Crie um terceiro vetor com o tamanho do maior deles.

Em cada posição, some os valores correspondentes; quando uma posição não existir no vetor menor, considere o valor ausente como zero.

Exiba o terceiro vetor.

*/

#include <stdio.h>

#define TAMANHO_MAXIMO 20

int main(void) {
    int vetor1[TAMANHO_MAXIMO];
    int vetor2[TAMANHO_MAXIMO];
    int soma[TAMANHO_MAXIMO];
    int tamanho1;
    int tamanho2;
    int tamanho_soma;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &tamanho1);

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &tamanho2);

    if (tamanho1 < 1 || tamanho1 > TAMANHO_MAXIMO ||
        tamanho2 < 1 || tamanho2 > TAMANHO_MAXIMO) {
        printf("Os tamanhos devem estar entre 1 e 20.\n");
        return 1;
    }

    printf("\nElementos do primeiro vetor:\n");
    for (int i = 0; i < tamanho1; i++) {
        printf("vetor1[%d]: ", i);
        scanf("%d", &vetor1[i]);
    }

    printf("\nElementos do segundo vetor:\n");
    for (int i = 0; i < tamanho2; i++) {
        printf("vetor2[%d]: ", i);
        scanf("%d", &vetor2[i]);
    }

    if (tamanho1 > tamanho2) {
        tamanho_soma = tamanho1;
    } else {
        tamanho_soma = tamanho2;
    }

    for (int i = 0; i < tamanho_soma; i++) {
        int valor1 = 0;
        int valor2 = 0;

        if (i < tamanho1) {
            valor1 = vetor1[i];
        }

        if (i < tamanho2) {
            valor2 = vetor2[i];
        }

        soma[i] = valor1 + valor2;
    }

    printf("\nVetor resultante:\n");
    for (int i = 0; i < tamanho_soma; i++) {
        printf("%d ", soma[i]);
    }
    printf("\n");

    return 0;
}
