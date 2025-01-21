#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#endif
#define MAX 100

typedef struct {
    int itens[MAX];  
    int tamanho;     
} Lista;

typedef Lista* l1;
typedef Lista* l2;

Lista* criaLista();

void insereOrdenadoDes(Lista* lista, int valor);

void eliminarElementos(Lista* l1, Lista* l2);

void imprimeLista(Lista* lista);

 
