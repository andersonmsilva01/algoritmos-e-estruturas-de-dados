/*
15. Números primos no intervalo
Imprima todos os primos entre dois valores A e B.
*/

#include <stdio.h>

int main(){

    for (int num = 1; num <= 100; num++){
        int primo = 1;

        for(int divisor = 2; divisor * divisor <= num; divisor++){
            if(num % divisor == 0){
                printf("não é primo %d\n",num);
                break;
            }
        }

        if(primo == 1){
                printf("\né primo %d\n", num);
            }
    }


    return 0;

}
