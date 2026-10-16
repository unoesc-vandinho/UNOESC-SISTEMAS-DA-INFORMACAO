#define TAMANHO 5
#include "fila-circular.cpp"

/* ===========================================================
 * UNOESC - CHAPECÓ - 2024/1
 *
 * Disciplina: Estrutura de Dados
 * Professor: Prof. Dr. Thiago Zonta
 * Alunos: Vandoir, Eduardo
 *
 * Arquivo 1: Roteiro de Teste Obrigatório
 * Importa a implementação pronta de "fila-circular.cpp"
 * =========================================================== */

int main()
{
    /* Instanciação do objeto: aqui o construtor roda e
     * cria a fila vazia (I = -1, F = -1). */
    ClasseFila fila;

    printf("=====================================================\n");
    printf("         ROTEIRO DE TESTE OBRIGATORIO                \n");
    printf("=====================================================\n\n");

    printf("--- Passo 1: Inserir 10 ---\n");
    fila.Insere(10);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 2: Inserir 20 ---\n");
    fila.Insere(20);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 3: Inserir 30 ---\n");
    fila.Insere(30);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 4: Consultar inicio ---\n");
    printf("Inicio: %d\n", fila.InicioFila());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 5: Remover ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 6: Remover ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 7: Inserir 40 ---\n");
    fila.Insere(40);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 8: Inserir 50 ---\n");
    fila.Insere(50);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 9: Inserir 60 (F da a volta) ---\n");
    fila.Insere(60);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 10: Inserir 70 (Fila cheia) ---\n");
    fila.Insere(70);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 11: Inserir 80 (Erro: Fila cheia) ---\n");
    fila.Insere(80);
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 12: Remover (30) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 13: Remover (40) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 14: Remover 50 (I da a volta) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 15: Remover (60) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 16: Remover 70 (Fila fica vazia) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    printf("--- Passo 17: Remover (Erro: Fila vazia) ---\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();
    printf("\n");

    return 0;
}
