#ifndef LISTA_H
#define LISTA_H
#endif
#define MAX_FUNCIONARIOS 50
#define MAX_NOME 100
#define MAX_VEICULO 50

typedef struct {
    char nome[MAX_NOME];
    char cpf[12]; 
    char veiculo[MAX_VEICULO];
} Funcionario;

typedef struct lista{
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int prox;
} ListaFuncionarios;

ListaFuncionarios* criaLista();
int adicionaFuncionario(ListaFuncionarios *lista, Funcionario f);
void imprimeLista(ListaFuncionarios lista);


