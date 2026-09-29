/*
20. Verificação de palíndromo numérico
Leia um número e verifique se ele é igual ao seu reverso
(ex: 121, 1331).
*/

#include <stdio.h>

int main() {
    int n, original, digito, invertido = 0;

    printf("Digite um numero: ");
    scanf("%d", &n);

    original = n;

    while (n > 0) {
        digito = n % 10;
        invertido = invertido * 10 + digito;
        n = n / 10;
    }

    if (original == invertido) {
        printf("O numero e palindromo.\n");
    } else {
        printf("O numero nao e palindromo.\n");
    }

    return 0;
}