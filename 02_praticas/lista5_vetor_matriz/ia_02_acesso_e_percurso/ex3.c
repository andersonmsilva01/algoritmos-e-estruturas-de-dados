/*
3. Percorrer um vetor alternando as extremidades
Nível: Difícil
Assunto: Acesso e percurso

Enunciado:

Leia 10 números inteiros e exiba-os alternando as posições das extremidades:

- primeiro, último, segundo, penúltimo e assim por diante,

até que todos tenham sido exibidos. Não altere a ordem dos elementos dentro do vetor.
*/

#include <stdio.h>

int main(void) {
    int v[10];
    int n = 10;
    int inicio = 0;
    int fim = n - 1;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nElementos alternando as extremidades:\n");

    while (inicio <= fim) {
        printf("v[%d] = %d\n", inicio, v[inicio]);

        if (inicio != fim) {
            printf("v[%d] = %d\n", fim, v[fim]);
        }

        inicio++;
        fim--;
    }

    return 0;
}

/*
CORREÇÃO: CORRETO.
18-21: O vetor, seu tamanho e os índices das duas extremidades foram declarados
e inicializados corretamente.
23-26: O primeiro laço lê as 10 posições válidas, de v[0] até v[9].
30-39: O while exibe primeiro a extremidade esquerda e depois a direita, move os
dois índices em direção ao centro e encerra quando todas as posições foram
exibidas.
33-35: A condição evita repetir o elemento central quando o vetor possui uma
quantidade ímpar de elementos.
Geral: A tentativa atende completamente ao enunciado sem alterar os valores nem
a ordem armazenada no vetor.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[10];
    int n = 10;
    int inicio = 0;
    int fim = n - 1;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nElementos alternando as extremidades:\n");

    while (inicio <= fim) {
        printf("v[%d] = %d\n", inicio, v[inicio]);

        if (inicio != fim) {
            printf("v[%d] = %d\n", fim, v[fim]);
        }

        inicio++;
        fim--;
    }

    return 0;
}
*/
