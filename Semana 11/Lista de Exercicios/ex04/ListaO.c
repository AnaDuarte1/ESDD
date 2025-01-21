#include <stdio.h>
#include <stdlib.h>
#include "ListaO.h"

void inicializarLista(Lista *lista, int capacidade) {
    lista->dados = (int *)malloc(capacidade * sizeof(int)); 
    lista->tamanho = 0; 
    lista->capacidade = capacidade; 
}

void liberarLista(Lista *lista) {
    free(lista->dados); 
    lista->tamanho = 0;  
    lista->capacidade = 0; 
}

void imprimirLista(const Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

void adicionarElemento(Lista *lista, int elemento) {
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2; // Dobra a capacidade
        lista->dados = (int *)realloc(lista->dados, lista->capacidade * sizeof(int)); // Realoca a memória
    }
    lista->dados[lista->tamanho++] = elemento; 
}

Lista mesclarListas(const Lista *lista1, const Lista *lista2) {
    Lista resultado;
    inicializarLista(&resultado, lista1->tamanho + lista2->tamanho);  

    int i = 0, j = 0;
    
    while (i < lista1->tamanho && j < lista2->tamanho) {
        if (lista1->dados[i] < lista2->dados[j]) {
            // Adiciona o elemento de lista1
            if (resultado.tamanho == 0 || resultado.dados[resultado.tamanho - 1] != lista1->dados[i]) {
                adicionarElemento(&resultado, lista1->dados[i]);
            }
            i++;
        } else if (lista1->dados[i] > lista2->dados[j]) {
            // Adiciona o elemento de lista2
            if (resultado.tamanho == 0 || resultado.dados[resultado.tamanho - 1] != lista2->dados[j]) {
                adicionarElemento(&resultado, lista2->dados[j]);
            }
            j++;
        } else {
            // Adiciona apenas um elemento, caso sejam iguais
            if (resultado.tamanho == 0 || resultado.dados[resultado.tamanho - 1] != lista1->dados[i]) {
                adicionarElemento(&resultado, lista1->dados[i]);
            }
            i++;
            j++;
        }
    }

    // Adiciona os elementos restantes de lista1
    while (i < lista1->tamanho) {
        if (resultado.tamanho == 0 || resultado.dados[resultado.tamanho - 1] != lista1->dados[i]) {
            adicionarElemento(&resultado, lista1->dados[i]);
        }
        i++;
    }

    // Adiciona os elementos restantes de lista2
    while (j < lista2->tamanho) {
        if (resultado.tamanho == 0 || resultado.dados[resultado.tamanho - 1] != lista2->dados[j]) {
            adicionarElemento(&resultado, lista2->dados[j]);
        }
        j++;
    }

    return resultado;
}
