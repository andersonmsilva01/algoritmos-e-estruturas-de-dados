/* 10. IMC — Calcule o IMC de uma pessoa e classifique entre: abaixo do peso, normal, sobrepeso ou obeso. */

#include <stdio.h>

int main(void){

  float peso;
  float altura;

  printf("digite o seu peso: \n");
  scanf("%f", &peso);

  printf("digite a sua altura: \n");
  scanf("%f", &altura);

  float imc = peso / (altura * altura);

  if (imc < 18.5){
      printf("o seu imc é: %.2f e está abaixo do peso\n", imc);
    }

  else if  (imc <= 24.9){
      printf("o seu imc é: %.2f e está normal\n", imc);
    }


  else if  (imc <=29.9){
      printf("o seu imc é: %.2f e vc está com sobrepeso\n", imc);
    }

  else  {
      printf("o seu imc é: %.2f e vc está com obesidade \n", imc);
    }

return 0;
}