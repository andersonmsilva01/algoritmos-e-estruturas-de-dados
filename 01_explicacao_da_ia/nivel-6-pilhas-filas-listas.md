---
titulo: Nível 6 — Pilhas, Filas e Listas
categoria: conceito
tags: [pilha, fila, lista, fifo, lifo, encadeamento, ponteiros, estruturas-de-dados]
fontes: [aula_pilha_fila_lista.pdf, lista7_fila.pdf, lista8_pilha.pdf]
atualizado: 2026-09-27
---

# Nível 6 — Pilhas, Filas e Listas

Este material reúne e organiza os conceitos dos PDFs `aula_pilha_fila_lista.pdf`, `lista7_fila.pdf` e `lista8_pilha.pdf`. A ideia central é simples: **a estrutura escolhida determina quais operações serão fáceis, rápidas ou restritas**.

---

## 1. Visão geral

### Explicação simples

- **Pilha:** funciona como uma pilha de pratos. O último prato colocado é o primeiro retirado.
- **Fila:** funciona como uma fila de atendimento. A primeira pessoa que entra é a primeira atendida.
- **Lista:** funciona como uma sequência de itens. É possível acessar, inserir ou remover em posições diferentes.

### Explicação técnica

Pilha, fila e lista são **tipos abstratos de dados (TADs)**. Um TAD é definido principalmente pelas operações que oferece, e não pela forma como os dados ficam guardados internamente.

| Estrutura | Regra principal | Inserção típica | Remoção típica | Exemplo |
|---|---|---|---|---|
| Pilha | LIFO | No topo | No topo | Desfazer ações, chamadas de funções |
| Fila | FIFO | No fim | No início | Atendimento, impressão, escalonamento |
| Lista | Ordem por posição | Início, fim ou meio | Início, fim ou meio | Cadastros e sequências editáveis |

**LIFO** significa *Last In, First Out*: último a entrar, primeiro a sair.

**FIFO** significa *First In, First Out*: primeiro a entrar, primeiro a sair.

Uma mesma estrutura abstrata pode ser implementada de formas diferentes:

- com **arranjo (vetor)**: memória contígua, capacidade normalmente fixa e acesso por índice;
- com **nós encadeados**: memória alocada conforme a necessidade e acesso por ponteiros.

### Interface e encapsulamento

Os exercícios dos PDFs pedem que o programa use operações como `empilha`, `desempilha`, `enfilera` e `desenfilera`, sem acessar os campos internos diretamente. Isso é importante porque:

1. impede que outras partes do programa quebrem as regras da estrutura;
2. permite trocar a implementação interna sem mudar o restante do programa;
3. concentra em um só lugar os testes de cheia, vazia e índices válidos.

```text
Programa usuário
      |
      | chama empilha(), enfilera(), insere()...
      v
Interface da estrutura
      |
      | protege os detalhes internos
      v
Vetor, índices, nós e ponteiros
```

---

## 2. Pilha

### 2.1 Conceito

#### Explicação simples

Em uma pilha, só se trabalha diretamente com o **topo**.

```text
            topo
              |
              v
          +-------+
          |   C   |  <- último que entrou; primeiro que sai
          +-------+
          |   B   |
          +-------+
          |   A   |
          +-------+
             fundo
```

Se `A`, `B` e `C` forem empilhados nessa ordem, eles serão removidos como `C`, `B`, `A`.

#### Explicação técnica

As operações básicas são:

- **inicializar/criar:** deixa a pilha vazia;
- **empilhar (*push*):** insere no topo;
- **desempilhar (*pop*):** remove e devolve o topo;
- **consultar o topo (*peek*):** devolve o topo sem removê-lo;
- **tamanho:** informa quantos elementos existem;
- **esvaziar/destruir:** remove os elementos ou libera a estrutura.

Com um vetor, o campo `topo` pode representar a **próxima posição livre**. Essa será a convenção usada aqui:

```text
dados: [ 3 ][ 7 ][ 1 ][   ][   ]
índice:   0    1    2    3    4
                         ^
                         topo = 3
```

Assim:

- pilha vazia: `topo == 0`;
- pilha cheia: `topo == CAPACIDADE`;
- elemento do topo: `dados[topo - 1]`.

Todas as operações básicas têm custo **O(1)**.

### 2.2 Nível fácil — operações básicas

O exemplo usa retorno `bool` para informar se a operação deu certo. Isso evita encerrar o programa dentro da estrutura e evita usar um número especial que talvez também seja um dado válido.

