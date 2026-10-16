#define TAMANHO 60
#define TIPO_ELEMENTO char
#define FORMATO_ELEMENTO "%c"
#include "fila-circular.cpp"

/* ===========================================================
 * UNOESC - CHAPECÓ - 2024/1
 *
 * Disciplina: Estrutura de Dados
 * Professor: Prof. Dr. Thiago Zonta
 * Alunos: Vandoir, Eduardo
 *
 * Arquivo 2: Desafio do Item 5 - Jogando Cartas Coloridas Fora
 * (Inspirado no problema 1110 do beecrowd e no jogo UNO)
 *
 * Importa a ClasseFila configurada com TIPO_ELEMENTO char de "fila-circular.cpp"
 *
 * Regras da dinâmica:
 * - Monte inicial com n cartas (2 <= n <= 50).
 * - Enquanto houver 2 ou mais cartas no monte:
 *     1. A carta do topo é jogada fora (vai para o descarte).
 *     2. Dependendo da carta descartada:
 *        - Carta numérica ('0' a '9'): 1 carta do topo vai para a base.
 *        - Pular ('P'): 2 cartas do topo vão para a base.
 *        - Coringa ('C'): 0 cartas vão para a base.
 * =========================================================== */

void processarCasoCartasColoridas(int n, const char cartas[])
{
    // A ClasseFila trabalha diretamente com char
    ClasseFila monte;
    char descartadas[60];
    int qtdDescartadas = 0;

    // 1. Insere as n cartas diretamente como char
    for (int i = 0; i < n; i++)
    {
        monte.Insere(cartas[i]);
    }

    // 2. Simula o jogo enquanto houver 2 ou mais cartas
    while (monte.Quantidade() >= 2)
    {
        // Passo A: A carta do topo é descartada (retorna char nativo)
        char descartada = monte.Remove();
        descartadas[qtdDescartadas] = descartada;
        qtdDescartadas = qtdDescartadas + 1;

        // Passo B: Define quantas cartas do topo vão para a base
        int moverParaBase = 0;
        if (descartada >= '0' && descartada <= '9')
        {
            moverParaBase = 1;
        }
        else if (descartada == 'P' || descartada == 'p')
        {
            moverParaBase = 2;
        }
        else if (descartada == 'C' || descartada == 'c')
        {
            moverParaBase = 0;
        }

        // Passo C: Move as cartas do topo para a base (uma a uma)
        for (int k = 0; k < moverParaBase; k++)
        {
            if (!monte.FilaVazia())
            {
                char cartaMover = monte.Remove();
                monte.Insere(cartaMover);
            }
        }
    }

    // 3. Exibe as cartas descartadas na ordem
    printf("Cartas descartadas: ");
    for (int i = 0; i < qtdDescartadas; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%c", descartadas[i]);
    }
    printf("\n");

    // 4. Exibe a carta que restou (retorna char nativo)
    printf("Carta restante: %c\n", monte.InicioFila());
}

int main()
{
    printf("=====================================================\n");
    printf("   DESAFIO ITEM 5 - JOGANDO CARTAS COLORIDAS FORA    \n");
    printf("=====================================================\n\n");

    printf(">>> EXECUTANDO CASOS DE TESTE DO ENUNCIADO <<<\n\n");

    printf("--- Exemplo 1: n = 7 [1 2 3 4 5 6 7] ---\n");
    char e1[] = {'1', '2', '3', '4', '5', '6', '7'};
    processarCasoCartasColoridas(7, e1);
    printf("\n");

    printf("--- Exemplo 2: n = 8 [3 P 7 C 0 P 2 9] ---\n");
    char e2[] = {'3', 'P', '7', 'C', '0', 'P', '2', '9'};
    processarCasoCartasColoridas(8, e2);
    printf("\n");

    printf("--- Exemplo 3: n = 6 [C 4 C 8 P 1] ---\n");
    char e3[] = {'C', '4', 'C', '8', 'P', '1'};
    processarCasoCartasColoridas(6, e3);
    printf("\n");

    printf("--- Exemplo 4: n = 2 [P 3] ---\n");
    char e4[] = {'P', '3'};
    processarCasoCartasColoridas(2, e4);
    printf("\n");

    printf("=====================================================\n");
    printf("Deseja testar casos manuais? (1 - Sim / 0 - Sair): ");
    int opcao = 0;
    if (scanf("%d", &opcao) == 1 && opcao == 1)
    {
        int n;
        printf("\nDigite n (2 a 50) e em seguida as cartas (0 para sair):\n");
        while (scanf("%d", &n) == 1 && n != 0)
        {
            char cartas[60];
            for (int i = 0; i < n; i++)
            {
                scanf(" %c", &cartas[i]);
            }
            processarCasoCartasColoridas(n, cartas);
            printf("\nDigite o proximo n (ou 0 para sair): ");
        }
    }

    return 0;
}
