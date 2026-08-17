---
titulo: Nível 4 — Vetores, Strings e Matrizes
categoria: conceito
tags: [vetores, arrays, matrizes, strings, avancado]
fontes: [Declarations - cppreference.com.md, Null-terminated byte strings.md, lista5_extra.jpeg]
atualizado: 2026-06-28
---

# Nível 4 — Vetores, Strings e Matrizes

Até agora você guardou **um valor por variável**. Aqui você aprende a guardar **muitos valores** juntos em uma única estrutura: vetores (arrays), strings (vetor de caracteres) e matrizes (vetores de vetores).

---

## 1. Vetores (arrays unidimensionais)

### Explicação simples

Imagine uma **gaveta com 10 divisórias**, todas iguais. Em cada divisória cabe um valor do mesmo tipo (todos `int`, ou todos `float`, etc). Cada divisória tem um **número (índice)**, começando do **0**.

Se você tem `int v[10]`, as divisórias são `v[0], v[1], v[2], ..., v[9]`. Não existe `v[10]` — acessar essa posição é um bug grave!

### Explicação técnica

Um array em C é uma sequência **contígua na memória** de elementos do mesmo tipo. O nome do array, em quase todos os contextos, **decai para um ponteiro** para o primeiro elemento. Por isso `v[i]` é equivalente a `*(v + i)`.

C **não verifica os limites** do array em tempo de execução. Acessar `v[15]` em um array de 10 posições é **undefined behavior**: pode crashar, pode corromper outra variável, pode aparentemente funcionar.

### Declaração

```c
int v[10];                              // 10 inteiros (valores indeterminados)
int notas[5] = {7, 8, 9, 6, 10};        // inicializado
int zerado[100] = {0};                  // todos zerados (truque comum)
float salarios[3] = {1500.0, 2300.5, 4200.75};
```

### Acesso e percurso

```c
#include <stdio.h>

int main(void) {
    int v[5];

    // Preenchimento
    for (int i = 0; i < 5; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Impressão
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    // Impressão na ordem inversa
    for (int i = 4; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
```

---

## 2. Padrões fundamentais com vetores

### Soma de todos os elementos

```c
int soma = 0;
for (int i = 0; i < n; i++)
    soma += v[i];
```

### Maior e menor

```c
int max = v[0], min = v[0];        // inicia com o primeiro
for (int i = 1; i < n; i++) {
    if (v[i] > max) max = v[i];
    if (v[i] < min) min = v[i];
}
```

### Contar ocorrências de um valor

```c
int alvo, count = 0;
scanf("%d", &alvo);
for (int i = 0; i < n; i++)
    if (v[i] == alvo) count++;
```

### Substituir elementos

```c
// Trocar todos os negativos por zero
for (int i = 0; i < n; i++)
    if (v[i] < 0) v[i] = 0;
```

### Soma de dois vetores em um terceiro

```c
int a[10], b[10], c[10];
// ... leitura ...
for (int i = 0; i < 10; i++)
    c[i] = a[i] + b[i];
```

### Detecção de duplicatas (laços aninhados)

```c
int tem_repetido = 0;
for (int i = 0; i < n && !tem_repetido; i++) {
    for (int j = i + 1; j < n; j++) {
        if (v[i] == v[j]) {
            tem_repetido = 1;
            break;
        }
    }
}
```

---

## 3. Ordenação — Bubble Sort

### Explicação simples

O **Bubble Sort** ("ordenação por bolhas") compara pares de elementos vizinhos e os troca se estiverem fora de ordem. A cada "passada", o maior elemento "borbulha" para o fim. Repete até estar tudo ordenado.

Não é o algoritmo mais rápido (O(n²)), mas é o mais fácil de entender e implementar.

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int v[] = {5, 2, 8, 1, 9, 3};
    int n = 6;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");   // 1 2 3 5 8 9
    return 0;
}
```

---

## 4. Strings — vetores de caracteres

### Explicação simples

Em C, uma **string** é simplesmente um **vetor de `char`** que termina com um caractere especial: `'\0'` (caractere nulo). Esse `\0` marca o "fim da string". Tudo isso é automático quando você usa aspas duplas (`"Olá"`), mas você precisa lembrar que o **tamanho real ocupado é texto + 1**.

### Explicação técnica

C não tem tipo `string` nativo. Strings são arrays de `char` terminados em `'\0'` (null terminator). Funções padrão (`strlen`, `strcpy`, `printf("%s", ...)`) **dependem** desse `'\0'` para saber onde a string acaba — sem ele, leem memória até encontrar um zero qualquer (UB).

### Declaração e uso

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    // 3 formas equivalentes
    char s1[6] = "Olá";              // espaço para "O", "l", "á", "\0" (+padding)
    char s2[] = "Mundo";              // tamanho calculado automaticamente
    char s3[] = {'O','i','\0'};       // forma explícita

    printf("%s %s\n", s1, s2);        // %s para imprimir string inteira

    // Leitura: %s lê até o primeiro espaço (sem &!)
    char nome[50];
    printf("Nome: ");
    scanf("%49s", nome);              // 49 para deixar 1 byte para \0
    printf("Olá, %s!\n", nome);

    // Tamanho
    printf("Tamanho: %zu\n", strlen(nome));

    return 0;
}
```

