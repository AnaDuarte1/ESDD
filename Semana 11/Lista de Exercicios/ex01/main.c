#include <stdio.h>
#include <stdlib.h>
#include "listaS.h"

int main() {
    Lista lista = criaLista();  

    insereElemento(lista, 10);
    insereElemento(lista, 20);
    insereElemento(lista, 30);
    insereElemento(lista, 25);

    printf("Lista: ");
    imprimeLista(lista);

    // Verificando se a lista está ordenada
    if (verificaOrdenada(lista)) {
        printf("A lista está ordenada.\n");
    } else {
        printf("A lista não está ordenada.\n");
    }

    free(lista);

    return 0;
}
