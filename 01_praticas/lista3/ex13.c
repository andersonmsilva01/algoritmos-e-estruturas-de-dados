/*
13. Potência
Calcule X^N sem usar pow(), apenas com laço.
*/

#include <stdio.h>

int main(){

  int num;
  printf("digite um numero: ");
  scanf("%d", &num);

  int pot;
  printf("elevado a quanto: ");
  scanf("%d", &pot);

  if (pot < 0) {
    printf("o expoente deve ser maior ou igual a zero\n");
    return 1;
  }

  int resultado = 1;

  for(int i = 0; i < pot; i++){
    resultado *= num;
  }

  printf("%d^%d = %d\n", num, pot, resultado);

  return 0;
}
