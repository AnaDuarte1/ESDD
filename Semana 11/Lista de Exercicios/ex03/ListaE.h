#ifndef LISTAE_H
#define LISTAE_H
#endif

typedef struct Lista {
    int valor;
    struct Lista* proximo;
} Lista;

Lista* criarLista();

Lista* inserirElemento(Lista* lista, int valor);
void imprimirLista(Lista* lista);
Lista* unirListas(Lista* l1, Lista* l2);


