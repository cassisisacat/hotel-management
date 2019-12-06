#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "cliente_struct.h"
#include "management.h"

void printMenu();

int main()
{
    setlocale(LC_ALL, "portuguese");

    FILE *arquivo;
    char op;

    if ((arquivo = fopen("arquivo.txt", "r+b")) == NULL)
    {
        printf("Arquivo n�o existe ... criando arquivo!");

        if ((arquivo = fopen("arquivo.txt", "w+b")) == NULL)
        {
            printf("Erro na cria��o do arquivo!!");
            exit(1);
        }
    }

    do{
        printMenu();

        op = getchar();

        switch (op)
        {
        case 'a':
            system("clear");
            printf("P�GINA DE CADASTRO...\n\n");
            inclui_cliente(arquivo);
            break;
        case 'b':
            system("clear");
            printf("P�GINA DE CADASTRO...\n\n");
            inclui_funcionario(arquivo);
            break;
        case 'c':
            system("clear");
            printf("Aqui est� as informa��es sobre os clientes ...\n\n");
            imprime_cliente(arquivo);
            break;
        }
    } while (op != 'd');

    fclose(arquivo);

    return 0;
}

void printMenu(){

    printf("HOTEL MANAGEMENT\n\n");
    printf("a - Cadastrar cliente\n");
    printf("b - Cadastrar funcionario\n");
    printf("c - Mostrar clientes\n");
    printf("d - Sair do programa\n");
    printf("\nDigite sua op��o:\n ");

}