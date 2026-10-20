# Explorador de Localidades - IBGE

**Avaliação A1.2 - Trabalho - Parte 1**
**Disciplina:** Fundamentos ao Desenvolvimento Web (FDW 2026.2) - Unoesc
**Professor:** Rafaeli Pinheiro
**Acadêmico:** Vandoir Gerhard
**Curso:** Sistemas de Informação - 2º semestre - Noturno

## 🔗 Link do projeto (GitHub Pages)

https://unoesc-vandinho.github.io/UNOESC-SISTEMAS-DA-INFORMACAO/2-fase/desenvolvimento-web/prova-api-ibge/

## Sobre

Aplicação web que consome a **API de Localidades do IBGE** (https://servicodados.ibge.gov.br/api/docs/localidades) e permite navegar pelo Brasil: **Estado → Município → Distritos**, exibindo os dados oficiais de cada localidade.

## Métodos da API utilizados

Base: `https://servicodados.ibge.gov.br/api/v1/localidades`

| # | Método | Uso | Filtro |
|---|---|---|---|
| 1 | `GET /regioes` | Preenche o filtro de regiões | Sem filtro |
| 2 | `GET /estados` | Lista todos os estados | Sem filtro |
| 3 | `GET /regioes/{id}/estados` | Estados de uma região | Com filtro |
| 4 | `GET /estados/{UF}/municipios` | Municípios do estado escolhido | Com filtro |
| 5 | `GET /municipios/{id}` | Detalhe de um único município | Com filtro (ID) |
| 6 | `GET /municipios/{id}/distritos` | Distritos do município | Com filtro (ID) |

## Critérios atendidos

- **Interface HTML responsiva:** Bootstrap 5 (grid e componentes) com apresentação dos dados em cards.
- **Exibição com repetição:** listas de estados, municípios e distritos.
- **Exibição sem repetição:** card de detalhe de um município.
- **Chamadas com e sem filtros:** conforme a tabela acima, além de busca por nome de município.
- **Rodapé** com nome completo e identificação da disciplina.

## Tecnologias

HTML5, CSS3 e JavaScript puro (`fetch` / `async-await`), mais Bootstrap 5 e Bootstrap Icons via CDN. Sem frameworks.

## Estrutura

```text
prova-api-ibge/
├── index.html
├── script.js
├── style.css
└── README.md
```

## Executar localmente

```bash
python3 -m http.server 8765
# abrir http://localhost:8765/
```
