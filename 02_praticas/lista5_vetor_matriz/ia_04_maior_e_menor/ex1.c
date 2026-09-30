    /*
    1. Encontrar o maior e o menor valor
    Nível: Fácil
    Assunto: Maior e menor

    Enunciado:
    Leia 10 números inteiros e informe o maior e o menor valor armazenado no
    vetor.
    */

    #include <stdio.h>

    int main(){

        int v[9];
        int maior = v[0]; int menor = v[0];

        for(int i = 1; i < 10; i++){
            printf("v[%d]: ",i);
            scanf("%d", &v[i]);

            if(v[i] > maior){
                maior = v[i];
            }

            if(v[i] < menor){
                menor = v[i];
            }
        }

        printf("\nmaior: %d\n"
            "\nmenor: %d\n", maior, menor
        );

	        return 0;
	    }

/*
CORREÇÃO: INCORRETO.
15: Para armazenar 10 números, o vetor precisa ter 10 posições. v[9] possui
somente 9 posições válidas, de v[0] até v[8].
16: maior e menor recebem v[0] antes que essa posição tenha sido preenchida.
> **Undefined Behavior:** ler v[0] sem inicialização produz comportamento
indefinido.
18-20: O laço começa em 1, portanto nunca lê v[0], e tenta gravar em v[9], que
está fora dos limites do vetor declarado.
> **Undefined Behavior:** gravar em v[9] fora dos limites produz comportamento
indefinido.
22-28: As comparações estão estruturadas corretamente, mas dependem de maior e
menor terem sido inicializados com um valor válido do vetor.
31-33: A exibição final possui os especificadores e argumentos corretos.
Geral: É necessário ler v[0] antes de usá-lo como valor inicial de maior e menor.
Depois, o laço pode ler e comparar as posições de v[1] até v[9].

CÓDIGO CORRETO:

#include <stdio.h>

int main(void) {
    int v[10];
    int n = 10;

    printf("v[0]: ");
    scanf("%d", &v[0]);

    int maior = v[0];
    int menor = v[0];

    for (int i = 1; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);

        if (v[i] > maior) {
            maior = v[i];
        }

        if (v[i] < menor) {
            menor = v[i];
        }
    }

    printf("\nMaior: %d\nMenor: %d\n", maior, menor);

    return 0;
}
*/
