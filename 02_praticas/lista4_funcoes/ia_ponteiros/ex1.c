/*
1. Acessar um valor por ponteiro

No main(), 

declare uma variável inteira 

e um ponteiro para inteiro.

Faça o ponteiro guardar o endereço da variável.

Mostre:
- o valor da variável diretamente;
- o endereço da variável;
- o valor acessado por meio do ponteiro.

Objetivo: praticar os operadores & (obter endereço) e * (acessar o valor).
*/

#include <stdio.h>

int main(void) {

int x = 10;
int *p = x;
p = &x;

printf("
    
valor da variavel: %d. 
    
endereço da variavel: %d. 
    
valor acessado pelo ponteiro %p.",
    
    x, p, *p
    );

    return 0;
}

/*
CORREÇÃO: INCORRETO.
- "int *p = x;" tenta usar o valor de x como endereço. O ponteiro deve receber &x.
- O texto do printf foi quebrado em várias linhas dentro das aspas e causa erro de compilação.
- O endereço deve ser mostrado com %p e o valor acessado com *p deve usar %d.
- Na chamada do printf, a ordem correta dos dados é: x, (void *)p e *p.
*/
