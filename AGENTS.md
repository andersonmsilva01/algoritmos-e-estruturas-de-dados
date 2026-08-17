# Regras para o assistente (AGENTS.md)

## Compilação de arquivos .c (01_praticas)

Toda vez que o usuário rodar o compilador C (`gcc`) em um arquivo de práticas:

1. Comitar o arquivo `.c` com uma mensagem contendo o nome do arquivo e o número da tentativa de resolução.
   - Exemplo: tentativa 3 do `lista2/ex7.c` → `feat(lista2/ex7.c): tentativa 3`
2. Manter o histórico de tentativas: verificar `git log` para descobrir qual é o número da próxima tentativa antes de commitar.

## Executáveis

1. Sempre que um novo executável for gerado (arquivo binário sem extensão, `.dSYM`, etc.), adicioná-lo ao `.gitignore` imediatamente.
2. Nunca commitar executáveis ou binários compilados no repositório.