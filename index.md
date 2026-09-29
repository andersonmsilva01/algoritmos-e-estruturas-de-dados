# Índice do Projeto — Linguagem C

> Fontes: páginas do **cppreference.com** (clippadas via Obsidian Web Clipper) + **ISO/IEC 9899:2011** (padrão oficial C11, 701 páginas).
> Documentação da linguagem C: `03_material_extra/doc_c_oficial/`
> Material da disciplina: `00_material_aula_ifmg/`

---

## Estrutura principal

| Caminho | Conteúdo |
|---|---|
| `00_material_aula_ifmg/` | Aulas e atividades fornecidas pelo IFMG. |
| `01_explicacao_da_ia/` | Explicações didáticas organizadas por nível. |
| `02_praticas/` | Resoluções, tentativas, anotações e dúvidas. |
| `03_material_extra/` | Documentação oficial e materiais auxiliares. |

---

## Fontes Ingeridas

### Linguagem C — Núcleo

| Arquivo | Resumo |
|---------|--------|
| `C reference.md` | Página raiz da referência C no cppreference. Índice geral com links para todos os padrões (C89 a C23), seções de linguagem, biblioteca padrão e especificações técnicas. Ponto de entrada da documentação. |
| `C language.md` | Visão geral de todos os construtos da linguagem C: conceitos básicos, keywords, preprocessador, expressões, declarações, inicialização, funções, statements. Serve como mapa da linguagem. |
| `Basic concepts.md` | Definições fundamentais: o que é um programa C, como declarações, identificadores, escopo, espaços de nomes, tipos e objetos se relacionam. Base conceitual para entender todo o restante. |
| `C keywords.md` | Lista completa de todas as palavras reservadas em C, do C89 ao C23. Inclui keywords com underscore (`_Bool`, `_Atomic`, etc.), suas macros de conveniência e em qual padrão cada uma foi introduzida ou depreciada. |
| `Declarations - cppreference.com.md` | Sintaxe e semântica de declarações em C: especificadores de tipo, qualificadores, classes de armazenamento, declaradores (ponteiro, array, função), diferença entre declaração e definição, redeclarações permitidas. Contém exemplos de declarações complexas com ponteiros para funções. |
| `Statements - cppreference.com.md` | Os 5 tipos de statements em C: compound (`{}`), expression, selection (`if`/`switch`), iteration (`for`/`while`/`do-while`), jump (`break`/`continue`/`return`/`goto`). Inclui labels e null statements. |
| `Expressions - cppreference.com.md` | Operadores em C (atribuição, aritmética, lógicos, comparação, acesso a membros), categorias de valor (lvalue/non-lvalue), ordem de avaliação, conversões implícitas e casts. Inclui expressões primárias, literais e expressões não-avaliadas (`sizeof`). |
| `Functions - cppreference.com.md` | Declaração e definição de funções em C. Funções não são aninhadas. Parâmetros, retorno, chamada de função. Cada função não-inline deve ser definida exatamente uma vez no programa. |
| `Preprocessor - cppreference.com.md` | Diretivas do preprocessador: `#define`/`#undef`, `#include`, `#if`/`#ifdef`/`#ifndef`/`#elif`/`#endif`, `#error`/`#warning`, `#pragma`, `#line`. Executado na fase 4 de tradução, antes da compilação. |
| `Initialization - cppreference.com.md` | Inicialização de objetos em C: explícita (escalar, array, struct/union), implícita (automáticos = indeterminate, statics = zero), empty initialization (`= {}` desde C23). Contém exemplo com designadores (`[0].a = {1}`). |
| `Value categories.md` | Categorias de valor em C: lvalue (designa objeto), non-lvalue object expression, function designator. Fundamentais para entender operadores e conversões. |
| `Order of evaluation.md` | Ordem de avaliação de expressões e sequencing: sequence points, quando operandos podem ser avaliados em qualquer ordem. Relacionado a undefined behavior com expressões como `i++ + i++`. |
| `Variadic functions.md` | Funções com número variável de argumentos (`...`). Macros `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy` via `<stdarg.h>`. Base para implementações de funções printf-like. |
| `Experimental C features.md` | Especificações técnicas experimentais do cppreference: extensões de memória dinâmica e extensões de ponto flutuante (FP Ext 1 e 4). Não são parte do padrão principal. |

