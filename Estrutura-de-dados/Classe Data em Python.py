# ===========================================================
# VERSAO POO (Programacao Orientada a Objetos) do TAD Data
#
# Este arquivo espelha, em Python, a mesma ClasseData criada em
# C++, usando os mesmos nomes de atributos e metodos para
# facilitar a comparacao lado a lado.
#
# As mesmas duas diferencas centrais em relacao ao TAD valem
# aqui:
#
# 1) Dia/Mes/Ano ficam "dentro" do objeto, como atributos
#    "privados por convencao" (o prefixo "_" antes do nome
#    indica que nao devem ser acessados de fora da classe -
#    Python nao impede de verdade, mas o "_" e o sinal usado
#    pela comunidade para dizer "isso e uso interno"). Os
#    metodos, por outro lado, sao publicos e podem ser
#    chamados de fora (do main, por exemplo). Nenhum metodo
#    precisa mais receber a data como parametro, porque cada
#    metodo ja enxerga os atributos do proprio objeto (via
#    "self"). Compare com a versao TAD, em que toda funcao
#    (AcrescentaDias, EscreveExtenso, DataValida...) precisava
#    receber D (ou Dia, Mes, Ano) por parametro.
#
# 2) Para usar qualquer metodo, e obrigatorio primeiro
#    INSTANCIAR um objeto da classe (ex: "data = ClasseData(...)").
#    Sem essa instancia, nao existe "Dia", "Mes" ou "Ano" para
#    os metodos acessarem - nao ha como chamar
#    "data.escreveExtenso()" sem que "data" exista. Isso nao
#    existe no TAD: la, bastava chamar as funcoes passando os
#    dados, sem precisar de nenhum objeto.
# ===========================================================


