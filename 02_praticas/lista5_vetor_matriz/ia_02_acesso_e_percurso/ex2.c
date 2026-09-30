/*
2. Acessar posições pares e ímpares
Nível: Intermediário
Assunto: Acesso e percurso

Enunciado:
Leia 12 números inteiros. Em um primeiro percurso, exiba os elementos que estão nos índices pares. Em um segundo percurso, exiba os elementos que estão nos índices ímpares. Mostre junto cada índice e seu valor.
*/

#include <stdio.h>

int main(){

int v[12];
int n = 12;

    for(int i = 0; i < n ; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

        printf("\n índices pares \n");
        for(int i = 0; i < n; i += 2){
            printf("v[%d] = %d\n", i, v[i]);
        }

        printf("\n índices ímpares \n");
        for(int i = 1; i < n; i += 2){
            printf("v[%d] = %d\n", i, v[i]);
        }


    return 0;
}

/*
CORREÇÃO: CORRETO.
14-20: O vetor possui 12 posições e o primeiro laço lê corretamente todos os
valores, de v[0] até v[11].
22-25: O segundo laço começa no índice 0 e avança de dois em dois, exibindo o
índice e o valor de todas as posições pares.
27-30: O terceiro laço começa no índice 1 e avança de dois em dois, exibindo o
índice e o valor de todas as posições ímpares.
Geral: A tentativa atende completamente ao enunciado.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[12];
    int n = 12;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nÍndices pares:\n");

    for (int i = 0; i < n; i += 2) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\nÍndices ímpares:\n");

    for (int i = 1; i < n; i += 2) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}
*/
