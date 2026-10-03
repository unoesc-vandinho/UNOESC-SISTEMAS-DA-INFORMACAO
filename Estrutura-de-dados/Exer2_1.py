import os

produto = [0] * 10
ocupado = [0] * 10


while True:
    os.system("clear")
    print("\n=============================")
    print("      CONTROLE DE ESTOQUE")
    print("=============================")
    print("1 - Armazenar produto")
    print("2 - Armazenar produto em endereco especifico")
    print("3 - Remover produto")
    print("4 - Localizar produto")
    print("5 - Gerar rota de reposição")
    print("6 - Gerar rota de coleta")
    print("7 - Mostrar mapa completo")
    print("0 - Sair")
    opcao = int(input("Opção: "))
    
    if opcao == 0:
        break
    # ==========================
    # ARMAZENAR PRODUTO
    # ==========================
    if opcao == 1:

        codigo = int(input("Código do produto: "))

        encontrou = False

        for i in range(10):
            if ocupado[i] == 0:
                produto[i] = codigo
                ocupado[i] = 1
                print("Produto armazenado na prateleira", i)
                encontrou = True
                break

        if encontrou == False:
            print("Depósito cheio.")

    #===========================
    #  INSERIR ENDERECO ESPECIFICO
    #===========================
    elif opcao == 2:
        codigo = int(input("Codigo do produto: "))
        posicao = int(input("Entre com a prateleira desejada: "))
        if posicao < 0 or posicao > 9:
            print("Prateleira incorreta.")
        elif ocupado[posicao] == 1: 
            print("Prateleira ja esta em uso.")
        else:
            ocupado[posicao] = 1
            produto[posicao] = codigo
            print("Produto armazenado na prateleira %d."%posicao)
    # ==========================
    # REMOVER PRODUTO
    # ==========================
    elif opcao == 3:

        codigo = int(input("Código do produto: "))

        encontrou = False

        for i in range(10):
            if ocupado[i] == 1:
                if produto[i] == codigo:
                    ocupado[i] = 0
                    print("Produto removido com sucesso.")
                    encontrou = True
                    break

        if encontrou == False:
            print("Produto não encontrado.")

    # ==========================
    # LOCALIZAR PRODUTO
    # ==========================
    elif opcao == 4:

        codigo = int(input("Código do produto: "))

        encontrou = False

        for i in range(10):
            if ocupado[i] == 1:
                if produto[i] == codigo:
                    print("Produto encontrado na prateleira", i)
                    encontrou = True
                    break

        if encontrou == False:
            print("Produto não encontrado ou já removido.")

    # ==========================
    # ROTA DE REPOSIÇÃO
    # ==========================
    elif opcao == 5:

        encontrou = False

        print("\nPrateleiras disponíveis para reposição:")

        for i in range(10):
            if ocupado[i] == 0:
                print(i)
                encontrou = True

        if encontrou == False:
            print("Não há prateleiras disponíveis para reposição.")

    # ==========================
    # ROTA DE COLETA
    # ==========================
    elif opcao == 6:

        encontrou = False

        print("\nRota de coleta:")

        for i in range(10):
            if ocupado[i] == 1:
                print("Prateleira", i, "-> Produto", produto[i])
                encontrou = True

        if encontrou == False:
            print("Nenhum produto disponível para coleta.")

    # ==========================
    # MAPA COMPLETO
    # ==========================
    elif opcao == 7:

        print("\nEndereço | Produto | Situação")

        for i in range(10):
            if ocupado[i] == 1:
                print(i, " | ", produto[i], " | Ocupada")
            else:
                print(i, " | --- | Livre")

    elif opcao != 0:
        print("Opção inválida!")
    
    parar = input("Digite Enter para continuar.")

print("Programa encerrado.")