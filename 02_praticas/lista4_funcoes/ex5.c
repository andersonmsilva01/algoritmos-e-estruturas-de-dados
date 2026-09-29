/*
05. Somar dois números
Tipo: Passagem por valor | Com retorno

Enunciado:
Crie uma função chamada somar(int a, int b) que recebe dois inteiros por valor e retorna a soma deles como inteiro. No main(), leia dois números do teclado com scanf, chame a
função e imprima o resultado.

Dica: O tipo de retorno da função é int. Use return a + b;
*/

#include <stdio.h>

int somar(int a, int b){
    return a + b;
}

int main(){

    int x,y;
    scanf("%d %d", &x, &y);

    somar(x,y);
    int result = somar(x,y);
    printf("esse é o resultado de %d + %d = %d\n", x,y,result);

    return 0;
}
