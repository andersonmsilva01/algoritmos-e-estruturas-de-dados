/*
3. Encontrar o segundo maior e o segundo menor distintos
Nível: Difícil
Assunto: Maior e menor

Enunciado:
Leia 20 números inteiros e encontre o segundo maior e o segundo menor valor distinto do vetor, sem ordenar os elementos.

Se não existirem pelo menos dois valores diferentes, informe que não é possível obter o resultado.
*/

#include <stdio.h>

int main(){

int v[20];
int n = 20;
int maior1; int maior2;
int menor1; int menor2;

printf("v[%d]", v[0]);
scanf("%d %d", &maior1, &maior2);

    for(int i = 1; i < n; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if(v[i] > maior1){
            maior1 = v[i];
        }
        if(v[i] < menor1){
            menor2 = v[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(v[i] < maior1){
            maior2 = v[i];
        }
        if(v[i] > menor1){
            menor2 = v[i];
        }
    }

    printf(
        "\n 1º maior: %d || 2º maior: %d \n"
        "\n 1º menor: %d || 2º menor: %d  \n",
        maior1,
        maior2,
        menor1,
        menor2
        );




    return 0;
}

/*
CORREÇÃO: INCORRETO.

18-19: As variáveis menor1 e menor2 são declaradas, mas nunca recebem valores antes de serem usadas. maior1 e maior2 recebem dados no scanf, porém esses dados não são armazenados no vetor.
21: v[0] é usado no printf antes de ser inicializado. A leitura de um valor indeterminado causa comportamento indefinido. Além disso, o valor do elemento está sendo usado onde deveria aparecer apenas o índice 0.
22: A leitura preenche maior1 e maior2 em vez de preencher v[0]. Por isso, a primeira posição do vetor permanece sem valor e a entrada não corresponde aos 20 elementos solicitados.
24-34: A passagem começa corretamente na posição 1, mas só seria válida se v[0], maior1 e menor1 tivessem sido inicializados com o primeiro elemento. A maior variável é atualizada, porém o menor valor não é calculado.
31-33: menor1 é comparado sem inicialização, causando comportamento indefinido, e o resultado é colocado em menor2. Nesta primeira passagem deveria ser atualizado o menor valor principal.
36-43: A ideia de fazer uma segunda passagem está correta, mas v[0] continua sem inicialização e volta a causar comportamento indefinido.
37-39: maior2 recebe qualquer valor menor que maior1 e acaba guardando apenas o último candidato encontrado. Também é necessário verificar se o candidato é maior que o segundo maior atual.
40-42: menor2 recebe qualquer valor maior que menor1 e acaba guardando apenas o último candidato. Também é necessário verificar se o candidato é menor que o segundo menor atual.
45-52: A saída utiliza resultados que podem estar incorretos ou não inicializados e não trata o caso em que todos os elementos possuem o mesmo valor.
Geral: O uso de duas passagens é uma boa escolha e dispensa laços aninhados. A primeira deve encontrar o menor e o maior; a segunda deve encontrar os segundos valores distintos usando dois indicadores de resultado encontrado.
Geral: Código correto e completo:

#include <stdio.h>

#define TAMANHO 20

int main(void) {
    int v[TAMANHO];
    int maior;
    int menor;
    int segundo_maior = 0;
    int segundo_menor = 0;
    int encontrou_segundo_maior = 0;
    int encontrou_segundo_menor = 0;

    for (int i = 0; i < TAMANHO; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    maior = v[0];
    menor = v[0];

    for (int i = 1; i < TAMANHO; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }

        if (v[i] < menor) {
            menor = v[i];
        }
    }

    for (int i = 0; i < TAMANHO; i++) {
        if (v[i] < maior) {
            if (!encontrou_segundo_maior || v[i] > segundo_maior) {
                segundo_maior = v[i];
                encontrou_segundo_maior = 1;
            }
        }

        if (v[i] > menor) {
            if (!encontrou_segundo_menor || v[i] < segundo_menor) {
                segundo_menor = v[i];
                encontrou_segundo_menor = 1;
            }
        }
    }

    if (!encontrou_segundo_maior || !encontrou_segundo_menor) {
        printf("Nao existem pelo menos dois valores distintos.\n");
    } else {
        printf("Segundo maior distinto: %d\n", segundo_maior);
        printf("Segundo menor distinto: %d\n", segundo_menor);
    }

    return 0;
}
*/
