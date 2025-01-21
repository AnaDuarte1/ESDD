#include <stdio.h>
#include <stdlib.h>
#include "ListaE.h"

Lista* criarLista() {
    Lista* novaLista = malloc(sizeof(Lista));
    if (novaLista != NULL) {
        novaLista->proximo = NULL;
    }
    return novaLista;
}

Lista* inserirElemento(Lista* lista, int valor) {
    Lista* novoNo = malloc(sizeof(Lista));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->proximo = lista;  
    }
    return novoNo;  
}

void imprimirLista(Lista* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Lista* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}

Lista* unirListas(Lista* l1, Lista* l2) {
    Lista* l3 = NULL;  
    Lista* temp = l1;
    while (temp != NULL) {
        l3 = inserirElemento(l3, temp->valor);
        temp = temp->proximo;
    }

    temp = l2;
    while (temp != NULL) {
        l3 = inserirElemento(l3, temp->valor);
        temp = temp->proximo;
    }

    return l3;  
}
