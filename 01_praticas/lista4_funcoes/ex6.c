/*
06. Calcular área do retângulo
Tipo: Passagem por valor | Com retorno

Enunciado:
Crie uma função chamada area(float base, float altura) que recebe dois valores reais por valor e retorna a área do retângulo (base × altura) como float. No main(), leia os valores
e exiba o resultado com 2 casas decimais.

Dica: Tipo de retorno float. Use %.2f no printf para formatar.
*/

#include <stdio.h>
float area(float base, float altura){
    return base * altura;
}

int main(){

    float x,y;
    scanf("%f %f", &x, &y);

    area(x,y);
    float result = area(x,y);
    printf("essa é a area: %.2f\n", result);

    return 0;
}