### Funções úteis de `<string.h>`

| Função | Uso |
|--------|-----|
| `strlen(s)` | Tamanho da string (sem contar `\0`) |
| `strcpy(dest, src)` | Copia `src` em `dest` |
| `strcat(dest, src)` | Concatena `src` no fim de `dest` |
| `strcmp(s1, s2)` | Compara: `0` se iguais, `<0` ou `>0` se diferentes |

> **Nunca use `==` para comparar strings!** Isso compara endereços, não conteúdo.

### Vetor de strings (matriz de char)

```c
char nomes[10][50];   // 10 nomes, cada um com até 49 chars + \0

for (int i = 0; i < 10; i++) {
    printf("Nome %d: ", i + 1);
    scanf("%49s", nomes[i]);
}

for (int i = 0; i < 10; i++) {
    printf("%s\n", nomes[i]);
}
```

---

## 5. Matrizes (arrays bidimensionais)

### Explicação simples

Uma **matriz** é uma tabela: **linhas × colunas**. Cada célula é acessada por **dois índices**: `m[linha][coluna]`. Ambos começam do `0`.

Pense num jogo da velha: a matriz é o tabuleiro 3×3.

```
        col 0    col 1    col 2
linha 0  [0][0]  [0][1]  [0][2]
linha 1  [1][0]  [1][1]  [1][2]
linha 2  [2][0]  [2][1]  [2][2]
```

### Declaração

```c
int m[3][3];                          // 3 linhas, 3 colunas (lixo)
int identidade[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};
```

### Percurso típico (dois laços aninhados)

```c
// Preenchimento
for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        scanf("%d", &m[i][j]);

// Impressão formatada como tabela
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
        printf("%4d", m[i][j]);
    printf("\n");
}
```

> Por convenção: `i` percorre **linhas**, `j` percorre **colunas**.

---

## 6. Algoritmos clássicos com matrizes

### Soma de todos os elementos

```c
int soma = 0;
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        soma += m[i][j];
```

### Diagonal principal (`i == j`)

```c
int soma_diag = 0;
for (int i = 0; i < n; i++)
    soma_diag += m[i][i];   // m[0][0], m[1][1], m[2][2]...
```

### Diagonal secundária (`i + j == n - 1`)

```c
int soma_sec = 0;
for (int i = 0; i < n; i++)
    soma_sec += m[i][n - 1 - i];   // m[0][n-1], m[1][n-2]...
```

### Soma de cada linha

```c
for (int i = 0; i < n; i++) {
    int soma_linha = 0;
    for (int j = 0; j < n; j++)
        soma_linha += m[i][j];
    printf("Linha %d: %d\n", i, soma_linha);
}
```

### Elementos acima da diagonal principal (`j > i`)

```c
int soma_acima = 0;
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        soma_acima += m[i][j];
```

### Matriz identidade (verificação)

```c
int eh_identidade = 1;
for (int i = 0; i < n && eh_identidade; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j && m[i][j] != 1) { eh_identidade = 0; break; }
        if (i != j && m[i][j] != 0) { eh_identidade = 0; break; }
    }
}
```

### Transposta

```c
int t[4][4];
for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
        t[j][i] = m[i][j];      // troca índices
```

### Multiplicação de matrizes (triplo laço)

> Regra: número de **colunas** da primeira = número de **linhas** da segunda.

```c
// A[2][3] * B[3][2] = C[2][2]
int a[2][3], b[3][2], c[2][2];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        c[i][j] = 0;
        for (int k = 0; k < 3; k++)
            c[i][j] += a[i][k] * b[k][j];
    }
}
```

### Posição (linha, coluna) do maior elemento

