/*
3. Trocar dois valores

Crie a função trocar(int *a, int *b). 

- Ela deve trocar os valores das duas
variáveis usando os ponteiros 
- e uma variável auxiliar.

No main(), leia dois números inteiros, mostre os valores antes da troca,
chame a função passando os endereços das variáveis e mostre os valores depois.

Objetivo: praticar o uso de mais de um ponteiro como parâmetro de função.
*/

#include <stdio.h>

void trocar(int *a, int *b) {
    int a = 10;
    int b = 20;
    printf("depois: %d %d ", a, b);
}

int main(void) {
    
    int x;
    int y;
    scanf("%d %d", &x, &y);

    printf("antes: %d %d", x, y);
    
    trocar(x, y);

    return 0;
}

/*
CORREÇÃO: INCORRETO.
- "int a" e "int b" tentam redeclarar os parâmetros da função e causam erro de compilação.
- A função não realiza a troca. É necessário usar uma variável auxiliar e acessar *a e *b.
- A chamada deve passar os endereços das variáveis: trocar(&x, &y).
- Faltou mostrar x e y no main depois da chamada.
*/
