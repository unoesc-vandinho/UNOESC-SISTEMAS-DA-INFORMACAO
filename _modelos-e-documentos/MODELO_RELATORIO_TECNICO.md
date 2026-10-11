<style>
  body {
    font-family: Arial, "Helvetica Neue", Helvetica, sans-serif;
    font-size: 12pt;
    line-height: 1.5;
    text-align: justify;
    color: #222222;
  }
  h1, h2, h3, h4 {
    color: #1E4679;
    font-weight: bold;
  }
  h1 {
    border-bottom: 2px solid #1E4679;
    padding-bottom: 4px;
    margin-top: 24px;
  }
  .capa {
    text-align: center;
    page-break-after: always;
  }
  .instituicao {
    font-size: 14pt;
    font-weight: bold;
    color: #1E4679;
    text-transform: uppercase;
  }
  .sub-instituicao {
    font-size: 11pt;
    color: #555555;
  }
  .titulo-trabalho {
    font-size: 18pt;
    font-weight: bold;
    color: #1E4679;
    margin-top: 80px;
    margin-bottom: 10px;
  }
  .subtitulo-trabalho {
    font-size: 13pt;
    color: #333333;
  }
  .autores {
    margin-top: 80px;
    font-size: 12pt;
  }
  .rodape-capa {
    margin-top: 100px;
    font-size: 11pt;
  }
  .caixa-destaque {
    background-color: #F4F6F9;
    border-left: 4px solid #1E4679;
    padding: 12px 16px;
    margin: 15px 0;
    border-radius: 4px;
  }
  table {
    width: 100%;
    border-collapse: collapse;
    margin: 15px 0;
  }
  th {
    background-color: #1E4679;
    color: #ffffff;
    font-weight: bold;
    padding: 8px;
    text-align: left;
  }
  td {
    border-bottom: 1px solid #dddddd;
    padding: 8px;
  }
  code {
    background-color: #f4f4f4;
    padding: 2px 4px;
    border-radius: 4px;
    font-family: Consolas, "Courier New", monospace;
  }
</style>

<div class="capa">
  <div class="instituicao">Universidade do Oeste de Santa Catarina</div>
  <div class="sub-instituicao">Campus Chapecó · Curso de Sistemas de Informação</div>
  <div class="sub-instituicao">25830 · Introdução ao Hardware / Arquitetura de Hardware</div>

  <div class="titulo-trabalho">RELATÓRIO TÉCNICO</div>
  <div class="subtitulo-trabalho"><strong><<Nome do Projeto>></strong></div>
  <div class="subtitulo-trabalho">Projeto Prático — Sensor + Atuador com Arduino/ESP32</div>
  <div class="subtitulo-trabalho"><em>Atividade Avaliativa</em></div>

  <div class="autores">
    <strong>Integrantes:</strong><br>
    <<Nome completo do integrante 1>><br>
    <<Nome completo do integrante 2>><br>
    <<Nome completo do integrante 3>><br>
    <<Nome completo do integrante 4>>
  </div>

  <div class="rodape-capa">
    <strong>Professor:</strong> Jacson Luiz Matte<br>
    Chapecó - SC, <<Mês>> de 2026
  </div>
</div>

---

## Resumo

<div style="text-align: justify;">
<<Em até 8 linhas: qual problema o projeto resolve, quais sensores e atuadores foram usados, qual placa (Arduino Uno ou ESP32) e qual foi o resultado. Escreva por último, quando tudo estiver pronto.>>
</div>

<div class="caixa-destaque">
  🔗 <strong>Vídeo demonstrativo:</strong> <a href="https://<<link-do-video>>">https://<<link-do-video>></a><br>
  💻 <strong>Código-fonte completo:</strong> <a href="https://<<link-do-repositorio>>">https://<<link-do-repositorio>></a><br>
  ⚡ <strong>Circuito no Tinkercad:</strong> <a href="https://www.tinkercad.com/things/<<id>>">https://www.tinkercad.com/things/<<id>></a>
</div>

---

## 1. Introdução e Problema

<div style="text-align: justify;">
<<Que situação do dia a dia o projeto ataca? Quem seria o usuário? Por que um sensor e um atuador resolvem isso? Termine com o objetivo do projeto em uma frase clara e objetiva.>>
</div>

