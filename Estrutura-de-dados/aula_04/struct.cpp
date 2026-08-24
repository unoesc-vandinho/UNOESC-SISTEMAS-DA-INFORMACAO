#include <stdio.h>

struct CLIENTS
{
    char name[10];
    int codigo;
};

int main()
{
    struct CLIENTS clientes[4];
    for (int i = 1; i < 4; i++)
    {
        printf("Enter your name: ");
        scanf("%s", & clientes[i].name);

        printf("Enter your code: ");
        scanf("%d", & clientes[i].codigo);
    }

    for (int i = 1; i < 4; i++)
    {
        printf("Name: %s\n", & clientes[i].name);
        printf("Code: %d\n", & clientes[i].codigo);
    }   

    return 0;
}