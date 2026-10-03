#include <stdio.h>

/* ---------------------------------------------------------
 * TAD Data
 * Representa uma data (Dia, Mes, Ano) e expõe as operações
 * InicializaData, AcrescentaDias e EscreveExtenso.
 * --------------------------------------------------------- */

struct TADData {
/*Inicializando para evitar o erro que ocorreu no vídeo
 *ou seja, se não inicializar vai dar erro.*/
    int Dia = -1;
    int Mes = -1;
    int Ano = -1;
};

/* ---------------------------------------------------------
 * Funções de controle dos dados (uso interno do TAD)
 * --------------------------------------------------------- */

int EhBissexto(int Ano) {
    return (Ano % 4 == 0 && Ano % 100 != 0) || (Ano % 400 == 0);
}

int DiasNoMes(int Mes, int Ano) {
    if (Mes == 1 || Mes == 3 || Mes == 5 || Mes == 7 ||
        Mes == 8 || Mes == 10 || Mes == 12) {
        return 31;
    }

    if (Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) {
        return 30;
    }

    if (Mes == 2) {
        if (EhBissexto(Ano)) {
            return 29;
        } else {
            return 28;
        }
    }

    return -1;
}

int DataValida(int Dia, int Mes, int Ano) {
    int diasDoMes;

    if (Ano <= 0 || Mes < 1 || Mes > 12) {
        return 0;
    }

    diasDoMes = DiasNoMes(Mes, Ano);

    if (Dia < 1 || Dia > diasDoMes) {
        return 0;
    }

    return 1;
}

/* ---------------------------------------------------------
 * Interface do TAD
 * --------------------------------------------------------- */

/* Inicializa uma Data a partir de Dia, Mes e Ano.
 * Se a combinação for inválida (ex: 31/04/2026), retorna uma
 * Data com Dia = -1. */
struct TADData InicializaData(int Dia, int Mes, int Ano) {
    struct TADData D;

    if (!DataValida(Dia, Mes, Ano)) {
        D.Dia = -1;
        D.Mes = -1;
        D.Ano = -1;
        return D;
    }

    D.Dia = Dia;
    D.Mes = Mes;
    D.Ano = Ano;
    return D;
}

/* Soma DiasParaAdicionar dias à data D e retorna o resultado.
 * Se D for inválida, ou DiasParaAdicionar for negativo,
 * retorna uma Data com Dia = -1. */
struct TADData AcrescentaDias(struct TADData D, int DiasParaAdicionar) {
    struct TADData Resultado;
    int i;

    Resultado = D;

    for (i = 0; i < DiasParaAdicionar; i++) {
        Resultado.Dia++;

        if (Resultado.Dia > DiasNoMes(Resultado.Mes, Resultado.Ano)) {
            Resultado.Dia = 1;
            Resultado.Mes++;

            if (Resultado.Mes > 12) {
                Resultado.Mes = 1;
                Resultado.Ano++;
            }
        }
    }

    return Resultado;
}

/* Escreve a data por extenso no formato:
 * "24 de Agosto de 2026"
 * Se a data for inválida, informa isso ao usuário. */
void EscreveExtenso(struct TADData D) {
    if (D.Dia == -1 || !DataValida(D.Dia, D.Mes, D.Ano)) {
        printf("Data invalida.\n");
        return;
    }

    printf("%d de ", D.Dia);

    if (D.Mes == 1) {
        printf("Janeiro");
    } else if (D.Mes == 2) {
        printf("Fevereiro");
    } else if (D.Mes == 3) {
        printf("Marco");
    } else if (D.Mes == 4) {
        printf("Abril");
    } else if (D.Mes == 5) {
        printf("Maio");
    } else if (D.Mes == 6) {
        printf("Junho");
    } else if (D.Mes == 7) {
        printf("Julho");
    } else if (D.Mes == 8) {
        printf("Agosto");
    } else if (D.Mes == 9) {
        printf("Setembro");
    } else if (D.Mes == 10) {
        printf("Outubro");
    } else if (D.Mes == 11) {
        printf("Novembro");
    } else if (D.Mes == 12) {
        printf("Dezembro");
    }

    printf(" de %d\n", D.Ano);
}

/* ---------------------------------------------------------
 * Programa principal: le a data do usuario e testa o TAD
 * --------------------------------------------------------- */

int main() {
    int dia, mes, ano, diasParaAdicionar;
    struct TADData D, DResultado;

    printf("Digite o dia/mes/ano: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    D = InicializaData(dia, mes, ano);

    if (D.Dia == -1) 
        printf("Data invalida! Encerrando o programa.\n");
    else
    {
        printf("Data informada: ");
        EscreveExtenso(D);

        printf("Quantos dias deseja acrescentar? ");
        scanf("%d", &diasParaAdicionar);

        DResultado = AcrescentaDias(D, diasParaAdicionar);

        printf("Nova data: ");
        EscreveExtenso(DResultado);
    }
    return 0;
}
