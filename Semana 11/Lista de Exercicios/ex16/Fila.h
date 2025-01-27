#ifndef FILA_H
#define FILA_H

#include <stdbool.h>


typedef struct No {
    int dado;
    struct No* prox;
} No;

struct Fila {
    No* inicio;
    No* fim;
    No* iterador; // Ponteiro para iteração
};

typedef struct Fila Fila;

Fila* criaFila();
void destroiFila(Fila* fila);

// Operações básicas
void insereFila(Fila* fila, int elemento);
int eliminaFila(Fila* fila);
bool filaVazia(Fila* fila);

// Operações de iteração
void findFirst(Fila* fila);
int findNext(Fila* fila);

// Função para comparar duas filas
bool comparaFilas(Fila* f1, Fila* f2);

#endif
