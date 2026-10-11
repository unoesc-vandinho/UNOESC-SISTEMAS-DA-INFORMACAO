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
    contactForm.addEventListener('submit', (e) => {
      e.preventDefault();
      if (!contactForm.checkValidity()) {
        e.stopPropagation();
        contactForm.classList.add('was-validated');
        return;
      }
      
      const nome = document.getElementById('contatoNome')?.value || 'Cliente';
      alert(`Obrigado pelo contato, ${nome}! Sua mensagem foi enviada com sucesso para a equipe da Pintinho Amarelinho. Responderemos em breve.`);
      contactForm.reset();
      contactForm.classList.remove('was-validated');
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
    orcamentoForm.addEventListener('submit', (e) => {
      e.preventDefault();
      if (!orcamentoForm.checkValidity()) {
        e.stopPropagation();
        orcamentoForm.classList.add('was-validated');
        return;
      }

      const nome = document.getElementById('orcamentoNome')?.value || 'Cliente';
      const servico = document.getElementById('orcamentoServicoNome')?.textContent || 'serviço';
      const modalElement = document.getElementById('modalOrcamento');

      if (modalElement && typeof bootstrap !== 'undefined') {
        const modalInstance = bootstrap.Modal.getInstance(modalElement);
        if (modalInstance) {
          modalInstance.hide();
        }
      }

      alert(`Solicitação recebida com sucesso, ${nome}!\n\nRegistramos seu pedido de orçamento para: "${servico}". Nossa equipe entrará em contato pelo telefone/WhatsApp ou e-mail informados.`);
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
});
