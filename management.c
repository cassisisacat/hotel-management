#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "cliente_struct.h"
#include "management.h"
#include "employee.h"
void inclui_cliente(FILE *arquivo)
{
    cliente m;
    int posicao;
    printf("Digite o c�digo do cliente...:");
    fflush(stdin);
    scanf("%d", &m.codigo);
    posicao = localiza_cliente(arquivo, m.codigo);
    if (posicao == -1)
    {
        printf("\nDigite o nome do cliente...: ");
        fflush(stdin);
        fgets(m.nome, 100, stdin);
        printf("\nDigite o endere�o do cliente...: ");
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
        printf("Codigo j� existe, inclus�o n�o realizada!");
    }
}

void inclui_funcionario(FILE *arquivo)
{
    funcionario F;
    int posicao;
    printf("Digite o c�digo do funcionario: ");
    fflush(stdin);
    scanf("%d", &F.codigo);
    posicao = localiza_cliente(arquivo, F.codigo);
    if (posicao == -1)
    {
        printf("\nDigite o nome do funcionario: ");
        fflush(stdin);
        fgets(F.nome, 100, stdin);
        printf("\nDigite o cargo do funcionario: ");
        fflush(stdin);
        fgets(F.cargo, 100, stdin);
        printf("\nDigite o telefone do funcionario: ");
        fflush(stdin);
        scanf("%f", &F.telefone);
        printf("\nDigite o salario do funcionario: ");
        fflush(stdin);
        scanf("%f", &F.telefone);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&F, sizeof(F), 1, arquivo);
        fflush(arquivo);
    }
    else
    {
        printf("Codigo j� existe, inclus�o n�o realizada!");
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
        printf("C�digo ->  %d\n", m.codigo);
        printf("Nome ->  %s\n", m.nome);
        printf("Endere�o  ->  %s\n", m.endereco);
        printf("Telefone  ->  %f\n\n", m.telefone);
        fread(&m, sizeof(m), 1, arquivo);
    }
}
