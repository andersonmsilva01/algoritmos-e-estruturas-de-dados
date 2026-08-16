/* 1. Par ou Ímpar — Leia um número inteiro e informe se ele é par ou ímpar. */

#include <stdio.h>

int main (){

    int num;

    printf("digite um numero: \n");
    scanf("%d", &num);

    if (num % 2 == 0){
    printf("numero par\n");}
    
    else {
        printf("numero impar\n");} 


return 0;
}