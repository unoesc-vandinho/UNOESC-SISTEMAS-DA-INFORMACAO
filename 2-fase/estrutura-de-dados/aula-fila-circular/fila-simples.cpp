#ifndef FILA_SIMPLES_CPP
#define FILA_SIMPLES_CPP

#include <stdio.h>

/* ===========================================================
 * UNOESC - CHAPECÓ - 2024/1
 *
 * Disciplina: Estrutura de Dados
 * Professor: Prof. Dr. Thiago Zonta
 * Aluno: Vandoir, Eduardo
 *
 * Atividade - Fila Circular (baseada em vetor)
 * Esqueleto de codigo em C++ - ClasseFila
 *
 * Assim como fizemos com a ClasseLista e a ClassePilha, os dados
 * (Fila, I e F) ficam DENTRO do objeto (atributos privados), e
 * os metodos NAO precisam receber Fila/I/F por parametro - cada
 * metodo ja enxerga os atributos do proprio objeto que o chamou.
 *
 * Regras (lembrete da apostila):
 * - A fila tem tamanho fixo de 5 posicoes (TAMANHO) - pequeno
 *   de proposito, para que o "dar a volta" apareca logo.
 * - Proibido usar recursao.
 * - Use apenas o que ja vimos em aula: vetores, lacos (for/while)
 *   e if/else dentro dos metodos.
 * - Insere SEMPRE no fim (F) e remove SEMPRE do inicio (I) -
 *   nao existe "inserir/remover do meio" aqui.
 * - Fila CIRCULAR: quando I ou F estiver na ultima posicao
 *   (TAMANHO - 1) e precisar avancar, ele volta para 0.
 * - Os metodos abaixo devem seguir exatamente as assinaturas e
 *   o comportamento descritos nos comentarios.
 * =========================================================== */

#ifndef TAMANHO
#define TAMANHO 5
#endif

#ifndef TIPO_ELEMENTO
#define TIPO_ELEMENTO int
#endif

#ifndef FORMATO_ELEMENTO
#define FORMATO_ELEMENTO "%d"
#endif

class ClasseFila
{
private:
  /* Atributos: o vetor que guarda os valores, o indice I do
   * inicio (proximo a ser atendido) e o indice F do fim
   * (ultimo que entrou). Privados, assim como Lista/F e
   * Pilha/Topo - so podem ser acessados de dentro da classe.
   * Repare: e a primeira estrutura com DUAS variaveis de
   * controle, uma para cada extremidade. */
  TIPO_ELEMENTO Fila[TAMANHO];
  int I;
  int F;

public:
  /* -------------------------------------------------------
   * Construtor
   *
   * Roda automaticamente quando um objeto ClasseFila e
   * criado (ex: "ClasseFila fila;"). Sem essa instanciacao,
   * nenhum metodo abaixo poderia ser chamado - nao existiria
   * "fila" para chamar fila.Insere(...), por exemplo.
   *
   * Ja faz o papel do InicializaFila() da apostila.
   * ------------------------------------------------------- */
  ClasseFila()
  {
    I = -1;
    F = -1;
  }

  /* -------------------------------------------------------
   * FilaVazia
   * Entradas: nenhuma (usa o I do proprio objeto)
   * Retorno: 1 se a fila estiver vazia (I == -1), senao 0
   * ------------------------------------------------------- */
  int FilaVazia()
  {
    return I == -1;
  }

  /* -------------------------------------------------------
   * FilaCheia
   * Entradas: nenhuma (usa I e F do proprio objeto)
   * Retorno: 1 se a fila estiver cheia, senao 0
   *
   * A fila circular esta cheia quando a posicao SEGUINTE a F
   * (seguindo a regra do "avancar") e justamente o I:
   *   (F == TAMANHO - 1 e I == 0)  ou  (F + 1 == I)
   *
   * Lembrete: uma fila vazia (I == -1) nunca esta cheia -
   * use FilaVazia() antes de testar a condicao acima.
   * ------------------------------------------------------- */
  int FilaCheia()
  {
    if (FilaVazia())
    {
      return 0;
    }
    return (F == TAMANHO - 1 && I == 0) || (F + 1 == I);
  }

  /* -------------------------------------------------------
   * Insere (enfileirar)
   * Entradas: VALOR a inserir
   * Efeito: avanca F (dando a volta se F == TAMANHO - 1) e
   *         escreve VALOR na posicao F da Fila
   * Retorno: nada (void)
   *
   * Lembrete: use FilaCheia() antes de inserir. Se nao houver
   * espaco, nao insira nada (apenas avise o erro).
   * Se a fila estava vazia, o I tambem precisa mudar (de -1
   * para 0) - o primeiro que entra e tambem o primeiro da fila.
   * Repare que, diferente da ClasseLista, aqui NENHUM outro
   * elemento precisa ser deslocado.
   * ------------------------------------------------------- */
  void Insere(TIPO_ELEMENTO VALOR)
  {
    if (FilaCheia())
    {
      printf("Erro: fila cheia!\n");
      return;
    }

    if (FilaVazia())
    {
      I = 0;
      F = 0;
      Fila[F] = VALOR;
      return;
    }

    if (F == TAMANHO - 1)
    {
      F = 0;
    }
    else
    {
      F = F + 1;
    }
    Fila[F] = VALOR;
  }

