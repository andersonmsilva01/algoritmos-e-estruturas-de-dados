/*
08. Substituir os números negativos por zero
Tipo: Vetor

Enunciado:
Leia um vetor com 15 elementos e substitua todos os números negativos por zero.
*/

#include <stdio.h>

int main(){
    int vetor[15];

    for(int i = 0; i < 15; i++){
        scanf("%d", &vetor[i]);

        if(vetor[i] < 0){
            vetor[i] = 0;
        }
    }

    for(int i = 0; i < 15; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
