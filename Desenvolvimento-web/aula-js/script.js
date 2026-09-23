import MENU from './menu.json' with { type: 'json' }

document.addEventListener('DOMContentLoaded', ()=>{
  const table = document.querySelector('#cardapio-tbody')
  for (const item of MENU) {
    table.insertAdjacentHTML('beforeend', `<tr>
      <td>${item.codigo}</td>
      <td>${item.nome}</td>
      <td>${item.preco.toFixed(2).toString().replaceAll('.', ',')}</td>
    </tr>`)
  }
})

function calcularIdade(){
  const yearBirth = +document.querySelector('#year').value
  const yearNow = new Date().getFullYear()
  document.querySelector('#idade').textContent = Math.abs(yearNow - yearBirth)
}

function calcularSalario(){
  const SALARIO_MINIMO = 1621
  const salario = +document.querySelector('#salario').value
  const aumento = salario > SALARIO_MINIMO ? (salario * 8) / 100 : (salario * 15) / 100
  document.querySelector('#novoSalario').textContent = salario + aumento
}

function maiorIdade(){
  const yearOld = +document.querySelector('[name="idade"]').value
  const mensagem = yearOld > 17 ? "Você é maior de idade" : "Você é menor de idade"
  document.querySelector('#maiorMenor').textContent = mensagem
}

function calcularNotaFinal(){
  const notas = Array.from(document.querySelectorAll('[name^="nota"]')).map(nota => +nota.value)
  const media = notas.reduce((soma, nota) => soma + nota, 0) / notas.length
  document.querySelector('#media').textContent = media.toFixed(2)
}

function calcularTotalPedido(){
   const quantidade = +document.querySelector('#quantidade').value
   const sortItem = Math.floor(Math.random() * MENU.length)
   const item  = MENU[sortItem]
   const total = (item.preco * quantidade).toFixed(2)
   const mensagem = `O Pedido de ${quantidade} ${item.nome} deu um total de: ${total}`
   document.querySelector('#preco').textContent = mensagem
}

Object.assign(window, { calcularIdade, calcularSalario, maiorIdade, calcularNotaFinal, calcularTotalPedido })
