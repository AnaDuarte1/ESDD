#include <stdio.h>
#include "lista.h"

void inicializaLista(Lista *l) {
    l->tamanho = 0;
}

int insereElemento(Lista *l, int elemento) {
    if (l->tamanho >= MAX) {
        return 0; 
    }
    l->elementos[l->tamanho++] = elemento;
    return 1; // Inserção bem-sucedida
}

void removeDuplicados(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        for (int j = i + 1; j < l->tamanho; j++) {
            if (l->elementos[i] == l->elementos[j]) {
                // Move todos os elementos à esquerda
                for (int k = j; k < l->tamanho - 1; k++) {
                    l->elementos[k] = l->elementos[k + 1];
                }
                l->tamanho--; // Reduz o tamanho da lista
                j--; // Reposiciona o índice j para verificar a nova posição
            }
        }
    }
}

void exibeLista(Lista l) {
    printf("{ ");
    for (int i = 0; i < l.tamanho; i++) {
        printf("%d", l.elementos[i]);
        if (i < l.tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}
