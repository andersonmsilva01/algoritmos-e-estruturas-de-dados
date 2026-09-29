/* 🟢 Nível Avançado
11. Ano Bissexto — Leia um ano e determine se é bissexto 
(divisível por 4, exceto centenários não divisíveis por 400). */

#include <stdio.h>

int main (void){

  int ano;

  printf("digite um ano:  \n");
  scanf("%d", &ano);

  if (ano / 4 && !(ano/100) || ano /400) {
    printf("o ano digitado é: %d e é bissexto", ano);
  } 

  else { 
    printf("não é bissexto");
  }
    
  
  return 0;
}