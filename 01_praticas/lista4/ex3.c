/*
03. Exibir menu principal
Tipo: Sem parâmetro | Sem retorno

Enunciado:
Crie uma função chamada exibirMenu() sem parâmetros e sem retorno. Ela deve exibir na tela um menu com as opções: 1 - Cadastrar, 2 - Consultar, 3 - Sair. Cada opção deve estar em uma linha separada. Chame a função no main().

Dica: Use múltiplos printf(), um para cada opção do menu.
*/

#include <stdio.h>

void exibirMenu(){
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Sair\n");
}


int main(){

    exibirMenu();


    return 0;
}
