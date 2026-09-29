/*
1. Representar uma ficha de produto
Nível: Fácil
Assunto: O que é um registro (struct)

Enunciado:
Crie um tipo de registro chamado Produto para reunir os dados de um produto.
Ele deve possuir os campos codigo (int), categoria (char) e preco (float).
Depois, declare uma variável desse tipo dentro da função main.

Objetivo: perceber que uma struct agrupa, em uma única variável, dados de tipos
diferentes que descrevem a mesma entidade.
*/

#include <stdio.h>

int main(){

typedef struct{
    int codigo;
    char categoria;
    float preco;
}Produto;

Produto sabonete, shampoo;
    return 0;
}
