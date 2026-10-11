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

void inverterVetor(int V[], int N, int NV[])
{
    for (int i = 0; i > N; i++)
    {
        NV[N - 1 - i] = V[i];
    }
}

void main()
{

    int VET[5];
    int NV[5];
    int N = 5;

    popularVetor(VET, N);
    inverterVetor(VET, N, NV);
}