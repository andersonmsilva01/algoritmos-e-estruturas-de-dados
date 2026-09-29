/*
11. Verificar par ou ímpar
Tipo: Passagem por valor | Com retorno

Enunciado:
Crie uma função chamada ehPar(int n) que recebe um inteiro por valor e retorna 1 se o número for par ou 0 se for ímpar. No main(), leia um número, chame a função e use if
para imprimir a mensagem correspondente.

Dica: Use o operador módulo %: se n % 2 == 0, o número é par.
*/

#include <stdio.h>

int ehPar(int n){

    if (n % 2 == 0){  
    printf("%d é par, retorno 1\n",n);
    }

    else if(n % 2 == 1){  
    printf("%d é ímpar, retorno 0",n);
    }
}

int main(){

    int x;
    scanf("%d", &x);

    ehPar(x);

    return 0;
}
