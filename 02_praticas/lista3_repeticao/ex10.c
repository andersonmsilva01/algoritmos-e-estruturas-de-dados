/*
10. Soma dos divisores
Leia um número e some todos os seus divisores.
*/

#include <stdio.h> 

int main(){ 

    int num; 
    int div; 
    int soma = 0; 

    printf("quais são os divisores do numero\n"); 
    printf("digite um numero: \n"); 
    scanf("%d", &num); 

    for(int i =1; i <=num; i++){ // Percorre todos os números de 1 até num.
        if(num % i != 0) // Verifica se i não é divisor de num.
            continue; // Avança para o próximo valor quando i não é divisor.
        div = i; // Guarda o divisor encontrado.
        soma += i; // Adiciona o divisor à soma acumulada.
        
        if(num % i == 0); // Testa se i é divisor; 
        printf("esses são os divisores %d\n", div); // Exibe o divisor encontrado.
        } // Encerra o laço de repetição.

    printf("a soma dos divisores é %d\n", soma); 

    return 0; 
} 