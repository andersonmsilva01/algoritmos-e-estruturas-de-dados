/* 12. Pedra, Papel e Tesoura — Leia a jogada de dois jogadores e determine o vencedor. */

#include <stdio.h>

int main(){

  /* pedra, papel, tesoura */

  int pedra; int papel; int tesoura;

  int jog1;
  int jog2;

  printf("---vamos jogar pedra, papel e tesoura---\n");
  
  printf("jogador 1\n");
  scanf("%d", jog1);
  
  printf("jogador 2\n");
  scanf("%d", jog2);

  if (jog1 == jog2) {
    printf("empate");
  }

  else if (jog1 == pedra && jog1 == tesoura) {
    printf("jogador 1 venceu");
  }

  else if (jog1 == papel && jog1 == pedra) {
      printf("jogador 1 venceu");
  }

  else if (jog1 == tesoura && jog1 == papel) {
      printf("jogador 1 venceu");
  }

  else {
    printf("jogador 2 venceu");
  }


    return 0;
}
