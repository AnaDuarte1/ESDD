#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "lista.h"

struct lista {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int prox;
};

Lista* criaLista() {
    Lista *list = (Lista*) malloc(sizeof(struct lista)); 
    if (list != NULL)
        list->prox = 0; 
    return list;
}

int adicionaFuncionario(Lista *lista, Funcionario f) {
    if (lista->prox < MAX_FUNCIONARIOS) {
        lista->funcionarios[lista->prox] = f;
        lista->prox++;
        return 1;
    }
    return 0;
}

void imprimeLista(Lista *lista) {
    for (int i = 0; i < lista->prox; i++) {
        printf("Nome: %s, CPF: %s, Veículo: %s\n", lista->funcionarios[i].nome, lista->funcionarios[i].cpf, lista->funcionarios[i].veiculo);
    }
}

void liberaLista(Lista *lista) {
    free(lista);
}
