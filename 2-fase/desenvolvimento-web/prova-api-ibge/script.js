const API = 'https://servicodados.ibge.gov.br/api/v1/localidades';
const API_LOGS_BASE = 'https://piway.com.br/unoesc/api';
const MATRICULA = '331914';
const NOME_API = 'IBGE Localidades';

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
    const dados = await resp.json();
    // Registra a chamada na API de logs (sem bloquear a tela)
    inserirLog(descreverMetodo(caminho), descreverResultado(dados));
    return dados;
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

// ---------------------------------------------------------------
// LOGS (API de registro de logs)
// ---------------------------------------------------------------

// Evita "/" nos route-params (o servidor trataria como outra rota)
function descreverMetodo(caminho) {
  return caminho.split('?')[0].replace(/^\//, '').replace(/\//g, ' > ');
}

function descreverResultado(dados) {
  if (Array.isArray(dados)) return `${dados.length} resultado(s)`;
  return dados?.nome ?? '1 resultado';
}

// Descobre o campo de ID do log (a documentação não informa o nome do campo)
const CAMPOS_ID = ['id', 'idlog', 'id_log', 'idLog', 'ID', 'Id'];
function idDoLog(log) {
  const campo = CAMPOS_ID.find((c) => log?.[c] !== undefined);
  return campo ? { campo, valor: log[campo] } : null;
}

// Inserir log: GET /inserir/log/MATRICULA/API/METODO/RESULTADO
async function inserirLog(metodo, resultado) {
  try {
    const rota = [MATRICULA, NOME_API, metodo, resultado].map(encodeURIComponent).join('/');
    const resp = await fetch(`${API_LOGS_BASE}/inserir/log/${rota}`);
    if (!resp.ok) { console.warn('API Logs não disponível (inserir)'); return null; }
    return await resp.text();
  } catch (err) {
    console.warn('Falha ao inserir log', err);
    return null;
  }
}

// Exibir logs: GET /logs/MATRICULA  (abre o modal e formata com JsonViewer)
async function exibirLogs() {
  const modalEl = $('#modalLogs');
  bootstrap.Modal.getOrCreateInstance(modalEl).show();
  const lista = $('#lista-logs');
  const viewerBox = $('#json-viewer');
  lista.innerHTML = '<div class="text-muted">Carregando logs...</div>';
  viewerBox.innerHTML = '';
  try {
    const resp = await fetch(`${API_LOGS_BASE}/logs/${encodeURIComponent(MATRICULA)}`);
    if (!resp.ok) throw new Error(`Erro ${resp.status}`);
    const json = await resp.json();
    renderListaLogs(json);
    const alvo = document.createElement('div');
    viewerBox.appendChild(alvo);
    new JsonViewer({ value: json, defaultInspectDepth: 1 }).render(alvo);
  } catch (err) {
    console.error(err);
    lista.innerHTML = '<div class="text-danger">API de logs não disponível.</div>';
  }
}

// Lista os logs com botão de excluir
function renderListaLogs(logs) {
  const lista = $('#lista-logs');
  if (!Array.isArray(logs)) {
    // A API retorna texto de erro (ex.: matrícula inválida)
    lista.innerHTML = `<div class="text-danger">${esc(typeof logs === 'string' ? logs : JSON.stringify(logs))}</div>`;
    return;
  }
  if (!logs.length) {
    lista.innerHTML = '<div class="text-muted">Nenhum log registrado.</div>';
    return;
  }
  lista.innerHTML = logs.map((log) => {
    const id = idDoLog(log);
    const resumo = Object.entries(log)
      .filter(([k]) => !id || k !== id.campo)
      .map(([, v]) => esc(v))
      .join(' &middot; ');
    return `
      <div class="d-flex align-items-center justify-content-between border rounded p-2 mb-2">
        <small class="me-2">${id ? `<strong>#${esc(id.valor)}</strong> ` : ''}${resumo}</small>
        ${id ? `<button type="button" class="btn btn-sm btn-outline-danger" data-id-log="${esc(id.valor)}"
                  title="Excluir log"><i class="bi bi-trash"></i></button>` : ''}
      </div>`;
  }).join('');
}

// Deletar log: GET /excluir/log/IDLOG/aluno/MATRICULA
async function deletarLog(idLog) {
  try {
    const resp = await fetch(
      `${API_LOGS_BASE}/excluir/log/${encodeURIComponent(idLog)}/aluno/${encodeURIComponent(MATRICULA)}`);
    if (!resp.ok) throw new Error(`Erro ${resp.status}`);
    console.log(await resp.text());
    await exibirLogs(); // recarrega a lista e o JSON
  } catch (err) {
    console.error(err);
    mostrarAlerta('Não foi possível excluir o log.');
  }
}

// Deletar todos os logs: a API só exclui por ID, então busca a lista e exclui um a um
async function deletarTodosLogs() {
  try {
    const resp = await fetch(`${API_LOGS_BASE}/logs/${encodeURIComponent(MATRICULA)}`);
    if (!resp.ok) throw new Error(`Erro ${resp.status}`);
    const logs = await resp.json();
    const ids = Array.isArray(logs) ? logs.map(idDoLog).filter(Boolean).map((i) => i.valor) : [];
    if (!ids.length) { alert('Não há logs para excluir.'); return; }
    if (!confirm(`Excluir TODOS os ${ids.length} logs?`)) return;
    const resultados = await Promise.all(ids.map((id) =>
      fetch(`${API_LOGS_BASE}/excluir/log/${encodeURIComponent(id)}/aluno/${encodeURIComponent(MATRICULA)}`)
        .then((r) => r.ok)
        .catch(() => false)));
    const falhas = resultados.filter((ok) => !ok).length;
    if (falhas) mostrarAlerta(`${falhas} log(s) não puderam ser excluídos.`);
    await exibirLogs();
  } catch (err) {
    console.error(err);
    mostrarAlerta('Não foi possível excluir os logs.');
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
  $('#lista-logs').addEventListener('click', (ev) => {
    const b = ev.target.closest('[data-id-log]');
    if (b && confirm(`Excluir o log #${b.dataset.idLog}?`)) deletarLog(b.dataset.idLog);
  });
  try {
    await carregarRegioes();
    await listarEstados();
  } catch (err) {
    console.error(err);
    mostrarAlerta('Falha ao conectar com a API do IBGE.');
  }
});

