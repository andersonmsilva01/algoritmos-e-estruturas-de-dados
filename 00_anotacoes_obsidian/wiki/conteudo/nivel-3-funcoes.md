---
titulo: Nível 3 — Funções e Ponteiros
categoria: conceito
tags: [funcoes, ponteiros, recursao, parametros, intermediario, avancado]
fontes: [Functions - cppreference.com.md, Declarations - cppreference.com.md]
atualizado: 2026-05-27
---

# Nível 3 — Funções e Ponteiros

Aqui você aprende a **organizar** o código em blocos reutilizáveis. Funções deixam o programa mais limpo, mais fácil de testar e evitam repetir lógica.

E, junto delas, ponteiros — o conceito mais "diferente" de C, mas com explicação simples se você for com calma.

---

## 1. O que é uma função

### Explicação simples

Uma **função** é uma "mini-receita" com nome próprio que você pode chamar quantas vezes quiser. Pense em uma máquina de café:
- Você joga **entrada** (água, pó)
- A máquina faz o processo
- Devolve **saída** (café)

Em C é igual: a função recebe **parâmetros**, faz algo, e (opcionalmente) **retorna** um valor.

### Explicação técnica

Funções em C **não podem ser aninhadas** (não dá para declarar função dentro de função, salvo o `main`). Cada função tem:
- **Tipo de retorno** (incluindo `void` para "não retorna nada")
- **Nome (identificador único)**
- **Lista de parâmetros** entre parênteses
- **Corpo** entre chaves

Uma função deve ser **declarada** antes de ser usada. Você pode declarar primeiro o **protótipo** (assinatura) no topo e definir depois.

### Anatomia

```c
#include <stdio.h>

// PROTÓTIPO — informa ao compilador que essa função existe
int somar(int a, int b);

int main(void) {
    int resultado = somar(3, 4);   // CHAMADA
    printf("%d\n", resultado);     // imprime 7
    return 0;
}

// DEFINIÇÃO — implementação completa
int somar(int a, int b) {
    return a + b;
}
```

### Tipos de função

| Retorno | Parâmetros | Exemplo de assinatura |
|---------|-----------|----------------------|
| `void` | nenhum | `void saudacao(void)` |
| `void` | sim | `void exibirTabuada(int n)` |
| `int`/`float`/... | sim | `int somar(int a, int b)` |
| `int`/`float`/... | nenhum | `int idadeAtual(void)` |

---

## 2. Passagem por valor

### Explicação simples

Quando você passa uma variável para uma função, C faz uma **cópia**. A função mexe na cópia, e a variável original **não muda** lá fora.

É como dar uma fotocópia de um documento para alguém: a pessoa pode rabiscar a cópia, mas o original na sua mão fica intacto.

### Código de exemplo

```c
#include <stdio.h>

void dobrar(int n) {        // recebe CÓPIA
    n = n * 2;              // só altera a cópia local
    printf("Dentro: %d\n", n);
}

int main(void) {
    int x = 5;
    dobrar(x);              // passa cópia de x
    printf("Fora: %d\n", x); // ainda é 5
    return 0;
}
// Saída:
// Dentro: 10
// Fora: 5
```

---

## 3. Ponteiros — o mínimo essencial

### Explicação simples

Imagine que cada variável **mora em uma casa** com um **endereço**. Normalmente você lida com a casa pelo nome ("a casa do João"). Mas às vezes você precisa do **endereço** dela ("Rua X, número 42") para mandar correspondência.

Um **ponteiro** é uma variável que guarda **um endereço de memória**, não um valor comum.

- `&x` → "**endereço** da variável x" (operador "endereço de")
- `*p` → "**valor** que está no endereço guardado em p" (operador "dereferenciar")

### Explicação técnica

Em C, todo objeto tem um endereço na memória. Um ponteiro é uma variável tipada que armazena esse endereço. O **tipo** do ponteiro determina como o byte da memória é interpretado e quantos bytes são lidos a partir desse endereço.

