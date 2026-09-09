/*
14. Triângulo de asteriscos
Imprima um triângulo com * de N linhas usando laços aninhados.
*/

#include <stdio.h>

int main(){

    int n = 5;

     for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <=i; j++){
            printf("* ");
        }
    printf("\n");
    }


    return 0;
}
