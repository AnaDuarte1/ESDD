#include <stdio.h>
#include "operacoes.h"

void imprimeConjunto(Conjunto c) {
    printf("{ ");
    for (int i = 0; i < c.prox; i++) {
        printf("%d ", c.elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto A, B, C;
    inicializaConjunto(&A);
    inicializaConjunto(&B);

    int n, elem;

    // Adiciona elementos ao conjunto A
    printf("Digite o número de elementos do conjunto A: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d de A: ", i + 1);
        scanf("%d", &elem);
        adicionaElemento(&A, elem);
    }

    // Adiciona elementos ao conjunto B
    printf("Digite o número de elementos do conjunto B: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d de B: ", i + 1);
        scanf("%d", &elem);
        adicionaElemento(&B, elem);
    }

    // Operações de Conjuntos
    C = uniao(A, B);
    printf("União de A e B: ");
    imprimeConjunto(C);

    C = intersecao(A, B);
    printf("Interseção de A e B: ");
    imprimeConjunto(C);

    C = diferenca(A, B);
    printf("Diferença de A e B: ");
    imprimeConjunto(C);

    return 0;
}
