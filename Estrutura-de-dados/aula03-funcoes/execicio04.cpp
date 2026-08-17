#include <stdio.h>

void main(){
    int RES[2];
    int VET[5];
    int N = 5;

    popularVetor(VET, N);

    buscarMaiorValor(VET, N, RES);

    printf("Maior valor: %d\n", RES[0]);
    printf("Posicao: %d\n", RES[1]);

}

void popularVetor(int V[], int N){
    printf("Definindo os valores do Vetor\n");

    for (int i = 0; i < N; i++)
    {
        printf("Digite o proximo valor do vetor:\b");
        scanf("%d", &V[1]); 
    }
    
}

void buscarMaiorValor(int V[], int N, int R[]){   
    for (int i = 0; i < N; i++)
    {
        if(V[i] >= R[1]) {
            R[0] = i;
            R[1] = V[1];
        }

    }

}