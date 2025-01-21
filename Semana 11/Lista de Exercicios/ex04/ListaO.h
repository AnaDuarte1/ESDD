#ifndef LISTA_O_H
#define LISTA_O_H
#endif

typedef struct {
    int *dados;    
    int tamanho;    
    int capacidade; 
} Lista;

void inicializarLista(Lista *lista, int capacidade);

void liberarLista(Lista *lista);
Lista mesclarListas(const Lista *lista1, const Lista *lista2);
void imprimirLista(const Lista *lista);