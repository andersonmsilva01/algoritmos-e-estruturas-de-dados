#include <stdio.h>

// 1) void sem parâmetros
void saudacao(void) {
    printf("Olá, mundo!\n");
}

// 2) void com parâmetros
void exibirTabuada(int n) {
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

// 3) retorno específico com parâmetros
int somar(int a, int b) {
    return a + b;
}

float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

// 4) retorno específico sem parâmetros
int idadeAtual(void) {
    return 20;
}

int main(void) {
    // Tipo 1: void sem parâmetros
    saudacao();

    // Tipo 2: void com parâmetros
    exibirTabuada(5);

    // Tipo 3: retorno com parâmetros
    int resultado = somar(3, 7);
    printf("Soma: %d\n", resultado);

    float media = calcularMedia(7.5, 9.0);
    printf("Média: %.1f\n", media);

    // Tipo 4: retorno sem parâmetros
    int idade = idadeAtual();
    printf("Idade: %d\n", idade);

    return 0;
}
