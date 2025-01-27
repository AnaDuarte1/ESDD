#include <stdio.h>
#include <stdlib.h>
#include "Robo.h"

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, char comando) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->comando = comando;
    novoNodo->proximo = pilha->topo;
    pilha->topo = novoNodo;
}

char desempilhar(Pilha* pilha) {
    Nodo* nodoRemovido = pilha->topo;
    char comando = nodoRemovido->comando;
    pilha->topo = nodoRemovido->proximo;
    free(nodoRemovido);
    return comando;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}

// Função para imprimir o caminho de ida
void imprimirCaminhoIda(Pilha* pilha) {
    Nodo* atual = pilha->topo;
    printf("Caminho de ida: ");
    while (atual != NULL) {
        printf("%c ", atual->comando);
        atual = atual->proximo;
    }
    printf("\n");
}

void imprimirCaminhoVolta(Pilha* pilha) {
    printf("Caminho de volta: ");
    while (!pilhaVazia(pilha)) {
        char comando = desempilhar(pilha);
        // Inverter comandos de DIREITA e ESQUERDA
        if (comando == 'D') {
            printf("E ");
        } else if (comando == 'E') {
            printf("D ");
        } else {
            printf("F ");
        }
    }
    printf("\n");
}
