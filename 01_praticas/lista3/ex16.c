/*
16. Pirâmide numérica
Imprima uma pirâmide onde cada linha exibe o número da linha
repetido (ex: linha 3 -> 3 3 3).
*/

#include <stdio.h>

int main(){

    int linhas = 5;

    for(int i = 1; i <=linhas; i++){
        for(int col=1; col<=i; col++){
            printf("%d ", i);
        }
        printf("\n");
    }


    return 0;
}
