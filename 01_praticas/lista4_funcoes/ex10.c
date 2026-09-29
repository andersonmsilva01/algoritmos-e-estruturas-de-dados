/*
10. Converter temperatura
Tipo: Passagem por valor | Com retorno

Enunciado:
Crie uma função chamada celsiusParaFahr(float c) que recebe uma temperatura em Celsius por valor e retorna o equivalente em Fahrenheit usando a fórmula F = (C × 9/5)
+ 32. No main(), leia a temperatura e imprima a conversão com 1 casa decimal.

Dica: Use divisão com ponto flutuante: 9.0 / 5.0 para evitar divisão inteira.
*/

#include <stdio.h>

float celsiusParaFahr(float c){
    float f;
    return f = (c * 9.0/5.0) + 32;  
}


int main(){

    float temp;
    scanf("%f",&temp);

    celsiusParaFahr(temp);
    float conv = celsiusParaFahr(temp);

    printf("%2.fº Celsius convertido para %2.fº Fahrenheit.\n",temp, conv);

    return 0;
}
