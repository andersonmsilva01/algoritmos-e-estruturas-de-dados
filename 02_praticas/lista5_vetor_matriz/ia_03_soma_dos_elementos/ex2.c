/*
2. Calcular somas separadas
Nível: Intermediário
Assunto: Soma de todos os elementos

Enunciado:
Leia 15 números inteiros.

Calcule e exiba separadamente

    - a soma dos valores positivos
    - a soma dos valores negativos
    - e a soma total do vetor.

O valor zero não deve alterar as somas positiva e negativa.
*/

#include <stdio.h>

int main(){

int v[15];
int n = 15;
int somaPos = 0;
int somaNeg = 0;
int somaTd = 0;


    for(int i = 0; i < n; i++){
        printf("v[%d]: ",i);
        scanf("%d", &v[i]);

    if(v[i] > 0){
        somaPos += v[i];
    }

    if(v[i] < 0){
        somaNeg += v[i];
    }

    if(v[i] != 0){
    somaTd += v[i];
    }

    }

    printf(
        "\n---TDS AS SOMAS---\n"
        "\n positivos: %d \n"
        "\n negativos: %d \n"
        "\n tds os valores: %d \n", somaPos, somaNeg, somaTd
        );



    return 0;
}

/*
CORREÇÃO: CORRETO.
22-26: O vetor e os três acumuladores foram declarados corretamente, com as
somas iniciadas em zero.
29-45: O laço lê as 15 posições válidas e separa corretamente os valores
positivos dos negativos.
41-43: A condição que exclui o zero da soma total é desnecessária, mas não muda
o resultado, pois somar zero também manteria o total inalterado.
47-52: Os três especificadores %d correspondem, na mesma ordem, a somaPos,
somaNeg e somaTd.
Geral: A tentativa atende ao enunciado. No código correto abaixo, a soma total é
feita sem condição para deixar mais claro que ela inclui todos os elementos.

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[15];
    int n = 15;
    int somaPos = 0;
    int somaNeg = 0;
    int somaTd = 0;

    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if (v[i] > 0) {
            somaPos += v[i];
        } else if (v[i] < 0) {
            somaNeg += v[i];
        }

        somaTd += v[i];
    }

    printf(
        "\n--- TODAS AS SOMAS ---\n"
        "\nPositivos: %d\n"
        "Negativos: %d\n"
        "Todos os valores: %d\n",
        somaPos,
        somaNeg,
        somaTd
    );

    return 0;
}
*/
