#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "management.h"

void inclui_cliente(FILE *arquivo)
{
    cliente m;
    int posicao;
    printf("Digite o codigo do cliente...:");
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
        fgets(m.telefone, 12, stdin);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&m, sizeof(m), 1, arquivo);
        fflush(arquivo);
    }
    else
    {
        printf("Codigo ja existe, inclusao nao realizada!");
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
        fgets(F.telefone, 12, stdin);
        printf("\nDigite o salario do funcionario: ");
        fflush(stdin);
        scanf("%f", &F.salario);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&F, sizeof(F), 1, arquivo);
        fflush(arquivo);
    }
    else
    {
        printf("Codigo j� existe, inclus�o n�o realizada!");
    }
}

void cadastra_quarto(FILE *arq){
    quarto q;

    printf("Digite o codigo do quarto: ");
    fflush(stdin);
    scanf("%d", &q.codigo);

    printf("Digite a capacidade de hospedes do quarto: ");
    fflush(stdin);
    scanf("%d", &q.capacidade);
    
    printf("Digite o valor da diaria: ");
    fflush(stdin);
    scanf("%d", &q.valordiaria);
    
    printf("Digite o status do quarto: ");
    fflush(stdin);
    scanf("%d", &q.status);

    fseek(arq, 0, SEEK_END);
    fwrite(&q, sizeof(q), 1, arq);
    fflush(arq);

    printf("Quarto cadastrado!\n\n");
}

void imprime(FILE *arq, int pos, int tipo){
    if(tipo == 1){
        cliente c;
        fseek(arq, sizeof(c) * pos, SEEK_CUR);
        printf("Codigo: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", 
          &c.codigo, &c.nome, &c.endereco, &c.telefone);
    }
    if(tipo == 2){
        funcionario f;
        fseek(arq, sizeof(f) * pos, SEEK_CUR);
        printf("Codigo: %d\nNome: %s\nCargo: %s\nTelefone: %s\nSalario: %f",
            &f.codigo, &f.nome, &f.cargo, &f.telefone, &f.salario);
    }
}

void pesquisa(FILE *clientes, FILE *funcionarios){
    system("clear");

    int op, cod, pos;

    printf("Pesquisar por:\n 1.Clientes\n 2.Funcionarios\n");
    fflush(stdin);
    scanf("%d", &op);
    printf("Digite o codigo: ");
    fflush(stdin);
    scanf("%d", &cod);

    pos = localiza_cliente(clientes, cod);

    if(op == 1 && pos != -1 ){
        imprime(clientes, pos, 1);
    } else if (op == 2 && pos != -1){
        imprime(funcionarios, pos, 2);
    } else {
        printf("Opcao inexistente!");
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

    fclose(arquivo);

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
        printf("Telefone  ->  %s\n\n", m.telefone);
        fread(&m, sizeof(m), 1, arquivo);
    }

    fclose(arquivo);
}
