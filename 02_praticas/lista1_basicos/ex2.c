// Lista 1 
/* 2. Faça um algoritmo que leia dois números inteiros e mostre: a soma, a subtração, a multiplicação e a divisão.*/
#include <stdio.h>

int main() {

    int num1 = 5, num2 = 2;
    float soma = num1 + num2;
    float subtração = num1 - num2;
    float multiplicação = num1 * num2;
    float divisão = num1 / num1;
    printf("soma: %.0f \n", soma);
    printf("subtração: %2.f\n",subtração);
    printf("multiplicação: %.f \n", multiplicação);
    printf("divisão: %.2f", divisão);
    
    return 0;
}
