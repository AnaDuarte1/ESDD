#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia!\n");
        return -1; // Indica que a pilha está vazia
    }
    No* noRemovido = pilha->topo;
    int dado = noRemovido->dado;
    pilha->topo = pilha->topo->proximo;
    free(noRemovido);
    return dado;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void exibirPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia!\n");
        return;
    }
    No* atual = pilha->topo;
    printf("Elementos da pilha:\n");
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
}

void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}