```c
int x = 10;        // x é um int comum, valor 10
int *p = &x;       // p é ponteiro para int, guarda o endereço de x

printf("%d\n", x);   // 10  (valor de x)
printf("%p\n", &x);  // 0x7ffeefb... (endereço de x)
printf("%p\n", p);   // 0x7ffeefb... (mesmo endereço)
printf("%d\n", *p);  // 10  (dereferencia: vai no endereço e pega o valor)

*p = 99;             // altera o valor NA MEMÓRIA → x agora é 99
printf("%d\n", x);   // 99
```

### Tabela rápida

| Notação | Significado |
|---------|-------------|
| `int *p` | declaração: `p` é ponteiro para `int` |
| `&x` | endereço da variável `x` |
| `*p` | valor armazenado no endereço `p` (dereferenciar) |
| `p = &x` | `p` passa a apontar para `x` |
| `*p = 5` | escreve `5` no endereço que `p` aponta (altera `x`!) |

> O `*` na declaração e o `*` no uso são coisas diferentes:
> - **Declaração:** `int *p;` → "p é do tipo ponteiro-para-int"
> - **Uso:** `*p = 10;` → "no endereço apontado por p, escreva 10"

---

## 4. Passagem por referência

### Explicação simples

Para que uma função realmente **altere** a variável original, você passa o **endereço** dela (`&variavel`) em vez do valor. Dentro da função, você acessa a variável original via `*ponteiro`.

É como dar a chave da sua casa em vez de uma fotocópia: agora a pessoa pode entrar e mexer de verdade.

### Código de exemplo

```c
#include <stdio.h>

void dobrar(int *n) {       // recebe endereço (ponteiro)
    *n = *n * 2;            // altera o valor NA MEMÓRIA ORIGINAL
}

int main(void) {
    int x = 5;
    dobrar(&x);             // passa o endereço de x
    printf("x agora é: %d\n", x);  // 10 — alterou de verdade!
    return 0;
}
```

### Swap clássico (troca de valores)

```c
void trocar(int *a, int *b) {
    int temp = *a;          // guarda o valor original de a
    *a = *b;                // a recebe o valor de b
    *b = temp;              // b recebe o valor antigo de a
}

int main(void) {
    int x = 10, y = 20;
    trocar(&x, &y);
    printf("x=%d, y=%d\n", x, y);  // x=20, y=10
    return 0;
}
```

---

## 5. Múltiplos "retornos" via ponteiros

Como uma função só pode retornar **um único valor**, usamos ponteiros quando precisamos devolver mais de um resultado.

### Código de exemplo

```c
#include <stdio.h>

void maxMin(int a, int b, int c, int d, int *max, int *min) {
    *max = a; *min = a;

    if (b > *max) *max = b;
    if (c > *max) *max = c;
    if (d > *max) *max = d;

    if (b < *min) *min = b;
    if (c < *min) *min = c;
    if (d < *min) *min = d;
}

int main(void) {
    int maior, menor;
    maxMin(7, 3, 9, 1, &maior, &menor);
    printf("Maior: %d, Menor: %d\n", maior, menor);  // 9, 1
    return 0;
}
```

---

## 6. Recursão — uma função que chama a si mesma

### Explicação simples

Recursão é quando uma função **chama ela mesma** com um problema menor, até chegar em um caso simples que ela sabe responder direto. É como uma boneca russa: cada uma contém uma menor, até a menor de todas.

**Toda recursão precisa de um caso base** (a parada), senão chama para sempre e estoura a memória.

### Código de exemplo — Fatorial

```c
int fatorial(int n) {
    if (n <= 1) return 1;            // CASO BASE — sem isso, infinito
    return n * fatorial(n - 1);      // CHAMADA RECURSIVA
}

// fatorial(4) → 4 * fatorial(3)
//             → 4 * (3 * fatorial(2))
//             → 4 * (3 * (2 * fatorial(1)))
//             → 4 * 3 * 2 * 1 = 24
```

### Quando usar?

