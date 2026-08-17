---
titulo: Nível 1 — Estruturas Condicionais
categoria: conceito
tags: [condicionais, if, else, switch, logica, intermediario]
fontes: [Statements - cppreference.com.md, Expressions - cppreference.com.md]
atualizado: 2026-05-27
---

# Nível 1 — Estruturas Condicionais

Aqui você ensina o programa a **tomar decisões**: "se isso, faça aquilo; senão, faça outra coisa". É o que diferencia uma calculadora de um programa "inteligente".

---

## 1. `if`, `else if`, `else`

### Explicação simples

Imagine que você está atravessando uma rua:
- **SE** o semáforo está verde → atravesse
- **SENÃO SE** está amarelo → cuidado
- **SENÃO** (está vermelho) → pare

Em código C, é exatamente essa estrutura: `if` → `else if` → `else`. Você pode ter quantos `else if` quiser, mas só um `if` no começo e (opcionalmente) um `else` no fim.

### Explicação técnica

`if` é uma **selection statement**. Ele avalia uma expressão entre parênteses: se o resultado é **diferente de zero**, executa o bloco; se é zero, pula para o `else` (se houver). Em C, não existe tipo booleano "puro" antes de C99 — qualquer valor não-zero é verdadeiro.

As chaves `{ ... }` agrupam várias instruções em um único bloco. Se houver apenas uma instrução, as chaves são opcionais — mas é **boa prática** sempre usar para evitar bugs.

### Sintaxe

```c
if (condição) {
    // executado se condição for verdadeira
} else if (outra_condição) {
    // executado se a primeira foi falsa E esta é verdadeira
} else {
    // executado se todas as anteriores forem falsas
}
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    float nota;

    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);

    if (nota >= 7.0) {
        printf("Aprovado\n");
    } else if (nota >= 5.0) {
        printf("Recuperação\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
```

> **Dica:** a ordem importa! As condições são avaliadas de cima para baixo. Se a primeira for verdadeira, as outras nem são testadas.

---

## 2. Operadores relacionais

### Explicação simples

São os operadores de "comparação" — eles olham para dois valores e respondem **sim** (verdadeiro, valor 1) ou **não** (falso, valor 0).

### Explicação técnica

Operadores relacionais produzem resultado do tipo `int`: `1` se a comparação é verdadeira, `0` se é falsa. Eles têm precedência menor que aritmética, mas maior que lógicos.

### Tabela

| Operador | Significado | Exemplo | Resultado se a=5, b=3 |
|----------|-------------|---------|----------------------|
| `==` | igual a | `a == b` | `0` (falso) |
| `!=` | diferente de | `a != b` | `1` (verdadeiro) |
| `<` | menor que | `a < b` | `0` |
| `>` | maior que | `a > b` | `1` |
| `<=` | menor ou igual | `a <= b` | `0` |
| `>=` | maior ou igual | `a >= b` | `1` |

> **Armadilha clássica:** `if (a = 5)` em vez de `if (a == 5)`. O primeiro **atribui** 5 a `a` (sempre verdadeiro!), o segundo **compara**. Compiladores modernos avisam, mas fique atento.

---

## 3. Operadores lógicos

### Explicação simples

Servem para **combinar condições**:
- `&&` (E) — só verdadeiro se **as duas** forem verdadeiras ("café E pão")
- `||` (OU) — verdadeiro se **pelo menos uma** for verdadeira ("café OU chá")
- `!` (NÃO) — inverte: `!verdadeiro = falso` ("NÃO está chovendo")

### Explicação técnica

Os operadores `&&` e `||` fazem **curto-circuito**: se o resultado já pode ser determinado pelo primeiro operando, o segundo nem é avaliado. Isso é útil para evitar erros:

```c
if (ponteiro != NULL && ponteiro > 0)  // só dereferencia se != NULL
```

### Tabela

