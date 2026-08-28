/*
11. Número primo
Verifique se um número lido é primo usando um laço.
*/

#include <stdio.h>

int main(){

  int num;

  printf("digite um numero: \n");
  scanf("%d", &num);

  while(num % 2 == 0){
    printf("não é numero primo")
  }


    return 0;
}

