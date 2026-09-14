# Pintinho Amarelinho — Petshop & Clínica Veterinária

Projeto de desenvolvimento web institucional e responsivo criado para a prestação de serviços de petshop e clínica veterinária, elaborado conforme os requisitos da **Avaliação A1.1 (Partes 1 e 2)** da disciplina de **Fundamentos ao Desenvolvimento Web**.

---

## 🎓 Informações Acadêmicas

* **Instituição:** Universidade do Oeste de Santa Catarina (UNOESC)
* **Curso:** Bacharelado em Sistemas de Informação
* **Semestre / Turno:** 2º Semestre — Noturno
* **Disciplina:** Fundamentos ao Desenvolvimento Web (FDW)
* **Docente:** Prof. Rafaeli Pinheiro
* **Acadêmico Desenvolvedor:** Vandoir Gerhard
* **Temática Sorteada:** Serviços de Petshop e Veterinária

---

## ⚖️ Aviso Legal e Origem dos Conteúdos

> **Aviso de Fins Educacionais:** Este website foi desenvolvido exclusivamente para avaliação pedagógica e acadêmica na UNOESC, sem fins comerciais ou lucrativos.
> 
> * **Textos e Conceito:** A história de fundação, descrições clínicas, missão, visão, valores e casos fictícios foram elaborados com o auxílio de ferramentas de Inteligência Artificial (IA) para simular uma identidade corporativa madura e acolhedora.
> * **Imagens:** As fotos e elementos visuais utilizados são provenientes de imagens públicas indexadas no Google Imagens, bancos de imagem de uso ilustrativo e/ou geradas por Inteligência Artificial para fins estritamente demonstrativos no contexto da disciplina.

---

## 🛠️ Tecnologias Utilizadas

* **HTML5:** Estruturação semântica, acessibilidade e boas práticas.
* **CSS3:** Folha de estilos própria com base na paleta mineral do Manual de Marca (Mostarda Ocre `#D4A359`, Azul Ardósia `#1E2B37`, Areia Suave `#F6F4EF` e Verde Sálvia `#9AA899`) e fontes *Cormorant Garamond* e *Inter*.
* **Bootstrap 5.3 (CDN Oficial):** Componentes responsivos nativos:
  * `Navbar` (menu responsivo com recolhimento mobile)
  * `Carousel` (banners rotativos da página principal)
  * `Card` (cards de serviços, profissionais, depoimentos e blog)
  * `Table` (tabelas de preços, horários e especificações)
  * `Accordion` (perguntas frequentes / FAQ e detalhes clínicos)
  * `Modal` (formulário de solicitação de orçamento)
* **Bootstrap Icons:** Biblioteca vetorial de ícones.
* **JavaScript Nativo:** Validação de formulários, fechamento de menu mobile e integração assíncrona com a [BrasilAPI](https://brasilapi.com.br/) para preenchimento automático de endereço por CEP.
* **Iframes:** Incorporação interativa do Google Maps e vídeos informativos do YouTube.

---

## 📁 Estrutura de Arquivos

```text
prova/
├── README.md                            # Documentação geral do projeto
├── index.html                           # Página principal (Landing Page completa)
├── consulta-clinica.html                # Página exclusiva do Serviço 1
├── ultrassonografia.html                # Página exclusiva do Serviço 2
├── estetica-calm-spa.html               # Página exclusiva do Serviço 3
├── servico1.html, servico2.html, ...    # Aliases de compatibilidade para correção
│
├── css/
│   └── style.css                        # Estilos e identidade visual personalizada
│
├── js/
│   └── main.js                          # Lógica nativa e busca de CEP (BrasilAPI)
│
├── img/                                 # Pasta unificada com as 18 imagens otimizadas
│   ├── favicon.jpg                      # Favicon e logotipo circular
│   ├── fachada_WH_1600x900px.jpg        # Foto da fachada (Carrossel / Sobre Nós)
│   ├── nos_WH_1600x900px.jpg            # Foto da equipe (Carrossel / Sobre Nós)
│   ├── pet-model_WH_1600x900px.jpg      # Foto do spa pet (Carrossel)
│   ├── servico-checkup_WH_640x426px.jpg # Consulta Clínica
│   ├── utrassonografia_WH_640x426px.jpg # Ultrassonografia
│   ├── pet-model_WH_640x426px.jpg       # Spa e Grooming
│   ├── profissional01.jpg               # Dra. Clara Letícia
│   ├── profissional02.avif              # Dr. Pedro Henrique
│   ├── milo_WH_400x400px.jpg            # Depoimento Milo
│   ├── amora_WH_400x400px.jpg           # Depoimento Amora
│   ├── pipoca_WH_400x400px.jpg          # Depoimento Pipoca
│   ├── cliente04_WH_400x400px.jpg       # Depoimento Bento
│   ├── cliente05_WH_400x400px.jpg       # Depoimento Luna
│   └── post01.avif, post02.avif...      # Artigos do Blog
│
└── docs/                                # Arquivos e requisitos da Parte 1 e 2
    ├── Parte-1_Conteudo_Completo.docx   # Documento DOCX oficial da Parte 1
    ├── Parte-1_Conteudo_Completo.txt    # Documento TXT da Parte 1
    ├── Requisitos - Avaliação A1 (parte-1).md
    ├── Requisitos - Avaliação A1.md
    └── *.md originais da coleta
```

---

## 🚀 Como Executar Localmente

Como o projeto foi construído com tecnologias web nativas, qualquer servidor estático é suficiente.

Utilizando o Python:

```bash
# Navegue até a pasta da avaliação
cd Desenvolvimento-web/prova

# Inicie o servidor HTTP local
python3 -m http.server 8000
```

Abra no seu navegador:
👉 **http://localhost:8000**

---

## 🌐 Publicação no GitHub Pages

O projeto está pronto para publicação através do GitHub Pages, ficando disponível no endereço do repositório:
```text
https://unoesc-vandinho.github.io/UNOESC-SISTEMAS-DA-INFORMACAO/Desenvolvimento-web/prova/
```
