#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
<<<<<<< HEAD
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
        printf("Arquivo não existe ... criando arquivo!");

        if ((arquivo = fopen("arquivo.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
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
            printf("PÁGINA DE CADASTRO...\n\n");
            inclui_cliente(arquivo);
            break;
        case 'b':
            system("clear");
            printf("Aqui está as informações sobre os clientes ...\n\n");
            imprime_cliente(arquivo);
            break;
        }
    } while (op != 'c');

    fclose(arquivo);

    return 0;
}

void printMenu(){
    
    printf("HOTEL MANAGEMENT\n\n");
    printf("a - Cadastrar cliente\n");
    printf("b - Mostrar clientes\n");
    printf("c - Sair do programa\n");
    printf("\nDigite sua opção:\n ");
    
}
=======
#include "funcoes.c"


int main()
{
    setlocale(LC_ALL,"portuguese");
    management();
    return 0;
}
>>>>>>> 6065121f31814f58b7de55467c9bdf1007a69fe1
