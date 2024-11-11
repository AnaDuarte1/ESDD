#include <stdio.h>
#include "operacoes.h"

void inicializaConjunto(Conjunto *c) {
    c->qtd = 0;
}

int contemElemento(Conjunto *c, int elem) {
    for (int i = 0; i < c->qtd; i++) {
        if (c->elementos[i] == elem) {
            return 1;  // Elemento encontrado
        }
    }
    return 0;  // Elemento não encontrado
}

void adicionaElemento(Conjunto *c, int elem) {
    if (!contemElemento(c, elem)) {  // Adiciona apenas se não estiver presente
        c->elementos[c->qtd] = elem;
        c->qtd++;
    }
}

Conjunto uniao(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);
    
    for (int i = 0; i < a.qtd; i++) {
        adicionaElemento(&c, a.elementos[i]);
    }
    for (int i = 0; i < b.qtd; i++) {
        adicionaElemento(&c, b.elementos[i]);
    }
    return c;
}

Conjunto intersecao(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);

    for (int i = 0; i < a.qtd; i++) {
        if (contemElemento(&b, a.elementos[i])) { // Verifica se o elemento de 'a' está em 'b'
            adicionaElemento(&c, a.elementos[i]);
        }
    }
    return c;
}

Conjunto diferenca(Conjunto a, Conjunto b) {
    Conjunto c;
    inicializaConjunto(&c);
    
    for (int i = 0; i < a.qtd; i++) {
        if (!contemElemento(&b, a.elementos[i])) {
            adicionaElemento(&c, a.elementos[i]);
        }
    }
    return c;
}