---

### Biblioteca Padrão — Tipos e Suporte

| Arquivo | Resumo |
|---------|--------|
| `C Standard Library headers.md` | Lista completa dos 31 headers da stdlib C, do `<assert.h>` ao `<wctype.h>`, com descrição de cada um e a partir de qual padrão estão disponíveis. Inclui feature test macros do C23. |
| `Type support.md` | Tipos adicionais e macros de conveniência: `size_t`, `ptrdiff_t`, `NULL`, `offsetof`, `max_align_t`, tipos inteiros de largura fixa, macros booleanas (`bool`/`true`/`false`), `alignas`/`alignof`, `noreturn`. |

---

### Biblioteca Padrão — Entrada/Saída e Strings

| Arquivo | Resumo |
|---------|--------|
| `File input_output.md` | I/O em C via `<stdio.h>`: tipo `FILE*`, streams padrão (`stdin`/`stdout`/`stderr`), funções de arquivo (`fopen`/`fclose`/`fread`/`fwrite`), I/O formatado (`printf`/`scanf`), posicionamento (`fseek`/`ftell`), erros (`feof`/`ferror`/`perror`). |
| `Null-terminated byte strings.md` | Strings de bytes terminadas em null. Funções de `<string.h>` e `<ctype.h>`: classificação de caracteres (`isalpha`, `isdigit`...), manipulação (`strcpy`, `strcat`, `strlen`, `strcmp`, `strstr`, `strtok`), operações em memória (`memcpy`, `memset`, `memmove`), conversões numéricas (`atoi`, `strtol`, `strtod`). |
| `Null-terminated multibyte strings.md` | Strings multibyte terminadas em null. Funções para conversão entre bytes multibyte e wide characters, via `<stdlib.h>` e `<wchar.h>`. |
| `Null-terminated wide strings.md` | Strings wide (`wchar_t`) terminadas em null. Funções wide equivalentes às de `<string.h>`: `wcslen`, `wcscpy`, `wcscat`, etc., via `<wchar.h>`. |

---

### Biblioteca Padrão — Memória e Utilitários

| Arquivo | Resumo |
|---------|--------|
| `Dynamic memory management.md` | Gerenciamento dinâmico via `<stdlib.h>`: `malloc` (aloca), `calloc` (aloca e zera), `realloc` (redimensiona), `free` (libera). C11 adiciona `aligned_alloc`; C23 adiciona `free_sized` e `free_aligned_sized`. |
| `Program support utilities.md` | Controle do programa: `exit`, `abort`, `atexit`, `system`, `getenv`, `quick_exit`. Inclui saltos não-locais (`setjmp`/`longjmp`) e tratamento de sinais (`signal`/`raise`). |
| `Error handling.md` | Tratamento de erros: `errno` via `<errno.h>`, `assert` via `<assert.h>`, `static_assert` (C11). Erros da stdlib reportados via `errno`. |
| `Date and time utilities.md` | Funções de data e hora via `<time.h>`: `time`, `clock`, `difftime`, `mktime`, `localtime`, `gmtime`, `strftime`. Tipos `time_t`, `clock_t`, `struct tm`. |
| `Localization support.md` | Suporte à localização via `<locale.h>`: `setlocale`, `localeconv`. Afeta comportamento de I/O, strings e matemática dependentes de locale. |

---

### Biblioteca Padrão — Numérica e Matemática

