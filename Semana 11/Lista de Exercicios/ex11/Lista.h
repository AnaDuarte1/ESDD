#ifndef LISTA_H
#define LISTA_H
#endif

typedef struct No {
    int dado; 
    struct No* proximo; 
} No;

typedef struct {
    No* cabeca; // Ponteiro para o primeiro nó da lista
} Lista;

Lista* criarLista();
void adicionarElemento(Lista* lista, int dado);
void removerElemento(Lista* lista, int dado);
void exibirLista(Lista* lista);
void liberarLista(Lista* lista);
