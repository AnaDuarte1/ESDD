#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista1;
    inicializaLista(&lista1);

    int elementos[] = {1, 3, 4, 5, 2, 3, 4};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    for (int i = 0; i < n; i++) {
        insereElemento(&lista1, elementos[i]);
    }

    printf("Lista original: ");
    exibeLista(lista1);

    removeDuplicados(&lista1);

    printf("Lista sem duplicados: ");
    exibeLista(lista1);

    return 0;
}
