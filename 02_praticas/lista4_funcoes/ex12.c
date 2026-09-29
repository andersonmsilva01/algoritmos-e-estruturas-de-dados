/*
12. Calcular fatorial

Tipo: Passagem por valor | Com retorno

Enunciado:
Crie uma função chamada fatorial(int n) que recebe um inteiro não negativo por valor e retorna seu fatorial. Use if para tratar o caso base (fatorial de 0 ou 1 é 1) e a recursão (ou um laço for) para os demais casos. No main(), leia o número e exiba o resultado.

Dica: Caso base: if (n <= 1) return 1. Recursão: return n * fatorial(n - 1).
*/

#include <stdio.h>

int fatorial(int n){
  if(n >= 1) return 1;
  return n * fatorial(n-1);
}

int main(){

    int x;
    scanf("%d", &x);

    int result = fatorial(x);
    printf("fatorial de %d é %d.\n", x, result);


    return 0;
}
