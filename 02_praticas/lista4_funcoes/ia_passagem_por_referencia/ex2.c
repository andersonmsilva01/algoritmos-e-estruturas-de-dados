/*
2. Quociente e resto

Crie a função dividir(int dividendo, int divisor, int *quociente, int *resto). 

Ela deve calcular a divisão inteira e devolver o quociente e o resto por meio dos dois últimos parâmetros.

No main(), leia o dividendo e o divisor, chame a função e mostre os dois resultados. 

Considere que o divisor será diferente de zero.
*/

#include <stdio.h>

void dividir(int dividendo, int divisor, int *quociente, int *resto) {

    *quociente = dividendo / divisor;
    *resto = dividendo % divisor;

}

int main(void) {

    int d1 = 20;
    int d2 = 2;

    dividir(&d1,&d2);
    printf("quociente: %d, resto: %d", d1, d2);

    return 0;
}
