def CadastrarVetor(V, N):
    for i in range(N):
        V[i] = int(input(f"Digite o valor da posição {i}: "))


def MostrarVetor(V, N):
    for i in range(N):
        print(f"Posição {i}: {V[i]}")


def AlterarVetor(V, N, procurado, novo):
    alteracoes = 0

    for i in range(N):
        if V[i] == procurado:
            V[i] = novo
            alteracoes += 1

    return alteracoes


# Programa principal
V = [0] * 10
N = 10

CadastrarVetor(V, N)

print("\nVetor cadastrado:")
MostrarVetor(V, N)

procurado = int(input("\nDigite o valor a ser procurado: "))
novo = int(input("Digite o novo valor: "))

alteracoes = AlterarVetor(V, N, procurado, novo)

if alteracoes > 0:
    print(f"\nForam alteradas {alteracoes} posicoes.")
else:
    print("\nO valor nao foi encontrado. Nenhuma posicao foi alterada.")

print("\nVetor após a alteracao:")
MostrarVetor(V, N)