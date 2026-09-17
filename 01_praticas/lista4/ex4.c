/*
04. Exibir tabuada do 5
Tipo: Sem parâmetro | Sem retorno

Enunciado:
Crie uma função chamada tabuadaCinco() sem parâmetros e sem retorno. Ela deve usar um laço for para imprimir a tabuada completa do número 5, de 1 a 10, no formato: "5 x 1 = 5". Chame a função no main().

Dica: for de i=1 até i<=10. O resultado é sempre 5 * i.
*/

#include <stdio.h>

void tabuadaCinco(){
    
    int result, num = 5;
    
    for(int i = 1; i <=10; i++){
    result = num * i;
    printf ("%d x %d = %d\n", num, i, result);
    }
}

int main(void){

    tabuadaCinco();

    return 0;
}
