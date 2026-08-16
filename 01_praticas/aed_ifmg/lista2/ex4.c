/*4. Aprovado ou Reprovado — Leia a média de um aluno e diga se ele foi 
aprovado (≥ 7) ou reprovado.*/

#include <stdio.h>

int main(){

    float nota1, nota2, nota3;

    printf("digite as 3 notas: \n");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    float media = nota1 + nota2 + nota3 / 3; 
    
    if (media >= 7) {
        printf("aprovado\n");
    }
    else {
        printf("reprovado\n");
    }


return 0;
}