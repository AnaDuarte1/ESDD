#include <stdio.h>
#include <stdlib.h>
#include "listaS.h"

Lista criaLista() {
    Lista lista = (Lista)malloc(sizeof(ListaSequencial));  
    if (lista != NULL) {
        lista->tamanho = 0;  
    return lista;
}
}

int insereElemento(Lista lista, int valor) {
    if (lista->tamanho < MAX) {
        lista->itens[lista->tamanho] = valor;  
        lista->tamanho++;  
        return 1;  
    }
    return 0;  
}

int verificaOrdenada(Lista lista) {
    int crescente = 1, decrescente = 1;

    for (int i = 0; i < lista->tamanho - 1; i++) {
        if (lista->itens[i] > lista->itens[i + 1]) {
            crescente = 0;  // Se encontrar um valor maior que o próximo, não está crescente
        }
        if (lista->itens[i] < lista->itens[i + 1]) {
            decrescente = 0;  // Se encontrar um valor menor que o próximo, não está decrescente
        }
    }

    if (crescente || decrescente) {
        return 1;  // A lista está ordenada
    }

    return 0;  // A lista não está ordenada
}

// Função para imprimir os elementos da lista
void imprimeLista(Lista lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->itens[i]);
    }
    printf("\n");
}

