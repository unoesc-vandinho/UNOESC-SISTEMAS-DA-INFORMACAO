---
title: "<<Nome do Projeto>>"
subtitle: "Projeto Prático — Sensor + Atuador com Arduino/ESP32"
activity: "Atividade Avaliativa III"
institution: "UNIVERSIDADE DO OESTE DE SANTA CATARINA"
campus: "Campus Chapecó · Curso de Sistemas de Informação"
course: "25830 · Introdução ao Hardware / Arquitetura de Hardware"
professor: "Jacson Luiz Matte"
date: "Chapecó - SC, 2026"
author:
  - "<<Nome completo do integrante 1>>"
  - "<<Nome completo do integrante 2>>"
  - "<<Nome completo do integrante 3>>"
  - "<<Nome completo do integrante 4>>"
toc: true
---

# Resumo

> <<Em até 8 linhas: qual problema o projeto resolve, quais sensores e atuadores foram usados, qual placa (Arduino Uno ou ESP32) e qual foi o resultado. Escreva por último, quando tudo estiver pronto.>>

- **Vídeo demonstrativo:** https://<<link-do-video>>
- **Código-fonte completo:** https://<<link-do-repositorio>>
- **Circuito no Tinkercad:** https://www.tinkercad.com/things/<<id>>

# 1. Introdução e Problema

<<Que situação do dia a dia o projeto ataca? Quem seria o usuário? Por que um sensor e um atuador resolvem isso? Termine com o objetivo do projeto em uma frase clara e objetiva.>>

# 2. Pesquisa: Projetos de Referência

<<Liste de 2 a 4 projetos encontrados na internet que inspiraram a solução. Para cada um: o que ele faz, o que foi aproveitado e o que decidiram fazer de forma diferente. Cite as fontes na seção de Referências.>>

# 3. Componentes Utilizados

| Componente | Função no Projeto | Pino(s) | Qtde |
| :--- | :--- | :---: | :---: |
| Arduino Uno / ESP32 | Placa controladora principal | -- | 1 |
| <<Sensor>> | <<O que ele mede>> | `A0` | 1 |
| <<Atuador (LED / Buzzer / Relé)>> | <<Ação executada>> | `9` | 1 |
| <<Resistor 220 $\Omega$>> | <<Limita corrente>> | -- | 1 |

# 4. Diagrama do Circuito

<<Insira a imagem do circuito: captura do Tinkercad ou diagrama de ligações esquemático. Todas as conexões do código precisam estar visíveis e com identificação legível dos pinos.>>

![Diagrama de Ligações do Projeto](./diagrama.png)

# 5. Funcionamento do Sistema

<<Descreva o comportamento do sistema passo a passo em formato de sequência lógica: o que o sensor lê, qual decisão a lógica do código toma e qual ação o atuador executa.>>

# 6. Código-Fonte: Trechos Relevantes

<<Destaque apenas os 2 ou 3 blocos principais de código responsáveis pela lógica central acompanhados de uma breve explicação.>>

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

# 7. Testes e Ajustes Realizados

<<Relate o que foi testado no protótipo, eventuais falhas encontradas e os ajustes realizados em hardware ou software (calibração de limiar, tempos).>>

| Teste Realizado | Resultado Esperado | Resultado Obtido / Ajuste |
| :--- | :--- | :--- |
| <<Cobrir o sensor LDR>> | <<Acionar LED de alerta>> | <<OK / Calibrado limiar para 380>> |
| <<Remover obstáculo>> | <<Desligar LED>> | <<OK>> |

# 8. Resultados, Limitações e Melhorias Futuras

<<O projeto cumpriu todos os objetivos propostos? Quais limitações técnicas foram identificadas? O que a equipe implementaria em uma próxima versão?>>

# 9. Divisão de Responsabilidades

| Integrante | Responsabilidades no Projeto |
| :--- | :--- |
| <<Nome do Integrante 1>> | <<Pesquisa teórica, proposta e montagem do circuito físico>> |
| <<Nome do Integrante 2>> | <<Programação da leitura dos sensores e testes de bancada>> |
| <<Nome do Integrante 3>> | <<Programação dos atuadores, gravação e edição do vídeo>> |
| <<Nome do Integrante 4>> | <<Elaboração do relatório técnico e apresentação final>> |

# 10. Referências

1. <<AUTOR. **Título do projeto de referência**. Nome do Site, ano. Disponível em: <URL>. Acesso em: dd mmm. aaaa.>>
2. ARDUINO. **Language Reference**. Disponível em: <https://www.arduino.cc/reference>. Acesso em: 10 out. 2026.
3. <<Datasheets dos componentes e sensores utilizados no projeto.>>
