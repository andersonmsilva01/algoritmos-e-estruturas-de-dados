/* 9. Desconto por Faixa — Leia o valor de uma compra e aplique desconto conforme a tabela: 

até R$ 100 → 5%; 

R$ 101 a R$ 500 → 10%; 

acima de R$500  → 15%. 
*/

#include <stdio.h>

int main(void){

float valor_compra;


printf("quanto vc comprou: ");
scanf("%f", &valor_compra);
printf("esse é o valor original da compra %.2f\n", valor_compra);

float desconto5 = valor_compra * 0.05;
float final_5 = valor_compra - desconto5;

float desconto10 = valor_compra * 0.10;
float final_10 = valor_compra - desconto10;

float desconto15 = valor_compra * 0.15;
float final_15 = valor_compra - desconto15;

if (valor_compra <= 100 ){
  printf("Parabéns, vc ganhou 5%% de desconto valor %.2f \n", final_5);
}

else if (valor_compra <= 500){
  printf("Parabéns, vc ganhou 10%% de desconto valor %.2f \n", final_10);
}

else {
  printf("Parabéns, vc ganhou 15%% de desconto valor %.2f\n", final_15);
}


return 0;
}