```c
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 10

typedef struct {
    int dados[CAPACIDADE];
    int topo; /* quantidade de elementos e próxima posição livre */
} Pilha;

void pilha_inicializar(Pilha *p) {
    p->topo = 0;
}

bool pilha_vazia(const Pilha *p) {
    return p->topo == 0;
}

bool pilha_cheia(const Pilha *p) {
    return p->topo == CAPACIDADE;
}

int pilha_tamanho(const Pilha *p) {
    return p->topo;
}

bool empilhar(Pilha *p, int valor) {
    if (pilha_cheia(p)) {
        return false;
    }

    p->dados[p->topo] = valor;
    p->topo++;
    return true;
}

bool desempilhar(Pilha *p, int *valor) {
    if (pilha_vazia(p)) {
        return false;
    }

    p->topo--;
    *valor = p->dados[p->topo];
    return true;
}

bool consultar_topo(const Pilha *p, int *valor) {
    if (pilha_vazia(p)) {
        return false;
    }

    *valor = p->dados[p->topo - 1];
    return true;
}

int main(void) {
    Pilha p;
    int valor;

    pilha_inicializar(&p);
    empilhar(&p, 3);
    empilhar(&p, 7);
    empilhar(&p, 1);
    empilhar(&p, 9);

    consultar_topo(&p, &valor);
    printf("Topo: %d\n", valor);
    printf("Tamanho: %d\n", pilha_tamanho(&p));

    while (desempilhar(&p, &valor)) {
        printf("Saiu: %d\n", valor);
    }

    return 0;
}
```

Saída:

```text
Topo: 9
Tamanho: 4
Saiu: 9
Saiu: 1
Saiu: 7
Saiu: 3
```

Observe a ordem inversa: `9` foi o último valor empilhado e o primeiro desempilhado.

### 2.3 Nível intermediário — parênteses balanceados

Uma expressão está balanceada quando cada símbolo de abertura é fechado pelo símbolo correto e na ordem correta.

```text
( a + [ b * c ] )
^     ^       ^ ^
|     +-------+ |
+---------------+
```

A pilha guarda os símbolos de abertura. Ao encontrar um fechamento, o algoritmo verifica o topo:

1. `(`, `[` ou `{` → empilha;
2. `)`, `]` ou `}` → desempilha e compara;
3. se faltar abertura ou o tipo for diferente → expressão inválida;
4. no final, a pilha precisa estar vazia.

```c
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIMBOLOS 100

typedef struct {
    char dados[MAX_SIMBOLOS];
    int topo;
} PilhaChar;

bool abertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool fechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool forma_par(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

bool balanceada(const char *texto) {
    PilhaChar p = {.topo = 0};

    for (int i = 0; texto[i] != '\0'; i++) {
        char atual = texto[i];

        if (abertura(atual)) {
            if (p.topo == MAX_SIMBOLOS) {
                return false; /* expressão excedeu a capacidade */
            }
            p.dados[p.topo++] = atual;
        } else if (fechamento(atual)) {
            if (p.topo == 0) {
                return false; /* fechamento sem abertura */
            }

            char abre = p.dados[--p.topo];
            if (!forma_par(abre, atual)) {
                return false;
            }
        }
    }

    return p.topo == 0;
}

int main(void) {
    const char *a = "(a+[b*c])";
    const char *b = "(a+[b)]";
    const char *c = ")(";

    printf("%s -> %s\n", a, balanceada(a) ? "válida" : "inválida");
    printf("%s -> %s\n", b, balanceada(b) ? "válida" : "inválida");
    printf("%s -> %s\n", c, balanceada(c) ? "válida" : "inválida");

    return 0;
}
```

Saída:

```text
(a+[b*c]) -> válida
(a+[b)] -> inválida
)( -> inválida
```

Complexidade: **O(n)** no tempo e **O(n)** de memória no pior caso.

### 2.4 Nível difícil — avaliar expressão pós-fixada

Na notação pós-fixada, o operador aparece depois dos operandos:

```text
Infixa:     3 + 4
Pós-fixada: 3 4 +
```

Para cada operador, o programa desempilha primeiro o operando da direita e depois o da esquerda:

```text
Pilha antes de '-': [ 8 ][ 3 ] <- topo

direita  = 3
esquerda = 8
resultado = 8 - 3 = 5
```

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALORES 100

typedef struct {
    int dados[MAX_VALORES];
    int topo;
} Pilha;

bool empilhar(Pilha *p, int valor) {
    if (p->topo == MAX_VALORES) return false;
    p->dados[p->topo++] = valor;
    return true;
}

bool desempilhar(Pilha *p, int *valor) {
    if (p->topo == 0) return false;
    *valor = p->dados[--p->topo];
    return true;
}

