#include <stdlib.h>
#include <math.h>
#include "ponto.h"


typedef struct ponto{
    float x;
    float y;
};

// Função para criar um ponto
Ponto* criaPto(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// Função para liberar memória de um ponto
void liberaPto(Ponto* p) {
    free(p);
}

// Função para calcular a distância entre dois pontos
float distanciaPto(Ponto* p1, Ponto* p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

float colineares(Ponto* p1, Ponto* p2, Ponto* p3){
    int determinante = (p2->x - p1->x) * (p3->y - p1->y) - (p3->x - p1->x) * (p2->y - p1->y);;

    return determinante == 0;
}
