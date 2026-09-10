/*
18. Sequência com critério de parada
Leia números em loop até o usuário digitar -1 e exiba o maior valor digitado.
*/

#include <stdio.h>

int main() {
    int valor = 0;
    int maior;
    int primeiro = 1;

    while (valor != -1) {
        printf("Digite um numero: ");
        scanf("%d", &valor);

        if (valor == -1) {
            printf("Encerrado\n");
        }
        else if (primeiro == 1 || valor > maior) {
            maior = valor;
            primeiro = 0;
        }
    }

    if (primeiro == 0) {
        printf("O maior valor digitado foi: %d\n", maior);
    }

    return 0;
}