| Arquivo | Resumo |
|---------|--------|
| `Numerics - cppreference.com.md` | Visão geral da biblioteca numérica: funções matemáticas, ambiente de ponto flutuante, números pseudo-aleatórios, complexos, type-generic math, manipulação de bits (C23), aritmética inteira com verificação (C23). |
| `Common mathematical functions.md` | Funções de `<math.h>`: trigonométricas (`sin`, `cos`, `tan`), exponenciais (`exp`, `log`), potências (`pow`, `sqrt`), arredondamento (`floor`, `ceil`, `round`), valor absoluto (`fabs`), etc. |
| `Floating-point environment.md` | Controle do ambiente de ponto flutuante via `<fenv.h>` (C99): modos de arredondamento (`FE_TONEAREST`...), flags de exceção (`FE_OVERFLOW`, `FE_DIVBYZERO`...), `fegetround`/`fesetround`. |
| `Pseudo-random number generation.md` | Geração de números pseudo-aleatórios via `<stdlib.h>`: `rand`, `srand`, `RAND_MAX`. Limitações do `rand` padrão (qualidade baixa, não thread-safe). |
| `Complex number arithmetic.md` | Aritmética de números complexos via `<complex.h>` (C99): tipos `_Complex`/`complex`, funções `creal`, `cimag`, `cabs`, `carg` e operações aritméticas complexas. |
| `Type-generic math (since C99).md` | Macros de matemática type-generic via `<tgmath.h>` (C99): despacham automaticamente para `sqrtf`/`sqrt`/`sqrtl`/`csqrt` etc. com base no tipo do argumento. |
| `Bit manipulation (since C23).md` | Funções de manipulação de bits via `<stdbit.h>` (C23): `stdc_count_zeros`, `stdc_count_ones`, `stdc_rotate_left`, `stdc_bit_width`, etc. |
| `Floating-point extensions part 1_ binary floating-point arithmetic.md` | Especificação técnica (não padrão): extensões de ponto flutuante binário IEEE 754. Tipos decimais e operações adicionais além de `<math.h>`. |
| `Floating-point extensions part 4_ supplementary functions.md` | Especificação técnica (não padrão): funções suplementares de ponto flutuante (FP Ext 4 TS). |
| `Dynamic memory extensions.md` | Especificação técnica (não padrão): extensões de memória dinâmica (dynamic memory TR) com funções além de `malloc`/`free`. |

---

### Biblioteca Padrão — Concorrência

| Arquivo | Resumo |
|---------|--------|
| `Concurrency support library.md` | Threads via `<threads.h>` (C11): `thrd_create`/`thrd_join`, mutexes (`mtx_t`), variáveis de condição (`cnd_t`), armazenamento local por thread (`tss_t`). Operações atômicas via `<stdatomic.h>`. |

---

### Algoritmos

| Arquivo | Resumo |
|---------|--------|
| `Algorithms - cppreference.com.md` | Algoritmos genéricos da stdlib: `qsort` (ordenação) e `bsearch` (busca binária), ambos via `<stdlib.h>`. São os únicos algoritmos genéricos da biblioteca padrão C. |

---

---

### Padrão Oficial

| Arquivo | Resumo |
|---------|--------|
| `ISO_IEC9899_2011.pdf` | **Padrão oficial C11 (ISO/IEC 9899:2011) — 701 páginas. Draft N1570, April 2011.** Documento normativo completo da linguagem C na revisão de 2011. Estrutura em 4 partes: (1) preliminares (cláusulas 1–4: escopo, referências, termos, conformidade); (2) ambientes (cláusula 5: modelo de tradução, execução, limites); (3) linguagem (cláusula 6: conceitos, conversões, elementos léxicos, expressões, declarações, statements, funções, preprocessador); (4) biblioteca (cláusula 7: todos os headers). Seguido de Anexos normativos (D, F, G, K, L) e informativos (A, B, C, E, J). |

**Estrutura do documento:**

