# Diretrizes do Repositório & Regras para Agente de IA (Supervisor)

Este documento define os padrões de governança, organização de pastas, convenção de commits e as responsabilidades do **Agente de IA** como supervisor e revisor deste repositório.

---

## 🤖 Papel do Agente de IA (Supervisor de Repositório)

Sempre que um Agente de IA estiver interagindo neste repositório (criando arquivos, resolvendo exercícios ou adicionando projetos):

1. **Atualização Contínua do `README.md`:**
   - Toda vez que uma nova disciplina, aula, exercício relevante ou projeto for adicionado, o Agente de IA **DEVE atualizar o `README.md` principal**.
   - Se o projeto for uma aplicação web (HTML/CSS/JS), adicionar o link correspondente para o GitHub Pages:
     `https://unoesc-vandinho.github.io/UNOESC-SISTEMAS-DA-INFORMACAO/<caminho-da-pasta>/`
2. **Preservação da Raiz Limpa:**
   - **Nunca** criar arquivos avulsos na raiz (ex: scripts `.py`, arquivos `.docx`, `.pdf` ou `.cpp`).
   - Arquivos gerais/modelos de pesquisa ou resenhas devem ser colocados em `_modelos-e-documentos/`.
   - Exercícios e aulas devem ser colocados na fase e disciplina correspondente (`<fase>/<disciplina>/`).
3. **Padronização de Nomenclatura:**
   - Usar `kebab-case` para nomes de pastas e arquivos de código (ex: `estrutura-de-dados`, `aula-03`, `calculo-imc.js`).
4. **Verificação de `.gitignore`:**
   - Nunca comitar arquivos compilados (`.exe`, `.o`, `.out`), ambientes virtuais (`.venv/`), dependências (`node_modules/`) ou temporários do Office (`~$*`).

---

## 🗂️ Estrutura de Diretórios

```text
UNOESC-SISTEMAS-DA-INFORMACAO/
├── 2-fase/                      # Disciplinas da 2ª Fase
│   ├── arquitetura-de-hardware/
│   ├── desenvolvimento-web/
│   ├── estrutura-de-dados/
│   ├── introducao-ao-hardware/
│   ├── modelagem-de-sistemas/
│   └── pesquisa-e-normas/
├── 3-fase/                      # (Próximos semestres conforme avanço)
├── _modelos-e-documentos/       # Modelos institucionais (.docx), resenhas e ABNT
├── .agents/                     # Regras de automação e IA
├── AGENTS.md                    # Este guia de padrões
├── .gitignore
└── README.md                    # Vitrine e sumário central
```

---

## 💬 Padrão de Commits (Conventional Commits)

Todas as mensagens de commit devem seguir o padrão:

`<tipo>(<fase>/<disciplina>): <descrição em português>`

### Tipos Permitidos:
- **`feat`**: Nova atividade, código de aula, exercício ou projeto final.
  - *Exemplo:* `feat(2-fase/web): implementa consumo da api viacep com fetch`
- **`fix`**: Correção de bug em código ou correção em documento.
  - *Exemplo:* `fix(2-fase/estrutura-de-dados): corrige ponteiro nulo na lista encadeada`
- **`docs`**: Alteração em documentações, resumos, PDFs ou atualização do `README.md`.
  - *Exemplo:* `docs(readme): atualiza índice de projetos da 2ª fase`
- **`refactor`**: Reestruturação de código ou movimentação de pastas sem alteração de funcionalidade.
  - *Exemplo:* `refactor(estrutura): reorganiza pastas para o padrão de fases`
- **`chore`**: Atualização de `.gitignore`, workflows ou regras de agentes.
  - *Exemplo:* `chore(agents): atualiza regras de supervisão do repositório`

---

## 📋 Checklist Rápido para o Agente antes de Finalizar Tarefas

- [ ] Os arquivos foram colocados na pasta correta (`<fase>/<disciplina>/`)?
- [ ] O `README.md` foi atualizado refletindo o novo conteúdo/link?
- [ ] Nenhum arquivo temporário ou binário está pendente no `git status`?
- [ ] A mensagem de commit sugerida segue a convenção?
