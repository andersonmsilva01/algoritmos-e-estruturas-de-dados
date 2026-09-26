/*
06. Exibir um vetor na ordem inversa
Tipo: Vetor

Enunciado:
Leia um vetor com 20 posições e mostre os elementos na ordem inversa.
*/

#include <stdio.h>

int main(){
    int vetor[20];

    for(int i = 0; i < 20; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 19; i >= 0; i--){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
