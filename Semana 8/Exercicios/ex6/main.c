#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista1;
    inicializaLista(&lista1);

    // Adicionando elementos à lista
    int elementos[] = {3, 8, 4, 2, 5};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    for (int i = 0; i < n; i++) {
        insereElemento(&lista1, elementos[i]);
    }

    printf("Lista original: ");
    exibeLista(lista1);

    // Invertendo a lista
    inverteLista(&lista1);

    printf("Lista invertida: ");
    exibeLista(lista1);

    return 0;
}
