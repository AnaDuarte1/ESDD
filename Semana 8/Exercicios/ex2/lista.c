
#include <stdio.h>
#include <string.h>
#include "lista.h"

ListaFuncionarios* criaLista() {
    ListaFuncionarios *list = (ListaFuncionarios*) malloc(sizeof(struct lista)); 
    if (list != NULL)
        list->prox = 0; 
    return list;
}

int adicionaFuncionario(ListaFuncionarios *lista, Funcionario f) {
    if (lista->prox < MAX_FUNCIONARIOS) {
        lista->funcionarios[lista->prox] = f;
        lista->prox++;
        return 1;
    }
    return 0;
}

void imprimeLista(ListaFuncionarios lista) {
    for (int i = 0; i < lista.prox; i++) {
        printf("Nome: %s, CPF: %s, Veículo: %s\n", lista.funcionarios[i].nome, lista.funcionarios[i].cpf, lista.funcionarios[i].veiculo);
    }
}
