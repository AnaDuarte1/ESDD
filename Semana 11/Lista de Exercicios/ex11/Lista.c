#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = NULL; // Inicialmente, a lista está vazia
    return lista;
}

void adicionarElemento(Lista* lista, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = lista->cabeca; 
    lista->cabeca = novoNo; 
}

void removerElemento(Lista* lista, int dado) {
    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && atual->dado != dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", dado);
        return; 
    }

    if (anterior == NULL) {
        lista->cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo; 
    }

    free(atual); 
}

void exibirLista(Lista* lista) {
    No* atual = lista->cabeca;
    if (atual == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista:\n");
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista); 
}