/*
3. Tabuada
Leia um número e imprima sua tabuada do 1 ao 10.
*/

#include <stdio.h>

//varias tabuadas de uma vez

int main(void){
  for(int n = 1; n <=10; n++){
    printf("--- Tabuada do %d ---\n",n);
    for(int i = 1; i <= 10; i++){
    printf("%d x %d = %d\n", n, i, i * n);
    }
  }
    return 0;
}

