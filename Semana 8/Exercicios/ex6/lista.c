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

void inverteLista(Lista *l) {
    int inicio = 0, fim = l->tamanho - 1;
    while (inicio < fim) {
        int temp = l->elementos[inicio];
        l->elementos[inicio] = l->elementos[fim];
        l->elementos[fim] = temp;
        inicio++;
        fim--;
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
