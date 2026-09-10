/*
19. Tabuada completa
Imprima a tabuada de 1 a 10 completa usando laços aninhados.
*/

#include <stdio.h>

int main(){

    for(int i=1; i <=10; i++){
        printf("\ntabuada do %d\n", i);

        for(int vezes=1; vezes <=10; vezes++){
            printf("%d x %d = %d\n", i, vezes, i * vezes);
        }
    }
        

    return 0;
}
