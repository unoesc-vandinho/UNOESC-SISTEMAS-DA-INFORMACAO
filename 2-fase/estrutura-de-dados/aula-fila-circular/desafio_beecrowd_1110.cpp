#define TAMANHO 60
#include "fila-circular.cpp"

/* ===========================================================
 * UNOESC - CHAPECÓ - 2024/1
 *
 * Disciplina: Estrutura de Dados
 * Professor: Prof. Dr. Thiago Zonta
 * Alunos: Vandoir, Eduardo
 *
 * Arquivo 3: Desafio Beecrowd 1110 - Jogando Cartas Fora
 * (Problema de Fila Circular)
 *
 * Importa a ClasseFila pronta de "fila-circular.cpp"
 *
 * Regras:
 * - Monte com n cartas numeradas de 1 até n (1 <= n <= 50).
 * - A carta 1 está no topo e a carta n está na base.
 * - Enquanto houver pelo menos 2 cartas:
 *     1. A carta do topo é descartada.
 *     2. A próxima carta do topo é movida para a base.
 * =========================================================== */

void processarCaso1110(int n)
{
    ClasseFila fila;
    int descartadas[60];
    int qtdDescartadas = 0;

    // 1. Insere as cartas de 1 até n
    for (int i = 1; i <= n; i++)
    {
        fila.Insere(i);
    }

    // 2. Enquanto houver 2 ou mais cartas
    while (fila.Quantidade() >= 2)
    {
        // Descarta o topo
        int descartada = fila.Remove();
        descartadas[qtdDescartadas] = descartada;
        qtdDescartadas = qtdDescartadas + 1;

        // Move o novo topo para a base
        int cartaMover = fila.Remove();
        fila.Insere(cartaMover);
    }

    // 3. Exibe as cartas descartadas
    printf("Discarded cards:");
    for (int i = 0; i < qtdDescartadas; i++)
    {
        if (i == 0)
        {
            printf(" %d", descartadas[i]);
        }
        else
        {
            printf(", %d", descartadas[i]);
        }
    }
    printf("\n");

    // 4. Exibe a carta restante
    printf("Remaining card: %d\n", fila.InicioFila());
}

int main()
{
    printf("=====================================================\n");
    printf("       DESAFIO BEECROWD 1110 - JOGANDO CARTAS FORA   \n");
    printf("=====================================================\n\n");

    printf(">>> EXECUTANDO CASOS DE TESTE DE EXEMPLO <<<\n\n");

    printf("--- Caso 1: n = 7 ---\n");
    processarCaso1110(7);
    printf("\n");

    printf("--- Caso 2: n = 19 ---\n");
    processarCaso1110(19);
    printf("\n");

    printf("--- Caso 3: n = 10 ---\n");
    processarCaso1110(10);
    printf("\n");

    printf("--- Caso 4: n = 6 ---\n");
    processarCaso1110(6);
    printf("\n");

    printf("=====================================================\n");
    printf("Deseja testar casos manuais? (1 - Sim / 0 - Sair): ");
    int opcao = 0;
    if (scanf("%d", &opcao) == 1 && opcao == 1)
    {
        int n;
        printf("\nDigite n (1 a 50, digite 0 para encerrar):\n");
        while (scanf("%d", &n) == 1 && n != 0)
        {
            processarCaso1110(n);
            printf("\nDigite o proximo n (ou 0 para sair): ");
        }
    }

    return 0;
}
