---
titulo: Nível 2 — Estruturas de Repetição
categoria: conceito
tags: [loops, for, while, do-while, repeticao, intermediario]
fontes: [Statements - cppreference.com.md]
atualizado: 2026-07-01
---

# Nível 2 — Estruturas de Repetição (Laços)

Aqui você ensina o programa a **repetir tarefas**. Em vez de copiar e colar a mesma instrução 100 vezes, você escreve uma vez dentro de um laço e diz "faça isso N vezes".

---

## 1. `for` — quando você sabe quantas vezes vai repetir

###
### Explicação técnica

`for` é a forma mais compacta de laço quando você tem três coisas claras:
1. **Inicialização** — executada uma vez, antes de tudo
2. **Condição** — testada antes de cada iteração; se falsa, sai do laço
3. **Atualização** — executada ao final de cada iteração

### Sintaxe

```c
for (inicialização; condição; atualização) {
    // corpo do laço
}
```

Equivale a:
```c
inicialização;
while (condição) {
    // corpo
    atualização;
}
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    // Imprime números de 1 a 10
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    // Contagem regressiva de 10 a 1
    for (int i = 10; i >= 1; i--) {
        printf("%d\n", i);
    }

    // Pulando de 2 em 2
    for (int i = 0; i <= 20; i += 2) {
        printf("%d ", i);   // 0 2 4 6 8 10 12 14 16 18 20
    }
    printf("\n");

    return 0;
}
```

> **Atenção:** `int i = 1` dentro do `for` é C99+. Em C89, você precisava declarar `int i;` antes.

---

## 2. `while` — repetir enquanto uma condição for verdadeira

### Explicação simples

Use o `while` quando você **não sabe** exatamente quantas vezes vai repetir, mas sabe a **condição de parada**.

Exemplo: "fique servindo café **enquanto** a xícara não estiver cheia". Você não sabe quantas vezes vai despejar, depende do tamanho da xícara.

### Explicação técnica

`while` avalia a condição **antes** de cada iteração. Se ela for falsa logo no início, o corpo nunca executa. Use quando a parada depende de:
- Entrada do usuário (`while (n != 0)`)
- Resultado de um cálculo
- Estado mutável (leitura de arquivo, etc.)

### Sintaxe

```c
while (condição) {
    // executado enquanto a condição for verdadeira
}
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int n = 1234;

    // Conta quantos dígitos tem o número
    int digitos = 0;
    while (n > 0) {
        n = n / 10;
        digitos++;
    }
    printf("Tinha %d dígitos\n", digitos);  // 4

    // Leitura até o usuário digitar 0
    int valor;
    int soma = 0;
    printf("Digite números (0 para parar):\n");
    scanf("%d", &valor);
    while (valor != 0) {
        soma += valor;
        scanf("%d", &valor);
    }
    printf("Soma: %d\n", soma);

    return 0;
}
```

---

## 3. `do-while` — executa **pelo menos uma vez**

### Explicação simples

Igual ao `while`, mas a condição é testada **no fim**, não no começo. Ou seja, o código **roda pelo menos uma vez**, e só depois decide se vai repetir.

Uso típico: **menus** ("mostre o menu, leia a opção, depois decida se mostra de novo").

### Explicação técnica

`do-while` é a única forma onde o corpo executa **antes** da primeira avaliação da condição. Atenção: o `;` no final é obrigatório (diferente de `for` e `while`).

### Sintaxe

```c
do {
    // corpo (sempre roda pelo menos 1 vez)
} while (condição);   // ATENÇÃO ao ponto e vírgula
```

### Código de exemplo

```c
#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) printf("Cadastrando...\n");
        if (opcao == 2) printf("Consultando...\n");

    } while (opcao != 0);

    printf("Saindo.\n");
    return 0;
}
```

---

## 4. `break` e `continue`

### Explicação simples

- `break` → **sai** do laço imediatamente
- `continue` → **pula** o resto da iteração atual e vai para a próxima

