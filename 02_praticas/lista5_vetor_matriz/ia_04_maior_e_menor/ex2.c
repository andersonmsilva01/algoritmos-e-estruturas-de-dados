/*
2. Encontrar valores extremos e suas posições
Nível: Intermediário
Assunto: Maior e menor

Enunciado:
Leia 15 números inteiros. Informe o maior e o menor valor e a primeira posição
em que cada um aparece. Considere que os índices começam em zero.
*/

#include <stdio.h>

int main(){

int v[15];
int ma= v[0]; int me = v[0];
int ind1 = v[0]; int ind2 = v[0];

for(int i = 0; i < 16; i++){
    printf("v[%d]: ", i);
    scanf("%d", &v[i]);

    if(v[i] > ma){
        ma = v[i];
        ind1 = v[i];
    }

    if(v[i] < me){
        me = v[i];
        ind2 = v[i];
    }
}

printf(
    "\n--VALOR--\n"
    "\nmaior: %d\n"
    "\nmenor: %d\n"
    "\n--POSICOES--\n"
    "\nmaior: %d\n"
    "\nmenor: %d\n", ma, me, ind1, ind2
);
    return 0;
}

/*
CORREÇÃO: INCORRETO.
15: O vetor foi declarado corretamente com 15 posições, cujos índices válidos
vão de 0 a 14.
16-17: ma, me, ind1 e ind2 usam v[0] antes que ele seja preenchido. Além disso,
os índices devem começar com 0, e não com o valor armazenado em v[0].
> **Undefined Behavior:** ler v[0] sem inicialização produz comportamento
indefinido.
19-21: A condição i < 16 executa 16 leituras e tenta gravar em v[15], fora dos
limites do vetor. Para 15 posições, o limite deve impedir que i ultrapasse 14.
> **Undefined Behavior:** gravar em v[15] fora dos limites produz comportamento
indefinido.
23-30: Ao encontrar um novo maior ou menor, ind1 e ind2 recebem v[i], que é o
valor. Para guardar a posição, devem receber o índice i.
34-41: A quantidade e a ordem dos especificadores correspondem aos quatro
argumentos, mas os índices calculados anteriormente estão incorretos.
Geral: Para preservar a primeira ocorrência, v[0] deve ser lido primeiro e usado
para inicializar os extremos e os índices. As demais posições devem atualizar os
dados somente quando surgir um valor estritamente maior ou menor.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[15];
    int n = 15;

    printf("v[0]: ");
    scanf("%d", &v[0]);

    int maior = v[0];
    int menor = v[0];
    int indiceMaior = 0;
    int indiceMenor = 0;

    for (int i = 1; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if (v[i] > maior) {
            maior = v[i];
            indiceMaior = i;
        }

        if (v[i] < menor) {
            menor = v[i];
            indiceMenor = i;
        }
    }

    printf(
        "\nMaior: %d, primeira posição: %d\n"
        "Menor: %d, primeira posição: %d\n",
        maior,
        indiceMaior,
        menor,
        indiceMenor
    );

    return 0;
}
*/
