/*
3. Alterar somente a cópia

Crie a função aumentarUm(int n). Some 1 a n e mostre-o dentro da função.
No main(), mostre a variável antes e depois de chamar a função.
*/

#include <stdio.h>


void aumentarUm(int n){
    n = n + 1;
    printf("valor depois: %d\n",n);
}

int main(void) {
    
    int x;
    printf("\ndigite um valor: ");
    scanf("%d", &x);
    printf("\nantes da funcao: %d\n", x);

    aumentarUm(x);

    return 0;
}

/*
CORREÇÃO: PARCIALMENTE CORRETO.
- A função aumenta e mostra corretamente a cópia de x.
- Falta mostrar x no main depois de aumentarUm(x). Esse último printf demonstrará
  que o valor original não mudou.
*/
