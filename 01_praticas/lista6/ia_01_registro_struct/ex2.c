/*
2. Reunir os dados de um livro
Nível: Intermediário
Assunto: O que é um registro (struct)

Enunciado:
Crie um tipo de registro chamado Livro com os campos titulo, de até 49
caracteres, numeroPaginas (int) e preco (float). Declare duas variáveis desse
tipo para representar dois livros distintos.

Não use três variáveis separadas para cada livro: todos os dados de um mesmo
livro devem pertencer ao seu registro.
*/

#include <stdio.h>

int main(){

typedef struct{
    char titulo[49];
    int paginas;
    float preco;
}livro;

livro l1, l2;

scanf("%s %d %f", l1.titulo, l1.paginas, l1.preco);

scanf("%s %d %f", l2.titulo, l2.paginas, l2.preco);

printf("
    
    --- livro 1 ---
    nome: %s
    paginas: %d
    preco: %.1f

    --- livro 2 ---
    nome: %s
    paginas: %s
    preco: %.1f

    ", l1.titulo, l1.paginas, l1.preco, l2.titulo, l2.paginas, l2.preco

    );


    return 0;
}
