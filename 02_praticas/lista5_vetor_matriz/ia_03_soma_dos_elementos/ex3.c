/*
3. Somar elementos dentro de um intervalo de posições
Nível: Difícil
Assunto: Soma de todos os elementos

Enunciado:
Leia um vetor de 20 números inteiros e duas posições, inicio e fim.

Valide para que as posições pertençam ao vetor e inicio seja menor ou igual a fim.

Depois,calcule a soma de todos os elementos entre essas duas posições, inclusive.
*/

#include <stdio.h>

int main()
{

    int v[19];
    int ini = v[0];
    int fim = v[19];
    int soma;

    for (int i = 0; i <= 19; i++)
    {
        printf("v[%d]", i);
        scanf("%d", &v[i]);

        while (ini <= fim)
        {
            soma = ini + fim;
        }
    }

    printf("soma de td: %d", soma);

    return 0;
}

/*
CORREÇÃO: INCORRETO.
19: Um vetor que precisa armazenar 20 números deve ter 20 posições. v[19]
possui somente 19 posições válidas, de v[0] até v[18].
20-21: ini e fim devem ser posições informadas pelo usuário, mas recebem valores
do vetor antes de qualquer elemento ter sido inicializado. Além disso, v[19]
está fora dos limites do vetor declarado.
> **Undefined Behavior:** as leituras de valores não inicializados e o acesso a
v[19] fora dos limites produzem comportamento indefinido.
22: soma não foi inicializada. Um acumulador de adição deve começar em zero.
24-27: O limite i <= 19 seria adequado para um vetor com 20 posições, mas grava
fora dos limites do vetor v[19] que foi declarado.
29-32: O while está dentro do laço de leitura, ini e fim nunca são modificados e
soma recebe apenas ini + fim. Se a condição for verdadeira, o laço é infinito;
ele não soma os elementos entre as duas posições.
35: soma pode ser exibida sem ter recebido um valor quando ini > fim.
> **Undefined Behavior:** usar soma sem inicialização produz comportamento
indefinido.
Geral: Primeiro devem ser lidos os 20 elementos. Depois, devem ser lidas e
validadas as duas posições. Por último, outro laço deve somar de ini até fim,
incluindo as duas extremidades.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[20];
    int n = 20;
    int ini;
    int fim;
    int soma = 0;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    do {
        printf("Início e fim, entre 0 e 19: ");
        scanf("%d %d", &ini, &fim);

        if (ini < 0 || ini >= n || fim < 0 || fim >= n || ini > fim) {
            printf("Posições inválidas. Tente novamente.\n");
        }
    } while (ini < 0 || ini >= n || fim < 0 || fim >= n || ini > fim);

    for (int i = ini; i <= fim; i++) {
        soma += v[i];
    }

    printf("Soma de v[%d] até v[%d]: %d\n", ini, fim, soma);

    return 0;
}
*/
