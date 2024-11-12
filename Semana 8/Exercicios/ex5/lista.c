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
    return 1; 
}

void uneListasOrdenadas(Lista *l1, Lista *l2, Lista *l3) {
    int i = 0, j = 0, k = 0;

    // Percorre ambas as listas enquanto houver elementos em ambas
    while (i < l1->tamanho && j < l2->tamanho) {
        if (l1->elementos[i] < l2->elementos[j]) {
            l3->elementos[k++] = l1->elementos[i++];
        } else {
            l3->elementos[k++] = l2->elementos[j++];
        }
    }

    // Copia os elementos restantes de l1, se houver
    while (i < l1->tamanho) {
        l3->elementos[k++] = l1->elementos[i++];
    }

    // Copia os elementos restantes de l2, se houver
    while (j < l2->tamanho) {
        l3->elementos[k++] = l2->elementos[j++];
    }

    l3->tamanho = k; // Define o tamanho da lista resultante
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
