/* 5. Maior de Idade — Leia a idade de uma pessoa e informe se ela é maior ou 
menor de idade. */
#include <stdio.h>

int main (){

int idade;

printf("digite sua idade: \n");
scanf("%d", &idade);

if (idade >= 18){
    printf("maior de idade\n");
}
else {
    printf("menor de idade\n");
}


    return 0;
}