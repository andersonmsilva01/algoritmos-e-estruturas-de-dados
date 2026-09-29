---
titulo: Nível 5 — Structs (Registros)
categoria: conceito
tags: [structs, registros, estruturas, typedef, ponteiros, avancado]
fontes: [aula_struct.pdf, lista6_struct.pdf]
atualizado: 2026-06-28
---

# Nível 5 — Structs (Registros)

Até o [[nivel-4-vetores-matrizes|Nível 4]] você agrupou **vários valores do mesmo tipo** (vetores e matrizes — estruturas **homogêneas**). Agora você aprende a agrupar **valores de tipos diferentes** que descrevem **uma mesma coisa**: o registro (`struct`) — uma estrutura **heterogênea**.

---

## 1. O que é um registro (struct)

### Explicação simples

Pense numa **ficha de cadastro** de um aluno. Ela tem um nome (texto), uma matrícula (número), uma nota (número com vírgula), um sexo (uma letra). São informações de **tipos diferentes**, mas todas pertencem ao **mesmo aluno**.

Um `struct` é exatamente isso: uma "ficha" que junta vários **campos** (cada um com seu nome e seu tipo) numa única variável. Em vez de carregar 4 variáveis soltas, você carrega **um aluno inteiro**.

### Explicação técnica

Um registro é uma coleção de dados que podem ser de **tipos diferentes**, agrupados sob um único nome. Cada dado é um **campo** (field/membro), identificado por um **nome** — não por um índice como no vetor.

| | Vetor / Matriz | Registro (struct) |
|---|---|---|
| Tipos dos elementos | Todos **iguais** (homogêneo) | Podem ser **diferentes** (heterogêneo) |
| Como acessa | Por **índice** — `v[i]` | Por **nome** do campo — `aluno.nota` |

> Cada campo pode ser de **qualquer tipo** (int, float, char, vetor, outra struct...). A única restrição clássica é que uma struct **não pode conter uma instância de si mesma** — só um **ponteiro** para si mesma (veja a seção 6).

---

## 2. As três formas de declarar uma struct

Todas criam o mesmo tipo. A diferença é só de sintaxe/conveniência.

### Forma A — com `typedef` (a mais usada e recomendada)

`typedef` dá um **nome novo** ao tipo, e aí você declara variáveis sem repetir a palavra `struct`:

```c
typedef struct {
    char nome[30];
    int  matricula;
    float nota;
} Aluno;          // "Aluno" é o nome do TIPO, não de uma variável

Aluno a1, a2;     // declara duas variáveis do tipo Aluno
```

> Convenção do material da disciplina: declarar o tipo **no início do programa, fora de todas as funções** (escopo global), para que todas as funções enxerguem o tipo.

### Forma B — struct com nome ("tag"), sem typedef

```c
struct Aluno {
    char nome[30];
    int  matricula;
    float nota;
};

struct Aluno a1;   // precisa repetir a palavra "struct"
```

### Forma C — struct anônima, declarando variáveis direto

```c
struct {
    char nome[30];
    int  matricula;
} a1, a2;          // cria SÓ a1 e a2; não há nome de tipo reutilizável
```

> Na prática, prefira a **Forma A (`typedef`)**: é a mais limpa para reutilizar o tipo em vetores e funções.

---

## 3. Acessando os campos — o operador `.`

A sintaxe é `nome_da_variável.nome_do_campo`:

```c
Aluno a;

// Atribuição
strcpy(a.nome, "Pedro Henrique");   // string: SEMPRE com strcpy, nunca a.nome = "..."
a.matricula = 1842655;
a.nota = 8.5;

// Leitura do usuário
scanf("%29[^\n]", a.nome);     // lê nome com espaços (ou "%s" para uma palavra)
scanf("%d", &a.matricula);     // & no campo, igual a qualquer variável
scanf("%c", &a.sexo);
scanf("%f", &a.nota);

// Uso e impressão
float bonus = 0.10 * a.nota;
printf("Aluno: %s — nota %.1f\n", a.nome, a.nota);
```

> **Armadilha de string:** campo `char nome[30]` é um **vetor**. Não dá para fazer `a.nome = "texto"` — isso é erro de compilação. Use `strcpy(a.nome, "texto")` (precisa de `#include <string.h>`).

