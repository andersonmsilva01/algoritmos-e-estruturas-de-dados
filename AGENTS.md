# Regras para o assistente (AGENTS.md)

## Respostas em C

1. Não gerar respostas com código em C no chat do opencode,codex etc, a menos que o usuário peça explicitamente.
   - Exceção: tarefas de compilação/commit de arquivos `.c` de práticas (regras abaixo continuam valendo).

## Criação de pastas de exercícios

Quando o usuário pedir para criar uma pasta de exercícios dentro da pasta de uma lista:

1. Nomear a pasta no padrão `ia_NN_nome_do_tema`, usando dois dígitos para o número e palavras minúsculas separadas por `_`.
   - Exemplo: `ia_03_soma_dos_elementos`.
2. Criar três exercícios, organizados por dificuldade:
   - `ex1.c`: fácil;
   - `ex2.c`: intermediário;
   - `ex3.c`: difícil.

## Correção de exercícios

Quando o usuário pedir para corrigir ou revisar uma tentativa de exercício:

1. Preservar o código da tentativa do usuário; não substituí-lo por uma solução pronta, salvo quando isso for pedido explicitamente.
2. Acrescentar ao final do arquivo um comentário de bloco iniciado por `CORREÇÃO: CORRETO.`, `CORREÇÃO: PARCIALMENTE CORRETO.` ou `CORREÇÃO: INCORRETO.`.
3. Dentro do comentário, registrar os acertos, os erros encontrados, o motivo de cada erro e os ajustes necessários.
4. Iniciar cada apontamento somente com `N:` ou `N-M:`, usando os números das linhas da tentativa original a que o comentário se refere, sem escrever `Linha` ou `Linhas` e sem criar itens iniciados por hífen (`-`). Quando o apontamento se aplicar ao exercício inteiro e não a uma linha específica, iniciá-lo com `Geral:`.
5. Incluir, no mesmo comentário de correção ao final do arquivo, o código correto e completo do exercício, sem substituir a tentativa original do usuário.
6. Sinalizar explicitamente erros de compilação, acessos fora dos limites e casos de comportamento indefinido.
7. Escrever o código da correção de forma limpa, simples e adequada ao nível do exercício, evitando estruturas ou técnicas complexas quando não forem necessárias.

## Compilação de arquivos .c (`02_praticas`)

Toda vez que o usuário rodar o compilador C (`gcc`) em um arquivo de práticas:

1. **Comitar ANTES de compilar novamente** — isso garante que o número da tentativa no commit corresponda à realidade.
2. Comitar o arquivo `.c` com uma mensagem contendo o nome do arquivo e o número da tentativa de resolução.
   - Exemplo: tentativa 3 do `lista2_condicionais/ex7.c` → `feat(lista2_condicionais/ex7.c): tentativa 3`.
3. Manter o histórico de tentativas: verificar `git log` para descobrir qual é o número da próxima tentativa antes de commitar.
4. Na mensagem do commit, usar sempre o caminho relativo à pasta `02_praticas/` (ex.: `lista2_condicionais/ex9.c`), nunca o caminho completo (`02_praticas/lista2_condicionais/ex9.c`).

## Executáveis

1. Versionar os executáveis e artefatos de compilação gerados em `02_praticas` — incluindo binários sem extensão e diretórios `.dSYM` — para registrar quais exercícios já foram compilados.
2. Não adicionar esses artefatos ao `.gitignore`.
3. Depois de cada compilação, commitar o executável e seus artefatos em um commit separado do arquivo `.c`, usando a mensagem `build(caminho/do/arquivo.c): artefatos da tentativa N`.
4. Na mensagem do commit, usar o caminho relativo à pasta `02_praticas/` e o mesmo número da tentativa usado no commit do arquivo `.c` correspondente.
5. Os artefatos produzidos pela mesma compilação podem ficar no mesmo commit, mas nunca misturar artefatos de exercícios ou tentativas diferentes.

## Commits

