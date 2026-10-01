/*
2. Contar a frequência de cada valor distinto
Nível: Intermediário
Assunto: Contar ocorrências de um valor

Enunciado:
Leia 12 números inteiros e informe quantas vezes cada valor distinto aparece.
Cada valor deve ser apresentado apenas uma vez no resultado, mesmo que esteja
repetido no vetor.
*/


/* CODIGO ANTERIOR

#include <stdio.h>

int main(){
int v[12];
int dist = 0;

for(int i = 0; i < 13; i++){
    printf("v[%d]: ", i);
    scanf("%d", &v[i]);

    if(v[i] != v[i] + v[i]){
        dist++;
    }
}

printf("distintos: %d", dist);

    return 0;
}
*/

#include <stdio.h>

#define TAMANHO 12

int main(void) {
    int v[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < TAMANHO; i++) {
        int contado_anteriormente = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] == v[i]) {
                contado_anteriormente = 1;
                break;
            }
        }

        if (contado_anteriormente) {
            continue;
        }

        int frequencia = 0;

        for (int j = 0; j < TAMANHO; j++) {
            if (v[j] == v[i]) {
                frequencia++;
            }
        }

        printf("%d aparece %d vez(es).\n", v[i], frequencia);
    }

    return 0;
}


/*
CORREÇÃO: INCORRETO.

15-20: O vetor possui 12 posições, com índices de 0 a 11, mas o laço executa 13 vezes. Quando i vale 12, o acesso a v[12] ultrapassa os limites do vetor e causa comportamento indefinido.
16: A variável dist armazena apenas uma quantidade total, mas o exercício exige a frequência individual de cada valor distinto.
22: A expressão v[i] != v[i] + v[i] não verifica se um valor já apareceu. Para valores diferentes de zero, ela normalmente será verdadeira; para zero, será falsa. A soma também pode ultrapassar o limite de int e causar comportamento indefinido.
22-24: Nenhum elemento é comparado com as outras posições do vetor, portanto as ocorrências de cada valor não são contadas.
27: A saída mostra somente uma suposta quantidade de valores distintos, enquanto o enunciado exige mostrar cada valor distinto acompanhado de sua frequência.
Geral: Código correto e completo:

#include <stdio.h>

#define TAMANHO 12

int main(void) {
    int v[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < TAMANHO; i++) {
        int contado_anteriormente = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] == v[i]) {
                contado_anteriormente = 1;
                break;
            }
        }

        if (contado_anteriormente) {
            continue;
        }

        int frequencia = 0;

        for (int j = 0; j < TAMANHO; j++) {
            if (v[j] == v[i]) {
                frequencia++;
            }
        }

        printf("%d aparece %d vez(es).\n", v[i], frequencia);
    }

    return 0;
}
*/
