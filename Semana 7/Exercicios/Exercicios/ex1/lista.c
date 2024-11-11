
#include <stdio.h>
#include <string.h>
#include "lista.h"

void inicializaLista(ListaFuncionarios *lista) {
    lista->qtd = 0;
}

int adicionaFuncionario(ListaFuncionarios *lista, Funcionario f) {
    if (lista->qtd < MAX_FUNCIONARIOS) {
        lista->funcionarios[lista->qtd] = f;
        lista->qtd++;
        return 1;
    }
    return 0;
}

void imprimeLista(ListaFuncionarios lista) {
    for (int i = 0; i < lista.qtd; i++) {
        printf("Nome: %s, CPF: %s, Veículo: %s\n", lista.funcionarios[i].nome, lista.funcionarios[i].cpf, lista.funcionarios[i].veiculo);
    }
}
