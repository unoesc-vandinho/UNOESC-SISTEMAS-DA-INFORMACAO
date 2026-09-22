#include <stdio.h>

/* ===========================================================
 * Atividade - Pilha Sequencial (baseada em vetor)
 * Esqueleto de codigo em C++ - ClassePilha
 *
 * Assim como fizemos com a ClasseLista, os dados (Pilha e Topo)
 * ficam DENTRO do objeto (atributos privados), e os metodos
 * NAO precisam receber Pilha/Topo por parametro - cada metodo
 * ja enxerga os atributos do proprio objeto que o chamou.
 *
 * Regras (lembrete da apostila):
 * - A pilha tem tamanho fixo de 10 posicoes (TAMANHO).
 * - Proibido usar recursao.
 * - Use apenas o que ja vimos em aula: vetores, lacos (for/while)
 *   dentro dos metodos. Sem alocacao dinamica, sem bibliotecas
 *   alem de cstdio.
 * - So se acessa o TOPO da pilha - nao existe "inserir/remover
 *   do meio" aqui (essa e a diferenca para a ClasseLista).
 * - Os metodos abaixo devem seguir exatamente as assinaturas e
 *   o comportamento descritos nos comentarios.
 * - O "main" ja esta pronto com o menu interativo - voce so
 *   precisa completar o corpo de cada metodo (onde esta escrito
 *   "TODO"). Nao altere as chamadas dentro do main.
 * =========================================================== */

#define TAMANHO 10

class ClassePilha {
private:
    /* Atributos: o vetor que guarda os valores e o indice Topo
     * do elemento do topo. Privados, assim como Lista/F eram
     * privados na ClasseLista - so podem ser acessados de
     * dentro da propria classe. */
    int Pilha[TAMANHO];
    int Topo;

public:
    /* -------------------------------------------------------
     * Construtor
     *
     * Roda automaticamente quando um objeto ClassePilha e
     * criado (ex: "ClassePilha pilha;"). Sem essa instanciacao,
     * nenhum metodo abaixo poderia ser chamado - nao existiria
     * "pilha" para chamar pilha.Empilha(...), por exemplo.
     *
     * Ja faz o papel do InicializaPilha() da apostila.
     * ------------------------------------------------------- */
    ClassePilha() {
        Topo = -1;
    }

    /* -------------------------------------------------------
     * PilhaVazia
     * Entradas: nenhuma (usa o Topo do proprio objeto)
     * Retorno: 1 se a pilha estiver vazia (Topo == -1), senao 0
     *
     * TODO: implemente a verificacao acima.
     * ------------------------------------------------------- */
    int PilhaVazia() {
        /* TODO: substitua a linha abaixo pela sua implementacao */
        return Topo == -1;
    }

    /* -------------------------------------------------------
     * PilhaCheia
     * Entradas: nenhuma (usa o Topo do proprio objeto)
     * Retorno: 1 se a pilha estiver cheia (Topo == TAMANHO - 1),
     *          senao 0
     *
     * TODO: implemente a verificacao acima.
     * ------------------------------------------------------- */
    int PilhaCheia() {
        /* TODO: substitua a linha abaixo pela sua implementacao */
        return Topo == TAMANHO - 1;
    }

    /* -------------------------------------------------------
     * Empilha (push)
     * Entradas: VALOR a inserir
     * Efeito: incrementa Topo em 1 e escreve VALOR na posicao
     *         Topo da Pilha do proprio objeto
     * Retorno: nada (void)
     *
     * Lembrete: use PilhaCheia() antes de empilhar. Se nao
     * houver espaco, nao insira nada (apenas avise o erro).
     * Repare que, diferente da ClasseLista, aqui NENHUM outro
     * elemento precisa ser deslocado.
     *
     * TODO: implemente a insercao.
     * ------------------------------------------------------- */
    void Empilha(int VALOR) {
        if(!PilhaCheia()){
            Topo += 1;
            Pilha[Topo] = VALOR;
        } 
    }