```c
int max = m[0][0], li = 0, lj = 0;
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (m[i][j] > max) {
            max = m[i][j];
            li = i;
            lj = j;
        }
printf("Maior é %d em [%d][%d]\n", max, li, lj);
```

---

## Exercícios resolvidos

### Lista 5, vetor ex. 13 — Alunos acima da média

```c
#include <stdio.h>

int main(void) {
    float notas[5];
    float soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    float media = soma / 5;
    int acima = 0;
    for (int i = 0; i < 5; i++)
        if (notas[i] > media) acima++;

    printf("Média: %.2f\n", media);
    printf("Acima da média: %d alunos\n", acima);
    return 0;
}
```

### Lista 5, matriz ex. 11 — Matriz Identidade

```c
#include <stdio.h>

int main(void) {
    int m[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &m[i][j]);

    int eh = 1;
    for (int i = 0; i < 3 && eh; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && m[i][j] != 1) { eh = 0; break; }
            if (i != j && m[i][j] != 0) { eh = 0; break; }
        }
    }

    if (eh) printf("É matriz identidade\n");
    else    printf("Não é matriz identidade\n");
    return 0;
}
```

### Lista 5, matriz ex. 14 — Multiplicação 2×3 por 3×2

```c
#include <stdio.h>

int main(void) {
    int a[2][3], b[3][2], c[2][2];

    printf("Matriz A (2x3):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("Matriz B (3x2):\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Resultado:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%6d", c[i][j]);
        printf("\n");
    }
    return 0;
}
```

### Lista 5 (extra), ex. 2 — Maior elemento e sua posição

Vetor `Q` de 20 posições aceitando **somente positivos**; mostrar o maior valor e a posição (índice) que ele ocupa.

```c
#include <stdio.h>

int main(void) {
    int Q[20];

    for (int i = 0; i < 20; i++) {
        do {
            printf("Q[%d] (positivo): ", i);
            scanf("%d", &Q[i]);
        } while (Q[i] <= 0);          // só aceita positivo
    }

    int max = Q[0], pos = 0;
    for (int i = 1; i < 20; i++)
        if (Q[i] > max) {
            max = Q[i];
            pos = i;
        }

    printf("Maior valor: %d na posição %d\n", max, pos);
    return 0;
}
```

> Os outros dois exercícios extras (menor/maior em vetor de 20; maior em vetor `A` de 30) são variações diretas do padrão **máximo/mínimo** mostrado na seção 2.

---

## Vetores e funções — passando arrays

Quando você passa um vetor para uma função, **o que viaja é o endereço do primeiro elemento**, não uma cópia. Por isso alterações feitas na função afetam o vetor original — diferente de variáveis simples.

```c
#include <stdio.h>

// Estas duas assinaturas são EQUIVALENTES:
void imprimir(int v[], int n);
void imprimir(int *v, int n);

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void dobrarVetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        v[i] *= 2;            // altera o original!
}

int main(void) {
    int v[5] = {1, 2, 3, 4, 5};
    imprimir(v, 5);           // 1 2 3 4 5
    dobrarVetor(v, 5);
    imprimir(v, 5);           // 2 4 6 8 10
    return 0;
}
```

> Por isso passar arrays é sempre eficiente — sem cópia, mesmo arrays grandes.

---

## Armadilhas comuns

| Armadilha | O que acontece | Como evitar |
|-----------|---------------|-------------|
| Acessar `v[N]` (fora) | UB silencioso ou crash | Limite sempre é `< N`, não `<= N` |
| Esquecer `\0` em string manual | `printf("%s")` lê lixo | Use aspas duplas ou termine manualmente |
| Comparar string com `==` | Compara endereços, não conteúdo | Use `strcmp` |
| `scanf("%s", &nome)` | Errado: `%s` não usa `&` | `scanf("%s", nome)` |
| `scanf("%s")` sem limite | Buffer overflow | Use `scanf("%49s", buf)` para `char buf[50]` |
| `gets()` | UB clássico, removido | Use `fgets(buf, sizeof buf, stdin)` |
| Dimensões trocadas em matriz | Lê coisa errada | `m[linha][coluna]` — `i` é linha |
| Inicialização `{0}` esperando preencher tudo | Só zera mesmo | Para outros valores, faça loop |
| Esquecer `=` extra em `int v[5] = {1,2,3,4,5}` | Erro de sintaxe | Sempre `=` antes de `{...}` |

---

## Ver também

- [[nivel-3-funcoes]] — pré-requisito (ponteiros)
- [[../analises/roteiro-estudo-listas-ifmg]] — visão geral