1. Nunca incluir assinatura de IA nos commits (ex.: `Co-Authored-By`, `Generated with`, etc.).

# Projeto de Algoritmos e Estruturas de Dados em C — Arquitetura

## Estrutura de diretórios

```text
.
├── AGENTS.md                       ← regras, arquitetura e fluxo de trabalho do projeto
├── index.md                        ← índice geral dos conteúdos e das fontes
├── log.md                          ← registro cronológico de atividades
├── 00_material_aula_ifmg/
│   ├── atividades/                 ← listas de exercícios e atividades da disciplina
│   └── aulas/                      ← slides, exemplos e materiais apresentados em aula
├── 01_explicacao_da_ia/
│   ├── nivel-0-fundamentos.md
│   ├── nivel-1-condicionais.md
│   ├── nivel-2-repeticao.md
│   ├── nivel-3-funcoes.md
│   ├── nivel-4-vetores-matrizes.md
│   ├── nivel-5-structs.md
│   └── nivel-6-pilhas-filas-listas.md
├── 02_praticas/
│   ├── 0.rascunho.c                ← arquivo para testes rápidos
│   ├── 1.anotaçoes.txt             ← anotações gerais de prática
│   ├── 2.calculos.txt               ← cálculos auxiliares
│   ├── 3.ex_pendente.txt            ← controle de exercícios pendentes
│   ├── dúvidas.md                   ← dúvidas surgidas durante os exercícios
│   ├── lista1_basicos/
│   ├── lista2_condicionais/
│   ├── lista3_repeticao/
│   ├── lista4_funcoes/
│   ├── lista5_vetor_matriz/
│   ├── lista6_struct/
│   ├── lista7_fila/
│   └── lista8_pilha/
├── 03_material_extra/
│   ├── doc_auxiliares/             ← manuais e materiais complementares
│   └── doc_c_oficial/              ← referências da linguagem C e padrão ISO
└── .vscode/                         ← configurações locais de edição, compilação e depuração
```

## Responsabilidade de cada área

- `00_material_aula_ifmg/` contém as fontes fornecidas pela disciplina. Preserve os arquivos originais e organize novos itens entre `atividades/` e `aulas/`.
- `01_explicacao_da_ia/` contém o material didático sintetizado por nível de aprendizado. Atualize essas páginas quando uma fonte trouxer conhecimento relevante para o estudo.
- `02_praticas/` contém as resoluções, tentativas e anotações produzidas durante a prática. Cada lista possui uma pasta cujo nome indica o assunto principal.
- `03_material_extra/` contém fontes externas. Referências oficiais ou páginas do cppreference ficam em `doc_c_oficial/`; materiais auxiliares ficam em `doc_auxiliares/`.
- `index.md` é o ponto de entrada para localizar explicações, fontes e materiais.
- `log.md` registra ingestões de fontes, perguntas relevantes e revisões do conteúdo.
- As regras no início deste arquivo são obrigatórias para criação de exercícios, compilação, executáveis e commits.

## Relação entre níveis, materiais e práticas

| Nível | Explicação | Pasta de prática | Material principal |
|---|---|---|---|
| 0 | `nivel-0-fundamentos.md` | `lista1_basicos/` | Lista 1 |
| 1 | `nivel-1-condicionais.md` | `lista2_condicionais/` | Lista 2 |
| 2 | `nivel-2-repeticao.md` | `lista3_repeticao/` | Lista 3 |
| 3 | `nivel-3-funcoes.md` | `lista4_funcoes/` | Lista 4 |
| 4 | `nivel-4-vetores-matrizes.md` | `lista5_vetor_matriz/` | Lista 5 |
| 5 | `nivel-5-structs.md` | `lista6_struct/` | Lista 6 |
| 6 | `nivel-6-pilhas-filas-listas.md` | `lista7_fila/` e `lista8_pilha/` | Listas 7 e 8 |

