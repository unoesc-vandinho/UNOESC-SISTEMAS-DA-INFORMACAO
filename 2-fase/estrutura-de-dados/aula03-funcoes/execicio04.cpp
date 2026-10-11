#include <stdio.h>

void popularVetor(int V[], int N)
{
    printf("Definindo os valores do Vetor\n");
    for (int i = 0; i < N; i++)
    {
        printf("Digite o proximo valor do vetor: ");
        scanf("%d", &V[i]); // Corrigido para i
    }
}

void buscarMaiorValor(int V[], int N, int R[])
{
    // Inicializa o maior valor com o primeiro elemento do vetor
    R[0] = V[0]; // R[0] guarda o maior VALOR
    R[1] = 0;    // R[1] guarda a POSIÇÃO (índice)

    for (int i = 1; i < N; i++) // Começa em 1 pois o 0 já foi testado
    {
        // Compara o elemento atual V[i] com o maior valor guardado R[0]
        if (V[i] > R[0])
        {
            R[0] = V[i]; // Atualiza o maior valor encontrado
            R[1] = i;    // Atualiza a posição dele
        }
    }
}

void main()
{
    int N = 5;
    int RES[2];
    int VET[N];

    popularVetor(VET, N);

    buscarMaiorValor(VET, N, RES);

    printf("Maior valor: %d\n", RES[0]);
    printf("Posicao: %d\n", RES[1]);
}
