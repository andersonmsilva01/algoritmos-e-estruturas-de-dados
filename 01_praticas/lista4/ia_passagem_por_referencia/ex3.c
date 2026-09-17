/*
3. Colocar dois valores em ordem

Crie a função ordenar(int *a, int *b). Se o valor de a for maior que o valor de b, a função deve trocar os dois valores. Caso contrário, nada deve mudar.

No main(), leia dois números inteiros, chame a função e mostre os números em
ordem crescente.
*/

#include <stdio.h>

void ordenar(int *a, int *b) {
if (*a > *b){
    int orig = *a;
    *a = *b;
    *b = orig;
}
else if (*a < *b){
    *a = *a;
    *b = *b;
} 
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    ordenar(&x , &y);
    printf("esses são os valores de a: %d b:%d \n",x,y);

    return 0;
}
