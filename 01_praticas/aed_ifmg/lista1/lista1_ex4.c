// 4.Crie um algoritmo que leia a idade de uma pessoa em anos e mostre essa idade em meses e dias (considere 365 dias por ano)

#include <stdio.h>

int main(){
    int idade;
    
    printf("qual a sua idade: ");
    scanf("%d", &idade);
    
    printf("idade em meses: %d\n", idade * 12);
    printf("idade em dias: %d\n", idade * 365);
    
    return 0;
}