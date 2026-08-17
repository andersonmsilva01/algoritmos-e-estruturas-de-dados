# Log da Wiki

## [2026-07-01] query | Lista de exercícios para prova de recuperação

Criada `wiki/analises/simulado-recuperacao.md`: lista de prática cumulativa (Níveis 0–5) para a prova de recuperação (100 pts), organizada por tema em ordem crescente + simulado cronometrado de 6 questões + checklist de armadilhas.

## [2026-06-28] ingest | aula_struct.pdf + lista6_struct.pdf + lista5_extra.jpeg + web_sintaxe_c.pdf

Ingeridas as 4 fontes novas adicionadas a `raw/`:
- `ifmg/aula_struct.pdf` (36 slides) + `ifmg/lista6_struct.pdf` (Lista 6) → criada `wiki/conteudo/nivel-5-structs.md` (didática completa: 3 formas de declarar, acesso por campo, vetor de registros, struct aninhada, structs e funções com `->`, exemplos e exercícios resolvidos da Lista 6).
- `doc_auxiliares/web_sintaxe_c.pdf` (Apêndice D — Manual de Sintaxe ANSI C) → criada `wiki/conteudo/referencia-sintaxe-c.md` (cheat-sheet de toda a sintaxe + seção de erratas: `int` 16-bit, `\h`, `#erro`, vírgula decimal, etc.).
- `ifmg/lista5_extra.jpeg` (3 exercícios extras de vetores) → adicionado ex. resolvido (maior + posição em Q de 20 positivos) a `nivel-4-vetores-matrizes.md`.
- Atualizados: `index.md` (nova seção "Material da Disciplina (IFMG) e Auxiliar" + tabela de conteúdo), `analises/roteiro-estudo-listas-ifmg.md` (Lista 6 / Nível 5 + checklist), frontmatter de `nivel-4`.

## [2026-05-27] conteudo | Material didático por nível (5 arquivos)

Criada pasta `wiki/conteudo/` com explicações simples + técnicas + código de exemplo para cada nível do roteiro:
- `nivel-0-fundamentos.md` — programa C básico, tipos, printf/scanf, operadores
- `nivel-1-condicionais.md` — if/else, switch, lógicos, ternário
- `nivel-2-repeticao.md` — for/while/do-while, break/continue, padrões clássicos (acumulador, contador, max/min, dígitos, fatorial, Fibonacci, primo, palíndromo)
- `nivel-3-funcoes.md` — funções, valor vs referência, ponteiros, recursão, swap, MDC
- `nivel-4-vetores-matrizes.md` — arrays, strings, matrizes 2D, Bubble Sort, diagonais, transposta, multiplicação, vetores em funções

Cada arquivo segue o padrão: Explicação simples (analogia) → Explicação técnica → Sintaxe/Tabela → Código → Exercícios resolvidos das listas IFMG → Armadilhas. Index atualizado.

## [2026-05-27] análise | Roteiro de estudo — Listas IFMG (5 listas)

Lidas e analisadas as 5 listas de exercícios do IFMG: algoritmos básicos (11 ex.), condicionais (15 ex.), repetição (20 ex.), funções (25 ex.), vetores e matrizes (30 ex.). Criada a página `wiki/analises/roteiro-estudo-listas-ifmg.md` com todos os tópicos necessários organizados em 4 níveis de dependência: fundamentos → condicionais → repetição → funções → vetores/matrizes. Inclui código de referência, tabela de armadilhas comuns e checklist de estudo por lista.

## [2026-05-26] ingest | ISO:IEC9899:2011.pdf (padrão C11 oficial, 701 páginas)

Lido e indexado o padrão oficial C11 (draft N1570). Resumo completo adicionado ao index.md: estrutura por cláusula (1–7.31), todos os headers com descrição, Anexos A–L. Destacadas as novidades do C11 vs C99: atomics, threads, Unicode (uchar.h), _Alignas/_Alignof, _Generic, _Noreturn, _Static_assert, anonymous structs/unions.

## [2026-05-26] ingest | doc_c_oficial (35 arquivos do cppreference.com)

Lidas e indexadas todas as 35 fontes da pasta `raw/doc_c_oficial/`. Cobertura: núcleo da linguagem (declarações, expressões, statements, funções, preprocessador, inicialização), tipos, I/O, strings, memória dinâmica, matemática, concorrência, algoritmos e especificações técnicas. Index atualizado com resumo de cada fonte.

## [2026-05-26] init | Wiki de Linguagem C criada

Estrutura inicial criada: diretórios `raw/`, `wiki/`, arquivos `index.md`, `log.md`, `CLAUDE.md`.
