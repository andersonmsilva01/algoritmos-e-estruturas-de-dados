/*
02. Exibir linha separadora
Tipo: Sem parâmetro | Sem retorno

Enunciado:
Crie uma função chamada linha() sem parâmetros e sem retorno. Ela deve usar um laço
for para imprimir exatamente 40 hifens seguidos de uma quebra de linha. No main(),
chame a função duas vezes.

Dica: Use for com contador de 0 a 39 e printf("-") dentro do laço.
*/

#include <stdio.h>

void linha(){
   for(int i = 1; i <= 40; i++){
    printf("%dº: - \n",i);
   } 
}

int main(){
linha();

    return 0;
}
