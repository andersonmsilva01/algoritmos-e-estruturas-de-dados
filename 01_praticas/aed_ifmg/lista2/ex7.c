/* 7. Calculadora Simples — Leia dois números e um operador (+, -, *, /) e realize a operação correspondente usando switch. */

#include <stdio.h>

int main(void) {

  int num1, num2;
  char operacao;

  printf("-----calculadora------");
  printf("digite o 1º numero:  ");
  scanf("%d", &num1);
  printf("digite o 2º numero:  2");
  scanf("%d", &num2);


  printf("qual operacao vamos fazer?");
  scanf(" %c", &operacao);

  switch (operacao){
    case '+':
      printf("soma: %d + %d = %d\n", num1, num2, num1 + num2);
    break;

    case '-':
      printf("subtração: %d - %d = %d\n", num1, num2, num1 - num2);
    break;
    
    case '*':
      printf("multiplicação: %d * %d = %d\n", num1, num2, num1 * num2);
    break;
    
    case '/':
      printf("divisão: %d / %d = %d\n", num1, num2, num1 / num2);
    break;    

    default:
      printf("invalido\n");
  }

  return 0;
}