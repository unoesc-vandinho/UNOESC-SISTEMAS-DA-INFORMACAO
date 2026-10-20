const API = 'https://servicodados.ibge.gov.br/api/v1/localidades';

let municipiosAtuais = [];
let ufSelecionada = null;

const $ = (sel) => document.querySelector(sel);

function esc(valor) {
  const d = document.createElement('div');
  d.textContent = valor ?? '';
  return d.innerHTML;
}

function mostrarAlerta(msg, tipo = 'danger') {
  const el = $('#alerta');
  el.textContent = msg;
  el.className = `alert alert-${tipo}`;
}

function limparAlerta() {
  $('#alerta').className = 'alert d-none';
}

async function apiGet(caminho) {
  $('#carregando').classList.remove('d-none');
  try {
    const resp = await fetch(`${API}${caminho}`);
    if (!resp.ok) throw new Error(`Erro ${resp.status} ao consultar o IBGE`);
    return await resp.json();
  } finally {
    $('#carregando').classList.add('d-none');
  }
}

// Método 1 (sem filtro): GET /regioes
async function carregarRegioes() {
  const regioes = await apiGet('/regioes?orderBy=nome');
  $('#filtro-regiao').innerHTML += regioes
    .map((r) => `<option value="${r.id}">${esc(r.nome)}</option>`)
    .join('');
}

// Método 2 (sem filtro): GET /estados  |  Método 3 (com filtro): GET /regioes/{id}/estados
async function listarEstados() {
  limparAlerta();
  try {
    const regiaoId = $('#filtro-regiao').value;
    const caminho = regiaoId ? `/regioes/${regiaoId}/estados?orderBy=nome` : '/estados?orderBy=nome';
    const estados = await apiGet(caminho);
    $('#contador-estados').textContent = `${estados.length} estado(s)`;
    $('#lista-estados').innerHTML = estados
      .map((e) => `
        <div class="col-6 col-md-4 col-lg-3">
          <button type="button" class="btn estado-card w-100 text-start ${ufSelecionada?.sigla === e.sigla ? 'ativo' : ''}"
                  data-sigla="${esc(e.sigla)}" data-nome="${esc(e.nome)}">
            <span class="badge text-bg-success me-2">${esc(e.sigla)}</span>${esc(e.nome)}
            <div class="small text-muted">${esc(e.regiao.nome)}</div>
          </button>
        </div>`)
      .join('');
  } catch (err) {
    console.error(err);
    mostrarAlerta('Não foi possível carregar os estados. Tente novamente.');
  }
}

// Método 4 (com filtro por UF): GET /estados/{UF}/municipios
async function selecionarEstado(sigla, nome) {
  limparAlerta();
  try {
    ufSelecionada = { sigla, nome };
    $('#sec-detalhe').classList.add('d-none');
    $('#busca-municipio').value = '';
    municipiosAtuais = await apiGet(`/estados/${sigla}/municipios?orderBy=nome`);
    $('#nome-uf').textContent = `${nome} (${sigla})`;
    $('#sec-municipios').classList.remove('d-none');
    renderMunicipios();
    document.querySelectorAll('.estado-card').forEach((b) =>
      b.classList.toggle('ativo', b.dataset.sigla === sigla));
    $('#sec-municipios').scrollIntoView({ behavior: 'smooth' });
  } catch (err) {
    console.error(err);
    mostrarAlerta('Não foi possível carregar os municípios.');
  }
}

// Filtro no cliente pelo nome digitado
function renderMunicipios() {
  const termo = $('#busca-municipio').value.trim().toLowerCase();
  const lista = municipiosAtuais.filter((m) => m.nome.toLowerCase().includes(termo));
  $('#contador-municipios').textContent = `${lista.length} de ${municipiosAtuais.length} município(s)`;
  $('#lista-municipios').innerHTML = lista.length
    ? lista
        .map((m) => `
          <div class="col-12 col-sm-6 col-lg-4">
            <button type="button" class="btn municipio-card w-100 text-start" data-id="${m.id}">
              <i class="bi bi-geo-alt me-1"></i>${esc(m.nome)}
            </button>
          </div>`)
        .join('')
    : '<div class="col-12 text-muted">Nenhum município encontrado.</div>';
}

// Método 5 (item único, sem repetição): GET /municipios/{id}
// Método 6 (lista): GET /municipios/{id}/distritos
async function selecionarMunicipio(id) {
  limparAlerta();
  try {
    const [m, distritos] = await Promise.all([
      apiGet(`/municipios/${id}`),
      apiGet(`/municipios/${id}/distritos?orderBy=nome`),
    ]);
    const uf = m.microrregiao.mesorregiao.UF;
    const dados = [
      ['Código IBGE', m.id],
      ['Estado', `${uf.nome} (${uf.sigla})`],
      ['Região', uf.regiao.nome],
      ['Mesorregião', m.microrregiao.mesorregiao.nome],
      ['Microrregião', m.microrregiao.nome],
      ['Região imediata', m['regiao-imediata']?.nome],
      ['Região intermediária', m['regiao-imediata']?.['regiao-intermediaria']?.nome],
    ];
    $('#detalhe-municipio').innerHTML = `
      <article class="result-card p-3 bg-white">
        <h3 class="h4 mb-3"><i class="bi bi-building me-2"></i>${esc(m.nome)}</h3>
        <div class="row">
          ${dados.map(([rotulo, valor]) => `
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">${rotulo}</div>
              <div>${esc(valor) || '-'}</div>
            </div>`).join('')}
        </div>
      </article>`;
    $('#lista-distritos').innerHTML = distritos.length
      ? distritos.map((d) => `
          <div class="col-12 col-sm-6 col-lg-4">
            <div class="result-card p-2 bg-white">
              <i class="bi bi-pin-map me-1"></i>${esc(d.nome)}
              <div class="small text-muted">Código ${d.id}</div>
            </div>
          </div>`).join('')
      : '<div class="col-12 text-muted">Este município não possui distritos cadastrados.</div>';
    $('#sec-detalhe').classList.remove('d-none');
    $('#sec-detalhe').scrollIntoView({ behavior: 'smooth' });
  } catch (err) {
    console.error(err);
    mostrarAlerta('Não foi possível carregar os dados do município.');
  }
}

document.addEventListener('DOMContentLoaded', async () => {
  $('#filtro-regiao').addEventListener('change', listarEstados);
  $('#busca-municipio').addEventListener('input', renderMunicipios);
  $('#lista-estados').addEventListener('click', (ev) => {
    const b = ev.target.closest('.estado-card');
    if (b) selecionarEstado(b.dataset.sigla, b.dataset.nome);
  });
  $('#lista-municipios').addEventListener('click', (ev) => {
    const b = ev.target.closest('.municipio-card');
    if (b) selecionarMunicipio(b.dataset.id);
  });
  try {
    await carregarRegioes();
    await listarEstados();
  } catch (err) {
    console.error(err);
    mostrarAlerta('Falha ao conectar com a API do IBGE.');
  }
});
