/*
1. Percorrer um vetor do início ao fim
Nível: Fácil
Assunto: Acesso e percurso

Enunciado:
Leia 8 números inteiros, armazene-os em um vetor e exiba os elementos na mesma
ordem em que foram digitados.
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