    /* -------------------------------------------------------
     * Desempilha (pop)
     * Entradas: nenhuma
     * Efeito: le o valor da posicao Topo e decrementa Topo em 1
     * Retorno: o VALOR que foi removido
     *
     * Lembrete: use PilhaVazia() antes de desempilhar. Se a
     * pilha estiver vazia, nao remova nada (apenas avise o
     * erro) - defina o que a funcao retorna nesse caso.
     * Repare que, diferente da ClasseLista, aqui NENHUM outro
     * elemento precisa ser deslocado.
     *
     * TODO: implemente a remocao.
     * ------------------------------------------------------- */
    int Desempilha() {
        if(PilhaVazia()) return -1;

        int pop = Pilha[Topo];
        Pilha[Topo] = 0;
        Topo -= 1;
        return pop;
    }

    /* -------------------------------------------------------
     * TopoPilha
     * Entradas: nenhuma
     * Efeito: nenhum - APENAS consulta, nao remove nada
     * Retorno: o VALOR que esta na posicao Topo
     *
     * Lembrete: use PilhaVazia() antes de consultar. Se a
     * pilha estiver vazia, nao ha topo para retornar - defina
     * o que a funcao retorna nesse caso.
     *
     * TODO: implemente a consulta.
     * ------------------------------------------------------- */
    int TopoPilha() {
        if(PilhaVazia()) return 0;
        
        return Pilha[Topo];
    }

    /* -------------------------------------------------------
     * MostrarPilha
     * Entradas: nenhuma
     * Efeito: exibe na tela os valores ocupados da Pilha do
     *         proprio objeto, do indice 0 ate Topo
     * Retorno: nada (void)
     *
     * Lembrete: se a pilha estiver vazia, exiba uma mensagem
     * adequada em vez de uma pilha vazia entre colchetes. Dica:
     * ao exibir, deixe claro qual elemento e o topo (ex.: uma
     * seta ou um texto ao lado do ultimo valor impresso).
     *
     * TODO: implemente a exibicao.
     * ------------------------------------------------------- */
    void MostrarPilha() {
        if(!PilhaVazia()){
             printf("A Pilha está vazia\n");
        }
        else{
            ClassePilha aux;

            while(PilhaVazia() == 0){
                int auxTopo = Topo;
                int valor = Desempilha();
                aux.Empilha(valor);
            };

            printf("Lista => [");
            while (!aux.PilhaVazia()) {
                int valor = aux.Desempilha();
                printf("%d, ", valor);
                Empilha(valor);
            };
                
            printf("]\n");
        }
    }
};

/* ===========================================================
 * Programa principal - menu interativo
 *
 * Em vez de um roteiro de teste fixo, o programa apresenta um
 * menu de opcoes e repete a pergunta ate o usuario escolher
 * sair (opcao 0). Cada opcao chama um metodo do objeto "pilha".
 *
 * NAO ALTERE a estrutura do menu abaixo. Complete apenas os
 * metodos da classe (onde esta escrito "TODO").
 *
 * Repare que nenhuma chamada precisa passar Pilha ou Topo: o
 * objeto "pilha" ja guarda esses dados internamente.
 * =========================================================== */
int main() {
    /* Instanciacao do objeto: e aqui que o construtor roda e
     * cria a pilha vazia (Topo = -1). Sem esta linha, nao
     * haveria "pilha" para chamar os metodos abaixo. */
    ClassePilha pilha;
    int opcao;
    int valor;
    int valorRemovido;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Consultar o topo (sem remover)\n");
        printf("4 - Mostrar pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            pilha.Empilha(valor);
            pilha.MostrarPilha();
        } else if (opcao == 2) {
            valorRemovido = pilha.Desempilha();
            printf("Valor desempilhado: %d\n", valorRemovido);
            pilha.MostrarPilha();
        } else if (opcao == 3) {
            printf("Valor do topo: %d\n", pilha.TopoPilha());
        } else if (opcao == 4) {
            pilha.MostrarPilha();
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
