#include <stdio.h>
#include <stdlib.h>
#include "ListaS.h"

int main() {
    Lista* l1 = criaLista();  
    Lista* l2 = criaLista();
    int numE, valor;

    printf("Quantos elementos você deseja inserir na lista L1? ");
    scanf("%d", &numE);

    for (int i = 0; i < numE; i++) {
        printf("Digite o %dº elemento: ", i + 1);
        scanf("%d", &valor);
        insereOrdenadoDes(l1, valor);
    }

    eliminarElementos(l1, l2);

    printf("\nLista 1: \n");
    imprimeLista(l1);


    printf("\nLista 2: \n");
    imprimeLista(l2);


    free(l1);
    free(l2);

    return 0;
}
