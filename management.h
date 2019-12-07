#include <stdio.h>

void inclui_cliente(FILE *arquivo);
void inclui_funcionario(FILE *arquivo);
int localiza_cliente(FILE *arquivo, int codigo);
void imprime_cliente(FILE *arquivo);
void imprime(FILE *arq, int pos, int tipo);
void pesquisa(FILE *clientes, FILE *funcionarios);