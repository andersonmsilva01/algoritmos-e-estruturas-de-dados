/*
07. Verificar sinal do número
Tipo: Passagem por valor | Sem retorno

Enunciado:
Crie uma função chamada verificarSinal(int n) que recebe um inteiro por valor e não retorna nada. Usando if, else if e else, ela deve imprimir se o número é "Positivo",
"Negativo" ou "Zero". Teste com três valores diferentes no main().

Dica: Três condições: n > 0, n < 0, e o else para zero.
*/

#include <stdio.h>

void verificarSinal(int n){
    n = n;

    if(n > 0){
        printf("%d é positivo\n", n);
    }

    else if(n < 0){
        printf("%d é negativo\n", n);
    }

    else {
        printf("%d é zero\n", n);
    }
   
}

int main(){

    int x;
    scanf("%d", &x);

    verificarSinal(x);

    return 0;
}
