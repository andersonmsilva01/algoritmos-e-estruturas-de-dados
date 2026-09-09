/*
6. Fatorial
Leia um número N e calcule N! usando um laço.
*/


 #include <stdio.h>

 int main(void) {
     int n;
     long long fatorial = 1;

     printf("Digite um numero inteiro nao negativo: ");
     scanf("%d", &n);

     if (n < 0) {
         printf("Nao existe fatorial de numero negativo.\n");
     } else {
         for (int i = 2; i <= n; i++) {
             fatorial *= i;
         }

         printf("%d! = %lld\n", n, fatorial);
     }

     return 0;
}