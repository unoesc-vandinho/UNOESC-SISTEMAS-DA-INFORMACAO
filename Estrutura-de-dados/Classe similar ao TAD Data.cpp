#include <cstdio>

/* ===========================================================
 * VERSAO POO (Programacao Orientada a Objetos) do TAD Data
 *
 * Este arquivo existe apenas para fins de COMPARACAO com a
 * versao em TAD (struct TADData + funcoes soltas). O objetivo
 * e mostrar, na pratica, duas diferencas centrais entre TAD e
 * classe:
 *
 * 1) Na classe, Dia/Mes/Ano ficam "dentro" do objeto, como
 *    atributos PRIVADOS (private) - so podem ser acessados de
 *    dentro da propria classe. Ja os metodos (equivalentes as
 *    antigas funcoes do TAD) sao PUBLICOS, para poderem ser
 *    chamados de fora (do main, por exemplo). Alem disso,
 *    nenhum metodo precisa mais receber a data como parametro,
 *    porque cada metodo ja enxerga os atributos do proprio
 *    objeto que o chamou. Compare com a versao TAD, em que toda
 *    funcao (AcrescentaDias, EscreveExtenso, DataValida...)
 *    precisava receber D (ou Dia, Mes, Ano) por parametro.
 *
 * 2) Para usar qualquer metodo, e obrigatorio primeiro
 *    INSTANCIAR um objeto da classe (ex: "ClasseData data(...);").
 *    Sem essa instancia, nao existe "Dia", "Mes" ou "Ano" para
 *    os metodos acessarem - o programa simplesmente nao roda
 *    (nem compila, no caso de tentar chamar um metodo sem
 *    objeto). Isso nao existe no TAD: la, bastava chamar as
 *    funcoes passando os dados, sem precisar de nenhum objeto.
 * =========================================================== */

class ClasseData {
private:
    /* Atributos: equivalentes aos campos da struct TADData,
     * mas agora "presos" ao objeto e privados (private), ou
     * seja, so podem ser acessados de dentro da propria classe -
     * nenhum codigo externo consegue ler ou alterar Dia, Mes ou
     * Ano diretamente. No TAD isso nao existia: qualquer parte
     * do programa podia acessar D.Dia livremente. */
    int Dia;
    int Mes;
    int Ano;

public:
    /* ---------------------------------------------------------
     * Metodos (equivalentes as funcoes auxiliares do TAD:
     * EhBissexto, DiasNoMes, DataValida). Publicos, mas repare
     * que agora NENHUM deles recebe Dia/Mes/Ano da data atual
     * por parametro quando nao precisa - eles usam os atributos
     * do proprio objeto diretamente.
     * --------------------------------------------------------- */

    /* ehBissexto ainda recebe "ano" por parametro porque essa
     * checagem tambem e usada para testar OUTROS anos, nao so
     * o ano do objeto atual (o mesmo motivo de DiasNoMes abaixo). */
    bool ehBissexto(int ano) {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }

