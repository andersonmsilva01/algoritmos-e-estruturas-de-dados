/*
2. Alterar uma variável por ponteiro

Crie a função dobrar(int *numero). A função deve alterar o valor apontado,
multiplicando-o por 2.

No main(), leia um número inteiro, mostre seu valor antes da chamada,
chame a função passando o endereço da variável e mostre o valor depois.

Objetivo: perceber que um ponteiro permite modificar a variável original.
*/

#include <stdio.h>

int dobrar(int *n) {
    return *n = n * 2;
    printf("valor dobrado: %d ", n);

}


int main(void) {

    int x;

    printf("digite um numero: ");
    scanf("%d", &x);

    dobrar(x);

    return 0;
}

/*
CORREÇÃO: INCORRETO.
- Em "*n = n * 2", n é um endereço. Para dobrar o valor, os dois usos devem acessar *n.
- O printf está depois do return e nunca será executado.
- No printf, n é um ponteiro; para mostrar o número, deve ser usado *n com %d.
- A chamada deve passar o endereço de x: dobrar(&x).
- Faltou mostrar o valor de x antes e depois da chamada.
*/
