#ifndef LISTA_H
#define LISTA_H
#endif

#define MAX 100 
typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void inicializaLista(Lista *l);

int insereElemento(Lista *l, int elemento);

void uneListasOrdenadas(Lista *l1, Lista *l2, Lista *l3);

void exibeLista(Lista l);
