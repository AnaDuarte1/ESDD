#ifndef OPERACOES_H
#define OPERACOES_H
#endif

typedef struct {
    int elementos[100];
    int prox;
} Conjunto;

void inicializaConjunto(Conjunto *c);
void adicionaElemento(Conjunto *c, int elem);
Conjunto uniao(Conjunto a, Conjunto b);
Conjunto intersecao(Conjunto a, Conjunto b);
Conjunto diferenca(Conjunto a, Conjunto b);


