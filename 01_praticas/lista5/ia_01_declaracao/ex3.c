/*
3. Trabalhar com capacidade e tamanho lógico
Nível: Difícil
Assunto: Declaração

Enunciado:
Declare um vetor de inteiros com capacidade para 50 elementos. 

Leia primeiro um tamanho lógico entre 1 e 50 e valide a entrada. 

Em seguida, leia somente essa quantidade de valores e exiba apenas a parte utilizada do vetor.

Objetivo: diferenciar a capacidade declarada do vetor da quantidade de posições
que realmente contém dados.
*/

#include <stdio.h>

int main(){

int v[50];
int n;

printf("quantos valores preencher de 1-50: \n");
scanf("%d", &n);
if(n > 50 || n < 1){
    printf("invalido");
}

for(int i = 0; i < n; i++){
    printf("\nv[%d]: ", i);
    scanf("%d", &v[i]);
}

printf("\n capacidade do vetor  50, tamanho lógico: %d\n", n);

    return 0;
}
