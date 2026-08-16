/* 8. Estação do Ano — Leia um número de mês (1–12) e exiba a estação do ano correspondente. */

#include <stdio.h>

int main(void) {

int mes;

printf("digite o número de um mês: ");
scanf("%d", &mes);

switch (mes){

  case 12:
  case 1:
  case 2:
  case 3:
    printf("é verão");
  break;

  case 4:
  case 5:
  case 6:
  case 7:
    printf("é inverno");
  break;

  default:
   printf("sem estação no momento");
}

return 0;

}