| Cláusula | Conteúdo | Páginas |
|----------|----------|---------|
| 1–4 | Escopo, referências normativas, termos e definições, conformidade | 1–9 |
| 5 | Ambiente: modelo de tradução, execução freestanding/hosted, limites de implementação, conjuntos de caracteres | 10–34 |
| 6.2 | Conceitos: escopo, linkage, namespaces, duração de armazenamento, tipos, representação, alinhamento | 35–48 |
| 6.3 | Conversões: aritméticas (inteiros, ponto flutuante), ponteiros, void | 50–55 |
| 6.4 | Elementos léxicos: keywords, identificadores, constantes (inteiro, float, char, string), pontuadores | 57–75 |
| 6.5 | Expressões: todos os operadores com semântica formal, precedência, avaliação | 76–105 |
| 6.6 | Expressões constantes | 106–107 |
| 6.7 | Declarações: storage-class, type specifiers, qualifiers, `inline`/`_Noreturn`, `alignas`, declaradores, inicialização, `static_assert` | 108–145 |
| 6.8 | Statements: labeled, compound, expression, selection, iteration, jump | 146–154 |
| 6.9 | Definições externas: definições de funções, definições de objetos externos | 155–159 |
| 6.10 | Diretivas de preprocessamento: inclusão condicional, `#include`, substituição de macros, `#line`, `#error`, `#pragma`, macros predefinidas | 160–179 |
| 6.11 | Direções futuras da linguagem (features depreciadas) | 179 |
| 7.1–7.2 | Introdução à biblioteca, headers padrão, identificadores reservados, `assert` | 180–187 |
| 7.3 | `<complex.h>`: aritmética complexa, cortes de ramo, funções trigonométricas/hiperbólicas/exponenciais complexas | 188–199 |
| 7.4 | `<ctype.h>`: classificação e mapeamento de caracteres | 200–204 |
| 7.5 | `<errno.h>`: `errno`, `EDOM`, `EILSEQ`, `ERANGE` | 205 |
| 7.6 | `<fenv.h>`: exceções de ponto flutuante, modos de arredondamento, ambiente FP | 206–215 |
| 7.7 | `<float.h>`: limites de tipos de ponto flutuante (`FLT_MAX`, `DBL_EPSILON`, etc.) | 216 |
| 7.8 | `<inttypes.h>`: macros de formato para `printf`/`scanf` com inteiros de largura fixa | 217–220 |
| 7.9–7.10 | `<iso646.h>` (grafias alternativas), `<limits.h>` (limites de inteiros: `INT_MAX`, `CHAR_BIT`, etc.) | 221–222 |
| 7.11 | `<locale.h>`: `setlocale`, `localeconv`, struct `lconv` | 223–230 |
| 7.12 | `<math.h>`: tratamento de erros, classificação (`isnan`, `isinf`, `fpclassify`), trig, hiperb, exp/log, potências, gamma, arredondamento, manipulação FP, `fma` | 231–261 |
| 7.13 | `<setjmp.h>`: `setjmp`/`longjmp` — saltos não-locais | 262–264 |
| 7.14 | `<signal.h>`: `signal`, `raise`, sinais padrão (`SIGABRT`, `SIGSEGV`, etc.) | 265–267 |
| 7.15 | `<stdalign.h>`: macros `alignas`/`alignof` | 268 |
| 7.16 | `<stdarg.h>`: `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy` | 269–272 |
| 7.17 | `<stdatomic.h>` **(novo C11)**: tipos atômicos, ordem de memória (`memory_order`), operações atômicas, fences, `atomic_flag` | 273–286 |
| 7.18–7.20 | `<stdbool.h>`, `<stddef.h>`, `<stdint.h>`: bool, NULL/size\_t/ptrdiff\_t, inteiros de largura fixa e seus limites | 287–295 |
| 7.21 | `<stdio.h>`: streams, arquivos, `fopen`/`fclose`, `printf`/`scanf` e variantes, I/O de caracteres, posicionamento, erros | 296–339 |
| 7.22 | `<stdlib.h>`: conversão numérica, `rand`/`srand`, `malloc`/`calloc`/`realloc`/`free`/`aligned_alloc`, `exit`/`abort`/`at_quick_exit`/`quick_exit`, `qsort`/`bsearch`, aritmética de inteiros, conversão multibyte | 340–360 |
| 7.23 | `<stdnoreturn.h>`: macro `noreturn` | 361 |
| 7.24 | `<string.h>`: cópia, concatenação, comparação, busca, `memcpy`/`memmove`/`memset`, `strlen`, `strtok`, `strerror` | 362–372 |
| 7.25 | `<tgmath.h>`: macros type-generic que despacham para float/double/long double/complex | 373–375 |
| 7.26 | `<threads.h>` **(novo C11)**: `thrd_create`/`thrd_join`, mutexes (`mtx_*`), variáveis de condição (`cnd_*`), threads-local storage (`tss_*`), `call_once` | 376–387 |
| 7.27 | `<time.h>`: `time_t`, `clock_t`, `struct tm`, `time`/`clock`/`difftime`/`mktime`/`localtime`/`gmtime`/`strftime` | 388–397 |
| 7.28 | `<uchar.h>` **(novo C11)**: conversão UTF-16/UTF-32 com `char16_t`/`char32_t` | 398–401 |
| 7.29 | `<wchar.h>`: I/O wide formatado, funções de string wide, conversão multibyte/wide | 402–446 |
| 7.30 | `<wctype.h>`: classificação e mapeamento de wide characters | 447–457 |
| Anexo A | Gramática completa da linguagem (léxica, de frases, do preprocessador) — referência formal | 458–474 |
| Anexo B | Sumário de todas as funções/macros da biblioteca padrão por header | 475–503 |
| Anexo C | Sequências de caracteres universais permitidas | 504 |
| Anexo E | Limites de implementação (mínimos exigidos pelo padrão) | 505–506 |
| Anexo F | IEC 60559 (IEEE 754): mapeamento de tipos C para formatos binários, comportamento de conversões, otimizações | 507–542 |
| Anexo G | Aritmética imaginária IEC 60559 | 543–546 |
| Anexo J | Comportamento portável e não-portável: **undefined behavior** (lista completa), **unspecified behavior**, **implementation-defined behavior**, **locale-specific behavior** | 547–600 |
| Anexo K | Interfaces bounds-checking (`_s`): versões seguras de `strcpy_s`, `scanf_s`, etc. (condicional) | 601–660 |
| Anexo L | Analisabilidade: definições de comportamento crítico indefinido para ferramentas de análise estática (condicional) | 661–663 |

