async function consultarCep() {
  const sppiner = document.querySelector('.btn-loading');
  const btnLLabel = document.querySelector('.btn-label');
  const cepInput = document.querySelector('#cep').value.trim() || '';
  const cepFeedback = document.querySelector('#cep + div');
  try {

    btnLLabel.classList.add('d-none');
    sppiner.classList.remove('d-none');
    cepFeedback.textContent = 'Buscando endereço...';
    cepFeedback.className = 'text-primary small mt-1';

    if (cepInput.length < 8) {
      cepFeedback.textContent = 'Por favor, CEP informado é inválido.';
      cepFeedback.className = 'text-error small mt-1';
      return;
    }
    const response = await fetch(`https://viacep.com.br/ws/${cepInput}/json/`);
    console.log(response);
    if (!response.ok) throw new Error('CEP não localizado');
    const data = await response.json();

    document.querySelector('#resultados').innerHTML = '';
    writeRes(data);

    cepFeedback.textContent = 'Endereço preenchido automaticamente pela BrasilAPI!';
    cepFeedback.className = 'text-success small mt-1';
  } catch (err) {
    console.error(err);
    cepFeedback.textContent = 'CEP não encontrado ou fora de alcance. Por favor, preencha manualmente.';
    cepFeedback.className = 'text-warning small mt-1';
  }
  finally {
    sppiner.classList.add('d-none');
    btnLLabel.classList.remove('d-none');
  }
}

async function consultarRua() {
  const cepFeedback = document.querySelector('#statusReq');
  const sppiner = document.querySelector('.btn-loading');

  try {
    sppiner.classList.remove('d-none');
    const ufInput = document.querySelector('#uf').value || '';
    const cidadeInput = document.querySelector('#cidade').value || '';
    const partRuanInput = document.querySelector('#rua').value || '';

    cepFeedback.textContent = 'Buscando endereço...';
    cepFeedback.className = 'text-primary small mt-1';

    if (ufInput.length < 1 || cidadeInput.length < 4 || partRuanInput.length < 4) {
      cepFeedback.textContent = 'Por favor, preencha todos os campos.';
      cepFeedback.className = 'text-error small mt-1';
      return;
    }

    const response = await fetch(`https://viacep.com.br/ws/${ufInput}/${cidadeInput}/${partRuanInput}/json/`);
    if (!response.ok) throw new Error('CEP não localizado');
    const dataList = await response.json();

    document.querySelector('#resultados').innerHTML = ''
    for (const data of dataList) { writeRes(data); }

    cepFeedback.textContent = 'Endereço preenchido automaticamente pela BrasilAPI!';
    cepFeedback.className = 'text-success small mt-1';
  } catch (err) {
    console.error(err);
    cepFeedback.textContent = 'Endereço não encontrado ou fora de alcance. Por favor, preencha manualmente.';
    cepFeedback.className = 'text-warning small mt-1';
  }
  finally {
    sppiner.classList.add('d-none');
  }
}

function writeRes(data) {
  document.querySelector('#resultados').innerHTML += `<div class="col-12 col-lg-6">
        <article class="result-card h-100 p-3 bg-white">
          <div class="d-flex justify-content-between align-items-start mb-3">
            <h2 class="h5 mb-0">${data.bairro || ''}</h2>
            <span class="badge text-bg-success">${data.cep || ''}</span>
          </div>
          <div class="row">
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">Bairro</div>
              <div id="bairro">${data.bairro || ''}</div>
            </div>
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">Cidade</div>
              <div id="cidade">${data.localidade || ''}</div>
            </div>
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">UF</div>
              <div id="uf_">${data.uf || ''}           </div>
            </div>
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">Complemento</div>
              <div id="complemento">${data.complemento || ''}  </div>
            </div>
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">DDD</div>
              <div id="ddd"="">${data.ddd || ''}   </div>
            </div>
            <div class="col-6 col-md-4 mb-2">
              <div class="result-label">IBGE</div>
              <div id="ibge">${data.ibge || ''} </div>
            </div>
          </div>
        </article>
      </div>`
}



