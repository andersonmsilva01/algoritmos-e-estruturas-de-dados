/*
1. Percorrer um vetor do início ao fim
Nível: Fácil
Assunto: Acesso e percurso

Enunciado:
Leia 8 números inteiros, armazene-os em um vetor e exiba os elementos na mesma ordem em que foram digitados.
*/

#include <stdio.h>

int main(){

int v[8];
int n = 8;

for(int i = 0; i < n; i++){
    printf("v[%d]: ", i);
    scanf("%d", &v[i]);

}

    return 0;
}

/*
CORREÇÃO: PARCIALMENTE CORRETO.
14-21: O vetor foi declarado com 8 posições e o laço lê corretamente os 8
números, guardando cada valor em sua posição.
18: O printf apenas solicita a entrada; ele não exibe o valor armazenado.
Geral: Falta fazer um novo percurso depois da leitura para mostrar os 8
elementos na mesma ordem em que foram digitados.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[8];
    int n = 8;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nElementos na ordem digitada:\n");

    for (int i = 0; i < n; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}
*/