### Código de exemplo

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) break;       // ao chegar em 5, sai do for
    if (i % 2 == 0) continue; // se for par, pula direto pro próximo i
    printf("%d\n", i);       // imprime: 1, 3
}
```

---

## 5. Padrões fundamentais de laço

Estes são os "moldes" que aparecem em **quase todo** exercício com laços. 
Todos seguem a mesma ideia: 
 - uma variável **guardada fora do laço** 
 - vai sendo atualizada **a cada volta**. 

---

### 5.1 Acumulador (soma / produto)

#### Explicação simples

A cada produto que passa, você **soma o preço dele ao total** que já tinha.

- O total começa em zero e vai **engordando** a cada item. No fim, ele guarda a conta inteira.

- O acumulador é isso: uma variável (o "total") que **acumula** um pouquinho a cada volta do laço.

#### Explicação técnica

- Você declara a variável acumuladora **antes** do laço, com um **valor neutro**
- Dentro do laço aplica a operação sobre ela mesma 
- (`soma += x` é o mesmo que `soma = soma + x`).

**O valor inicial depende da operação:**
 - **somar** começa em **0** (somar 0 não muda nada) 
 - **multiplicar** começa em **1** (multiplicar por 1 não muda nada), se começar em 0, o resultado é sempre 0 — erro clássico.

```c
// Soma de N números lidos
int n, x, soma = 0;              // neutro da soma = 0
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    soma += x;                   // soma = soma + x
}
printf("Total: %d\n", soma);

