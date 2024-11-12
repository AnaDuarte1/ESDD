#ifndef LISTA_H
#define LISTA_H

#define MAX_FUNCIONARIOS 50
#define MAX_NOME 100
#define MAX_VEICULO 50

typedef struct {
    char nome[MAX_NOME];
    char cpf[12];
    char veiculo[MAX_VEICULO];
} Funcionario;

typedef struct lista Lista;

Lista* criaLista();
int adicionaFuncionario(Lista *lista, Funcionario f);
void imprimeLista(Lista *lista);
void liberaLista(Lista *lista);

#endif
