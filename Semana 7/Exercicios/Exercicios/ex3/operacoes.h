#ifndef OPERACOES_H
#define OPERACOES_H

typedef struct {
    int elementos[100];
    int qtd;
} Conjunto;

void inicializaConjunto(Conjunto *c);
void adicionaElemento(Conjunto *c, int elem);
Conjunto uniao(Conjunto a, Conjunto b);
Conjunto intersecao(Conjunto a, Conjunto b);
Conjunto diferenca(Conjunto a, Conjunto b);

#endif
