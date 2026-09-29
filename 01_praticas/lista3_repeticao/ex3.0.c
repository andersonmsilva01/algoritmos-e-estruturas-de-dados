/*
3. Tabuada
Leia um número e imprima sua tabuada do 1 ao 10.
*/

#include <stdio.h>

int main(void){
// um tabuada somente

  int num;

  printf("digite um numero: ");
  scanf("%d", &num);
  printf("vamos imprimir a tabuada do %d\n", num);


  for(int i = 1; i <=10; i++){
    printf("%d x %d = %d\n", num, i, i * num);
  }

    return 0;
}

