/*
7. Fibonacci
Imprima os primeiros N termos da sequência de Fibonacci.
*/

#include <stdio.h>

int main(void) {
    int n;
    long long atual = 0;
    long long proximo = 1;

    printf("Quantos termos deseja imprimir? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Digite uma quantidade maior que zero.\n");
    } else {
        printf("Sequencia de Fibonacci: \n");

        for (int i = 0; i < n; i++) {
            printf("%lld", atual);

            if (i < n - 1) {
                printf(" \n");
            }

            long long seguinte = atual + proximo;
            atual = proximo;
            proximo = seguinte;
        }

        printf("\n");
    }

    return 0;
}