class ClasseData:

    # -----------------------------------------------------------
    # Construtor (equivalente ao "ClasseData(int dia, int mes,
    # int ano)" do C++)
    #
    # Em Python, o construtor sempre se chama "__init__" e o
    # primeiro parametro e sempre "self", que representa o
    # proprio objeto sendo criado (e o mesmo papel do "this"
    # implicito do C++). O construtor SO roda quando um objeto e
    # criado (instanciado), com a sintaxe
    # "data = ClasseData(dia, mes, ano)".
    #
    # Nao existe como usar a classe ClasseData sem passar por
    # este construtor - nao ha uma forma de "pular" a
    # instanciacao e chamar acrescentaDias() ou escreveExtenso()
    # direto, pois esses metodos so existem associados a um
    # objeto ja criado.
    # -----------------------------------------------------------
    def __init__(self, dia, mes, ano):
        if self.dataValida(dia, mes, ano):
            self.Dia = dia
            self.Mes = mes
            self.Ano = ano
        else:
            self.Dia = -1
            self.Mes = -1
            self.Ano = -1

    # ---------------------------------------------------------
    # Metodos (equivalentes as funcoes auxiliares do TAD:
    # EhBissexto, DiasNoMes, DataValida). Publicos, mas repare
    # que agora NENHUM deles recebe Dia/Mes/Ano da data atual
    # por parametro quando nao precisa - eles usam self.Dia,
    # self.Mes e self.Ano (os atributos do proprio objeto)
    # diretamente.
    # ---------------------------------------------------------

    # ehBissexto ainda recebe "ano" por parametro porque essa
    # checagem tambem e usada para testar OUTROS anos, nao so o
    # ano do objeto atual (o mesmo motivo de diasNoMes abaixo).
    def ehBissexto(self, ano):
        return (ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0)

    # diasNoMes tambem recebe mes/ano por parametro, pois e
    # chamada dentro do laco de acrescentaDias testando o
    # mes/ano "candidatos" apos incrementos, e nao apenas o
    # mes/ano atuais do objeto.
    def diasNoMes(self, mes, ano):
        if mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12:
            return 31

        if mes == 4 or mes == 6 or mes == 9 or mes == 11:
            return 30

        if mes == 2:
            if self.ehBissexto(ano):
                return 29
            else:
                return 28

        return -1

    # dataValida tambem recebe os tres valores por parametro,
    # pois e usada no construtor para validar dia/mes/ano ANTES
    # de decidir se eles podem virar os atributos do objeto -
    # nesse momento os atributos ainda nao foram definidos.
    def dataValida(self, dia, mes, ano):
        if ano <= 0 or mes < 1 or mes > 12:
            return False

        diasDoMes = self.diasNoMes(mes, ano)

        if dia < 1 or dia > diasDoMes:
            return False

        return True

    # getDia
    #
    # Em C++, Dia era privado e precisava de um metodo getter
    # para ser lido de fora da classe. Em Python, o atributo
    # continua acessivel diretamente (data.Dia), mas mantemos
    # getDia() para preservar a mesma estrutura de chamadas
    # usada no main da versao C++.
    def getDia(self):
        return self.Dia

    # acrescentaDias
    #
    # Equivale a AcrescentaDias do TAD, mas repare que NAO
    # recebe mais a data como parametro (antes era
    # "AcrescentaDias(struct TADData D, int DiasParaAdicionar)").
    # Aqui, Dia/Mes/Ano usados dentro do metodo sao os proprios
    # atributos do objeto que chamou o metodo (ex: em
    # "data.acrescentaDias(10)", os atributos alterados sao os
    # de "data"). Alem disso, o metodo altera o objeto
    # diretamente (nao ha "return" de uma nova data).
    def acrescentaDias(self, diasParaAdicionar):
        i = 0
        while i < diasParaAdicionar:
            self.Dia += 1

            # Chamada de metodo: diasNoMes(self.Mes, self.Ano)
            # usa os atributos atuais do proprio objeto.
            if self.Dia > self.diasNoMes(self.Mes, self.Ano):
                self.Dia = 1
                self.Mes += 1

                if self.Mes > 12:
                    self.Mes = 1
                    self.Ano += 1

            i += 1

    # escreveExtenso
    #
    # Equivale a EscreveExtenso do TAD, mas tambem sem receber
    # nenhuma data por parametro - ela imprime diretamente
    # self.Dia/self.Mes/self.Ano do objeto atual (ex:
    # "data.escreveExtenso()" imprime a data guardada dentro de
    # "data").
    def escreveExtenso(self):
        if self.Dia == -1:
            print("Data invalida.")
            return

        print("%d de " % self.Dia, end="")

        if self.Mes == 1:
            print("Janeiro", end="")
        elif self.Mes == 2:
            print("Fevereiro", end="")
        elif self.Mes == 3:
            print("Marco", end="")
        elif self.Mes == 4:
            print("Abril", end="")
        elif self.Mes == 5:
            print("Maio", end="")
        elif self.Mes == 6:
            print("Junho", end="")
        elif self.Mes == 7:
            print("Julho", end="")
        elif self.Mes == 8:
            print("Agosto", end="")
        elif self.Mes == 9:
            print("Setembro", end="")
        elif self.Mes == 10:
            print("Outubro", end="")
        elif self.Mes == 11:
            print("Novembro", end="")
        elif self.Mes == 12:
            print("Dezembro", end="")

        print(" de %d" % self.Ano)


# ---------------------------------------------------------
# Programa principal
#
# Repare no passo extra que nao existia no TAD: antes de
# chamar qualquer metodo, e necessario instanciar um objeto
# ("data = ClasseData(dia, mes, ano)"). Sem essa linha,
# nenhuma chamada como "data.escreveExtenso()" seria
# possivel, pois "data" simplesmente nao existiria.
# ---------------------------------------------------------
entrada = input("Digite o dia/mes/ano: ")
dia, mes, ano = entrada.split("/")
dia = int(dia)
mes = int(mes)
ano = int(ano)

# Instanciacao do objeto: e aqui que o construtor (__init__)
# roda. Sem esta linha, nao ha objeto "data" e o programa
# nao poderia usar acrescentaDias() nem escreveExtenso().
data = ClasseData(dia, mes, ano)

# Mesma logica da versao TAD: se a data digitada ja nasceu
# invalida, nem tentamos acrescentar dias a ela.
if data.getDia() == -1:
    print("Data invalida! Encerrando o programa.")
else:
    print("Data informada: ", end="")
    # Chamada de metodo, sem nenhum parametro de data - o
    # objeto "data" ja "sabe" qual e a sua propria data.
    data.escreveExtenso()

    diasParaAdicionar = int(input("Quantos dias deseja acrescentar? "))

    # Novamente, sem precisar passar a data - so o numero de
    # dias, que e a unica informacao "de fora" que o metodo
    # realmente precisa.
    data.acrescentaDias(diasParaAdicionar)

    print("Nova data: ", end="")
    data.escreveExtenso()