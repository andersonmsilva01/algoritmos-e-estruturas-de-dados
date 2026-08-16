/* Exercício 3
Elabore um algoritmo que leia um número inteiro e mostre seu antecessor e sucessor.*/

#include <stdio.h>

int main(){
    int num;
    int antecessor = num - 1;
    int sucessor = num +1;

    print("digite um numero inteiro: \n");
    scanf("%d", &num);
    print("esse é o antecessor: %d, esse é o sucessor: %d", antecessor, sucessor);
    
    return 0;

}

/* 
#include <stdio.h>

int main() {

    int num;
    printf("digite um numero inteiro: \n",num);
    scanf("%d", num);
    printf("numero antecessor: %d\n", num = i++);
    printf("numero sucessor: %d\n", num = i--);

    
    return 0;
}  
*/ 