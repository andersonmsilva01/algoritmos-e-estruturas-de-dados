/*
9. Contador de dígitos
Leia um número inteiro e conte quantos dígitos ele possui.
*/

#include <stdio.h>

int main(){

  int num;
  int digitos=0;

  printf("digite um numero: \n");
  scanf("%d", &num);

  while (num > 0) {
    num = num / 10;
    digitos++;
  }
  printf("tinha %d digitos\n", digitos);

    return 0;
}
