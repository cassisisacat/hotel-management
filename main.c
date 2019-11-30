#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
struct Tcliente
{
    int codigo;
    char nome[100];
    float telefone;
};
typedef struct Tcliente cliente;
cliente leCliente();
void imprimeCliente(cliente m);
void alteraCliente(cliente *m);
int main()
{
    setlocale(LC_ALL,"portuguese");
    cliente m[3];
    int op,i;
    do
    {
        system("cls");
        printf("Escolha:\n");
        printf("a - Cadastro Cliente\n");
        printf("b - Alterar informações do cliente\n");
        printf("c - Mostrar dados do cliente\n");
        printf("d - Sair do programa.\n");
        op=getchar();
        switch (op)
        {
        case 'a':
            for (i=0; i<3; i++)
            {
                m[i]=leCliente();
            }
            break;
        case 'b':
            for (i=0; i<3; i++)
            {
                alteraCliente(&m[i]);
            }
            break;
        case 'c':
            for (i=0; i<3; i++)
            {
                imprimeCliente(m[i]);
            }
            break;
        }
        if (op!='d')
        {
            system("pause");
        }
    }
    while (op!='d');
    return 0;
}

cliente leCliente()
{
    cliente m;
    printf("Codigo.. ");
    fflush(stdin);
    scanf("%d", &m.codigo);
    printf("Nome.. ");
    fflush(stdin);
    gets(m.nome);
    printf("Telefone.. ");
    fflush(stdin);
    scanf("%f", &m.telefone);
    return m;
}
void imprimeCliente(cliente m)
{
    printf("Código...: %d\n", m.codigo);
    printf("Nome...: %s\n", m.nome);
    printf("Telefone...: %.2f",  m.telefone);
}
void alteraCliente(cliente *m)
{
    printf("Codigo.. ");
    fflush(stdin);
    scanf("%d", &m->codigo);
    printf("Nome.. ");
    fflush(stdin);
    gets(m->nome);
    printf("Telefone.. ");
    fflush(stdin);
    scanf("%f", &m->telefone);
}