---

## 4. Inicialização na declaração

```c
typedef struct { float re, im; } Complexo;
struct Fruta { char nome[10]; int caloria; };

Complexo z = {1.0, -0.5};                    // re=1.0, im=-0.5 (na ordem dos campos)
struct Fruta banana = {"banana", 100};
struct Fruta maca = {0};                     // truque: zera todos os campos

// Vetor/matriz de structs também:
Complexo grade[2][2] = {
    {{1.0, -0.1}, {2.0, 0.2}},
    {{4.0, -0.4}, {5.0, 0.5}}
};
```

---

## 5. Vetor de registros

Quando você precisa de **várias fichas** (vários alunos, vários funcionários), use um **vetor de structs**. É o caso mais comum nas listas.

### Explicação simples

É uma **gaveta de fichas**: cada posição do vetor é uma ficha inteira. `turma[0]` é o primeiro aluno completo; `turma[0].nota` é a nota desse aluno.

```c
typedef struct {
    char nome[30];
    float nota;
} Aluno;

Aluno turma[42];          // 42 alunos

for (int i = 0; i < 5; i++) {
    printf("Nome do aluno %d: ", i + 1);
    scanf("%29s", turma[i].nome);          // campo do i-ésimo aluno
    printf("Nota: ");
    scanf("%f", &turma[i].nota);
}

// Encontrar o aluno de maior nota
int idxMaior = 0;
for (int i = 1; i < 5; i++)
    if (turma[i].nota > turma[idxMaior].nota)
        idxMaior = i;
printf("Maior nota: %s (%.1f)\n", turma[idxMaior].nome, turma[idxMaior].nota);
```

> Note a sintaxe combinada: **primeiro o índice, depois o campo** → `turma[i].nota`.

---

## 6. Struct dentro de struct (aninhamento)

Um campo pode ser **outra struct**. Útil para compor coisas como Data dentro de Funcionário.

```c
typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[20];
    Data nasc;          // uma struct como campo
    Data contrato;
    float salario;
} Funcionario;

Funcionario f;
f.nasc.dia = 1;         // encadeia os pontos: f -> nasc -> dia
f.nasc.mes = 12;
f.nasc.ano = 1980;
```

> **Recursão só com ponteiro:** uma struct não pode conter **uma instância de si mesma**, mas pode conter um **ponteiro** para si mesma. Isso é a base de listas encadeadas (assunto futuro).
> ```c
> struct No {
>     int valor;
>     struct No prox;    // ERRO! tamanho infinito
>     struct No *prox;   // OK! ponteiro tem tamanho fixo
> };
> ```

---

## 7. Structs e funções

### Passagem por valor (a função recebe uma cópia)

Por padrão, structs são passadas **por valor**: a função trabalha numa **cópia**, e alterações **não afetam** o original.

```c
void imprimir(Aluno a) {        // recebe cópia
    printf("%s — %.1f\n", a.nome, a.nota);
}                                // alterações aqui dentro NÃO mudam o original
```

### Passagem por referência (com ponteiro `*` e operador `->`)

Para **alterar** o original (ou evitar copiar uma struct grande), passe um **ponteiro**. Com ponteiro, acessa-se o campo com `->` em vez de `.`:

```c
void ler(Aluno *a) {                 // recebe endereço
    scanf("%29s", a->nome);          // a->nome  equivale a  (*a).nome
    scanf("%f", &a->nota);
}

int main(void) {
    Aluno x;
    ler(&x);                          // passa o endereço de x
    return 0;
}
```

| Situação | Operador |
|----------|----------|
| Variável struct (`Aluno a`) | `a.campo` |
| Ponteiro para struct (`Aluno *p`) | `p->campo` (ou `(*p).campo`) |

> **Retorno de struct:** uma função também pode **retornar** uma struct inteira por valor:
> ```c
> Complexo soma(Complexo a, Complexo b) {
>     Complexo c;
>     c.re = a.re + b.re;
>     c.im = a.im + b.im;
>     return c;
> }
> ```

---

## 8. Exemplo completo — cadastro de funcionários

Junta tudo: typedef, struct aninhada, vetor de structs e funções.

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char rua[30];
    int  numero;
} Endereco;