    /* diasNoMes tambem recebe mes/ano por parametro, pois e
     * chamada dentro do laco de AcrescentaDias testando o
     * mes/ano "candidatos" apos incrementos, e nao apenas o
     * mes/ano atuais do objeto. */
    int diasNoMes(int mes, int ano) {
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
            mes == 8 || mes == 10 || mes == 12) {
            return 31;
        }

        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
        }

        if (mes == 2) {
            if (ehBissexto(ano)) {
                return 29;
            } else {
                return 28;
            }
        }

        return -1;
    }

    /* dataValida tambem recebe os tres valores por parametro,
     * pois e usada no construtor para validar dia/mes/ano ANTES
     * de decidir se eles podem virar os atributos do objeto -
     * nesse momento os atributos ainda nao foram definidos. */
    bool dataValida(int dia, int mes, int ano) {
        int diasDoMes;

        if (ano <= 0 || mes < 1 || mes > 12) {
            return false;
        }

        diasDoMes = diasNoMes(mes, ano);

        if (dia < 1 || dia > diasDoMes) {
            return false;
        }

        return true;
    }

    /* ---------------------------------------------------------
     * Construtor
     *
     * Equivale a InicializaData do TAD, mas com uma diferenca
     * fundamental: no TAD, InicializaData era uma funcao comum,
     * chamada como qualquer outra (D = InicializaData(...)).
     * Aqui, o construtor SO roda quando um objeto e criado
     * (instanciado), com a sintaxe "ClasseData data(dia, mes, ano);".
     *
     * Nao existe como usar a classe ClasseData sem passar por este
     * construtor - nao ha uma forma de "pular" a instanciacao e
     * chamar acrescentaDias() ou escreveExtenso() direto, pois
     * esses metodos so existem associados a um objeto ja criado.
     * --------------------------------------------------------- */
    ClasseData(int dia, int mes, int ano) {
        if (dataValida(dia, mes, ano)) {
            Dia = dia;
            Mes = mes;
            Ano = ano;
        } else {
            Dia = -1;
            Mes = -1;
            Ano = -1;
        }
    }

    /* getDia
     *
     * Como Dia e privado, o main nao pode escrever "data.Dia"
     * diretamente (isso nao compilaria). Esse pequeno metodo
     * "getter" existe so para permitir checar, de fora da
     * classe, se a data e valida (Dia == -1) - o mesmo tipo de
     * checagem que a versao TAD fazia acessando D.Dia diretamente. */
    int getDia() {
        return Dia;
    }

    /* acrescentaDias
     *
     * Equivale a AcrescentaDias do TAD, mas repare que NAO
     * recebe mais a data como parametro (antes era
     * "AcrescentaDias(struct TADData D, int DiasParaAdicionar)").
     * Aqui, Dia/Mes/Ano usados dentro do metodo sao os proprios
     * atributos do objeto que chamou o metodo (ex: em
     * "data.acrescentaDias(10)", os atributos alterados sao os
     * de "data"). Alem disso, o metodo altera o objeto
     * diretamente (nao ha "return" de uma nova data). */
    void acrescentaDias(int diasParaAdicionar) {
        for (int i = 0; i < diasParaAdicionar; i++) {
            Dia++;

            /* Chamada de metodo: diasNoMes(Mes, Ano) usa os
             * atributos atuais do proprio objeto como argumento. */
            if (Dia > diasNoMes(Mes, Ano)) {
                Dia = 1;
                Mes++;

                if (Mes > 12) {
                    Mes = 1;
                    Ano++;
                }
            }
        }
    }

    /* escreveExtenso
     *
     * Equivale a EscreveExtenso do TAD, mas tambem sem receber
     * nenhuma data por parametro - ela imprime diretamente
     * Dia/Mes/Ano do objeto atual (ex: "data.escreveExtenso();"
     * imprime a data guardada dentro de "data"). */
    void escreveExtenso() {
        if (Dia == -1) {
            printf("Data invalida.\n");
            return;
        }

        printf("%d de ", Dia);

        if (Mes == 1) {
            printf("Janeiro");
        } else if (Mes == 2) {
            printf("Fevereiro");
        } else if (Mes == 3) {
            printf("Marco");
        } else if (Mes == 4) {
            printf("Abril");
        } else if (Mes == 5) {
            printf("Maio");
        } else if (Mes == 6) {
            printf("Junho");
        } else if (Mes == 7) {
            printf("Julho");
        } else if (Mes == 8) {
            printf("Agosto");
        } else if (Mes == 9) {
            printf("Setembro");
        } else if (Mes == 10) {
            printf("Outubro");
        } else if (Mes == 11) {
            printf("Novembro");
        } else if (Mes == 12) {
            printf("Dezembro");
        }

        printf(" de %d\n", Ano);
    }
};

/* ---------------------------------------------------------
 * Programa principal
 *
 * Repare no passo extra que nao existia no TAD: antes de
 * chamar qualquer metodo, e necessario instanciar um objeto
 * ("ClasseData data(dia, mes, ano);"). Sem essa linha, nenhuma
 * chamada como "data.escreveExtenso()" seria possivel - o
 * compilador nem deixaria o codigo ser gerado, pois "data"
 * simplesmente nao existiria.
 * --------------------------------------------------------- */
int main() 
{
    int dia, mes, ano, diasParaAdicionar;

    printf("Digite o dia/mes/ano: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    /* Instanciacao do objeto: e aqui que o construtor roda.
     * Sem esta linha, nao ha objeto "data" e o programa nao
     * poderia usar acrescentaDias() nem escreveExtenso(). */
    ClasseData data(dia, mes, ano);

    /* Mesma logica da versao TAD: se a data digitada ja nasceu
     * invalida, nem tentamos acrescentar dias a ela. */
    if (data.getDia() == -1) 
        printf("Data invalida! Encerrando o programa.\n");
    else 
    {
        printf("Data informada: ");
        /* Chamada de metodo, sem nenhum parametro de data - o
         * objeto "data" ja "sabe" qual e a sua propria data. */
        data.escreveExtenso();

        printf("Quantos dias deseja acrescentar? ");
        scanf("%d", &diasParaAdicionar);

        /* Novamente, sem precisar passar a data - so o numero
         * de dias, que e a unica informacao "de fora" que o
         * metodo realmente precisa. */
        data.acrescentaDias(diasParaAdicionar);

        printf("Nova data: ");
        data.escreveExtenso();
    }

    return 0;
}