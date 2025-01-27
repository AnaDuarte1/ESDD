#include <stdio.h>
#include <stdlib.h>
#include "ListaLigacoes.h"

// Função para criar a lista circular
ListaCircular* criarLista() {
    ListaCircular* lista = (ListaCircular*)malloc(sizeof(ListaCircular));
    lista->inicio = NULL;
    return lista;
}

// Função para inserir uma ligação de forma ordenada
void inserirLigacao(ListaCircular* lista, float custo, int id) {
    Ligacao* novaLigacao = (Ligacao*)malloc(sizeof(Ligacao));
    novaLigacao->custo = custo;
    novaLigacao->id = id;

    if (lista->inicio == NULL) {
        novaLigacao->proximo = novaLigacao; // Aponta para si mesma
        lista->inicio = novaLigacao;
        return;
    }

    Ligacao* atual = lista->inicio;
    Ligacao* anterior = NULL;

    // Percorre para encontrar a posição correta
    do {
        if (custo > atual->custo || (custo == atual->custo && anterior == NULL)) {
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->inicio);

    // Insere a nova ligação
    novaLigacao->proximo = atual;

    if (anterior == NULL) { // Inserção no início
        Ligacao* ultimo = lista->inicio;
        while (ultimo->proximo != lista->inicio) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novaLigacao;
        lista->inicio = novaLigacao;
    } else { // Inserção no meio ou fim
        anterior->proximo = novaLigacao;
    }
}

// Função para remover a ligação mais cara (início da lista)
void removerLigacao(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia! Nenhuma ligação para remover.\n");
        return;
    }

    Ligacao* removida = lista->inicio;

    if (lista->inicio->proximo == lista->inicio) { // Apenas 1 elemento
        lista->inicio = NULL;
    } else {
        Ligacao* ultimo = lista->inicio;
        while (ultimo->proximo != lista->inicio) {
            ultimo = ultimo->proximo;
        }
        lista->inicio = removida->proximo;
        ultimo->proximo = lista->inicio;
    }

    printf("Ligação removida: ID = %d, Custo = %.2f\n", removida->id, removida->custo);
    free(removida);
}

void imprimirLista(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Ligacao* atual = lista->inicio;
    printf("Lista de ligações:\n");
    do {
        printf("ID: %d, Custo: %.2f\n", atual->id, atual->custo);
        atual = atual->proximo;
    } while (atual != lista->inicio);
}

void liberarLista(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        free(lista);
        return;
    }

    Ligacao* atual = lista->inicio;
    do {
        Ligacao* temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != lista->inicio);

    free(lista);
}
