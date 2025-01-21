#include <stdio.h>
#include "ListaE.h"

int main() {
    Lista* l1 = NULL; 
    Lista* l2 = NULL;
    Lista* l3;

    int numEle1, numEle2, valor;

    printf("Digite a quantidade de elementos para a lista L1: ");
    scanf("%d", &numEle1);

    for (int i = 0; i < numEle1; i++) {
        printf("Digite o %dº valor para L1: ", i + 1);
        scanf("%d", &valor);
        l1 = inserirElemento(l1, valor); 
    }

    printf("\nDigite a quantidade de elementos para a lista L2: ");
    scanf("%d", &numEle2);

    for (int i = 0; i < numEle2; i++) {
        printf("Digite o %dº valor para L2: ", i + 1);
        scanf("%d", &valor);
        l2 = inserirElemento(l2, valor);  
    }

    l3 = unirListas(l1, l2);

    printf("\nLista L1: ");
    imprimirLista(l1);

    printf("Lista L2: ");
    imprimirLista(l2);

    printf("Lista L3 (União de L1 e L2): ");
    imprimirLista(l3);

    return 0;
}