| Operador | Nome      | Exemplo                      |
| -------- | --------- | ---------------------------- |
| `&&`     | E (AND)   | `idade >= 18 && idade <= 65` |
| \| \|    | OU (OR)   | `dia == 6 \|\| dia == 7`     |
| `!`      | NÃO (NOT) | `!(nota >= 7)`               |

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int idade;
    char tem_carteira;

    printf("Idade: ");
    scanf("%d", &idade);
    printf("Tem carteira? (s/n): ");
    scanf(" %c", &tem_carteira);

    if (idade >= 18 && tem_carteira == 's') {
        printf("Pode dirigir\n");
    } else if (idade < 18) {
        printf("Muito jovem\n");
    } else {
        printf("Precisa tirar carteira\n");
    }

    return 0;
}
```

---

## 4. `switch / case`

### Explicação simples

O `switch` é um atalho para quando você tem várias comparações **com o mesmo valor**. Em vez de escrever vários `if/else if`, você lista os "casos" possíveis.

Pense num menu de restaurante:
- Pediu **1** → traz salada
- Pediu **2** → traz pizza
- Pediu **3** → traz sobremesa
- **Qualquer outra coisa** (default) → "não temos isso"

### Explicação técnica

`switch` avalia uma expressão **inteira** (ou `char`, que é inteiro), e desvia para o `case` correspondente. **Sem o `break`**, a execução continua para o próximo `case` (fall-through) — comportamento intencional do padrão, mas fonte de muitos bugs quando esquecido.

`default` é o caso "qualquer outra coisa". É opcional, mas recomendado.

### Sintaxe

```c
switch (expressão) {
    case valor1:
        // código
        break;
    case valor2:
        // código
        break;
    default:
        // se nenhum case bateu
}
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int mes;

    printf("Digite o mês (1-12): ");
    scanf("%d", &mes);

    switch (mes) {
        case 12:
        case 1:
        case 2:
            printf("Verão\n");      // fall-through intencional: 12, 1, 2 caem aqui
            break;
        case 3:
        case 4:
        case 5:
            printf("Outono\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("Inverno\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("Primavera\n");
            break;
        default:
            printf("Mês inválido\n");
    }

    return 0;
}
```

> **Limitação:** `switch` **não funciona com `float`, `double`, strings ou intervalos** (`case 1..5` não existe em C padrão). Para esses, use `if/else if`.

---

## 5. Operador ternário (atalho para if/else simples)

### Explicação simples

É uma forma compacta de escrever um `if/else` em uma linha, quando você quer **escolher entre dois valores**.

### Sintaxe

```c
resultado = (condição) ? valor_se_verdadeiro : valor_se_falso;
```

### Código de exemplo

```c
int idade = 20;
char *categoria = (idade >= 18) ? "Adulto" : "Menor";

int a = 5, b = 3;
int maior = (a > b) ? a : b;     // maior recebe 5
```

> Use com moderação — em condições aninhadas, o ternário fica ilegível rápido.

---

## Exercícios resolvidos

### Lista 2, ex. 6 — Classificação de Triângulo

```c
#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Digite os três lados: ");
    scanf("%d %d %d", &a, &b, &c);

    // Primeiro: validar se forma triângulo
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("Equilátero\n");
        } else if (a == b || b == c || a == c) {
            printf("Isósceles\n");
        } else {
            printf("Escaleno\n");
        }
    } else {
        printf("Não forma triângulo\n");
    }

    return 0;
}
```

### Lista 2, ex. 11 — Ano Bissexto

```c
#include <stdio.h>

int main(void) {
    int ano;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    // Regra: divisível por 4 E não por 100, OU divisível por 400
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        printf("%d é bissexto\n", ano);
    } else {
        printf("%d não é bissexto\n", ano);
    }

    return 0;
}
```

### Lista 2, ex. 7 — Calculadora Simples com `switch`

```c
#include <stdio.h>

int main(void) {
    float a, b;
    char op;

    printf("Digite: numero1 operador numero2 (ex: 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+':
            printf("%.2f\n", a + b);
            break;
        case '-':
            printf("%.2f\n", a - b);
            break;
        case '*':
            printf("%.2f\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("%.2f\n", a / b);
            else
                printf("Erro: divisão por zero\n");
            break;
        default:
            printf("Operador inválido\n");
    }

    return 0;
}
```

---
## Armadilhas comuns

| Armadilha | Exemplo errado | Correto |
|-----------|---------------|---------|
| Usar `=` em vez de `==` | `if (x = 5)` | `if (x == 5)` |
| Esquecer `break` no switch | sem `break;` após um case | adicionar `break;` |
| Comparar floats com `==` | `if (x == 0.1)` é instável | `if (fabs(x - 0.1) < 1e-9)` |
| Comparar strings com `==` | `if (s1 == s2)` compara endereços | use `strcmp(s1, s2) == 0` |
| Condição sem chaves | `if (x) a; b;` — só `a` é condicional | sempre `{ ... }` |
| Precedência confusa | `if (a & b == c)` | `if ((a & b) == c)` |

---

## Ver também

- [[nivel-0-fundamentos]] — pré-requisito
- [[nivel-2-repeticao]] — próximo: laços
- [[../analises/roteiro-estudo-listas-ifmg]]