bool avaliar_posfixa(const char *expressao, int *resposta) {
    Pilha p = {.topo = 0};
    const char *cursor = expressao;

    while (*cursor != '\0') {
        if (*cursor == ' ') {
            cursor++;
            continue;
        }

        if ((*cursor >= '0' && *cursor <= '9') ||
            (*cursor == '-' && cursor[1] >= '0' && cursor[1] <= '9')) {
            char *fim;
            long numero = strtol(cursor, &fim, 10);

            if (!empilhar(&p, (int)numero)) return false;
            cursor = fim;
            continue;
        }

        if (*cursor == '+' || *cursor == '-' ||
            *cursor == '*' || *cursor == '/') {
            int esquerda, direita, resultado;

            if (!desempilhar(&p, &direita) ||
                !desempilhar(&p, &esquerda)) {
                return false;
            }

            switch (*cursor) {
                case '+': resultado = esquerda + direita; break;
                case '-': resultado = esquerda - direita; break;
                case '*': resultado = esquerda * direita; break;
                case '/':
                    if (direita == 0) return false;
                    resultado = esquerda / direita;
                    break;
                default: return false;
            }

            if (!empilhar(&p, resultado)) return false;
            cursor++;
            continue;
        }

        return false; /* caractere desconhecido */
    }

    if (p.topo != 1) return false;
    return desempilhar(&p, resposta);
}

int main(void) {
    const char *expressao = "5 1 2 + 4 * + 3 -";
    int resultado;

    if (avaliar_posfixa(expressao, &resultado)) {
        printf("%s = %d\n", expressao, resultado);
    } else {
        printf("Expressão inválida.\n");
    }

    return 0;
}
```

Saída:

```text
5 1 2 + 4 * + 3 - = 14
```

Complexidade: **O(n)**, pois cada item é processado uma vez.

### 2.5 Aplicações de pilha citadas nos PDFs

- histórico de desfazer/refazer;
- chamadas de funções e variáveis locais da recursão;
- inversão de strings;
- conversão de decimal para binário;
- verificação de palíndromos;
- expressões balanceadas;
- conversão infixa → pós-fixada;
- avaliação de expressão pós-fixada;
- pilha de mínimos.

---

## 3. Fila

### 3.1 Conceito

#### Explicação simples

Na fila, elementos novos entram no fim e elementos antigos saem pelo início.

```text
desenfileira                                  enfileira
     <- [ A ][ B ][ C ] <-
          ^           ^
       primeiro     último elemento
```

Se `A`, `B` e `C` entrarem nessa ordem, sairão como `A`, `B`, `C`.

#### Explicação técnica

As operações básicas são:

- **inicializar/criar**;
- **enfileirar (*enqueue*):** inserir no fim;
- **desenfileirar (*dequeue*):** remover do início;
- **consultar a frente:** obter o primeiro sem remover;
- **tamanho**;
- **esvaziar/destruir**.

Todas podem custar **O(1)** quando a estrutura mantém corretamente o início, o fim e a quantidade.

### 3.2 Por que a fila precisa ser circular?

Em uma fila simples de vetor, as remoções fazem o índice inicial avançar. Mesmo que existam posições livres no começo, o índice final pode chegar ao limite do vetor.

```text
Após algumas remoções:

[ livre ][ livre ][ 30 ][ 40 ][ 50 ]
                    ^             ^
                  início         fim
```

Não é necessário deslocar os elementos. Basta tratar o vetor como um círculo:

```text
posição seguinte = (posição atual + 1) % CAPACIDADE

0 <- 1 <- 2 <- 3 <- 4
^                   |
+-------------------+
```

Quando o índice passa da última posição, volta para zero.

Para distinguir fila cheia de fila vazia, há duas estratégias comuns:

1. sacrificar uma posição do vetor;
2. guardar um contador de elementos.

Os exemplos usam um contador, pois assim todas as posições do vetor podem ser utilizadas.

### 3.3 Nível fácil — fila circular

Aqui, `fim` indica a próxima posição onde um elemento será inserido.

```c
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 10

