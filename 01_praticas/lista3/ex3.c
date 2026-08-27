/*
3. Tabuada
Leia um número e imprima sua tabuada do 1 ao 10.
*/

#include <stdio.h>

int main(void){

  int num;
  int tab;
  
  printf("digite um numero: \n");
  scanf("%d", &num);

  for (int tab = 1; int tab < 10; int tab++);

  while(num > 0){
  num *= tab;
  printf("essa é a tabuada desse numero: "\n);
  }

    return 0;
}