typedef struct {
    char nome[30];
    int  idade;
    float salario;
    Endereco end;        // struct dentro de struct
} Funcionario;

// Retorna o funcionário de maior salário
Funcionario maiorSalario(Funcionario v[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (v[i].salario > v[idx].salario)
            idx = i;
    return v[idx];
}

float mediaSalarial(Funcionario v[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += v[i].salario;
    return soma / n;
}

int main(void) {
    Funcionario equipe[3];
    int n = 3;

    for (int i = 0; i < n; i++) {
        printf("Nome: ");    scanf("%29s", equipe[i].nome);
        printf("Idade: ");   scanf("%d", &equipe[i].idade);
        printf("Salário: "); scanf("%f", &equipe[i].salario);
        printf("Rua: ");     scanf("%29s", equipe[i].end.rua);
        printf("Número: ");  scanf("%d", &equipe[i].end.numero);
    }

    Funcionario top = maiorSalario(equipe, n);
    printf("\nMaior salário: %s (R$ %.2f)\n", top.nome, top.salario);
    printf("Média salarial: R$ %.2f\n", mediaSalarial(equipe, n));
    return 0;
}
```

---

## 9. Exercícios resolvidos (Lista 6)

### Básico 5 — Produto (struct com múltiplos tipos)

```c
#include <stdio.h>

typedef struct {
    int id;
    int quantidade;
    float preco;
} Produto;

int main(void) {
    Produto p;
    printf("ID: ");         scanf("%d", &p.id);
    printf("Quantidade: "); scanf("%d", &p.quantidade);
    printf("Preço: ");      scanf("%f", &p.preco);

    printf("Valor total: %.2f\n", p.quantidade * p.preco);
    return 0;
}
```

### Básico 6 — Vetor de struct (média das notas)

```c
#include <stdio.h>

typedef struct {
    int matricula;
    float nota;
} Aluno;

int main(void) {
    Aluno turma[5];
    float soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Matrícula do aluno %d: ", i + 1);
        scanf("%d", &turma[i].matricula);
        printf("Nota: ");
        scanf("%f", &turma[i].nota);
        soma += turma[i].nota;
    }

    printf("Média da turma: %.2f\n", soma / 5);
    return 0;
}
```

### Básico 9 — Data válida

```c
#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

int main(void) {
    Data d;
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    int diasNoMes = 31;
    if (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11)
        diasNoMes = 30;
    else if (d.mes == 2) {
        int bissexto = (d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0);
        diasNoMes = bissexto ? 29 : 28;
    }

    int valida = (d.mes >= 1 && d.mes <= 12) &&
                 (d.dia >= 1 && d.dia <= diasNoMes);

    printf(valida ? "Data válida\n" : "Data inválida\n");
    return 0;
}
```

---

## Armadilhas comuns

| Armadilha | O que acontece | Como evitar |
|-----------|---------------|-------------|
| `a.nome = "texto"` | Erro: não se atribui a vetor | `strcpy(a.nome, "texto")` (`<string.h>`) |
| Usar `.` em ponteiro | Erro de compilação | Ponteiro usa `->` (ou `(*p).campo`) |
| Esquecer `&` ao ler campo escalar | `scanf` falha/segfault | `scanf("%d", &a.matricula)` |
| Pôr `&` ao ler campo string | `%s` já é endereço | `scanf("%s", a.nome)` sem `&` |
| Esperar que função `por valor` altere a struct | Só mexe na cópia | Passe **ponteiro** (`Aluno *`) |
| `struct No prox;` dentro da própria struct | Tamanho infinito (erro) | Use **ponteiro**: `struct No *prox;` |
| Ordem errada na inicialização `{...}` | Campos trocados | Siga a **ordem de declaração** dos campos |
| Índice e campo invertidos | `turma.nota[i]` está errado | É `turma[i].nota` (índice primeiro) |

---

## Ver também

- [[nivel-4-vetores-matrizes]] — pré-requisito (vetores, strings, matrizes)
- [[nivel-3-funcoes]] — passagem por valor vs. referência, ponteiros
- [[referencia-sintaxe-c]] — seções D.17 (estruturas), D.18 (uniões), D.19 (campos de bits)
- [[../analises/roteiro-estudo-listas-ifmg]] — roteiro completo
