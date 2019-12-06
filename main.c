#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "management.h"

void printMenu();
void criarArquivos(FILE *clientes, FILE *funcionarios, FILE *estadias, FILE *quartos);

int main()
{
    setlocale(LC_ALL, "portuguese");

    FILE *clientes;
    FILE *funcionarios;
    FILE *estadias;
    FILE *quartos;

    int op;

    criarArquivos(clientes, funcionarios, estadias, quartos);

    do{
        printMenu();

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("clear");
            printf("PAGINA DE CADASTRO...\n\n");
            inclui_cliente(clientes);
            break;
        case 2:
            system("clear");
            printf("PAGINA DE CADASTRO...\n\n");
            inclui_funcionario(clientes);
            break;
        case 3:
            system("clear");
            printf("Aqui esta as informa��es sobre os clientes ...\n\n");
            imprime_cliente(clientes);
            break;
        }
    } while (op != 4);

    fclose(clientes);

    return 0;
}

void criarArquivos( FILE *clientes, FILE *funcionarios, FILE *estadias, FILE *quartos){//, FILE *funcionarios ){

    if ((clientes = fopen("clientes.txt", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((clientes = fopen("clientes.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((funcionarios = fopen("funcionarios.txt", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((funcionarios = fopen("funcionarios.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((estadias = fopen("estadias.txt", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((estadias = fopen("estadias.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if ((quartos = fopen("quartos.txt", "r+b")) == NULL){

        printf("Arquivo não existe ... criando arquivo!");

        if ((quartos = fopen("quartos.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

}

void printMenu(){

    printf("HOTEL MANAGEMENT\n\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Cadastrar funcionario\n");
    printf("3 - Mostrar clientes\n");
    printf("4 - Sair do programa\n");
    printf("\nDigite sua opção: ");

}
