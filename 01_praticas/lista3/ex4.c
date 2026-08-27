/*
4. Soma de N números
Leia N números do usuário e exiba a soma total.
*/
#include <stdio.h>

int main(){
  int n, x, soma = 0;
  scanf("%d", &n);

  for(int i=0; i < n; i++) {
    scanf("%d", &x);
    soma+=x;
  }
  printf("total: %d \n",soma);

    return 0;
}