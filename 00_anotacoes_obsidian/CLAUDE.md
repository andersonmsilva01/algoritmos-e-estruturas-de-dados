# Wiki de Linguagem C — Schema

## Estrutura de diretórios

```
anotacoes_obsidian/
├── CLAUDE.md          ← este arquivo (schema e instruções)
├── raw/               ← fontes brutas (artigos, PDFs, trechos de livros, código)
└── wiki/
    ├── index.md       ← índice de todas as páginas da wiki
    ├── log.md         ← registro cronológico de atividades
    ├── overview.md    ← visão geral e síntese do conhecimento acumulado
    ├── conceitos/     ← páginas de conceitos (ponteiros, memória, tipos, etc.)
    ├── entidades/     ← funções, bibliotecas, ferramentas (printf, malloc, gcc, etc.)
    └── exemplos/      ← trechos de código explicados e arquivados
```

## Convenções de páginas

- Toda página começa com frontmatter YAML:
  ```yaml
  ---
  titulo: Nome da Página
  categoria: conceito | entidade | exemplo | fonte | síntese
  tags: [tag1, tag2]
  fontes: [nome-da-fonte.md]
  atualizado: YYYY-MM-DD
  ---
  ```
- Use links internos do Obsidian: `[[nome-da-pagina]]`
- Seções padrão para conceitos: Definição, Como funciona, Armadilhas comuns, Exemplos, Ver também
- Seções padrão para entidades (funções/bibliotecas): Assinatura, Descrição, Parâmetros, Retorno, Exemplo, Ver também
- Código sempre em blocos com a linguagem especificada: ` ```c `

## Operações

### Ingerir fonte
1. Ler o arquivo em `raw/`
2. Discutir os pontos principais com o usuário
3. Criar página de resumo em `wiki/` na categoria adequada
4. Atualizar `wiki/index.md`
5. Atualizar páginas de conceitos/entidades relacionadas
6. Adicionar entrada em `wiki/log.md` com o formato: `## [YYYY-MM-DD] ingest | Título da Fonte`

### Responder pergunta
1. Ler `wiki/index.md` para encontrar páginas relevantes
2. Ler as páginas relevantes
3. Sintetizar resposta com citações às páginas da wiki
4. Se a resposta for valiosa, arquivá-la como nova página em `wiki/`
5. Adicionar entrada em `wiki/log.md`: `## [YYYY-MM-DD] query | Pergunta resumida`

### Lint (revisão de saúde)
- Verificar contradições entre páginas
- Identificar páginas órfãs (sem links de entrada)
- Identificar conceitos mencionados sem página própria
- Sugerir novas fontes ou perguntas para investigar
- Adicionar entrada em `wiki/log.md`: `## [YYYY-MM-DD] lint | Resumo`

## Categorias de conteúdo para C

- **conceitos/**: tipos de dados, ponteiros, arrays, strings, memória (stack/heap), escopo, preprocessador, undefined behavior, etc.
- **entidades/**: funções da stdlib (printf, malloc, free, fopen...), gcc/clang, make, gdb, valgrind, bibliotecas
- **exemplos/**: programas e trechos comentados por tema

## Notas

- Sempre prefira clareza a brevidade nas páginas da wiki — estas páginas são para estudo
- Quando houver comportamento indefinido (UB) relevante, sinalize com `> **Undefined Behavior:**`
- Quando houver diferença entre padrões C (C89/C99/C11/C17/C23), anote explicitamente
