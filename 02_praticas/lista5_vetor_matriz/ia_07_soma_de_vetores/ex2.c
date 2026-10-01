/*
2. Somar vetores com tamanho informado
Nível: Intermediário
Assunto: Soma de dois vetores em um terceiro

Enunciado:
Leia um tamanho entre 1 e 20.
Depois, leia dois vetores de números reais com
essa quantidade de elementos.

Gere um terceiro vetor com as somas das posições
correspondentes e exiba os três vetores de forma alinhada.


*/

#include <stdio.h>
#define tam 20

int main(){

int a[tam];
int b[tam];
int c[tam];

    for(int i = 0; i > 1 || i < 20; i++){
        printf("\n");
        printf("vetor a: ", a[i]);
        scanf("%d", &a[i]);
}
printf("\n");

    for(int i = 0; i > 1 || i < 20; i++){
        printf("vetor b: ", b[i]);
        scanf("%d", &b[i]);
    }

    printf("\n---soma dos vetores---\n");

   for(int i = 0; i < tam; i++){
        c[i] = a[i] + b[i];
        printf("vetor novo: c[%d]: %d\n", i, c[i]);
        }

    return 0;
}

/*
CORREÇÃO: INCORRETO.
18-24: A capacidade de 20 posições está adequada, mas os vetores foram
declarados como int. O enunciado pede números reais, portanto o tipo deve ser
float. Também falta uma variável para guardar o tamanho informado pelo usuário.
26: A condição i > 1 || i < 20 permanece verdadeira para qualquer valor de i.
Quando i chega a 20, a primeira comparação é verdadeira e o laço continua
indefinidamente, ultrapassando os limites do vetor.
> **Undefined Behavior:** acessar posições a partir de a[20] ultrapassa os
limites do vetor e produz comportamento indefinido.
28: O printf não possui um especificador para a[i], mas recebe esse argumento
antes que a posição tenha sido preenchida.
> **Undefined Behavior:** ler a[i] sem inicialização produz comportamento
indefinido.
29: O especificador %d lê um inteiro, mas o exercício pede números reais.
33-35: O segundo laço repete os mesmos problemas de condição, acesso fora dos
limites, leitura não inicializada no printf e tipo inadequado.
40-43: A soma percorre sempre as 20 posições, em vez de usar o tamanho informado,
e mostra somente o terceiro vetor. O enunciado pede os três vetores alinhados.
Geral: É necessário ler e validar primeiro um tamanho entre 1 e 20. Depois, os
dois vetores devem ser preenchidos somente até esse tamanho, suas posições
correspondentes devem ser somadas e os três valores de cada posição devem ser
exibidos juntos.

CÓDIGO CORRETO:

#include <stdio.h>
#define TAM 20

int main(void) {
    float a[TAM];
    float b[TAM];
    float c[TAM];
    int n;

    do {
        printf("Tamanho entre 1 e 20: ");
        scanf("%d", &n);

        if (n < 1 || n > TAM) {
            printf("Tamanho inválido.\n");
        }
    } while (n < 1 || n > TAM);

    printf("\nVetor A:\n");

    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%f", &a[i]);
    }

    printf("\nVetor B:\n");

    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    printf("\nPosição |   Vetor A |   Vetor B |   Vetor C\n");

    for (int i = 0; i < n; i++) {
        printf("%7d | %9.2f | %9.2f | %9.2f\n", i, a[i], b[i], c[i]);
    }

    return 0;
}
*/