**Novidades introduzidas pelo C11 em relação ao C99:**
- `<stdatomic.h>`: operações atômicas e modelo de memória para concorrência
- `<threads.h>`: threads, mutexes, variáveis de condição, TSS
- `<uchar.h>`: suporte a Unicode (UTF-16/UTF-32)
- `_Alignas` / `_Alignof` / `<stdalign.h>`: controle de alinhamento
- `_Generic`: seleção genérica em expressões (type-generic programming)
- `_Noreturn` / `<stdnoreturn.h>`: anotação de funções que não retornam
- `_Static_assert` / `static_assert`: asserções em tempo de compilação
- Anonymous structs e unions
- `aligned_alloc`, `at_quick_exit`, `quick_exit` em `<stdlib.h>`
- Remoção de `gets` (substituída por `gets_s` no Anexo K)
- Suporte condicional a interfaces bounds-checking (Anexo K) e analisabilidade (Anexo L)

---

### Material da Disciplina (IFMG) e Auxiliar

| Arquivo | Resumo |
|---------|--------|
| `00_material_aula_ifmg/atividades/lista1_basicos.pdf` | Lista 1: algoritmos e fundamentos. Relacionada ao [[01_explicacao_da_ia/nivel-0-fundamentos|Nível 0]]. |
| `00_material_aula_ifmg/atividades/lista2_condicionais.pdf` | Lista 2: estruturas condicionais. Relacionada ao [[01_explicacao_da_ia/nivel-1-condicionais|Nível 1]]. |
| `00_material_aula_ifmg/atividades/lista3_repeticao.pdf` | Lista 3: estruturas de repetição. Relacionada ao [[01_explicacao_da_ia/nivel-2-repeticao|Nível 2]]. |
| `00_material_aula_ifmg/atividades/lista4_funcoes.pdf` | Lista 4: funções. Relacionada ao [[01_explicacao_da_ia/nivel-3-funcoes|Nível 3]]. |
| `00_material_aula_ifmg/atividades/lista5_vetor_matriz.pdf` | Lista 5: vetores e matrizes. Relacionada ao [[01_explicacao_da_ia/nivel-4-vetores-matrizes|Nível 4]]. |
| `00_material_aula_ifmg/atividades/lista5_extra.jpeg` | Três exercícios extras de vetores, incorporados ao [[01_explicacao_da_ia/nivel-4-vetores-matrizes|Nível 4]]. |
| `00_material_aula_ifmg/atividades/lista6_struct.pdf` | Lista 6: structs e registros. Relacionada ao [[01_explicacao_da_ia/nivel-5-structs|Nível 5]]. |
| `00_material_aula_ifmg/atividades/lista7_fila.pdf` | Lista 7: filas. Relacionada ao [[01_explicacao_da_ia/nivel-6-pilhas-filas-listas|Nível 6]]. |
| `00_material_aula_ifmg/atividades/lista8_pilha.pdf` | Lista 8: pilhas. Relacionada ao [[01_explicacao_da_ia/nivel-6-pilhas-filas-listas|Nível 6]]. |
| `00_material_aula_ifmg/aulas/aula_struct.pdf` | Slides de structs/registros usados como base para o [[01_explicacao_da_ia/nivel-5-structs|Nível 5]]. |
| `00_material_aula_ifmg/aulas/aula_pilha_fila_lista.pdf` | Slides sobre pilhas, filas e listas usados como base para o [[01_explicacao_da_ia/nivel-6-pilhas-filas-listas|Nível 6]]. |
| `00_material_aula_ifmg/aulas/codigo_empilha.rtf` | Exemplo de implementação de operação de empilhamento. |
| `03_material_extra/doc_auxiliares/web_sintaxe_c.pdf` | "Apêndice D — Manual de Sintaxe da Linguagem C": referência rápida da sintaxe ANSI C. |

