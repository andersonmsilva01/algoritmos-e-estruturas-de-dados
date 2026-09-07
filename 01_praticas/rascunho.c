#include <stdio.h>

int main() {
  
int n = 1234;
int soma = 0, qtd = 0;

while (n > 0) {
    int digito = n % 10;   
    soma += digito;              
    qtd++;                       
    n = n / 10;                  
}
printf("Qtd de dígitos: %d, soma: %d\n", qtd, soma);   

    return 0;
}
/* 

gcc -Wall lista2_ex6.c -o lista2_ex6

*/