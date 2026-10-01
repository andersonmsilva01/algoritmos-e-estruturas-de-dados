/*
1. Contar as ocorrências de um número
Nível: Fácil
Assunto: Contar ocorrências de um valor

Enunciado:
Leia 10 números inteiros e, depois, leia um número para busca. Informe quantas vezes esse número aparece no vetor.
*/

#include <stdio.h>

int main(){

int v[10];
int n = 10;
int alvo;
int count = 0;

printf("digite o alvo: ");
scanf("%d", &alvo);

for(int i = 0; i < n; i++){
    printf("v[%d]: ", i);
    scanf("%d", &v[i]);

    if(v[i] == alvo){
        count++;
    }
}

printf("alvo: %d, repetições: %d", alvo, count);

    return 0;
}

/*
CORREÇÃO: PARCIALMENTE CORRETO.

14-23: O vetor possui espaço para 9 inteiros, mas o laço lê 10 valores. Quando i vale 9, o acesso a v[9] ultrapassa os limites do vetor e causa comportamento indefinido. O vetor deve possuir 10 posições.
18-19: A leitura do alvo funciona, mas ocorre antes da leitura do vetor. O enunciado solicita primeiro os 10 números e depois o número procurado.
21-28: A estrutura do laço e a contagem das ocorrências estão corretas, desde que o vetor tenha o tamanho adequado.
25-27: A comparação com o alvo e o incremento do contador resolvem corretamente a parte principal do exercício.
30: A saída informa o alvo e sua quantidade de ocorrências corretamente.
Geral: Código correto e completo:

#include <stdio.h>

#define TAMANHO 10

int main(void) {
    int v[TAMANHO];
    int alvo;
    int ocorrencias = 0;

    for (int i = 0; i < TAMANHO; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("Digite o alvo: ");
    scanf("%d", &alvo);

    for (int i = 0; i < TAMANHO; i++) {
        if (v[i] == alvo) {
            ocorrencias++;
        }
    }

    printf("Alvo: %d, ocorrencias: %d\n", alvo, ocorrencias);

    return 0;
}
*/
