# Regras para o assistente (AGENTS.md)

## Respostas em C

1. Não gerar respostas com código em C no chat do opencode, a menos que o usuário peça explicitamente.
   - Exceção: tarefas de compilação/commit de arquivos `.c` de práticas (regras abaixo continuam valendo).

## Compilação de arquivos .c (01_praticas)

Toda vez que o usuário rodar o compilador C (`gcc`) em um arquivo de práticas:

1. **Comitar ANTES de compilar novamente** — isso garante que o número da tentativa no commit corresponda à realidade.
2. Comitar o arquivo `.c` com uma mensagem contendo o nome do arquivo e o número da tentativa de resolução.
   - Exemplo: tentativa 3 do `lista2/ex7.c` → `feat(lista2/ex7.c): tentativa 3`
3. Manter o histórico de tentativas: verificar `git log` para descobrir qual é o número da próxima tentativa antes de commitar.
4. Na mensagem do commit, usar sempre o caminho relativo à pasta `01_praticas/` (ex: `lista2/ex9.c`), nunca o caminho completo (`01_praticas/lista2/ex9.c`).

## Executáveis

1. Sempre que um novo executável for gerado (arquivo binário sem extensão, `.dSYM`, etc.), adicioná-lo ao `.gitignore` imediatamente.
2. Nunca commitar executáveis ou binários compilados no repositório.

## Commits

1. Nunca incluir assinatura de IA nos commits (ex: `Co-Authored-By`, `Generated with`, etc.).