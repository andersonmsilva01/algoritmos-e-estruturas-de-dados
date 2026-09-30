---
titulo: Nível 0 — Fundamentos de C
categoria: conceito
tags: [fundamentos, printf, scanf, tipos, operadores, iniciante]
fontes: [C language.md, Basic concepts.md, File input_output.md]
atualizado: 2026-05-27
---

# Nível 0 — Fundamentos de C

Tudo que precisa antes de escrever qualquer programa em C: 
- a estrutura de um programa
- guardar valores em variáveis
- mostrar coisas na tela
- ler do teclado
- como fazer contas

---

## 1. Estrutura mínima de um programa

### Explicação simples

- No topo, você lista os "utensílios" que vai usar (`#include`)
- A receita principal fica dentro de uma "função" chamada `main`
- Cada instrução termina com ponto e vírgula `;` (como o "ponto final")
- O programa começa a executar pela primeira linha do `main` e segue de cima para baixo

### Explicação técnica

 - O `#include` é uma diretiva do preprocessador que injeta o conteúdo de um header antes da compilação. 
 
 - Todo programa C executável precisa de uma função `main` — é o ponto de entrada definido pelo padrão.

 - `<stdio.h>` traz declarações de `printf`, `scanf` e outras funções de I/O.
 
 - O retorno `int` do `main` é o **status code** que o programa devolve
 
- Em int main(void) diz que a função main não recebe parâmetros 
- Poderia ser escrito int main() mas (void) deixa explícito que não usa argumentos da linha de comando
- `main(int argc, char *argv[])` seria a versão que recebe parâmetros.


### Código de exemplo

```c
#include <stdio.h>           // utensílio: funções de entrada/saída

int main(void) {             // função principal — começa aqui
    printf("Olá, mundo!\n"); // imprime mensagem na tela
    return 0;                // devolve "sucesso" pro sistema
}
```

**Como compilar e rodar (no terminal):**
```bash
gcc programa.c -o programa   # compila programa.c gerando o executável "programa"
./programa                   # executa o programa
```

> O `\n` dentro da string é o caractere de **nova linha** — pula para a linha seguinte.

---

## 2. Variáveis e tipos de dados

Cada variável em C tem:
- **Tipo** — determina quantos bytes ocupa na memória e como os bits são interpretados
- **Nome (identificador)** — só pode ter letras, dígitos e `_`, e não pode começar com dígito
- **Valor** — se você não inicializar, o conteúdo é **indeterminado** (lixo de memória)
- **Escopo** — visível apenas dentro do bloco `{ ... }` onde foi declarada

### Tipos primitivos principais

| Tipo | Tamanho típico | Faixa típica | Format specifier |
|------|---------------|--------------|------------------|
| `int` | 4 bytes | -2.147.483.648 a 2.147.483.647 | `%d` |
| `float` | 4 bytes | ~7 dígitos significativos | `%f`, `%.2f` |
| `double` | 8 bytes | ~15 dígitos significativos | `%lf`, `%.2lf` |
| `char` | 1 byte | -128 a 127 (ou 0 a 255) | `%c` |
| `long long` | 8 bytes | até ~9 quintilhões | `%lld` |

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int idade = 25;              // inteiro inicializado
    float altura = 1.75f;        // float (o 'f' final é opcional mas explícito)
    double pi = 3.14159265358;   // double — mais precisão
    char letra = 'A';            // UM caractere, sempre entre aspas SIMPLES
    long long populacao = 8000000000LL; // long long — inteiro bem grande
    int lixo;                    // declarada mas não inicializada — conteúdo aleatório!

    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f m\n", altura);  // %.2f = duas casas decimais
    printf("Pi: %.4lf\n", pi);
    printf("Letra: %c\n", letra);
    prinf("Populacao: %lld", populacao);

    lixo = 10;                   // agora sim, com valor definido
    printf("Agora ok: %d\n", lixo);

    return 0;
}
```

> **Armadilha:** `'A'` (aspas simples) é um caractere. `"A"` (aspas duplas) é uma **string** de um caractere — coisas diferentes.

> **'A'** é um char — um único caractere que ocupa 1 byte na memória.
> **"A"** é uma string — um array de chars com 2 bytes: o caractere 'A' mais o \0 (terminador nulo) que o C adiciona no fim automaticamente.

**Na prática:**

>**char c = 'A';** // ok — 1 byte
**char c2 = "A";**// ERRO — vai dar warning/erro, tipos diferentes
**const char *s = "A";** // ok — string, vale "A\0"

>Ou seja: 'A' é o valor 65 (o código ASCII), "A" é um vetor escondido {'A', '\0'}. São tipos diferentes e não dá pra trocar um pelo outro direto.


---

## 3. `printf` — saída formatada

### Explicação simples

O `printf` que escreve coisas na tela. Você diz **o que** quer escrever e, se a frase tiver "espaços em branco" marcados com `%`, você fornece os valores para preencher esses espaços.

### Explicação técnica

- `printf` é uma função **variádica** (aceita número variável de argumentos) declarada em `<stdio.h>`. 
- O primeiro argumento é a **format string**, que contém texto literal e **conversion specifiers** (`%d`, `%f`, etc.). 
- Cada specifier consome um argumento na ordem em que aparece.

### Format specifiers mais usados

| Specifier | Para que serve |
|-----------|---------------|
| `%d` ou `%i` | inteiro |
| `%f` | float ou double |
| `%.2f` | float com 2 casas decimais (nao funciona em scanf) |
| `%lf` | double (em scanf, obrigatório; em printf, não) |
| `%c` | caractere |
| `%s` | string |
| `%%` | um sinal de % literal |
| `\n` | nova linha |
| `\t` | tabulação |

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int notas = 8;
    float media = 7.5;
    char inicial = 'J';

    printf("Nome: %c.\n", inicial);
    printf("Aluno tirou %d pontos. Média: %.2f\n", notas, media);
    printf("Aprovação: 70%% dos casos\n");      // %% para imprimir %
    printf("Col1\tCol2\tCol3\n");                // \t = tabulação
    printf("Valor formatado: |%5d|\n", 42);      // |   42| (largura 5)
    printf("Valor formatado: |%-5d|\n", 42);     // |42   | (alinhado à esquerda)

    return 0;
}
```

