#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
struct Tcliente
{
    int codigo;
    char nome[100],endereco[100];
    float telefone;
};
typedef struct Tcliente cliente;
void inclui_cliente(FILE *arquivo);
int localiza_cliente(FILE *arquivo, int codigo);
void imprime_cliente(FILE *arquivo);
void management();

int main()
{
    setlocale(LC_ALL,"portuguese");
    management();
    return 0;
}
void management()
{
    FILE * arquivo;
    char op;
    if ((arquivo = fopen("arquivo.txt", "r+b"))==NULL)
    {
        printf("Arquivo não exista ... criando arquivo!");
        if((arquivo = fopen("arquivo.txt", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {
        printf("HOTEL MANAGEMENT\n\n");
        printf("a - Cadastrar cliente\n");
        printf("b - Mostrar clientes\n");
        printf("c - Sair do programa\n");
        printf("\nDigite sua opção:\n ");
        op=getchar();
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
    }
    while (op!='c');
    fclose(arquivo);
}
void inclui_cliente(FILE *arquivo)
{
    cliente m;
    int posicao;
    printf("Digite o código do cliente...:");
    fflush(stdin);
    scanf("%d", &m.codigo);
    posicao=localiza_cliente(arquivo,m.codigo);
    if (posicao==-1)
    {
        printf("\nDigite o nome do cliente...: ");
        fflush(stdin);
        fgets(m.nome,100,stdin);
        printf("\nDigite o endereço do cliente...: ");
        fflush(stdin);
        fgets(m.endereco,100,stdin);
        printf("\nDigite o telefone do cliente...: ");
        fflush(stdin);
        scanf("%f", &m.telefone);
        fseek(arquivo,0,SEEK_END);
        fwrite(&m,sizeof(m),1,arquivo);
        fflush(arquivo);
    }
    else{
    printf("Codigo já existe, inclusão não realizada!");
    }
}

int localiza_cliente(FILE *arquivo,int codigo)
{
int posicao=-1,achou=0;
cliente m;
fseek(arquivo,0,SEEK_SET);
fread(&m,sizeof(m),1,arquivo);
while(!feof(arquivo) && !achou)
{
    posicao++;
    if(m.codigo==codigo)
    {
        achou=1;
    }
    fread(&m,sizeof(m),1,arquivo);
}
if(achou)
{
    return posicao;
}
else
{
    return -1;
}

}


void imprime_cliente(FILE *arquivo){
    cliente m;
    fseek(arquivo,0,SEEK_SET);
    fread(&m,sizeof(m),1,arquivo);
    while(!feof(arquivo))
    {
        printf("Código ->  %d\n", m.codigo);
        printf("Nome ->  %s\n", m.nome);
        printf("Endereço  ->  %s\n", m.endereco);
        printf("Telefone  ->  %f\n", m.telefone);
        fread(&m,sizeof(m),1,arquivo);
    }
}
