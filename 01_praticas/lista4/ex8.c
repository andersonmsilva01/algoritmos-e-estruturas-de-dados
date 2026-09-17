/*
08. Calcular potência inteira
Tipo: Passagem por valor | Com retorno

Enunciado:

Crie uma função chamada potencia(int base, int exp) que recebe dois inteiros por valor e retorna o resultado de base elevado ao expoente. Use um laço for para realizar as multiplicações. 

No main(), leia os valores do teclado e exiba o resultado.

Dica: Inicialize resultado = 1 e multiplique pela base dentro do for, exp vezes.
*/

#include <stdio.h>

int potencia(int base, int exp){
    for(int i = 1; i <= exp; base * base);


}

int (){

int x,y;
scanf(" %d %d", &x, &y);

potencia(x,y);
int res = potencia(x,y);
printf("esse é o resultado da potencia %d", res);
    return 0;
}
