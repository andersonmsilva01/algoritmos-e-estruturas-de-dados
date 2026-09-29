/*
2. Declarar um vetor e preenchê-lo pelo teclado
Nível: Intermediário
Assunto: Declaração

Enunciado:
Declare um vetor de 8 números reais. Leia os oito valores pelo teclado e, ao final, exiba o primeiro e o último elemento armazenado.
*/

#include <stdio.h>

int main(){

    float v[8];
    int n =8;

    for(int i = 0; i < n; i++){
        scanf("%f", &v[i]);
    }

    printf("\n1º elemento v[0]: %2.f\n",v[0]);
    
    printf("\nÚltimo elemento v[0]: %2.f\n",v[7]);


    return 0;
}
