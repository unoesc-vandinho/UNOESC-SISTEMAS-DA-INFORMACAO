#include <stdio.h>
#include <stdlib.h>

void initVector(int V[10])
{
    /* Inicializa todas as posições como livres */
    for (int i = 0; i < 10; i++)
    {
        V[i] = 0;
    }
}

void adicionnarProduto(int Produto[10], int Ocupado[10], int codigo)
{
    /* ===========================
      ARMAZENAR PRODUTO
   =========================== */

    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < 10; i++)
    {
        if (Produto[i] == 0)
        {
            Produto[i] = codigo;
            Ocupado[i] = 1;

            printf("Produto armazenado na prateleira %d.\n", i);
            return;
        }
    }

    printf("Deposito cheio.\n");
}

void adicionarEndereco(int Produto[10], int Ocupado[10], int codigo, int posicao)
{
    /* ===========================
   INSERIR ENDERECO ESPECIFICO
=========================== */

    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("Entre com a prateleira desejada: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao > 9)
        printf("Prateleira incorreta.\n");
    else if (Ocupado[posicao] == 1)
        printf("Prateleira ja esta em uso.\n");
    else
    {
        Ocupado[posicao] = 1;
        Produto[posicao] = codigo;
        printf("Produto armazenado na prateleira %d.\n", posicao);
    }
}

void removerProduto(int Produto[10], int Ocupado[10], int codigo)
{
    /* ===========================
       REMOVER PRODUTO
    =========================== */

    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    for (i = 0; i < 10; i++)
    {
        if (Ocupado[i] == 1)
        {
            if (Produto[i] == codigo)
            {
                Ocupado[i] = 0;

                printf("Produto removido com sucesso.\n");

                return;
            }
        }
    }

    printf("Produto nao encontrado.\n");
}

void localizarProduto(int Produto[10], int Ocupado[10], int codigo)
{
    /* ===========================
       LOCALIZAR PRODUTO
    =========================== */
    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    for (i = 0; i < 10; i++)
    {
        if (Ocupado[i] == 1)
        {
            if (Produto[i] == codigo)
            {
                printf("Produto encontrado na prateleira %d.\n", i);
                return;
            }
        }
    }

    printf("Produto nao encontrado ou ja removido.\n");
}

int main()
{
    int produto[10];
    int ocupado[10];

    int i;
    int opcao;
    int codigo;
    int encontrou;
    int posicao;

    initVector(produto);
    initVector(ocupado);

    while (1)
    {
        system("clear");
        printf("\n=============================\n");
        printf("      CONTROLE DE ESTOQUE\n");
        printf("=============================\n");
        printf("1 - Armazenar produto\n");
        printf("2 - Armazenar produto em endereco especifico\n");
        printf("3 - Remover produto\n");
        printf("4 - Localizar produto\n");
        printf("5 - Gerar rota de reposicao\n");
        printf("6 - Gerar rota de coleta\n");
        printf("7 - Mostrar mapa completo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        ;

        if (opcao == 0)
        {
            break;
        }
        else if (opcao == 1)
        {
            adicionnarProduto(produto, ocupado, codigo);
        }
        else if (opcao == 2)
        {
            adicionarEndereco(produto, ocupado, codigo, posicao);
        }
        else if (opcao == 3)
        {
            removerProduto(produto, ocupado, codigo);
        }

        /* ===========================
           LOCALIZAR PRODUTO
        =========================== */
        else if (opcao == 4)
        {
            localizarProduto(produto, ocupado, codigo);
        }

        /* ===========================
           GERAR ROTA DE REPOSICAO
        =========================== */
        else if (opcao == 5)
        {
            encontrou = 0;

            printf("\nPrateleiras disponiveis para reposicao:\n");

            for (i = 0; i < 10; i++)
            {
                if (ocupado[i] == 0)
                {
                    printf("%d\n", i);
                    encontrou = 1;
                }
            }

            if (encontrou == 0)
            {
                printf("Nao ha prateleiras disponiveis para reposicao.\n");
            }
        }

        /* ===========================
           GERAR ROTA DE COLETA
        =========================== */
        else if (opcao == 6)
        {
            encontrou = 0;

            printf("\nRota de coleta:\n");

            for (i = 0; i < 10; i++)
            {
                if (ocupado[i] == 1)
                {
                    printf("Prateleira %d -> Produto %d\n", i, produto[i]);
                    encontrou = 1;
                }
            }

            if (encontrou == 0)
            {
                printf("Nenhum produto disponivel para coleta.\n");
            }
        }

        /* ===========================
           MAPA COMPLETO
        =========================== */
        else if (opcao == 7)
        {
            printf("\nEndereco | Produto | Situacao\n");

            for (i = 0; i < 10; i++)
            {
                if (ocupado[i] == 1)
                {
                    printf("%8d | %7d | Ocupada\n", i, produto[i]);
                }
                else
                {
                    printf("%8d |     --- | Livre\n", i);
                }
            }
        }
        printf("Digite Enter para continuar...");
        getchar();
        getchar();
    }
    return 0;
}
