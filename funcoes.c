#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu()
{
    int opcao;
    setlocale(LC_ALL,"portuguese");
    do
    {
        system("clear");
        printf("\=== Hotel Descanso Garantido ===\n");
        printf(" [1] - Cadastrar Cliente\n");
        printf(" [9] - Sair ===\n");
        printf("\n\n\nDigite sua opção: ");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            cadastrarCliente();
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while (opcao != 9);
    system("clear");
    getchar();
}

cadastrarCliente()
{
    int qtde_clientes_cadastro,i,t;
    system("clear");
    printf("\=== Hotel Descanso Garantido ===\n\n");
    printf("Página para cadastrar cliente\n\n");
    printf("Quantos clientes deseja cadastrar? ");
    scanf("%d", &qtde_clientes_cadastro);
    system("clear");

    for (i=0; i<qtde_clientes_cadastro; i++)
    {
        printf("Digite um código para o cliente: ");
        scanf("%d", &codigo_cliente[i]);
        system("clear");

        /* printf("Digite o nome do cliente: ");
        scanf("%c", &nome_cliente[i]);
        system("clear"); */
    }
}

