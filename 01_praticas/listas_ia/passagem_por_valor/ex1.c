/*
1. Mostrar um número

Crie a função mostrarNumero(int n). Ela deve mostrar o número recebido.
No main(), leia um número e passe-o para a função.
*/

#include <stdio.h>

void mostrarNumero(int n){
    int n = 0;
    printf("numero recebito: %d\n",n);
} 

int main(void) {
    
    int x;
    printf("digite um numero: \n");
    scanf("%d", &x);
    mostrarNumero(x);
    


    return 0;
}

/*
CORREÇÃO: INCORRETO.
- O parâmetro n já foi declarado na função. A linha "int n = 0;" tenta declará-lo novamente, causa erro de compilação e ainda descartaria o valor recebido.
- Remova essa linha para mostrar o número passado pelo main.
- "recebito" deve ser "recebido".
*/
