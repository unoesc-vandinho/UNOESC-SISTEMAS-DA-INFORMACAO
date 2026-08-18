#include <stdio.h>

void popularVetor(int V[], int N)
{
    printf("Definindo os valores do Vetor\n");

    for (int i = 0; i < N; i++)
    {
        printf("Digite o proximo valor do vetor: ");
        scanf("%d", &V[1]);
    }
}

int buscarValor(int V[], int N, int valor)
{
    for (int i = 0; i < N; i++)
    {
        if (V[i] == valor)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int VET[5];
    int N = 5;
    int valor;

    popularVetor(VET, N);

    printf("O valor a ser encontrado: ");
    scanf("%d", valor);

    int res = buscarValor(VET, N, valor);
    printf("O valor encontrado foi:  %d", valor);
}