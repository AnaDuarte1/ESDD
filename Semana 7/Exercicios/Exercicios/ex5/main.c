
#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista1, lista2, lista3;
    inicializaLista(&lista1);
    inicializaLista(&lista2);
    inicializaLista(&lista3);

    // Adicionando elementos à lista1
    int elementos1[] = {1, 3, 5, 7};
    int n1 = sizeof(elementos1) / sizeof(elementos1[0]);
    for (int i = 0; i < n1; i++) {
        insereElemento(&lista1, elementos1[i]);
    }

    // Adicionando elementos à lista2
    int elementos2[] = {2, 4, 6};
    int n2 = sizeof(elementos2) / sizeof(elementos2[0]);
    for (int i = 0; i < n2; i++) {
        insereElemento(&lista2, elementos2[i]);
    }

    printf("Lista 1: ");
    exibeLista(lista1);

    printf("Lista 2: ");
    exibeLista(lista2);

    // Unindo as listas ordenadas
    uneListasOrdenadas(&lista1, &lista2, &lista3);

    printf("Lista unida e ordenada: ");
    exibeLista(lista3);

    return 0;
}
