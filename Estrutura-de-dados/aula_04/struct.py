# clientes = [
#     {
#         "nome": "Tiago",
#         "codigo": 1
#     },
#     {
#         "nome": "Pedro",
#         "codigo": 4
#     },
#     {
#         "nome": "João",
#         "codigo": 2
#     },
#     {
#         "nome": "Maria",
#         "codigo": 6
#     }
# ]


clientes  = []
for i in range(3):
    c = {
            "nome": input("Digite o nome do cliente: "), 
            "codigo": int(input("Digite o código do cliente: "))
        }
    clientes.append(c)

print("Lista de clientes cadastrados:")
for cliente in clientes:
    print(f"Nome: {cliente['nome']}, Código: {cliente['codigo']}")
