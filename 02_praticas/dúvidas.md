nivel-0-fundamentos

- O retorno `int` do `main` é o **status code** que o programa devolve ao sistema operacional: `0` significa "executou sem erros".

- para que serve o void?

- **Como compilar e rodar no terminal:** (erro)
	gcc programa.c -o programa   # compila programa.c gerando o executável "programa"
	./programa                   # executa o programa

- que tipo de dado é esse? 
	| `long long` | 8 bytes        | até ~9 quintilhões             | `%lld`           |
	| ----------- | -------------- | ------------------------------ | ---------------- |
- me explique isso melhor:  **Armadilha:** `'A'` (aspas simples) é um caractere. `"A"` (aspas duplas) é uma **string** de um caractere — coisas diferentes.
- qual a diferença de usar %c ou %s para dar printf ou scanf de um palavra? 
- explique isso melhor: **Armadilha crítica:** esquecer o `&` em `scanf("%d", n)` causa segmentation fault (o programa quebra). Não tem warning óbvio.
- explique isso melhor: **Armadilha do `%c`:** quando você lê um número e depois um caractere, o `\n` do Enter fica na entrada. Use `" %c"` (com espaço) para ignorá-lo.
- explique isso melhor: quando operandos têm tipos diferentes, o "menor" é promovido. **Mas** se ambos forem inteiros, a divisão é inteira (descarta a parte fracionária).
- explique melhor como usar os operadores aritmeticos no codigo, ficou vago.

Nível 1 — Estruturas Condicionais
- me explique isso melhor:  **Limitação:** `switch` **não funciona com `float`, `double`, strings ou intervalos** (`case 1..5` não existe em C padrão). Para esses, use `if/else if`. só funciona com inteiros?
- me de um explemo de codigo completo de operador ternario
- significado da palavra fall-through
- para usar operador ternario e operador logico preciso usar * antes das variaveis?