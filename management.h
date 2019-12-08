#include <stdio.h>

void inclui_cliente(FILE *arquivo);
void inclui_funcionario(FILE *arquivo);
void cadastra_quarto(FILE *arq);
int localiza_cliente(FILE *arquivo, int codigo);
void imprime_cliente(FILE *arquivo);
void imprime(FILE *arq, int pos, int tipo);
void pesquisa(FILE *clientes, FILE *funcionarios, FILE*arq_quartos);
void exclui_estadia(FILE*arq_estadia, FILE *arq_quarto);
void cadastrar_estadia(FILE *arq, FILE *arq_quartos);
