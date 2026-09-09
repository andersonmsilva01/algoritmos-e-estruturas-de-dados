/*
18. Sequência com critério de parada
Leia números em loop até o usuário digitar -1 e exiba o
maior valor digitado.
*/

#include <stdio.h>

int main(){

    int valor;
    while(valor != -1){
        printf("digite um numero: ");
        scanf("%d", &valor);

        if(valor == -1){
            printf("encerrado");
        }
        else if(valor>valor){
            printf("esse é o maior valor digitado: %d",valor);
        }

    }


    return 0;
}
