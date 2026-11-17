/**
 * Pintinho Amarelinho - Petshop & Clínica Veterinária
 * Script de interatividade leve e nativo com integração à BrasilAPI
 */

document.addEventListener('DOMContentLoaded', () => {
  // 1. Fechar menu mobile ao clicar em itens da navbar
  const navLinks = document.querySelectorAll('.navbar-nav .nav-link:not(.dropdown-toggle)');
  const navbarCollapse = document.querySelector('.navbar-collapse');
  
  if (navbarCollapse && typeof bootstrap !== 'undefined') {
    navLinks.forEach(link => {
      link.addEventListener('click', () => {
        if (navbarCollapse.classList.contains('show')) {
          const bsCollapse = bootstrap.Collapse.getInstance(navbarCollapse) || new bootstrap.Collapse(navbarCollapse);
          bsCollapse.hide();
        }
      });
    });
  }

  // 2. Manipulação do formulário de contato
  const contactForm = document.getElementById('formContato');
  if (contactForm) {
    contactForm.addEventListener('submit', async (e) => {
      e.preventDefault();
      if (!contactForm.checkValidity()) {
        e.stopPropagation();
        contactForm.classList.add('was-validated');
        return;
      }
      const nome = document.getElementById('contatoNome')?.value || 'Cliente';
      const r = await enviarFormulario(contactForm, 'api-php/contato-salvar.php');
      if (r.sucesso) {
        alert(`Obrigado pelo contato, ${nome}! Sua mensagem foi registrada. Responderemos em breve.`);
        contactForm.reset();
        contactForm.classList.remove('was-validated');
      } else {
        alert(r.mensagem);
      }
    });
  }

  // 3. Integração com a BrasilAPI para consulta automática de CEP
  const cepInput = document.getElementById('orcamentoCep');
  const enderecoInput = document.getElementById('orcamentoEndereco');
  const bairroInput = document.getElementById('orcamentoBairro');
  const cidadeInput = document.getElementById('orcamentoCidade');
  const ufSelect = document.getElementById('orcamentoUF');
  const cepFeedback = document.getElementById('cepFeedback');

  if (cepInput) {
    // Máscara simples para CEP (00000-000)
    cepInput.addEventListener('input', (e) => {
      let value = e.target.value.replace(/\D/g, '');
      if (value.length > 8) value = value.slice(0, 8);
      if (value.length > 5) {
        value = value.replace(/^(\d{5})(\d)/, '$1-$2');
      }
      e.target.value = value;

      const rawCep = value.replace(/\D/g, '');
      if (rawCep.length === 8) {
        buscarCep(rawCep);
      }
    });

    cepInput.addEventListener('blur', () => {
      const rawCep = cepInput.value.replace(/\D/g, '');
      if (rawCep.length === 8) {
        buscarCep(rawCep);
      }
    });
  }

  async function buscarCep(cep) {
    if (cepFeedback) {
      cepFeedback.textContent = 'Buscando endereço...';
      cepFeedback.className = 'text-primary small mt-1';
    }

    try {
      const response = await fetch(`https://brasilapi.com.br/api/cep/v1/${cep}`);
      if (!response.ok) {
        throw new Error('CEP não localizado');
      }

      const data = await response.json();

      if (cidadeInput) cidadeInput.value = data.city || '';
      if (ufSelect) ufSelect.value = data.state || '';
      if (bairroInput && data.neighborhood) bairroInput.value = data.neighborhood;
      
      if (enderecoInput) {
        if (data.street) {
          enderecoInput.value = data.street + ', nº ';
          enderecoInput.focus();
        } else {
          enderecoInput.focus();
        }
      }

      if (cepFeedback) {
        cepFeedback.textContent = 'Endereço preenchido automaticamente pela BrasilAPI!';
        cepFeedback.className = 'text-success small mt-1';
      }
    } catch (err) {
      if (cepFeedback) {
        cepFeedback.textContent = 'CEP não encontrado ou fora de alcance. Por favor, preencha manualmente.';
        cepFeedback.className = 'text-warning small mt-1';
      }
    }
  }

  // 4. Manipulação do formulário do Modal de Orçamento
  const orcamentoForm = document.getElementById('formOrcamento');
  if (orcamentoForm) {
    orcamentoForm.addEventListener('submit', async (e) => {
      e.preventDefault();
      if (!orcamentoForm.checkValidity()) {
        e.stopPropagation();
        orcamentoForm.classList.add('was-validated');
        return;
      }

      const nome = document.getElementById('orcamentoNome')?.value || 'Cliente';
      const servico = document.getElementById('orcamentoServicoNome')?.textContent || 'serviço';
      const dados = new FormData(orcamentoForm);
      dados.append('servico', servico.trim());
      const r = await enviarFormulario(orcamentoForm, 'api-php/orcamento-salvar.php', dados);
      if (!r.sucesso) {
        alert(r.mensagem);
        return;
      }

      const modalElement = document.getElementById('modalOrcamento');
      if (modalElement && typeof bootstrap !== 'undefined') {
        const modalInstance = bootstrap.Modal.getInstance(modalElement);
        if (modalInstance) modalInstance.hide();
      }

      alert(`Solicitação recebida com sucesso, ${nome}!\n\nRegistramos seu pedido de orçamento para: "${servico.trim()}". Nossa equipe entrará em contato pelo telefone/WhatsApp ou e-mail informados.`);
      orcamentoForm.reset();
      orcamentoForm.classList.remove('was-validated');
      if (cepFeedback) cepFeedback.textContent = '';
    });
  }

  // 5. Tooltips
  if (typeof bootstrap !== 'undefined' && bootstrap.Tooltip) {
    const tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
    tooltipTriggerList.map(tooltipTriggerEl => new bootstrap.Tooltip(tooltipTriggerEl));
  }

  // 6. Depoimentos: listagem (SELECT) e envio (INSERT)
  const listaDepoimentos = document.getElementById('listaDepoimentos');

  function criarCardDepoimento(d) {
    const col = document.createElement('div');
    col.className = 'col-lg-4 col-md-6';
    const card = document.createElement('div');
    card.className = 'testimonial-card';

    const icone = document.createElement('i');
    icone.className = 'bi bi-quote testimonial-quote-icon';

    const corpo = document.createElement('div');
    const estrelas = document.createElement('div');
    estrelas.className = 'mb-2 text-warning';
    for (let i = 1; i <= 5; i++) {
      const star = document.createElement('i');
      star.className = i <= d.nota ? 'bi bi-star-fill' : 'bi bi-star';
      estrelas.appendChild(star);
    }
    const texto = document.createElement('p');
    texto.className = 'testimonial-text';
    texto.textContent = `"${d.texto}"`;
    corpo.append(estrelas, texto);

    const autor = document.createElement('div');
    autor.className = 'testimonial-author border-top pt-3';
    if (d.foto) {
      const img = document.createElement('img');
      img.src = d.foto;
      img.alt = d.nome;
      img.className = 'testimonial-avatar';
      autor.appendChild(img);
    } else {
      const avatar = document.createElement('div');
      avatar.className = 'testimonial-avatar d-flex align-items-center justify-content-center bg-light fw-bold';
      avatar.textContent = d.nome.charAt(0).toUpperCase();
      autor.appendChild(avatar);
    }
    const info = document.createElement('div');
    const nome = document.createElement('div');
    nome.className = 'testimonial-author-name';
    nome.textContent = d.nome;
    info.appendChild(nome);
    if (d.descricao) {
      const papel = document.createElement('div');
      papel.className = 'testimonial-author-role';
      papel.textContent = d.descricao;
      info.appendChild(papel);
    }
    const data = document.createElement('small');
    data.className = 'text-muted d-block';
    data.style.fontSize = '0.75rem';
    data.textContent = new Date(d.criado_em.replace(' ', 'T')).toLocaleDateString('pt-BR', { day: '2-digit', month: 'long', year: 'numeric' });
    info.appendChild(data);
    autor.appendChild(info);

    card.append(icone, corpo, autor);
    col.appendChild(card);
    return col;
  }

  // Quantos cards por slide conforme a largura da tela (1, 2 ou 3)
  let depoimentosCache = [];
  let porSlide = 0;

  function cardsPorSlide() {
    if (window.innerWidth >= 992) return 3;
    if (window.innerWidth >= 768) return 2;
    return 1;
  }

  function montarCarrossel() {
    const indicadores = document.getElementById('indicadoresDepoimentos');
    porSlide = cardsPorSlide();
    listaDepoimentos.replaceChildren();
    indicadores.replaceChildren();

    const total = Math.ceil(depoimentosCache.length / porSlide);
    for (let i = 0; i < total; i++) {
      const item = document.createElement('div');
      item.className = 'carousel-item' + (i === 0 ? ' active' : '');
      const row = document.createElement('div');
      row.className = 'row g-4 justify-content-center';
      depoimentosCache.slice(i * porSlide, (i + 1) * porSlide).forEach(d => row.appendChild(criarCardDepoimento(d)));
      item.appendChild(row);
      listaDepoimentos.appendChild(item);

      const ind = document.createElement('button');
      ind.type = 'button';
      ind.setAttribute('data-bs-target', '#carrosselDepoimentos');
      ind.setAttribute('data-bs-slide-to', i);
      ind.setAttribute('aria-label', `Slide ${i + 1}`);
      if (i === 0) { ind.className = 'active'; ind.setAttribute('aria-current', 'true'); }
      indicadores.appendChild(ind);
    }
  }

  async function carregarDepoimentos() {
    if (!listaDepoimentos) return;
    try {
      const resp = await fetch('api-php/depoimentos-listar.php');
      const r = await resp.json();
      if (!r.sucesso) throw new Error(r.mensagem);
      depoimentosCache = r.depoimentos;
      if (depoimentosCache.length === 0) {
        listaDepoimentos.innerHTML = '<div class="carousel-item active"><p class="text-center text-muted">Ainda não há depoimentos. Seja o primeiro!</p></div>';
        return;
      }
      montarCarrossel();
    } catch (err) {
      listaDepoimentos.innerHTML = '<div class="carousel-item active"><p class="text-center text-danger">Não foi possível carregar os depoimentos.</p></div>';
    }
  }

  // Remonta o carrossel se o número de cards por slide mudar (resize)
  window.addEventListener('resize', () => {
    if (depoimentosCache.length && cardsPorSlide() !== porSlide) montarCarrossel();
  });
  carregarDepoimentos();

  const depoimentoForm = document.getElementById('formDepoimento');
  if (depoimentoForm) {
    depoimentoForm.addEventListener('submit', async (e) => {
      e.preventDefault();
      if (!depoimentoForm.checkValidity()) {
        e.stopPropagation();
        depoimentoForm.classList.add('was-validated');
        return;
      }
      const r = await enviarFormulario(depoimentoForm, 'api-php/depoimento-salvar.php');
      alert(r.mensagem);
      if (r.sucesso) {
        depoimentoForm.reset();
        depoimentoForm.classList.remove('was-validated');
        carregarDepoimentos();
      }
    });
  }

  // 7. Serviços e Profissionais: listagem (SELECT)
  function el(tag, classe, texto) {
    const e = document.createElement(tag);
    if (classe) e.className = classe;
    if (texto !== undefined) e.textContent = texto;
    return e;
  }

  function criarCardServico(s) {
    const col = el('div', 'col-lg-4 col-md-6');
    const card = el('article', 'card-custom');

    const wrap = el('div', 'card-custom-img-wrap');
    const img = el('img', 'card-custom-img');
    img.src = s.imagem;
    img.alt = s.titulo;
    const badge = el('span', 'badge position-absolute top-0 end-0 m-3 py-2 px-3 fw-semibold', s.categoria);
    badge.style.backgroundColor = 'var(--color-slate)';
    badge.style.color = 'var(--color-primary)';
    wrap.append(img, badge);

    const corpo = el('div', 'card-custom-body');
    const preco = el('div', 'd-flex justify-content-between align-items-baseline mb-3 pt-2 border-top');
    preco.append(
      el('span', 'text-muted small', 'Valor a partir de:'),
      el('span', 'card-custom-price', Number(s.preco).toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' }))
    );
    const link = el('a', 'btn btn-primary-custom w-100');
    link.href = s.pagina;
    link.innerHTML = '<i class="bi bi-file-earmark-text"></i> ';
    link.append('Solicitar Orçamento e Detalhes');
    corpo.append(el('h3', 'card-custom-title', s.titulo), el('p', 'card-custom-text', s.descricao), preco, link);

    card.append(wrap, corpo);
    col.appendChild(card);
    return col;
  }

  function criarCardProfissional(p) {
    const col = el('div', 'col-lg-6 col-md-8');
    const card = el('div', 'doctor-card');
    const row = el('div', 'row g-0');

    const fotoWrap = el('div', 'col-sm-5 doctor-photo-wrap');
    const foto = el('img', 'doctor-photo');
    foto.src = p.foto;
    foto.alt = p.nome;
    fotoWrap.appendChild(foto);

    const info = el('div', 'col-sm-7 d-flex flex-column justify-content-between p-4');
    const topo = el('div');
    const tags = el('div', 'd-flex flex-wrap gap-1 mb-3');
    p.especialidades.split(',').forEach(t => tags.appendChild(el('span', 'badge bg-light text-dark border', t.trim())));
    topo.append(el('h3', 'doctor-name', p.nome), el('div', 'doctor-role', p.cargo), el('p', 'text-muted small mb-3', p.descricao), tags);

    const botao = el('a', 'btn btn-sm btn-outline-custom align-self-start');
    botao.href = p.link_agendamento;
    botao.target = '_blank';
    botao.rel = 'noopener noreferrer';
    botao.innerHTML = '<i class="bi bi-calendar-event"></i> ';
    botao.append(p.texto_botao);

    info.append(topo, botao);
    row.append(fotoWrap, info);
    card.appendChild(row);
    col.appendChild(card);
    return col;
  }

  async function carregarLista(url, chave, container, criarCard, rotulo) {
    if (!container) return;
    try {
      const resp = await fetch(url);
      const r = await resp.json();
      if (!r.sucesso) throw new Error(r.mensagem);
      container.replaceChildren(...r[chave].map(criarCard));
    } catch (err) {
      container.innerHTML = `<p class="text-center text-danger">Não foi possível carregar ${rotulo}.</p>`;
    }
  }

  carregarLista('api-php/servicos-listar.php', 'servicos', document.getElementById('listaServicos'), criarCardServico, 'os serviços');
  carregarLista('api-php/profissionais-listar.php', 'profissionais', document.getElementById('listaProfissionais'), criarCardProfissional, 'os profissionais');
});

// Envia um formulário (ou FormData) por POST e devolve o JSON do back-end.
async function enviarFormulario(form, url, dados = null) {
  try {
    const resp = await fetch(url, { method: 'POST', body: dados || new FormData(form) });
    return await resp.json();
  } catch (err) {
    return { sucesso: false, mensagem: 'Erro de comunicação com o servidor.' };
  }
}
