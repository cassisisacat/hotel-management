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
/*void alteraCliente(cliente *m);*/
void menu();
int main()
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}
void menu(){
    cliente m[3];
    int op,i,qtde,voltar;
    do
    {
        system("cls");
        printf("Bem vindos ao Hotel Descanso Garantido !\n\n");
        printf("Escolha:\n");
        printf("a - Cadastro Cliente\n");
        printf("b - Mostrar dados do cliente\n");
        printf("d - Sair do programa\n");
        op=getchar();
        switch (op)
        {
        case 'a':
            printf("Quantos clientes deseja cadastrar?");
            scanf("%d", &qtde);
            for (i=0; i<qtde; i++)
            {
                m[i]=leCliente();
            }
            printf("Cadastro realizado com sucesso!");
            break;
        case 'b':
            for (i=0; i<3; i++)
            {
                imprimeCliente(m[i]);
            }
            break;
        }
    }
    while (op!='d');
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
    printf("Telefone...: %.2f\n\n",  m.telefone);
}

/* FUNÇÃO PARA ALTERAR CLIENTES
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

            case 'c':
            for (i=0; i<3; i++)
            {
                alteraCliente(&m[i]);
            }
            break;*/
