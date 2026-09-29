/*
6. Classificação de Triângulo — Leia três lados e diga se formam um triângulo equilátero, isósceles ou escaleno. Valide se os lados realmente formam um 
triângulo.

- Equilátero: os 3 lados iguais (ex: 5, 5, 5)
- Isósceles: 2 lados iguais (ex: 5, 5, 4)
- Escaleno: todos os lados diferentes (ex: 5, 4, 3)
*/

#include <stdio.h>

int main(){

int lado_a, lado_b, lado_c;

printf("digite o lado 'a' de um triangulo: \n");
scanf("%f", &lado_a);

printf("digite o lado 'b' de um triangulo: \n");
scanf("%f", &lado_b);

printf("digite o lado 'c' de um triangulo: \n");
scanf("%f", &lado_c);



switch(lado_a, lado_b, lado_c){
  case lado_a == lado_b && lado_c:
    printf("se os lados: %.2f, %.2f, %.2f, são iguais, isso é um triangulo equilatéro!", lado_a, lado_b, lado_c);
  break;

  case lado_a == lado_b || lado_a == lado_c ||lado_b == lado_c;
    printf("se dois lados: %.2f, %.2f, %.2f, são iguais, isso é um trinagulo isósceles!", lado_a, lado_b, lado_c);
  break;

  case lado_a != lado_b && lado_c:
    printf("se todos os lados: %.2f, %.2f, %.2f, são diferentes, isso é um trinagulo escaleno!", lado_a, lado_b, lado_c);
  break;

  default:
    printf("invalido");
}


return 0;
}
