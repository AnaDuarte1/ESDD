#ifndef LISTALIGACOES_H
#define LISTALIGACOES_H
#endif
typedef struct Ligacao {
    float custo;
    int id;
    struct Ligacao* proximo;
} Ligacao;

typedef struct ListaCircular {
    Ligacao* inicio;
} ListaCircular;


ListaCircular* criarLista();
void inserirLigacao(ListaCircular* lista, float custo, int id);
void removerLigacao(ListaCircular* lista);
void imprimirLista(ListaCircular* lista);
void liberarLista(ListaCircular* lista);


