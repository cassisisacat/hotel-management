struct Tcliente{

    int codigo;
    char nome[100], endereco[100], telefone[12];

};
typedef struct Tcliente cliente;

struct employee{

    int codigo;
    char nome[100], endereco[100],cargo[100], telefone[12];
    float salario;

};
typedef struct employee funcionario;

struct quarto{

    int codigo, capacidade, disponivel;

}; typedef struct quarto quarto;