- Problemas naturalmente recursivos (árvores, fractais, busca em grafos)
- Algoritmos como **MDC de Euclides**, **busca binária**, **torres de Hanói**

Para tarefas simples, um laço `for`/`while` é mais rápido e usa menos memória.

---

## Exercícios resolvidos

### Lista 4, ex. 14 — Verificar número primo

```c
#include <stdio.h>

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);

    if (ehPrimo(n)) printf("%d é primo\n", n);
    else            printf("%d não é primo\n", n);
    return 0;
}
```

### Lista 4, ex. 23 — MDC (Algoritmo de Euclides)

```c
#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    int a, b;
    printf("Dois números: ");
    scanf("%d %d", &a, &b);
    printf("MDC = %d\n", mdc(a, b));
    return 0;
}
```

### Lista 4, ex. 24 — Mini Calculadora com `switch`

```c
#include <stdio.h>

float calcular(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            printf("Erro: divisão por zero\n");
            return 0;
        default:
            printf("Operador inválido\n");
            return 0;
    }
}

int main(void) {
    float a, b;
    char op;
    printf("Expressão (ex: 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);
    printf("Resultado: %.2f\n", calcular(a, b, op));
    return 0;
}
```

### Lista 4, ex. 25 — Conta Bancária com ponteiros

```c
#include <stdio.h>

void depositar(float *saldo, float valor) {
    if (valor > 0) {
        *saldo += valor;
        printf("Depositado R$ %.2f. Saldo: R$ %.2f\n", valor, *saldo);
    } else {
        printf("Valor inválido para depósito\n");
    }
}

void sacar(float *saldo, float valor) {
    if (valor > 0 && valor <= *saldo) {
        *saldo -= valor;
        printf("Sacado R$ %.2f. Saldo: R$ %.2f\n", valor, *saldo);
    } else {
        printf("Saldo insuficiente ou valor inválido\n");
    }
}

int main(void) {
    float saldo = 500.00;
    printf("Saldo inicial: R$ %.2f\n", saldo);

    depositar(&saldo, 200.00);     // ok
    sacar(&saldo, 100.00);         // ok
    sacar(&saldo, 9999.00);        // insuficiente

    return 0;
}
```

---

## Escopo de variáveis

### Explicação simples

Uma variável só **existe** dentro do bloco `{ ... }` onde foi declarada. Fora dele, "não existe". Por isso uma variável local de uma função **não é visível** em outra função.

### Tipos de escopo

| Onde declarada | Escopo |
|---------------|--------|
| Dentro de função | **Local** — só naquela função |
| Dentro de `{ }` (bloco) | **Bloco** — só ali |
| Fora de toda função | **Global** — visível em todo o arquivo (evite!) |
| Parâmetro da função | **Local** ao corpo da função |

```c
int contador = 0;   // global — qualquer função vê

void incrementar(void) {
    contador++;     // ok, vê a global
    int local = 1;  // só existe aqui
}
```

---

## Armadilhas comuns

| Armadilha | O que acontece | Como evitar |
|-----------|---------------|-------------|
| Esquecer protótipo | Warning ou erro | Declare protótipo no topo do arquivo |
| Recursão sem caso base | Stack overflow | Sempre tenha `if` que retorna sem recursar |
| Passar valor onde queria referência | Original não muda | Use `&` na chamada e `*` na função |
| Dereferenciar ponteiro `NULL` ou inválido | Segfault | Inicialize ponteiros; valide antes de `*p` |
| Retornar endereço de variável local | UB — variável morre ao sair | Não faça `return &local;` |
| Confundir `*p` com `p` | Bugs sutis | `p` é endereço; `*p` é o valor lá |
| Misturar `void` com retorno | Erro de compilação | Função `void` não pode `return valor;` |

---

## Ver também

- [[nivel-2-repeticao]] — pré-requisito
- [[nivel-4-vetores-matrizes]] — próximo: estrutura de dados
- [[../analises/roteiro-estudo-listas-ifmg]]