  /* -------------------------------------------------------
   * Remove (desenfileirar)
   * Entradas: nenhuma
   * Efeito: le o valor da posicao I e avanca I (dando a volta
   *         se I == TAMANHO - 1)
   * Retorno: o VALOR que foi removido
   *
   * Lembrete: use FilaVazia() antes de remover. Se a fila
   * estiver vazia, nao remova nada (apenas avise o erro) -
   * defina o que a funcao retorna nesse caso.
   * Caso especial: se o elemento removido era o UNICO da fila
   * (I == F), a fila fica vazia - volte I e F para -1. Esse
   * teste deve vir ANTES de avancar o I.
   * Repare que, diferente do RemoverInicio da ClasseLista,
   * aqui NENHUM elemento se desloca: quem "anda" e o I.
   * ------------------------------------------------------- */
  TIPO_ELEMENTO Remove()
  {
    if (FilaVazia())
    {
      printf("Erro: fila vazia!\n");
      return (TIPO_ELEMENTO)-1;
    }

    TIPO_ELEMENTO valor = Fila[I];

    if (I == F)
    {
      I = -1;
      F = -1;
      return valor;
    }

    if (I == TAMANHO - 1)
    {
      I = 0;
    }
    else
    {
      I = I + 1;
    }
    return valor;
  }

  /* -------------------------------------------------------
   * InicioFila
   * Entradas: nenhuma
   * Efeito: nenhum - APENAS consulta, nao remove nada
   * Retorno: o VALOR que esta na posicao I (o proximo a ser
   *          atendido)
   *
   * Lembrete: use FilaVazia() antes de consultar. Se a fila
   * estiver vazia, nao ha inicio para retornar - defina o
   * que a funcao retorna nesse caso.
   * ------------------------------------------------------- */
  TIPO_ELEMENTO InicioFila()
  {
    if (FilaVazia())
    {
      printf("Erro: fila vazia!\n");
      return (TIPO_ELEMENTO)-1;
    }

    return Fila[I];
  }

  /* -------------------------------------------------------
   * MostrarFila
   * Entradas: nenhuma
   * Efeito: exibe na tela os valores da fila NA ORDEM DE
   *         ATENDIMENTO (do I ate o F) e, ao final, os
   *         valores de I e F
   * Retorno: nada (void)
   *
   * Lembrete: se a fila estiver vazia, exiba uma mensagem
   * adequada. Cuidado: na fila circular o F pode estar ANTES
   * do I no vetor (ex.: I = 3, F = 1) - por isso nao basta um
   * for de I ate F. Use um indice auxiliar que comeca em I,
   * imprime, e avanca pela mesma regra do "dar a volta", ate
   * imprimir a posicao F.
   * ------------------------------------------------------- */
  void MostrarFila()
  {
    if (FilaVazia())
    {
      printf("Fila vazia!\n");
      printf("I = %d | F = %d\n", I, F);
      return;
    }

    int aux = I;
    printf("Fila: ");

    while (1)
    {
      printf(FORMATO_ELEMENTO " ", Fila[aux]);
      if (aux == F)
      {
        break;
      }
      if (aux == TAMANHO - 1)
      {
        aux = 0;
      }
      else
      {
        aux = aux + 1;
      }
    }

    printf("\nI = %d | F = %d\n", I, F);
  }

  /* -------------------------------------------------------
   * Quantidade
   * Retorno: quantidade de elementos atualmente na fila
   * ------------------------------------------------------- */
  int Quantidade()
  {
    if (FilaVazia())
    {
      return 0;
    }
    if (I <= F)
    {
      return F - I + 1;
    }
    return (TAMANHO - I) + (F + 1);
  }
};

int main()
{
  /* Instanciação do objeto: aqui o construtor roda e
   * cria a fila vazia (I = -1, F = -1). */
  ClasseFila fila;

  printf("=====================================================\n");
  printf("         ROTEIRO DE TESTE OBRIGATORIO                \n");
  printf("=====================================================\n\n");

  printf("--- Passo 1: Inserir 10 ---\n");
  fila.Insere(10);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 2: Inserir 20 ---\n");
  fila.Insere(20);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 3: Inserir 30 ---\n");
  fila.Insere(30);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 4: Consultar inicio ---\n");
  printf("Inicio: %d\n", fila.InicioFila());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 5: Remover ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 6: Remover ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 7: Inserir 40 ---\n");
  fila.Insere(40);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 8: Inserir 50 ---\n");
  fila.Insere(50);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 9: Inserir 60 (F da a volta) ---\n");
  fila.Insere(60);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 10: Inserir 70 (Fila cheia) ---\n");
  fila.Insere(70);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 11: Inserir 80 (Erro: Fila cheia) ---\n");
  fila.Insere(80);
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 12: Remover (30) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 13: Remover (40) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 14: Remover 50 (I da a volta) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 15: Remover (60) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 16: Remover 70 (Fila fica vazia) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  printf("--- Passo 17: Remover (Erro: Fila vazia) ---\n");
  printf("Removido: %d\n", fila.Remove());
  fila.MostrarFila();
  printf("\n");

  return 0;
}

#endif
