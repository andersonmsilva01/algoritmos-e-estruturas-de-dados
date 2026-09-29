/*
12. Inversão de número
Leia um número e imprima seus dígitos em ordem inversa.
*/

#include <stdio.h>

int main(){
int n, digito, inverter = 0;

printf("digite um numero: ");
scanf("%d", &n);
int original = n;


while(n > 0){
    digito = n % 10;
    inverter = inverter * 10 + digito;
    n = n/10;
    
}
printf("%d esse é o numero invertido\n", inverter);
printf("%d esse é o numero original\n", original);

    return 0;
}
