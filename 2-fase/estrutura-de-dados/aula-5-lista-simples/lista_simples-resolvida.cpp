#include <stdio.h>

/* ===========================================================
 * Atividade - Lista Linear Sequencial (baseada em vetor)
 * Esqueleto de codigo em C++ - ClasseLista
 *
 * Assim como fizemos com a ClasseData, os dados (Lista e F)
 * ficam DENTRO do objeto (atributos privados), e os metodos
 * NAO precisam receber Lista/F por parametro - cada metodo ja
 * enxerga os atributos do proprio objeto que o chamou.
 *
 * Regras (lembrete da apostila):
 * - A lista tem tamanho fixo de 10 posicoes (TAMANHO).
 * - Proibido usar recursao.
 * - Use apenas o que ja vimos em aula: vetores, lacos (for/while)
 *   dentro dos metodos. Sem alocacao dinamica, sem bibliotecas
 *   alem de cstdio.
 * - Os metodos abaixo devem seguir exatamente as assinaturas e
 *   o comportamento descritos nos comentarios.
 * - O "main" ja esta pronto com o roteiro de teste obrigatorio -
 *   voce so precisa completar o corpo de cada metodo (onde esta
 *   escrito "TODO"). Nao altere as chamadas dentro do main.
 * =========================================================== */

#define TAMANHO 10

class ClasseLista
{
private:
    /* Atributos: o vetor que guarda os valores e o indice F do
     * ultimo elemento ocupado. Privados, assim como Dia/Mes/Ano
     * eram privados na ClasseData - so podem ser acessados de
     * dentro da propria classe. */
    int Lista[TAMANHO];
    int F; // Ultimo indice ocupado da lista

public:
    /* -------------------------------------------------------
     * Construtor
     *
     * Roda automaticamente quando um objeto ClasseLista e
     * criado (ex: "ClasseLista lista;"). Sem essa instanciacao,
     * nenhum metodo abaixo poderia ser chamado - nao existiria
     * "lista" para chamar lista.InserirFim(...), por exemplo.
     * ------------------------------------------------------- */
    ClasseLista()
    {
        F = -1;
    }

    /* -------------------------------------------------------
     * ListaVazia
     * Entradas: nenhuma (usa o F do proprio objeto)
     * Retorno: 1 se a lista estiver vazia (F == -1), senao 0
     *
     * TODO: implemente a verificacao acima.
     * ------------------------------------------------------- */
    int ListaVazia()
    {
        return F == -1 ? 1 : 0;
    }

    /* -------------------------------------------------------
     * ValidaInsercao
     * Entradas: nenhuma (usa o F do proprio objeto)
     * Retorno: 1 se ha espaço para inserir (F + 1 < TAMANHO),
     *          senao 0
     *
     * TODO: implemente a verificacao acima.
     * ------------------------------------------------------- */
    int ValidaInsercao()
    {
        return (F + 1 < TAMANHO) ? 1 : 0;
    }

    /* -------------------------------------------------------
     * ValidaLimite
     * Entradas: k
     * Retorno: 1 se 0 <= k <= F (posicao k existe na lista
     *          atual), senao 0
     *
     * TODO: implemente a verificacao acima.
     * ------------------------------------------------------- */
    int ValidaLimite(int k)
    {
        return (k >= 0 && k <= F) ? 1 : 0;
    }

    /* -------------------------------------------------------
     * InserirInicio
     * Entradas: VALOR a inserir
     * Efeito: insere VALOR no indice 0 da Lista do proprio
     *         objeto, deslocando os demais elementos uma
     *         posicao para a direita, e atualiza F
     *
     * Lembrete: use ValidaInsercao() antes de inserir. Se nao
     * houver espaco, nao insira nada.
     *
     * TODO: implemente o deslocamento e a insercao.
     * ------------------------------------------------------- */
    void InserirInicio(int VALOR)
    {
        if (F < 0)
        {
            Lista[0] = VALOR;
            F++;
        }
        else
            InserirKesimo(VALOR, 0);
    }

    /* -------------------------------------------------------
     * InserirFim
     * Entradas: VALOR a inserir
     * Efeito: insere VALOR no indice F + 1 (nao precisa
     *         deslocar nenhum elemento) e atualiza F
     *
     * Lembrete: use ValidaInsercao() antes de inserir.
     *
     * TODO: implemente a insercao.
     * ------------------------------------------------------- */
    void InserirFim(int VALOR)
    {
        if (!ValidaInsercao())
            throw " Lista cheia, nao e possivel inserir mais elementos.";

        F++;
        Lista[F] = VALOR;
    }

    /* -------------------------------------------------------
     * InserirKesimo
     * Entradas: VALOR a inserir, k (posicao alvo)
     * Efeito: insere VALOR no indice k, deslocando para a
     *         direita todos os elementos a partir de k
     *         (inclusive), e atualiza F
     *
     * Lembrete: use ValidaInsercao() e ValidaLimite(k) antes de
     * inserir (k pode ser igual a F + 1, ou seja, inserir logo
     * apos o ultimo elemento - trate esse caso tambem).
     *
     * TODO: implemente o deslocamento e a insercao.
     * ------------------------------------------------------- */
    void InserirKesimo(int VALOR, int k)
    {
        if (!ValidaInsercao() || !ValidaLimite(k))
            throw "Posicao invalida ou lista cheia, nao e possivel inserir.";

        for (int i = F; i >= k; i--)
            Lista[i + 1] = Lista[i];

        F++;
        Lista[k] = VALOR;
    }

