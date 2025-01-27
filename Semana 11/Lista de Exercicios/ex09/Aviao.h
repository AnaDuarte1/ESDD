// Avião.h
#ifndef AVIAO_H
#define AVIAO_H
#endif

typedef struct Avião {
    char nome[20];
    float nivelCombustivel; // em litros
    struct Avião* proximo; // ponteiro para o próximo avião na lista
} Avião;

Avião* criarAvião(const char* nome, float nivelCombustivel);
void adicionarAvião(Avião** lista, Avião* novoAvião);
Avião* removerAvião(Avião** lista);
void exibirFila(Avião* lista);
void liberarLista(Avião* lista);