---

## 4. `scanf` — entrada do usuário

### Explicação simples

- O `scanf` espera o usuário digitar e guarda esse valor em uma variável. 
- Para o `scanf` saber onde guardar o valor, precisa passar o "endereço" da variável usando `&`.

### Explicação técnica

- O `scanf` lê da entrada padrão (`stdin`), interpreta os caracteres digitados de acordo com a format string 
- Armazena os valores convertidos nos **endereços de memória** apontados pelos argumentos usando `&`.


### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int idade;
    float salario;
    char inicial;

    printf("Digite sua idade: ");
    scanf("%d", &idade);          // & é obrigatório!

    printf("Digite seu salário: ");
    scanf("%f", &salario);

    printf("Digite sua inicial: ");
    scanf(" %c", &inicial);       // espaço antes de %c ignora \n pendente

    printf("\n--- Resumo ---\n");
    printf("%c, %d anos, ganha R$ %.2f\n", inicial, idade, salario);

    return 0;
}
```

> **Armadilha crítica:** esquecer o `&` em `scanf("%d", n)` causa segmentation fault (o programa quebra). Não tem warning óbvio.

> **Armadilha do `%c`:** quando você lê um número e depois um caractere, o `\n` do Enter fica na entrada. Use `" %c"` (com espaço) para ignorá-lo.

---

## 5. Operadores aritméticos

### Explicação simples

São as operações de calculadora: soma, subtração, multiplicação, divisão. 

- Em C, há uma operação extra muito útil — o **resto da divisão**, escrito como `%`. 
- Por exemplo: `7 % 3` dá `1` (7 dividido por 3 sobra 1).

### Explicação técnica

Os operadores binários `+`, `-`, `*`, `/`, `%` seguem regras de **conversão aritmética usual**: quando operandos têm tipos diferentes, o "menor" é promovido. 
- Mas se ambos forem inteiros, a divisão é inteira (descarta a parte fracionária). 
- O `%` só está definido para tipos inteiros.

### Tabela de operadores

| | Nome | Exemplo | Resultado |
|----------|------|---------|-----------|
| `+` | soma | `5 + 3` | `8` |
| `-` | subtração | `5 - 3` | `2` |
| `*` | multiplicação | `5 * 3` | `15` |
| `/` | divisão | `7 / 2` | `3` (inteira!) |
| `/` | divisão | `7.0 / 2` | `3.5` (real) |
| `%` | resto (módulo) | `7 % 2` | `1` |
| `++` | incremento | `i++` | `i = i + 1` |
| `--` | decremento | `i--` | `i = i - 1` |

### Operadores compostos de atribuição

```c
soma += 5;    // equivale a: soma = soma + 5
soma -= 5;    // soma = soma - 5
soma *= 2;    // soma = soma * 2
soma /= 2;    // soma = soma / 2
soma %= 3;    // soma = soma % 3
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int a = 7, b = 2;

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d (divisão INTEIRA!)\n", a, b, a / b);  // 3
    printf("%d %% %d = %d (resto)\n", a, b, a % b);            // 1

    // Para obter resultado real, pelo menos um operando precisa ser float/double:
    printf("%d / %d = %.2f (divisão REAL)\n", a, b, (float)a / b);  // 3.50

    // Conversão Celsius → Fahrenheit: armadilha clássica
    float c = 100.0;
    float f_errado = (c * 9 / 5) + 32;       // ok, mas...
    float f_certo  = (c * 9.0 / 5.0) + 32;   // mais seguro
    printf("100C = %.1fF\n", f_certo);

    return 0;
}
```

---


## Armadilhas comuns

| Armadilha | O que acontece | Como evitar |
|-----------|---------------|-------------|
| Esquecer `&` no `scanf` | Crash (segfault) | Sempre `&variavel` para tipos primitivos |
| `int / int` esperando real | Resultado truncado | Use `float` em pelo menos um operando |
| `%c` lendo `\n` antigo | Pula a leitura | Use `" %c"` com espaço |
| Variável não inicializada | Valor lixo | Sempre inicialize: `int x = 0;` |
| Aspas erradas (`"A"` vs `'A'`) | Erro de compilação ou warning | `' '` para char, `" "` para string |
| Esquecer `;` no fim | Erro de compilação | Toda instrução termina com `;` |
| Esquecer `\n` no `printf` | Saída sai grudada | Inclua `\n` nas mensagens |

---

## Ver também

- [[nivel-1-condicionais]] — próximo passo: tomar decisões
- [[../analises/roteiro-estudo-listas-ifmg]] — visão geral do plano