---

## 2. Pesquisa: Projetos de Referência

<div style="text-align: justify;">
<<Liste de 2 a 4 projetos encontrados na internet que inspiraram a solução. Para cada um: o que ele faz, o que foi aproveitado e o que decidiram fazer de forma diferente. Cite as fontes na seção de Referências.>>
</div>

---

## 3. Componentes Utilizados

| Componente | Função no Projeto | Pino(s) | Qtde |
| :--- | :--- | :---: | :---: |
| Arduino Uno / ESP32 | Placa controladora principal | -- | 1 |
| <<Sensor>> | <<O que ele mede>> | `A0` | 1 |
| <<Atuador (ex: LED / Buzzer / Relé)>> | <<Ação executada>> | `9` | 1 |
| <<Resistor 220 $\Omega$>> | <<Limita corrente>> | -- | 1 |

---

## 4. Diagrama do Circuito

<div style="text-align: justify;">
<<Insira a imagem do circuito: captura do Tinkercad ou diagrama de ligações esquemático. Todas as conexões do código precisam estar visíveis e com identificação legível dos pinos.>>
</div>

<p align="center">
  <img src="./diagrama.png" alt="Diagrama de Ligações do Projeto" width="650">
  <br>
  <em>Figura 1: Diagrama de ligações e pinagem do circuito.</em>
</p>

---

## 5. Funcionamento do Sistema

<div style="text-align: justify;">
<<Descreva o comportamento do sistema passo a passo em formato de sequência lógica: o que o sensor lê, qual decisão a lógica do código toma e qual ação o atuador executa.>>
</div>

---

## 6. Código-Fonte: Trechos Relevantes

<div style="text-align: justify;">
<<Destaque apenas os 2 ou 3 blocos principais de código responsáveis pela lógica central (leitura analógica/digital, regra de tomada de decisão, acionamento do atuador) acompanhados de uma breve explicação textual.>>
</div>

```cpp
// Leitura do sensor e regra de decisão
void loop() {
  int leitura = analogRead(A0);
  
  if (leitura < LIMIAR) {
    digitalWrite(PIN_ATUADOR, HIGH); // Ativa o atuador
  } else {
    digitalWrite(PIN_ATUADOR, LOW);  // Desativa o atuador
  }
  
  delay(200); // Intervalo de estabilização
}
```

---

## 7. Testes e Ajustes Realizados

<div style="text-align: justify;">
<<Relate o que foi testado no protótipo, eventuais falhas encontradas e os ajustes realizados em hardware ou software (como ajuste de sensibilidade/limiar, calibração ou tempos).>>
</div>

| Teste Realizado | Resultado Esperado | Resultado Obtido / Ajuste |
| :--- | :--- | :--- |
| <<Cobrir o sensor LDR>> | <<Acionar LED de alerta>> | <<OK / Calibrado limiar para 380>> |
| <<Remover obstáculo>> | <<Desligar LED>> | <<OK>> |

---

## 8. Resultados, Limitações e Melhorias Futuras

<div style="text-align: justify;">
<<O projeto cumpriu todos os objetivos propostos? Quais limitações técnicas foram identificadas? O que a equipe implementaria em uma próxima versão ou se tivesse mais tempo de desenvolvimento?>>
</div>

---

## 9. Divisão de Responsabilidades

| Integrante | Responsabilidades no Projeto |
| :--- | :--- |
| <<Nome do Integrante 1>> | <<Pesquisa teórica, proposta e montagem do circuito físico>> |
| <<Nome do Integrante 2>> | <<Programação da leitura dos sensores e testes de bancada>> |
| <<Nome do Integrante 3>> | <<Programação dos atuadores, gravação e edição do vídeo>> |
| <<Nome do Integrante 4>> | <<Elaboração do relatório técnico e apresentação final>> |

---

## 10. Referências

1. <<AUTOR. **Título do projeto de referência**. Nome do Site, ano. Disponível em: &lt;URL&gt;. Acesso em: dd mmm. aaaa.>>
2. ARDUINO. **Language Reference**. Disponível em: <https://www.arduino.cc/reference>. Acesso em: 10 out. 2026.
3. <<Datasheets dos componentes e sensores utilizados no projeto.>>
