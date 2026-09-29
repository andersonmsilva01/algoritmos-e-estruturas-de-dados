/*Maior de Dois Números — Leia dois números e exiba o maior deles. */

#include <stdio.h>

int main(){

    float num1;
    float num2;

    printf("digite um numero: ");
    scanf("%f", &num1); 
    printf("digite outro numero: ");
    scanf("%f", &num2);

     if (num1 > num2) {
     printf("o 1º num é maior: %.2f \n", num1); 
     }
     else {
     printf("o 2º num é maior: %.2f \n", num2);
     }

    return 0;
}