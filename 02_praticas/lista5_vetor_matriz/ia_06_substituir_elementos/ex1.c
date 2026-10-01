/*
1. Substituir valores negativos por zero
Nível: Fácil
Assunto: Substituir elementos

Enunciado:
Leia 10 números inteiros e substitua cada valor negativo por zero. Ao final,
exiba o vetor modificado.
*/

#include <stdio.h>
#define tam 10

int main(){

    int v[tam];

    for(int i = 0; i < tam; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if(v[i] < 0){
            v[i] = 0;
        }
    }

    printf("\nvetor modificado\n");

    for(int i = 0; i < tam; i++){
        printf("v[%d]: %d\n", i, v[i]);
    }

    return 0;
}

/*
CORREÇÃO: PARCIALMENTE CORRETO.
12-16: O tamanho e o vetor foram declarados corretamente para armazenar 10
números inteiros.
18-25: O laço lê todas as posições válidas e substitui corretamente cada valor
negativo por zero.
26: v[tam] representa v[10], mas os índices válidos do vetor vão de v[0] até
v[9]. Além disso, esse printf tenta mostrar apenas um elemento, enquanto o
enunciado pede o vetor inteiro.
> **Undefined Behavior:** acessar v[10] ultrapassa os limites do vetor e produz
comportamento indefinido.
Geral: Falta um segundo laço para percorrer e exibir todos os elementos depois
das substituições.

CÓDIGO CORRETO:

#include <stdio.h>
#define TAM 10

int main(void) {
    int v[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if (v[i] < 0) {
            v[i] = 0;
        }
    }

    printf("\nVetor modificado:\n");

    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}
*/
