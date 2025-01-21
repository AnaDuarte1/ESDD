#include <stdio.h>
#include <stdlib.h>
#include "ListaS.h"

Lista* criaLista() {
    Lista* novaLista = malloc(sizeof(Lista));
    if (novaLista != NULL) {
        novaLista->tamanho = 0;  
    }
    return novaLista;
}

void insereOrdenadoDes(Lista* lista, int valor) {
    if (lista->tamanho >= MAX) {
        printf("Lista cheia!\n");
        return;
    }

    int i = lista->tamanho - 1;
    while (i >= 0 && lista->itens[i] < valor) {
        lista->itens[i + 1] = lista->itens[i];
        i--;
    }

    lista->itens[i + 1] = valor;
    lista->tamanho++;
}

void eliminarElementos(Lista* l1, Lista* l2) {
    for (int i = 0; i < l1->tamanho; i++) {
        int valor = l1->itens[i];
        int existe = 0;
        for (int j = 0; j < l2->tamanho; j++) {
            if (l2->itens[j] == valor) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            insereOrdenadoDes(l2, valor);
        }
    }
}

void imprimeLista(Lista* lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->itens[i]);
    }
    printf("\n");
}
