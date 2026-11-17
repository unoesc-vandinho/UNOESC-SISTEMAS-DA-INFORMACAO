# Pintinho Amarelinho — Petshop & Clínica Veterinária (PHP + MariaDB)

Site institucional de petshop e clínica veterinária, elaborado para a disciplina **Fundamentos ao Desenvolvimento Web (FDW)**. Parte A1.1 (front-end) evoluída na **Avaliação A1.3** com back-end PHP e banco MariaDB.

## 🎓 Informações Acadêmicas

* **Instituição:** Universidade do Oeste de Santa Catarina (UNOESC) — Sistemas de Informação, 2º semestre, noturno
* **Disciplina:** Fundamentos ao Desenvolvimento Web — Prof. Rafaeli Pinheiro
* **Acadêmico:** Vandoir Gerhard
* **Temática:** Serviços de Petshop e Veterinária

> **Aviso:** projeto exclusivamente educacional. Textos gerados com auxílio de IA; imagens públicas, ilustrativas ou geradas por IA.

## 🛠️ Tecnologias

HTML5, CSS3, Bootstrap 5.3 (Navbar, Carousel, Card, Table, Accordion, Modal), Bootstrap Icons, JavaScript (`fetch`, validação, BrasilAPI para CEP), **PHP 8.5 (PDO)**, **MariaDB 11**, Docker Compose.

## 🗄️ Funcionalidades com Banco de Dados (A1.3)

| Seção | Operação | Endpoint (`app/api-php/`) | Tabela |
|---|---|---|---|
| Contato | INSERT | `contato-salvar.php` | `contatos` |
| Orçamento | INSERT | `orcamento-salvar.php` | `orcamentos` |
| Depoimentos | SELECT + INSERT (carrossel) | `depoimentos-listar.php`, `depoimento-salvar.php` | `depoimentos` |
| Serviços | SELECT | `servicos-listar.php` | `servicos` |
| Profissionais | SELECT | `profissionais-listar.php` | `profissionais` |

* `conexao.php`: conexão PDO (host `db`) e funções auxiliares; todas as respostas são JSON.
* Segurança básica: *prepared statements* (anti SQL injection), validação no servidor (`filter_var`, tamanhos, formatos), só POST nos envios e exibição com `textContent` (anti XSS).
* `app/js/main.js`: `fetch` para os endpoints (`enviarFormulario`, `carregarDepoimentos`, `carregarLista`).

## 🐳 Ambiente Docker

| Serviço | Imagem | Endereço |
|---|---|---|
| `web` | `php:8.5-apache` (+ `pdo_mysql`) | http://localhost:8081 |
| `db` | `mariadb:11` | interno (host `db`, porta 3306) |
| `phpmyadmin` | `phpmyadmin:5` | http://localhost:8080 |

```bash
docker compose up -d --build   # subir
docker compose down            # parar (dados ficam no volume db-data)
docker compose down -v         # parar e zerar o banco
```

Banco `pintinho_amarelinho`, usuário `admin`, senha `admin` (root também `admin`). O `MARIADB_DATABASE` só é lido quando o volume está vazio.

### Importar o banco

phpMyAdmin (http://localhost:8080, **root / admin**) → aba **Importar** → [`pintinho_amarelinho.sql`](./pintinho_amarelinho.sql) → **Executar**. O script cria o banco, as 5 tabelas e os dados iniciais.

## 📁 Estrutura

```text
prova-php/
├── README.md
├── Dockerfile / docker-compose.yml
├── pintinho_amarelinho.sql        # Exportação do banco (phpMyAdmin)
├── FDW 2026.2 - Avaliação A1.md   # Enunciado da avaliação
└── app/                           # Servido pelo Apache
    ├── index.html                 # Página principal
    ├── consulta-clinica.html, ultrassonografia.html, estetica-calm-spa.html  # Páginas de serviço (modal de orçamento)
    ├── servico1.html … servico3.html   # Aliases de compatibilidade
    ├── api-php/                   # Back-end PHP (JSON)
    ├── css/style.css
    ├── js/main.js
    ├── img/
    └── docs/                      # Conteúdos e requisitos das partes anteriores
```

> O PHP não roda no GitHub Pages; a apresentação é feita com os containers locais.
