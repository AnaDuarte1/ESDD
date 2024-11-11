#ifndef LISTA_H
#define LISTA_H

#define MAX 100 

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;
void inicializaLista(Lista *l);

int insereElemento(Lista *l, int elemento);

void inverteLista(Lista *l);

void exibeLista(Lista l);

#endif
