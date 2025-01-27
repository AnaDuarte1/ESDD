#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aviao.h"

Avião* criarAvião(const char* nome, float nivelCombustivel) {
    Avião* novoAvião = (Avião*)malloc(sizeof(Avião));
    strcpy(novoAvião->nome, nome);
    novoAvião->nivelCombustivel = nivelCombustivel;
    novoAvião->proximo = NULL;
    return novoAvião;
}

void adicionarAvião(Avião** lista, Avião* novoAvião) {
    if (*lista == NULL || (*lista)->nivelCombustivel > novoAvião->nivelCombustivel) {
        novoAvião->proximo = *lista;
        *lista = novoAvião;
    } else {
        Avião* atual = *lista;
        while (atual->proximo != NULL && atual->proximo->nivelCombustivel <= novoAvião->nivelCombustivel) {
            atual = atual->proximo;
        }
        novoAvião->proximo = atual->proximo;
        atual->proximo = novoAvião;
    }
}

Avião* removerAvião(Avião** lista) {
    if (*lista == NULL) {
        return NULL; 
    }
    Avião* removido = *lista;
    *lista = (*lista)->proximo;
    return removido;
}

void exibirFila(Avião* lista) {
    if (lista == NULL) {
        printf("Nenhum avião na fila.\n");
        return;
    }
    printf("Fila de Aviões:\n");
    while (lista != NULL) {
        printf("Avião: %s, Nível de Combustível: %.2f litros\n", lista->nome, lista->nivelCombustivel);
        lista = lista->proximo;
    }
}

void liberarLista(Avião* lista) {
    while (lista != NULL) {
        Avião* temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}