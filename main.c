#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "management.h"

void printMenu();

int main()
{
    setlocale(LC_ALL, "portuguese");

    FILE *clientes;
    FILE *funcionarios;
    FILE *estadias;
    FILE *quartos;

    int op;

    if ((clientes = fopen("clientes.dat", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((clientes = fopen("clientes.dat", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((funcionarios = fopen("funcionarios.dat", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((funcionarios = fopen("funcionarios.dat", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((estadias = fopen("estadias.dat", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((estadias = fopen("estadias.dat", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((quartos = fopen("quartos.dat", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((quartos = fopen("quartos.dat", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    do{
        printMenu();

        scanf("%d", &op);

        switch (op){
        case 1:
            system("cls");
            printf("PAGINA DE CADASTRO...\n\n");
            inclui_cliente(clientes);
            break;
        case 2:
            system("cls");
            printf("PAGINA DE CADASTRO...\n\n");
            inclui_funcionario(funcionarios);
            break;
        case 3:
            system("cls");
            cadastrar_quarto(quartos);
            break;
        case 4:
            system("cls");
            printf("Aqui esta as informa��es sobre os clientes ...\n\n");
            imprime_cliente(clientes);
            break;
        case 5:
            system("cls");
            pesquisa(clientes, funcionarios);
            break;
        case 6:
            system("cls");
            cadastrar_estadia(estadias, quartos);
            break;
        }

    } while (op != 0);

    fclose(clientes);

    return 0;
}

void printMenu(){

    printf("HOTEL MANAGEMENT\n\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Cadastrar funcionario\n");
    printf("3 - Cadastrar quarto\n");
    printf("4 - Mostrar clientes\n");
    printf("5 - Pesquisa\n");
    printf("6 - Cadastrar Estadia\n");
    printf("0 - Sair do programa\n");
    printf("\nDigite sua opção: ");

}
