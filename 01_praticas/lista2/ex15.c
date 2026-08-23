/* 15. Nota por Conceito — Leia a nota de um aluno (0–10) e atribua um conceito:

A (9–10), B (7–8), C (5–6), D (3–4), F (0–2). 

Exiba mensagem de erro para valores fora do intervalo. */

#include <stdio.h>

int main(){

  float aluno; 

  printf(" digite a nota do aluno: \n");
  scanf("%f", &aluno);

  if (aluno >= 9){
    printf("conceito A\n");
  }

  else if (aluno >= 7){
    printf("conceito B\n");
  }

  else if (aluno >= 5){
    printf("conceito C\n");
  }

  else if (aluno >= 3){
    printf("conceito D\n");
  }

  else {
    printf("conceito F\n");
  }

    return 0;
}
