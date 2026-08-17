---
titulo: Referência de Sintaxe C (Apêndice D)
categoria: síntese
tags: [referencia, sintaxe, cheat-sheet, ansi-c]
fontes: [web_sintaxe_c.pdf]
atualizado: 2026-06-28
---

# Referência de Sintaxe C — resumo do Apêndice D

Resumo do "Manual de Sintaxe da Linguagem C" (Apêndice D de *Fundamentos de Programação*). É um **cheat-sheet** de toda a sintaxe ANSI C — consulta rápida, não material de estudo passo a passo. Para aprender cada tópico, veja as páginas de conteúdo por nível.

> ⚠️ **Erratas da fonte** — o PDF tem imprecisões; veja a seção [Cuidados](#cuidados-e-erratas-da-fonte) no fim.

---

## Estrutura de um programa

```c
/* comentários: propósito, autor, data */
#include <stdio.h>          /* diretivas de pré-processador */
#define PI 3.14159          /* constantes/macros */

int soma(int a, int b);     /* protótipos / declarações globais */

int main(void) {            /* definição de funções (corpo) */
    return 0;
}
```

Ordem típica: comentários → diretivas → declarações globais → definições de funções.

---

## Tipos de dados

**Inteiros:** `char`, `short`, `int`, `long` (com variantes `signed`/`unsigned`).
**Reais:** `float`, `double`, `long double`.
**Lógico:** C clássico **não tem** tipo booleano — `0` é falso, qualquer valor `≠ 0` é verdadeiro. (C99+ tem `_Bool`/`<stdbool.h>`.)

```c
const int MAX = 100;        // const: valor não pode mudar
volatile char *porta;       // volatile: valor pode mudar "por fora"
```

**Literais numéricos:** `025` = octal, `0x25` = hexadecimal, `250L` = long.

**typedef** — dá um nome novo a um tipo existente:
```c
typedef struct { float x, y; } Ponto;
Ponto origem = {0.0, 0.0};
```

**enum** — lista de constantes inteiras (começam em 0 por padrão):
```c
enum Dia { SEG, TER, QUA };   // SEG=0, TER=1, QUA=2
```

---

## Operadores e precedência

| Categoria | Operadores |
|-----------|-----------|
| Aritméticos | `+  -  *  /  %` |
| Relacionais | `<  <=  >  >=  ==  !=` |
| Lógicos | `&&  \|\|  !` |
| Incr./decr. | `++  --` |
| Bit a bit | `&  \|  ^  <<  >>  ~` |
| Atribuição | `=  +=  -=  *=  /=  %=  <<=  >>=  &=  ^=  \|=` |
| Ternário | `cond ? a : b` |
| Vírgula (série) | `a, b` (avalia esq.→dir., valor é o de `b`) |

**Precedência (alta → baixa):** `() [] . ->` → unários (`! ~ ++ -- * & (cast) sizeof`) → `* / %` → `+ -` → deslocamentos → relacionais → `== !=` → `&` → `^` → `|` → `&&` → `||` → `?:` → atribuição → `,`.

```c
sizeof(int)        // nº de bytes do tipo
(float)9 / 2       // cast: força 4.5 em vez de divisão inteira
```

---

## Entrada e saída — `printf` / `scanf`

| Código | `printf` / `scanf` |
|--------|--------------------|
| `%d` | inteiro decimal |
| `%c` | caractere |
| `%s` | string |
| `%f` | float |
| `%lf` | double |
| `%e` | notação exponencial |
| `%u` | inteiro sem sinal |
| `%o` / `%x` | octal / hexadecimal |

```c
printf("Total: %d, média %.2f\n", n, m);
scanf("%d", &n);          // & obrigatório em escalares
scanf("%s", nome);        // string NÃO leva & (já é endereço)
```

---

## Sentenças de controle

```c
if (cond) { ... } else if (cond2) { ... } else { ... }

switch (op) {
    case 1: ...; break;
    default: ...;
}

cond ? a : b;                    // ternário

while (cond) { ... }
do { ... } while (cond);
for (init; cond; passo) { ... }

break;      // sai do laço/switch
continue;   // pula p/ próxima iteração
goto rotulo;  // (evitar)
```

A sentença `for` equivale a: `init; while(cond){ corpo; passo; }`.
Sentença **nula** (`;`) faz nada — usada em laços cujo trabalho está no cabeçalho.

---

## Funções

```c
tipo_retorno nome(tipo1 p1, tipo2 p2) {
    return expressao;
}

double area(int x, int y);   // protótipo (declarar antes de usar)
void encerra(int estado);    // void = não retorna nada
```

Erros típicos: faltar `return` em algum caminho; faltar protótipo (a função assume `int`); efeitos colaterais em variáveis globais.
`exit(0)` encerra o programa e fecha arquivos abertos.

---

## Estruturas de dados

**Arrays** — começam no índice `[0]`:
```c
int notas[25];
int m[4][3] = {{1,2,3},{4,5,6},{7,8,9},{0,0,0}};
int n = sizeof(v) / sizeof(v[0]);   // nº de elementos
```

**Strings** — arrays de `char` terminados em `'\0'`:
```c
char nome[] = "Serra Magna";     // inclui o \0 automático
```

**Structs** — coleção heterogênea (ver [[nivel-5-structs]]):
```c
struct Data { int dia, mes, ano; } hoje;
hoje.dia = 21;
typedef struct { int x, y; } Coord;
```

**Uniões** — armazenam **um** entre vários tipos no **mesmo** espaço de memória:
```c
union Demo { short x; long l; float f; } d;
d.x = 345;     // só um campo "vale" por vez
```

**Campos de bits** — empacotam inteiros em poucos bits (dependente de implementação):
```c
struct Pessoa {
    unsigned idade  : 7;   // 0..127
    unsigned sexo   : 1;
    unsigned filhos : 4;
};
```

---

## Ponteiros

```c
int m;
int *p = &m;     // p guarda o endereço de m
*p = 10;         // acessa/altera o valor apontado
int *nulo = NULL;

// ponteiro e array
float lista[50], *pl = lista;     // pl = &lista[0]
lista[4]  ==  *(lista + 4);       // equivalentes

char **pp;                 // ponteiro para ponteiro
int (*pf)(int, int);       // ponteiro para função
```

---

## Pré-processador

```c
#include <stdio.h>        // header do sistema
#include "meu.h"          // header local

#define PI 3.14159
#define QUAD(x) ((x)*(x)) // macro com parâmetro — use parênteses!

#ifndef GUARD_H           // include guard
#define GUARD_H
// ... conteúdo ...
#endif

#ifdef  / #ifndef / #if / #elif / #else / #endif   // compilação condicional
#undef NOME
#pragma ...
```

Macros predefinidas: `__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`, `__STDC__`.

---

## Cuidados e erratas da fonte

A fonte (`web_sintaxe_c.pdf`) é antiga e tem imprecisões — **não confie cegamente**:

| No PDF | Correto / observação |
|--------|----------------------|
| `int` = 2 bytes / 16 bits, `int` máx 32.767 | Era o modelo **16-bit** antigo. Em PCs modernos `int` tem **4 bytes** (`INT_MAX` ≈ 2,1 bilhões). Tamanhos são **dependentes de implementação** — use `<limits.h>` / `sizeof`. |
| `\h` = "nova linha" | **Errado.** Nova linha é `\n`. Não existe escape `\h` padrão. |
| `long double` = 10 bytes / 80 bits sempre | Depende da plataforma (pode ser 8, 12 ou 16 bytes). |
| `#erro` | A diretiva correta é `#error`. |
| Macro `#define quadrado(x) x*x` | Perigoso sem parênteses: `quadrado(a+b)` vira `a+b*a+b`. Use `((x)*(x))`. |
| `float total = 42,125;` | Em C o separador decimal é **ponto**: `42.125` (vírgula seria operador série). |

> Para valores normativos e portáveis, prefira as fontes oficiais já indexadas: `Type support.md`, `Basic concepts.md` e o padrão C11 (ver [[index]]).

---

## Ver também

- [[nivel-0-fundamentos]] · [[nivel-1-condicionais]] · [[nivel-2-repeticao]] · [[nivel-3-funcoes]] · [[nivel-4-vetores-matrizes]] · [[nivel-5-structs]]
- [[../analises/roteiro-estudo-listas-ifmg]] — roteiro de estudo