// Produto (ex.: fatorial de N) — neutro do produto = 1
long long produto = 1;
for (int i = 2; i <= n; i++) {
    produto *= i;                // produto = produto * i
}
```

---

### 5.2 Contador

#### Explicação simples

Imagine que você está numa **portaria contando quantas pessoas de camisa vermelha entram**. Todo mundo passa, mas você só **aperta o contador (+1)** quando vê uma camisa vermelha. As outras pessoas passam sem mexer no número.

O contador conta **quantas vezes** uma condição aconteceu — não soma valores, só conta ocorrências.

#### Explicação técnica

É um acumulador especial que **sempre soma 1**, mas **apenas quando um `if` é verdadeiro**. Começa em 0. A diferença para o acumulador é que ele ignora o valor em si — só interessa se a condição bateu ou não.

```c
// Quantos números lidos são positivos?
int n, x, positivos = 0;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x > 0) positivos++;      // só conta quando a condição é verdadeira
}
printf("Positivos: %d\n", positivos);
```

> **Soma vs. contagem:** `soma += x` responde *"qual o total?"*; `contador++` responde *"quantos?"*. Preste atenção ao que o enunciado pede.

---

### 5.3 Máximo ou mínimo

#### Explicação simples

Imagine que você quer saber **quem é a pessoa mais alta de uma fila**. Você olha a primeira e pensa: *"por enquanto, ela é a mais alta que eu vi"*. Aí compara com a próxima: se for **mais alta**, ela vira a nova "campeã". Segue assim até o fim da fila — no final, você tem a mais alta de todas.

#### Explicação técnica

Você guarda um **"campeão atual"** e o inicializa com o **primeiro valor** (nunca com 0 — se todos os números forem negativos, um `max` iniciado em 0 daria resposta errada). A cada novo valor, compara: se for maior (ou menor, para mínimo), ele **assume o posto**.

```c
// Maior de N números
int n, x, maior;
scanf("%d", &n);
scanf("%d", &maior);             // 1º valor é o campeão inicial
for (int i = 1; i < n; i++) {    // começa do 2º (i = 1)
    scanf("%d", &x);
    if (x > maior) maior = x;    // achou alguém maior -> troca o campeão
}
printf("Maior: %d\n", maior);
```

> Para o **mínimo**, é idêntico trocando `>` por `<`. Para achar os dois de uma vez, mantenha `maior` e `menor`, ambos iniciados com o primeiro valor.

---

### 5.4 Extração de dígitos (`% 10` e `/ 10`)

#### Explicação simples

Pense num número como uma **pilha de fichas empilhadas**, uma por dígito. Você quer tirar uma ficha de cada vez, **de trás pra frente** (do último dígito para o primeiro):
- **`% 10`** te dá o **último dígito** (o de cima da pilha): `1234 % 10 = 4`.
- **`/ 10`** (divisão inteira) **joga fora** esse último dígito: `1234 / 10 = 123`.

Repetindo isso, você "descasca" o número dígito por dígito até não sobrar nada (chegar a 0).

#### Explicação técnica

`% 10` (resto da divisão por 10) isola a **unidade**; `/ 10` (divisão **inteira**) desloca o número uma casa para a direita, descartando a unidade. O laço `while (n > 0)` roda uma vez por dígito e para quando o número "acaba".

Cuidado: como o processo extrai os dígitos **na ordem inversa** (do último para o primeiro), para *inverter* um número basta ir remontando; para somar/contar dígitos a ordem não importa.

```c
int n = 1234;
int soma = 0, qtd = 0;
while (n > 0) {
    int digito = n % 10;         // pega o último: 4, 3, 2, 1
    soma += digito;              // soma dos dígitos
    qtd++;                       // conta os dígitos
    n = n / 10;                  // remove o último: 123, 12, 1, 0
}
printf("Qtd de dígitos: %d, soma: %d\n", qtd, soma);   // 4 e 10
```

> Esse padrão é a base de: contar dígitos, somar dígitos, inverter número e verificar palíndromo (inverte e compara com o original).

---

## 6. Laços aninhados

### Explicação simples

Um laço **dentro** de outro. O de fora controla as **linhas**, o de dentro controla as **colunas** (ou similar).

### Código de exemplo

```c
// Tabuada completa de 1 a 5
for (int n = 1; n <= 5; n++) {
    printf("--- Tabuada do %d ---\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

// Triângulo de asteriscos
int linhas = 5;
for (int i = 1; i <= linhas; i++) {
    for (int j = 1; j <= i; j++) {
        printf("* ");
    }
    printf("\n");
}
// Saída:
// *
// * *
// * * *
// * * * *
// * * * * *
```

---

## Exercícios resolvidos

### Lista 3, ex. 6 — Fatorial

```c
#include <stdio.h>

int main(void) {
    int n;
    long long fat = 1;  // long long suporta números grandes

    printf("Digite N: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        fat *= i;
    }

    printf("%d! = %lld\n", n, fat);
    return 0;
}
```

### Lista 3, ex. 7 — Fibonacci

```c
#include <stdio.h>

int main(void) {
    int termos;
    printf("Quantos termos: ");
    scanf("%d", &termos);

    int a = 0, b = 1;
    for (int i = 0; i < termos; i++) {
        printf("%d ", a);
        int c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
```

### Lista 3, ex. 11 — Número Primo

```c
#include <stdio.h>

int main(void) {
    int n;
    printf("Digite o número: ");
    scanf("%d", &n);

    int primo = 1;
    if (n < 2) {
        primo = 0;
    } else {
        for (int i = 2; i * i <= n; i++) {   // só até √n (otimização)
            if (n % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo) printf("%d é primo\n", n);
    else       printf("%d não é primo\n", n);
    return 0;
}
```

### Lista 3, ex. 20 — Palíndromo Numérico

```c
#include <stdio.h>

int main(void) {
    int n, original, invertido = 0;
    printf("Digite o número: ");
    scanf("%d", &n);
    original = n;

    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }

    if (original == invertido)
        printf("%d é palíndromo\n", original);
    else
        printf("%d não é palíndromo\n", original);
    return 0;
}
```

### Lista 3, ex. 17 — Adivinhe o número

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));            // inicia gerador com hora atual
    int secreto = rand() % 100 + 1;  // 1 a 100
    int palpite;
    int tentativas = 0;

    do {
        printf("Palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite > secreto)      printf("Menor\n");
        else if (palpite < secreto) printf("Maior\n");

    } while (palpite != secreto);

    printf("Acertou em %d tentativas!\n", tentativas);
    return 0;
}
```

---

## Qual laço usar?

| Situação | Laço recomendado |
|----------|------------------|
| Sei exatamente quantas iterações (1 a 100) | `for` |
| Parada depende de uma condição que pode nunca virar verdadeira | `while` |
| Precisa rodar pelo menos uma vez (menu, validação de entrada) | `do-while` |
| Iterar sobre vetor com tamanho conhecido | `for` |
| Ler até um valor sentinela (`-1`, `0`) | `while` ou `do-while` |

---

## Armadilhas comuns

| Armadilha | O que acontece | Como evitar |
|-----------|---------------|-------------|
| Loop infinito | Condição nunca vira falsa | Garanta que algo dentro do laço mude a condição |
| Off-by-one | Iterar de mais ou de menos | `<` vai até `n-1`; `<=` vai até `n` |
| `;` solto no for | `for (i=0; i<10; i++);` — corpo vazio! | Não coloque `;` antes de `{` |
| `do-while` sem `;` | Erro de compilação | `} while (cond);` — o `;` é obrigatório |
| Modificar contador dentro do for | Comportamento confuso | Não altere `i` dentro do corpo |
| Overflow em fatorial/potência | Resultado errado silencioso | Use `long long` quando suspeitar |

---

## Ver também

- [[nivel-1-condicionais]] — pré-requisito
- [[nivel-3-funcoes]] — próximo: dividir o código em funções
- [[../analises/roteiro-estudo-listas-ifmg]]
