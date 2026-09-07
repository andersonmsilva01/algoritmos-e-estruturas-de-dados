/*
6. Fatorial
Leia um número N e calcule N! usando um laço.
*/

#include <stdio.h>

int main(){
long long n;
printf("digite um numero para cacular o fatorial: ");
scanf("%d",n);
long long produto=1;


for(int i = 2; i <= n; i++){
    produto *= n;
}
printf("fatorial de %d é: ", n);

    return 0;
}
