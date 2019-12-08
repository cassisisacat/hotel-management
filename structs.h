#pragma once
struct cliente{

    int codigo;
    char nome[100], endereco[100], telefone[12];

};
typedef struct cliente cliente;

struct funcionario{

    int codigo;
    char nome[100], endereco[100],cargo[100], telefone[12];
    float salario;

};
typedef struct funcionario funcionario;

struct quarto{

    int numero, capacidade, status, valordiaria;

}; typedef struct quarto quarto;

struct estadia{

    int codigo, qtd_diarias, codigo_cliente, qtd_hospedes, numero_quarto, valida;

}; typedef struct estadia estadia;