Os nomes da coluna **Explicação** são relativos a `01_explicacao_da_ia/`; os da coluna **Pasta de prática** são relativos a `02_praticas/`; e os materiais da disciplina ficam em `00_material_aula_ifmg/`.

## Convenções das explicações

- As páginas didáticas de `01_explicacao_da_ia/` começam com frontmatter YAML:

  ```yaml
  ---
  titulo: Nome da Página
  categoria: conceito | entidade | exemplo | fonte | síntese
  tags: [tag1, tag2]
  fontes: [nome-da-fonte.md]
  atualizado: YYYY-MM-DD
  ---
  ```

- Use links internos do Obsidian. Quando o caminho for necessário para eliminar ambiguidade, use a forma `[[01_explicacao_da_ia/nome-da-pagina]]`.
- Para conceitos, prefira as seções: Definição, Como funciona, Armadilhas comuns, Exemplos e Ver também.
- Para funções e bibliotecas, prefira: Assinatura, Descrição, Parâmetros, Retorno, Exemplo e Ver também.
- Identifique blocos de código com a linguagem correspondente.
- As fontes brutas de `00_material_aula_ifmg/` e `03_material_extra/` não precisam seguir o formato das páginas didáticas.

## Operações

### Ingerir uma fonte

1. Classificar e armazenar a fonte:
   - material da disciplina em `00_material_aula_ifmg/aulas/` ou `00_material_aula_ifmg/atividades/`;
   - documentação oficial em `03_material_extra/doc_c_oficial/`;
   - material complementar em `03_material_extra/doc_auxiliares/`.
2. Ler a fonte e discutir os pontos principais com o usuário.
3. Criar ou atualizar a explicação correspondente em `01_explicacao_da_ia/`.
4. Atualizar os caminhos e a descrição da fonte em `index.md`.
5. Adicionar uma entrada em `log.md` no formato `## [YYYY-MM-DD] ingest | Título da Fonte`.

### Responder uma pergunta de estudo

1. Consultar `index.md` para localizar os conteúdos relevantes.
2. Ler primeiro a explicação correspondente em `01_explicacao_da_ia/`.
3. Consultar as fontes de `00_material_aula_ifmg/` ou `03_material_extra/` quando for necessário confirmar detalhes.
4. Sintetizar a resposta apontando os arquivos usados como referência.
5. Quando a resposta acrescentar conteúdo duradouro ao projeto, atualizar a página do nível correspondente e registrar em `log.md` no formato `## [YYYY-MM-DD] query | Pergunta resumida`.

### Trabalhar em uma prática

1. Identificar a lista em `00_material_aula_ifmg/atividades/`.
2. Trabalhar no arquivo correspondente dentro de `02_praticas/listaN_tema/`.
3. Usar `01_explicacao_da_ia/` como apoio conceitual e `03_material_extra/` como referência complementar.
4. Registrar dúvidas recorrentes em `02_praticas/dúvidas.md`.
5. Antes de criar exercícios, compilar ou commitar práticas, seguir as regras no início deste arquivo.

### Lint (revisão de saúde)

- Verificar se os caminhos de `index.md` refletem a estrutura atual.
- Identificar explicações sem fonte ou sem ligação com uma lista de práticas.
- Identificar fontes ainda não incorporadas às explicações.
- Verificar links internos quebrados e páginas órfãs.
- Conferir se os níveis e as listas continuam coerentes entre si.
- Adicionar uma entrada em `log.md` no formato `## [YYYY-MM-DD] lint | Resumo`.

## Notas

- Prefira clareza a brevidade nas explicações: o conteúdo é destinado ao estudo.
- Preserve as tentativas dos exercícios; não substitua o histórico por uma solução final sem seguir as regras deste arquivo.
- Quando houver comportamento indefinido, sinalize com `> **Undefined Behavior:**`.
- Quando houver diferença entre padrões C (C89, C99, C11, C17 ou C23), anote-a explicitamente.
- Não misture materiais de origem, explicações e resoluções: cada tipo de conteúdo deve permanecer na pasta correspondente.