---

## Conteúdo de Estudo

Material didático completo por nível, com explicações simples (analogias e linguagem cotidiana) + explicações técnicas + código de exemplo comentado.

| Página | Descrição |
|--------|-----------|
| [[01_explicacao_da_ia/nivel-0-fundamentos|Nível 0 — Fundamentos]] | Estrutura de programa, tipos, `printf`/`scanf`, operadores aritméticos. Base para a Lista 1. |
| [[01_explicacao_da_ia/nivel-1-condicionais|Nível 1 — Condicionais]] | `if/else if/else`, `switch/case`, operadores relacionais e lógicos, ternário. Base para a Lista 2. |
| [[01_explicacao_da_ia/nivel-2-repeticao|Nível 2 — Repetição]] | `for`, `while`, `do-while`, `break`/`continue`, padrões de acumulador/contador/máximo, laços aninhados. Base para a Lista 3. |
| [[01_explicacao_da_ia/nivel-3-funcoes|Nível 3 — Funções]] | Funções, parâmetros, passagem por valor vs. por referência, ponteiros essenciais e recursão. Base para a Lista 4. |
| [[01_explicacao_da_ia/nivel-4-vetores-matrizes|Nível 4 — Vetores e Matrizes]] | Vetores, strings, matrizes 2D, Bubble Sort, transposta, multiplicação de matrizes e passagem de array para função. Base para a Lista 5. |
| [[01_explicacao_da_ia/nivel-5-structs|Nível 5 — Structs]] | Registros (`struct`): declaração (`typedef`), acesso por campo, vetor de registros, struct aninhada e structs em funções. Base para a Lista 6. |
| [[01_explicacao_da_ia/nivel-6-pilhas-filas-listas|Nível 6 — Pilhas, Filas e Listas]] | Pilhas, filas, fila circular, listas simples e duplas, complexidade e exemplos progressivos. Base para as Listas 7 e 8. |
| `03_material_extra/doc_auxiliares/web_sintaxe_c.pdf` | Referência rápida da sintaxe ANSI C. |

---

## Práticas

| Lista | Pasta de resoluções | Material de origem |
|---|---|---|
| 1 — Básicos | `02_praticas/lista1_basicos/` | `00_material_aula_ifmg/atividades/lista1_basicos.pdf` |
| 2 — Condicionais | `02_praticas/lista2_condicionais/` | `00_material_aula_ifmg/atividades/lista2_condicionais.pdf` |
| 3 — Repetição | `02_praticas/lista3_repeticao/` | `00_material_aula_ifmg/atividades/lista3_repeticao.pdf` |
| 4 — Funções | `02_praticas/lista4_funcoes/` | `00_material_aula_ifmg/atividades/lista4_funcoes.pdf` |
| 5 — Vetores e matrizes | `02_praticas/lista5_vetor_matriz/` | `00_material_aula_ifmg/atividades/lista5_vetor_matriz.pdf` |
| 6 — Structs | `02_praticas/lista6_struct/` | `00_material_aula_ifmg/atividades/lista6_struct.pdf` |
| 7 — Filas | `02_praticas/lista7_fila/` | `00_material_aula_ifmg/atividades/lista7_fila.pdf` |
| 8 — Pilhas | `02_praticas/lista8_pilha/` | `00_material_aula_ifmg/atividades/lista8_pilha.pdf` |
