#include <stdio.h>
#include "ListaO.h"

int main() {
    Lista lista1, lista2;
    inicializarLista(&lista1, 4); // Capacidade inicial de 4
    inicializarLista(&lista2, 6); // Capacidade inicial de 6

    int elemento;
    int n1, n2;

    printf("Digite o número de elementos da primeira lista: ");
    scanf("%d", &n1);

    printf("Digite os elementos da primeira lista (ordenados):\n");
    for (int i = 0; i < n1; i++) { 
        printf("Elemento %d: ", i + 1);
        scanf("%d", &elemento);
        adicionarElemento(&lista1, elemento);
    }

    printf("Digite o número de elementos da segunda lista: ");
    scanf("%d", &n2);

    printf("Digite os elementos da segunda lista (ordenados):\n");
    for (int i = 0; i < n2; i++) {
        int elemento;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &elemento);
        adicionarElemento(&lista2, elemento);
    }

    Lista listaMesclada = mesclarListas(&lista1, &lista2);

    printf("Lista mesclada sem elementos repetidos: ");
    imprimirLista(&listaMesclada);

    liberarLista(&lista1);
    liberarLista(&lista2);
    liberarLista(&listaMesclada);

    return 0;
}