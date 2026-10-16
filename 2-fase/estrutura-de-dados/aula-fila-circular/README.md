# Fila Circular (baseada em vetor)

## Informações da atividade

- Universidade: UNOESC - Chapecó
- Ano/Semestre: 2024/1
- Disciplina: Estrutura de Dados
- Professor: Prof. Dr. Thiago Zonta
- Aluno: Vandoir, Eduardo
- GitHub: [github.com/unoesc-vandinho](https://github.com/unoesc-vandinho/UNOESC-SISTEMAS-DA-INFORMACAO/tree/main/2-fase/estrutura-de-dados/aula-fila-circular)

## Objetivo

Implementar a estrutura de dados `Fila Circular` utilizando vetor, seguindo o modelo da `ClasseFila` em C++.

Assim como foi feito com a `ClasseLista` e a `ClassePilha`, os dados da fila (`Fila`, `I` e `F`) ficam dentro do objeto, como atributos privados. Os métodos não recebem esses valores como parâmetro, pois cada método já acessa os atributos do próprio objeto que o chamou.

## Regras da implementação

- A fila possui tamanho fixo de 5 posições (`TAMANHO`), de propósito pequeno para que o "dar a volta" apareça rapidamente.
- Não é permitido usar recursão.
- Use apenas o que foi visto em aula: vetores, laços (`for`/`while`) e `if/else` dentro dos métodos.
- Insere sempre no fim (`F`) e remove sempre no início (`I`).
- Não existe "inserir/remover do meio" nesta estrutura.
- A fila é circular: quando `I` ou `F` estiver na última posição (`TAMANHO - 1`) e precisar avançar, ele deve voltar para `0`.
- Os métodos devem seguir exatamente as assinaturas e o comportamento descritos no código de referência.

## Observação

A estrutura deve respeitar a lógica de fila circular, garantindo que os índices avancem corretamente e que a fila não seja acessada de forma inconsistente durante inserções e remoções.

```cpp
/*
 * Estrutura de dados: Fila Circular (baseada em vetor)
 * Esqueleto de código em C++ - ClasseFila
 */
```
