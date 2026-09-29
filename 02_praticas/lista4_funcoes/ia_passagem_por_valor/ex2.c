/*
2. Somar dois números

Crie a função somar(int a, int b), que retorna a soma dos números.
No main(), leia dois números e mostre o resultado da função.
*/

#include <stdio.h>

float somar(float a, float b){
    return a + b;
}

int main(void) {
    
    float x,y;
    scanf("%f %f", &x, &y);

    somar(x, y);
    float result = somar(x, y);
    printf("resultado: %.2f",result);


    return 0;
}

/*
CORREÇÃO: INCORRETO.
- A função promete retornar float, mas não possui return. A expressão "a + b;"
  sozinha não guarda nem retorna o resultado.
- Como a e b são int, use %d no printf. %f é para valores float/double.
- No scanf, x e y são int; portanto, o formato correto é "%d %d".
- "float somar(x, y);" não chama a função. É preciso chamar somar(x, y), guardar o retorno em uma variável e depois mostrar esse resultado.


1 tentativa:

float somar(int a, int b){
    a + b;
    printf("%f + %f = %f", a, b, a + b);
}

int main(void) {
    
    int x,y;
    scanf("%f %f", &x, &y);

   float somar(x, y);

    return 0;
}

2 tentativa

#include <stdio.h>

float somar(float a, float b){
    return a + b;
}

int main(void) {
    
    float x,y;
    scanf("%f %f", &x, &y);

    somar(x, y); // chamada desnecessaria
    float result = somar(x, y);
    printf("resultado: %f",result);


    return 0;
}
*/