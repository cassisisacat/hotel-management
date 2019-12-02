#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "cliente_struct.h"
#include "management.h"

void inclui_cliente(FILE *arquivo)
{
    cliente m;
    int posicao;
    printf("Digite o código do cliente...:");
    fflush(stdin);
    scanf("%d", &m.codigo);
    posicao = localiza_cliente(arquivo, m.codigo);
    if (posicao == -1)
    {
        printf("\nDigite o nome do cliente...: ");
        fflush(stdin);
        fgets(m.nome, 100, stdin);
        printf("\nDigite o endereço do cliente...: ");
        fflush(stdin);
        fgets(m.endereco, 100, stdin);
        printf("\nDigite o telefone do cliente...: ");
        fflush(stdin);
        scanf("%f", &m.telefone);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&m, sizeof(m), 1, arquivo);
        fflush(arquivo);
    }
    else
    {
        printf("Codigo já existe, inclusão não realizada!");
    }
}

int localiza_cliente(FILE *arquivo, int codigo)
{
    int posicao = -1, achou = 0;
    cliente m;
    fseek(arquivo, 0, SEEK_SET);
    fread(&m, sizeof(m), 1, arquivo);
    while (!feof(arquivo) && !achou)
    {
        posicao++;
        if (m.codigo == codigo)
        {
            achou = 1;
        }
        fread(&m, sizeof(m), 1, arquivo);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

void imprime_cliente(FILE *arquivo)
{
    cliente m;
    fseek(arquivo, 0, SEEK_SET);
    fread(&m, sizeof(m), 1, arquivo);
    while (!feof(arquivo))
    {
        printf("Código ->  %d\n", m.codigo);
        printf("Nome ->  %s\n", m.nome);
        printf("Endereço  ->  %s\n", m.endereco);
        printf("Telefone  ->  %f\n", m.telefone);
        fread(&m, sizeof(m), 1, arquivo);
    }
}
