#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

void inicializaConjunto(Conjunto *c) {
    c->prox = 0;
}

int contemElemento(Conjunto *c, int elem) {
    for (int i = 0; i < c->prox; i++) {
        if (c->elementos[i] == elem) {
            return 1;  // Elemento encontrado
        }
    }
    return 0;  // Elemento não encontrado
}

void adicionaElemento(Conjunto *c, int elem) {
    if (!contemElemento(c, elem)) {  // Adiciona apenas se não estiver presente
        c->elementos[c->prox] = elem;
        c->prox++;
    }
}

Conjunto uniao(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);

    for (int i = 0; i < a.prox; i++) {
        adicionaElemento(&c, a.elementos[i]);
    }
    for (int i = 0; i < b.prox; i++) {
        adicionaElemento(&c, b.elementos[i]);
    }
    return c;
}

Conjunto intersecao(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);

    for (int i = 0; i < a.prox; i++) {
        if (contemElemento(&b, a.elementos[i])) { // Verifica se o elemento de 'a' está em 'b'
            adicionaElemento(&c, a.elementos[i]);
        }
    }
    return c;
}

Conjunto diferenca(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);

    for (int i = 0; i < a.prox; i++) {
        if (!contemElemento(&b, a.elementos[i])) {
            adicionaElemento(&c, a.elementos[i]);
        }
    }
    return c;
}