typedef struct {
    int dados[CAPACIDADE];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void fila_inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

bool fila_vazia(const Fila *f) {
    return f->quantidade == 0;
}

bool fila_cheia(const Fila *f) {
    return f->quantidade == CAPACIDADE;
}

int fila_tamanho(const Fila *f) {
    return f->quantidade;
}

bool enfileirar(Fila *f, int valor) {
    if (fila_cheia(f)) {
        return false;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % CAPACIDADE;
    f->quantidade++;
    return true;
}

bool desenfileirar(Fila *f, int *valor) {
    if (fila_vazia(f)) {
        return false;
    }

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->quantidade--;
    return true;
}

bool consultar_frente(const Fila *f, int *valor) {
    if (fila_vazia(f)) {
        return false;
    }

    *valor = f->dados[f->inicio];
    return true;
}

int main(void) {
    Fila f;
    int valor;

    fila_inicializar(&f);
    enfileirar(&f, 3);
    enfileirar(&f, 7);
    enfileirar(&f, 1);
    enfileirar(&f, 9);

    consultar_frente(&f, &valor);
    printf("Frente: %d\n", valor);
    printf("Tamanho: %d\n", fila_tamanho(&f));

    while (desenfileirar(&f, &valor)) {
        printf("Saiu: %d\n", valor);
    }

    return 0;
}
```

Saída:

```text
Frente: 3
Tamanho: 4
Saiu: 3
Saiu: 7
Saiu: 1
Saiu: 9
```

### 3.4 Nível intermediário — remover todas as ocorrências

A função abaixo usa somente a interface da fila. Ela guarda o tamanho inicial porque os elementos mantidos voltam para o fim.

```c
void remover_valor(Fila *f, int procurado) {
    int quantidade_inicial = fila_tamanho(f);

    for (int i = 0; i < quantidade_inicial; i++) {
        int atual;
        desenfileirar(f, &atual);

        if (atual != procurado) {
            enfileirar(f, atual);
        }
    }
}

void imprimir_fila(Fila *f) {
    int quantidade_inicial = fila_tamanho(f);

    for (int i = 0; i < quantidade_inicial; i++) {
        int atual;
        desenfileirar(f, &atual);
        printf("%d ", atual);
        enfileirar(f, atual);
    }
    printf("\n");
}
```

Uso, acrescentado ao exemplo anterior:

```c
enfileirar(&f, 4);
enfileirar(&f, 2);
enfileirar(&f, 4);
enfileirar(&f, 8);
enfileirar(&f, 4);

printf("Antes:  ");
imprimir_fila(&f);

remover_valor(&f, 4);

printf("Depois: ");
imprimir_fila(&f);
```

Saída:

```text
Antes:  4 2 4 8 4
Depois: 2 8
```

Complexidade: **O(n)**. A ordem relativa dos valores mantidos não muda.

### 3.5 Nível difícil — escalonamento round-robin

No round-robin, cada processo recebe no máximo um intervalo chamado **quantum**. Se não terminar, volta para o fim da fila.

```text
Fila inicial: P1(5) -> P2(3) -> P3(7)
Quantum: 2

P1 usa 2 e volta com 3 restantes
P2 usa 2 e volta com 1 restante
P3 usa 2 e volta com 5 restantes
...
```

```c
#include <stdbool.h>
#include <stdio.h>

#define MAX_PROCESSOS 20

typedef struct {
    int id;
    int restante;
} Processo;

typedef struct {
    Processo dados[MAX_PROCESSOS];
    int inicio;
    int fim;
    int quantidade;
} FilaProcessos;

void inicializar(FilaProcessos *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

bool enfileirar(FilaProcessos *f, Processo p) {
    if (f->quantidade == MAX_PROCESSOS) return false;
    f->dados[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_PROCESSOS;
    f->quantidade++;
    return true;
}

bool desenfileirar(FilaProcessos *f, Processo *p) {
    if (f->quantidade == 0) return false;
    *p = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_PROCESSOS;
    f->quantidade--;
    return true;
}

void executar_round_robin(FilaProcessos *f, int quantum) {
    int tempo = 0;
    Processo atual;

    while (desenfileirar(f, &atual)) {
        int executado = atual.restante < quantum
                      ? atual.restante
                      : quantum;

        printf("t=%d: P%d executa %d", tempo, atual.id, executado);
        tempo += executado;
        atual.restante -= executado;

        if (atual.restante > 0) {
            printf("; faltam %d\n", atual.restante);
            enfileirar(f, atual);
        } else {
            printf("; termina em t=%d\n", tempo);
        }
    }
}

int main(void) {
    FilaProcessos fila;

    inicializar(&fila);
    enfileirar(&fila, (Processo){.id = 1, .restante = 5});
    enfileirar(&fila, (Processo){.id = 2, .restante = 3});
    enfileirar(&fila, (Processo){.id = 3, .restante = 7});

    executar_round_robin(&fila, 2);
    return 0;
}
```

Saída:

```text
t=0: P1 executa 2; faltam 3
t=2: P2 executa 2; faltam 1
t=4: P3 executa 2; faltam 5
t=6: P1 executa 2; faltam 1
t=8: P2 executa 1; termina em t=9
t=9: P3 executa 2; faltam 3
t=11: P1 executa 1; termina em t=12
t=12: P3 executa 2; faltam 1
t=14: P3 executa 1; termina em t=15
```

Se a capacidade da fila for suficiente, cada retirada e reinserção custa **O(1)**. O tempo total depende da quantidade de fatias de CPU executadas.

### 3.6 Fila encadeada

Uma fila também pode usar nós:

```text
primeiro                                  último
   |                                         |
   v                                         v
+----+------+    +----+------+    +----+------+
| 10 |   o------>| 20 |   o------>| 30 | NULL |
+----+------+    +----+------+    +----+------+
```

- remover o primeiro nó: **O(1)**;
- inserir depois do último nó: **O(1)**;
- guardar `ultimo` é essencial; sem ele, seria necessário percorrer toda a fila para inserir, custando **O(n)**;
- não existe uma capacidade fixa, mas `malloc` ainda pode falhar quando não houver memória.

### 3.7 Aplicações de fila citadas nos PDFs

- fila de banco;
- geração de números binários;
- problema de Josephus/batata quente;
- escalonamento round-robin;
- fila feita com duas pilhas;
- deque, com inserção e remoção nas duas pontas;
- fila genérica com `void *`;
- fila de prioridade.

---

## 4. Lista

### 4.1 Conceito

#### Explicação simples

Uma lista é uma sequência em que a posição dos elementos importa e as operações não ficam obrigatoriamente presas a uma única ponta.

```text
posição:   0      1      2      3
         [ 12 ][ 25 ][ 31 ][ 48 ]
```

É possível pedir, por exemplo:

- insira `20` na posição `1`;
- remova o elemento da posição `3`;
- recupere o elemento da posição `2`.

#### Explicação técnica

Uma lista pode oferecer:

- inserção e remoção no início;
- inserção e remoção no fim;
- inserção e remoção em uma posição;
- consulta por posição;
- busca por valor;
- tamanho e destruição.

A regra de acesso da lista é mais flexível que a da pilha e da fila. O custo depende fortemente da implementação escolhida.

### 4.2 Lista com vetor

Os elementos ficam lado a lado na memória:

```text
Antes de inserir 20 na posição 1:
[ 10 ][ 30 ][ 40 ][    ]

1. desloca para a direita:
[ 10 ][ 30 ][ 30 ][ 40 ]

2. grava o novo valor:
[ 10 ][ 20 ][ 30 ][ 40 ]
```

Vantagens:

- acesso direto por índice em **O(1)**;
- boa localidade de memória;
- implementação simples.

Desvantagens:

- capacidade fixa no vetor estático;
- inserir ou remover no meio exige deslocamentos: **O(n)**.

### 4.3 Nível fácil — lista com vetor

```c
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 10

typedef struct {
    int dados[CAPACIDADE];
    int tamanho;
} Lista;

void lista_inicializar(Lista *lista) {
    lista->tamanho = 0;
}

bool lista_inserir(Lista *lista, int posicao, int valor) {
    if (lista->tamanho == CAPACIDADE) return false;
    if (posicao < 0 || posicao > lista->tamanho) return false;

    for (int i = lista->tamanho; i > posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return true;
}

bool lista_remover(Lista *lista, int posicao, int *removido) {
    if (posicao < 0 || posicao >= lista->tamanho) return false;

    *removido = lista->dados[posicao];

    for (int i = posicao; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho--;
    return true;
}

bool lista_obter(const Lista *lista, int posicao, int *valor) {
    if (posicao < 0 || posicao >= lista->tamanho) return false;
    *valor = lista->dados[posicao];
    return true;
}

void lista_imprimir(const Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int main(void) {
    Lista lista;
    int removido;

    lista_inicializar(&lista);
    lista_inserir(&lista, 0, 10);
    lista_inserir(&lista, 1, 30);
    lista_inserir(&lista, 2, 40);

    printf("Original: ");
    lista_imprimir(&lista);

    lista_inserir(&lista, 1, 20);
    printf("Inserção: ");
    lista_imprimir(&lista);

    lista_remover(&lista, 2, &removido);
    printf("Removido: %d\n", removido);
    printf("Final:    ");
    lista_imprimir(&lista);

    return 0;
}
```

Saída:

```text
Original: 10 30 40
Inserção: 10 20 30 40
Removido: 30
Final:    10 20 40
```

### 4.4 Lista simplesmente encadeada

Cada elemento fica em um nó que guarda o dado e o endereço do próximo nó:

```text
início
  |
  v
+------+-------+    +------+-------+    +------+------+
|  10  |   o------->|  20  |   o------->|  30  | NULL |
+------+-------+    +------+-------+    +------+------+
  dado   próximo
```

Os nós não precisam ocupar posições vizinhas na memória. O ponteiro `proximo` mantém a ordem lógica.

Vantagens:

- cresce enquanto houver memória disponível;
- inserir ou remover depois de um nó conhecido custa **O(1)**;
- não é necessário deslocar os outros elementos.

Desvantagens:

- acessar a posição `i` exige seguir os ponteiros: **O(n)**;
- cada nó ocupa memória extra para o ponteiro;
- é obrigatório controlar `malloc` e `free`.

### 4.5 Nível intermediário — lista simplesmente encadeada

Este exemplo guarda ponteiros para o início e para o fim. A remoção procura a primeira ocorrência de um valor.

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void lista_inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

bool inserir_fim(Lista *lista, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) return false;

    novo->dado = valor;
    novo->proximo = NULL;

    if (lista->fim == NULL) {
        lista->inicio = novo; /* era uma lista vazia */
    } else {
        lista->fim->proximo = novo;
    }

    lista->fim = novo;
    lista->tamanho++;
    return true;
}

bool remover_valor(Lista *lista, int valor) {
    No *anterior = NULL;
    No *atual = lista->inicio;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (anterior == NULL) {
        lista->inicio = atual->proximo; /* removeu o primeiro */
    } else {
        anterior->proximo = atual->proximo;
    }

    if (lista->fim == atual) {
        lista->fim = anterior; /* removeu o último */
    }

    free(atual);
    lista->tamanho--;
    return true;
}

void lista_imprimir(const Lista *lista) {
    for (No *no = lista->inicio; no != NULL; no = no->proximo) {
        printf("%d ", no->dado);
    }
    printf("\n");
}

void lista_destruir(Lista *lista) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int main(void) {
    Lista lista;

    lista_inicializar(&lista);
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);

    printf("Antes:  ");
    lista_imprimir(&lista);

    remover_valor(&lista, 20);

    printf("Depois: ");
    lista_imprimir(&lista);
    printf("Tamanho: %d\n", lista.tamanho);

    lista_destruir(&lista);
    return 0;
}
```

Saída:

```text
Antes:  10 20 30
Depois: 10 30
Tamanho: 2
```

A procura custa **O(n)**. Depois que o nó é encontrado, a ligação e a liberação custam **O(1)**.

### 4.6 Lista duplamente encadeada

Cada nó conhece o anterior e o próximo:

```text
             +-------------------+
             |                   |
             v                   |
NULL <- [ 10 ] <-> [ 20 ] <-> [ 30 ] -> NULL
          ^                         ^
        início                     fim
```

Isso permite caminhar nos dois sentidos e remover um nó conhecido em **O(1)**, mas exige mais memória e mais cuidado ao atualizar os ponteiros.

Ao inserir `20` entre `10` e `30`, quatro ligações precisam ficar coerentes:

```text
10.proximo  = 20
20.anterior = 10
20.proximo  = 30
30.anterior = 20
```

### 4.7 Nível difícil — lista dupla ordenada

O exemplo insere valores em ordem crescente e permite percorrer a lista nos dois sentidos.

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} ListaDupla;

void inicializar(ListaDupla *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

bool inserir_ordenado(ListaDupla *lista, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) return false;

    novo->dado = valor;

    No *sucessor = lista->inicio;
    while (sucessor != NULL && sucessor->dado < valor) {
        sucessor = sucessor->proximo;
    }

    if (sucessor == NULL) {
        /* insere no fim */
        novo->anterior = lista->fim;
        novo->proximo = NULL;

        if (lista->fim != NULL) {
            lista->fim->proximo = novo;
        } else {
            lista->inicio = novo;
        }
        lista->fim = novo;
    } else {
        /* insere antes de sucessor */
        novo->proximo = sucessor;
        novo->anterior = sucessor->anterior;

        if (sucessor->anterior != NULL) {
            sucessor->anterior->proximo = novo;
        } else {
            lista->inicio = novo;
        }
        sucessor->anterior = novo;
    }

    lista->tamanho++;
    return true;
}

bool remover_valor(ListaDupla *lista, int valor) {
    No *atual = lista->inicio;

    while (atual != NULL && atual->dado != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->inicio = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->fim = atual->anterior;
    }

    free(atual);
    lista->tamanho--;
    return true;
}

void imprimir_crescente(const ListaDupla *lista) {
    for (No *no = lista->inicio; no != NULL; no = no->proximo) {
        printf("%d ", no->dado);
    }
    printf("\n");
}

void imprimir_decrescente(const ListaDupla *lista) {
    for (No *no = lista->fim; no != NULL; no = no->anterior) {
        printf("%d ", no->dado);
    }
    printf("\n");
}

void destruir(ListaDupla *lista) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int main(void) {
    ListaDupla lista;

    inicializar(&lista);
    inserir_ordenado(&lista, 30);
    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 40);
    inserir_ordenado(&lista, 20);

    printf("Crescente:   ");
    imprimir_crescente(&lista);

    printf("Decrescente: ");
    imprimir_decrescente(&lista);

    remover_valor(&lista, 30);
    printf("Sem o 30:    ");
    imprimir_crescente(&lista);

    destruir(&lista);
    return 0;
}
```

Saída:

```text
Crescente:   10 20 30 40
Decrescente: 40 30 20 10
Sem o 30:    10 20 40
```

A busca da posição de inserção ou do valor custa **O(n)**. Se o nó já fosse conhecido, inserir antes dele ou removê-lo custaria **O(1)**.

### 4.8 Lista genérica com `void *`

Os slides também apresentam nós capazes de guardar endereços de qualquer tipo:

```c
typedef struct No {
    void *dado;
    struct No *anterior;
    struct No *proximo;
} No;
```

Isso torna a estrutura reutilizável, mas cria uma responsabilidade importante: o código precisa definir **quem libera o objeto apontado por `dado`**.

```text
free(no);        -> libera apenas o nó
free(no->dado);  -> libera o objeto, se ele foi criado com malloc
```

Uma solução robusta é a função de destruição receber um ponteiro para função:

```c
void lista_destruir(Lista *lista, void (*destruir_dado)(void *));
```

Assim, a lista pode liberar cada dado da maneira correta antes de liberar o nó.

---

## 5. Comparação de complexidade

### Operações típicas

| Estrutura/implementação | Consultar extremidade | Inserir na extremidade usada | Remover na extremidade usada | Buscar valor |
|---|---:|---:|---:|---:|
| Pilha com vetor | O(1) | O(1) | O(1) | O(n) |
| Fila circular com vetor | O(1) | O(1) | O(1) | O(n) |
| Fila encadeada com início e fim | O(1) | O(1) | O(1) | O(n) |
| Lista com vetor | O(1) por índice | O(1) no fim; O(n) no meio | O(1) no fim; O(n) no meio | O(n) |
| Lista simplesmente encadeada | O(1) no início | O(1) após nó conhecido | O(1) após antecessor conhecido | O(n) |
| Lista duplamente encadeada | O(1) nas pontas | O(1) perto de nó conhecido | O(1) para nó conhecido | O(n) |

### Vetor versus encadeamento

| Critério | Vetor | Nós encadeados |
|---|---|---|
| Memória | Contígua | Nós podem ficar separados |
| Capacidade | Normalmente fixa | Cresce enquanto houver memória |
| Acesso por índice | O(1) | O(n) |
| Inserção/remoção no meio | Desloca elementos, O(n) | O(1) se a posição/nó adequado já for conhecido |
| Memória extra | Pouca | Ponteiro(s) em cada nó |
| Falha típica | Índice fora do limite | Ponteiro inválido ou vazamento |

> **Atenção:** localizar a posição em uma lista encadeada continua custando O(n). Dizer que “inserir no meio custa O(1)” só é correto quando o nó anterior/sucessor já é conhecido.

---

## 6. Erros e casos-limite que sempre devem ser testados

### Pilha

- desempilhar uma pilha vazia;
- empilhar em uma pilha cheia;
- consultar o topo vazio;
- confundir “índice do último elemento” com “próxima posição livre”.

### Fila

- desenfileirar uma fila vazia;
- enfileirar em uma fila cheia;
- esquecer a volta circular do índice;
- confundir fila cheia com vazia quando `inicio == fim`;
- alterar a ordem ao imprimir ou copiar.

### Lista

- inserir em posição negativa ou maior que o tamanho;
- remover de lista vazia;
- atualizar apenas um dos ponteiros;
- esquecer de atualizar `inicio` ou `fim` ao remover uma ponta;
- perder a referência de um nó antes de executar `free`;
- esquecer de liberar todos os nós.

### Sequência segura para remover um nó

```text
1. guardar o endereço necessário para continuar;
2. religar os vizinhos;
3. atualizar início/fim se necessário;
4. liberar o nó;
5. atualizar o tamanho.
```

---

## 7. Observações e correções dos slides

Os conceitos apresentados nos PDFs estão corretos, mas alguns trechos de código têm pequenos erros de digitação ou dependem de uma convenção que precisa ficar explícita:

1. Se `topo` indica a próxima posição livre, a pilha fica cheia quando `topo == MAX_ELEMENTOS`, e não quando `topo == MAX_ELEMENTOS - 1`. Testar `MAX_ELEMENTOS - 1` desperdiça a última posição.
2. Na fila circular, a expressão `ultimo + 1 == primeiro` não basta quando `ultimo` está na última posição. É preciso aplicar o módulo, sacrificar uma posição ou guardar a quantidade. Nesta nota foi usada a quantidade.
3. Na lista com vetor dos slides, aparecem nomes trocados como `x`/`posicao` e `elemtos`/`elementos`. Os exemplos desta nota usam um único nome de forma consistente.
4. Funções que devolvem um valor devem ser declaradas com o tipo correto. Por exemplo, uma função que retorna um elemento não pode ser `void`.
5. Em uma lista simplesmente encadeada, guardar apenas o ponteiro para o último nó torna a **inserção** no fim O(1), mas não torna a **remoção** do fim O(1), porque ainda é preciso encontrar o penúltimo nó. Uma lista dupla resolve isso.
6. Ao inserir o primeiro nó de uma lista encadeada vazia, normalmente é necessário atualizar tanto `inicio` quanto `fim`.

Essas correções não mudam o conceito estudado; apenas evitam acesso fora do vetor, perda de capacidade ou ponteiros inconsistentes.

---

## 8. Como escolher a estrutura

Use esta sequência de perguntas:

```text
Só preciso inserir e remover no mesmo lado?
    |
    +-- sim --> PILHA
    |
    +-- não
         |
         +-- preciso respeitar a ordem de chegada?
         |       |
         |       +-- sim --> FILA
         |       +-- não
         |
         +-- preciso acessar/inserir/remover em posições variadas?
                 |
                 +-- sim --> LISTA
```

Depois escolha a implementação:

- **vetor:** melhor quando a capacidade é conhecida e o acesso por posição é importante;
- **encadeada:** melhor quando o tamanho varia e inserções/remoções por nós conhecidos são frequentes;
- **lista dupla:** melhor quando é necessário caminhar nos dois sentidos ou remover nós conhecidos sem procurar o anterior.

---

## 9. Roteiro de estudo baseado nas listas 7 e 8

### Etapa 1 — dominar a interface

Faça primeiro:

- criar/inicializar;
- testar vazia e cheia;
- inserir;
- remover;
- consultar sem remover;
- tamanho;
- esvaziar e destruir.

### Etapa 2 — preservar a estrutura

Pratique:

- imprimir sem destruir;
- copiar;
- comparar;
- inverter;
- remover ocorrências mantendo a ordem.

O ponto principal é conseguir retirar temporariamente os elementos e depois reconstruir a estrutura na mesma ordem.

### Etapa 3 — aplicações clássicas

- pilha: parênteses, palíndromo, conversão de base e pós-fixa;
- fila: banco, binários, Josephus e round-robin;
- lista: inserção/remoção por posição e busca.

### Etapa 4 — desafios de implementação

- fila feita com duas pilhas;
- pilha de mínimos;
- fila e pilha com nós;
- deque;
- lista dupla;
- estruturas genéricas com `void *`;
- fila de prioridade;
- conversão infixa → pós-fixada.

---

## 10. Checklist antes de considerar um exercício pronto

- [ ] A regra LIFO/FIFO foi respeitada?
- [ ] A estrutura vazia foi testada?
- [ ] A capacidade máxima foi testada, quando existe?
- [ ] Os índices circulares voltam corretamente para zero?
- [ ] A função altera somente o que promete alterar?
- [ ] Uma impressão, cópia ou comparação deixa a estrutura original intacta?
- [ ] Todo `malloc` correspondente é liberado com `free`?
- [ ] `inicio`, `fim`, `topo` e `tamanho` continuam coerentes?
- [ ] Os casos com zero, um e vários elementos funcionam?
- [ ] A complexidade está de acordo com a estrutura escolhida?

---

## Resumo final

```text
PILHA: uma ponta; último entra, primeiro sai; LIFO.
FILA: duas pontas; primeiro entra, primeiro sai; FIFO.
LISTA: acesso flexível por posição ou por nós.

VETOR: índice rápido, capacidade limitada, deslocamentos no meio.
ENCADEADA: tamanho flexível, ponteiros, acesso sequencial.
```

O aprendizado mais importante não é decorar o código. É entender e manter os **invariantes**:

- na pilha, `topo` precisa representar corretamente a quantidade/próxima posição;
- na fila, início, fim e quantidade precisam descrever o mesmo estado;
- na lista, todos os ponteiros precisam formar uma cadeia válida, sem perder nós.

## Ver também

- [[nivel-5-structs]] — `struct`, ponteiros e passagem por referência
- [[nivel-4-vetores-matrizes]] — base das implementações com arranjo
- [[nivel-3-funcoes]] — funções e parâmetros por ponteiro
- [[referencia-sintaxe-c]] — consulta rápida da linguagem C
