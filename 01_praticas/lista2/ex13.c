/* 13. Validação de Login — Simule um login com usuário e senha cadastrados. Dê 3 tentativas antes de bloquear o acesso. */

#include <stdio.h>

int main(){

const char * user = "admin";
int senha = 123455;

const char * user_dig;
int senha_dig;

printf("digite seu usuario: ");
scanf("%s", &user_dig);

printf("digite a sua senha: ");
scanf("%d", &senha_dig);


if (user_dig == user && senha_dig == senha) {
  printf("login realizado");
}

else if (user_dig != user) {
    printf("usuario incorreto, vc tem mais 2 tentativas");
}

else if (senha_dig != senha) {
    printf("senha incorreta, vc tem mais 1 tentativas");
}

else {
  printf("acesso bloqueado");
}

  return 0;
}

