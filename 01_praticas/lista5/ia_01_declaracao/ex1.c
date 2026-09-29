/*
1. Declarar e inicializar um vetor
Nível: Fácil
Assunto: Declaração

Enunciado:
Declare um vetor de 5 números inteiros e inicialize-o, no momento da declaração, com os valores 2, 4, 6, 8 e 10. Depois, exiba os cinco valores.
*/

#include <stdio.h>

int main(){
int v[5] = {2,4,6,8,10};
int n = 5;

for(int i = 0; i < n; i++){
    printf("%d\n",v[i]);
}

    return 0;
}
