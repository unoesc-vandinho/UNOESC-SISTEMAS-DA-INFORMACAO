#include <stdio.h>

void CadastrarVetor(int V[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &V[i]);
    }
}

void MostrarVetor(int V[], int N)
{
    printf("Vetor [");
    for (int i = 0; i < N; i++)
    {
        printf(", %d", V[i]);
    }
    printf("]")
}

int AlterarVetor(int V[], int N, int procurado, int novo)
{
    int alteracoes = 0;

    for (int i = 0; i < N; i++)
    {
        if (V[i] == procurado)
        {
            V[i] = novo;
            alteracoes++;
        }
    }

    return alteracoes;
}

int main()
{
    int V[10];
    int N = 10;
    int procurado;
    int novo;
    int alteracoes;

    CadastrarVetor(V, N);

    printf("\nVetor cadastrado:\n");
    MostrarVetor(V, N);

    printf("\nDigite o valor a ser procurado: ");
    scanf("%d", &procurado);

    printf("Digite o novo valor: ");
    scanf("%d", &novo);

    alteracoes = AlterarVetor(V, N, procurado, novo);

    if (alteracoes > 0)
    {
        printf("\nForam alteradas %d posicoes.\n", alteracoes);
    }
    else
    {
        printf("\nO valor nao foi encontrado. Nenhuma posicao foi alterada.\n");
    }

    printf("\nVetor após a alteracao:\n");
    MostrarVetor(V, N);

    return 0;
}