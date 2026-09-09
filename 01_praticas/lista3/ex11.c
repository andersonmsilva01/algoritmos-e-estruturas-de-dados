/*
11. Número primo
Verifique se um número lido é primo usando um laço.
*/

#include <stdio.h>

int main(void) {
    int n;
    int primo = 1;

    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n < 2) {
        primo = 0;
    } else if (n == 2) {
        primo = 1;
    } else if (n % 2 == 0) {
        primo = 0;
    } else {
        for (int divisor = 3; divisor <= n / divisor; divisor += 2) {
            if (n % divisor == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo) {
        printf("%d e primo.\n", n);
    } else {
        printf("%d nao e primo.\n", n);
    }

    return 0;
}