    /* -------------------------------------------------------
     * RemoverInicio
     * Entradas: nenhuma
     * Efeito: remove o elemento do indice 0, deslocando os
     *         demais elementos uma posicao para a esquerda, e
     *         atualiza F
     * Retorno: o VALOR que foi removido
     *
     * Lembrete: use ListaVazia() antes de remover.
     *
     * TODO: implemente o deslocamento e a remocao.
     * ------------------------------------------------------- */
    int RemoverInicio()
    {
        if (ListaVazia())
            throw "Lista vazia, nao e possivel remover elementos.";

        int valorRemovido = Lista[0];

        for (int i = 0; i < F; i++)
            Lista[i] = Lista[i + 1];

        F--;
        return valorRemovido;
    }

    /* -------------------------------------------------------
     * RemoverFim
     * Entradas: nenhuma
     * Efeito: remove o elemento do indice F (nao precisa
     *         deslocar nenhum elemento) e atualiza F
     * Retorno: o VALOR que foi removido
     *
     * Lembrete: use ListaVazia() antes de remover.
     *
     * TODO: implemente a remocao.
     * ------------------------------------------------------- */
    int RemoverFim()
    {
        if (ListaVazia())
            throw "Lista vazia, nao e possivel remover elementos.";

        F--;
        return Lista[F];
    }

    /* -------------------------------------------------------
     * RemoverKesimo
     * Entradas: k (posicao alvo)
     * Efeito: remove o elemento do indice k, deslocando para a
     *         esquerda todos os elementos apos k, e atualiza F
     * Retorno: o VALOR que foi removido
     *
     * Lembrete: use ListaVazia() e ValidaLimite(k) antes de
     * remover. Se a posicao k nao existir na lista atual, nao
     * remova nada.
     *
     * TODO: implemente o deslocamento e a remocao.
     * ------------------------------------------------------- */
    int RemoverKesimo(int k)
    {
        if (ListaVazia() || !ValidaLimite(k))
            throw "Lista vazia, nao e possivel remover elementos.";

        int valorRemovido = Lista[k];

        for (int i = k; i < F; i++)
            Lista[i] = Lista[i + 1];

        F--;
        return valorRemovido;
    }

    /* -------------------------------------------------------
     * MostrarLista
     * Entradas: nenhuma
     * Efeito: exibe na tela os valores ocupados da Lista do
     *         proprio objeto, do indice 0 ate F
     * Retorno: nada (void)
     *
     * Lembrete: se a lista estiver vazia, exiba uma mensagem
     * adequada em vez de uma lista vazia entre colchetes.
     *
     * TODO: implemente a exibicao.
     * ------------------------------------------------------- */
    void MostrarLista()
    {
        if (ListaVazia())
        {
            printf("Lista vazia.\n");
            return;
        }

        printf("Lista: [");
        for (int i = 0; i <= F; i++)
            printf("%s%d", (i == 0) ? "" : ", ", Lista[i]);

        printf("]\n");
    }
};

/* ===========================================================
 * Programa principal - menu interativo
 *
 * Em vez de um roteiro de teste fixo, o programa apresenta um
 * menu de opcoes e repete a pergunta ate o usuario escolher
 * sair (opcao 0). Cada opcao chama um metodo do objeto "lista".
 *
 * NAO ALTERE a estrutura do menu abaixo. Complete apenas os
 * metodos da classe (onde esta escrito "TODO").
 *
 * Repare que nenhuma chamada precisa passar Lista ou F: o
 * objeto "lista" ja guarda esses dados internamente.
 * =========================================================== */
int main()
{
    /* Instanciacao do objeto: e aqui que o construtor roda e
     * cria a lista vazia. Sem esta linha, nao haveria "lista"
     * para chamar os metodos abaixo. */
    ClasseLista lista;
    int opcao;
    int valor;
    int k;
    int valorRemovido;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir na posicao k\n");
        printf("4 - Remover do inicio\n");
        printf("5 - Remover do fim\n");
        printf("6 - Remover da posicao k\n");
        printf("7 - Mostrar lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista.InserirInicio(valor);
            lista.MostrarLista();
        }
        else if (opcao == 2)
        {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista.InserirFim(valor);
            lista.MostrarLista();
        }
        else if (opcao == 3)
        {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            printf("Digite a posicao k: ");
            scanf("%d", &k);
            lista.InserirKesimo(valor, k);
            lista.MostrarLista();
        }
        else if (opcao == 4)
        {
            valorRemovido = lista.RemoverInicio();
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        }
        else if (opcao == 5)
        {
            valorRemovido = lista.RemoverFim();
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        }
        else if (opcao == 6)
        {
            printf("Digite a posicao k: ");
            scanf("%d", &k);
            valorRemovido = lista.RemoverKesimo(k);
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        }
        else if (opcao == 7)
        {
            lista.MostrarLista();
        }
        else if (opcao != 0)
        {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
