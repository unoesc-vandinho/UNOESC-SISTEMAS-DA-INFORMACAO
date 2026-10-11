---
trigger: always_on
description: Regras obrigatórias de supervisão e manutenção do repositório UNOESC
---

# Regras de Manutenção e Supervisão do Repositório UNOESC

Como Agente de IA trabalhando neste repositório:

1. **Atualização Automática do README.md**:
   - Sempre que adicionar, renomear ou modificar matérias, trabalhos ou exercícios relevantes, você DEVE atualizar o [README.md](../../README.md) com a referência, descrição sucinta e link relativo (ou link do GitHub Pages para páginas HTML).

2. **Organização por Fases**:
   - Respeite rigorosamente a divisão de pastas por fases (`1-fase/`, `2-fase/`, etc.).
   - Modelos institucionais e documentos ABNT ficam em `_modelos-e-documentos/`.
   - Mantenha a raiz sempre limpa de arquivos soltos.

3. **Padrão de Mensagens de Commit**:
   - Utilize sempre Conventional Commits no formato: `<tipo>(<fase>/<disciplina>): <descrição em português>`.
   - Exemplos: `feat(2-fase/web): adiciona tela de login`, `fix(2-fase/estrutura-de-dados): corrige lista circular`, `docs(readme): sincroniza sumario`.
