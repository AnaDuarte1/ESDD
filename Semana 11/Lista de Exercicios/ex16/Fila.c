#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

// Função para criar uma fila
Fila* criaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->iterador = NULL;
    return fila;
}

// Função para destruir uma fila
void destroiFila(Fila* fila) {
    while (!filaVazia(fila)) {
        eliminaFila(fila);
    }
    free(fila);
}

// Função para inserir um elemento na fila
void insereFila(Fila* fila, int elemento) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;
    if (filaVazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// Função para eliminar um elemento da fila
int eliminaFila(Fila* fila) {
    if (filaVazia(fila)) {
        return -1; // Indicador de erro
    }
    No* temp = fila->inicio;
    int dado = temp->dado;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return dado;
}

bool filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para inicializar a iteração
void findFirst(Fila* fila) {
    fila->iterador = fila->inicio;
}

// Função para obter o próximo elemento na iteração
int findNext(Fila* fila) {
    if (fila->iterador == NULL) {
        return -1; // Indicador de erro
    }
    int dado = fila->iterador->dado;
    fila->iterador = fila->iterador->prox;
    return dado;
}

// Função para comparar duas filas
bool comparaFilas(Fila* f1, Fila* f2) {
    findFirst(f1);
    findFirst(f2);

    int elemento1, elemento2;
    while ((elemento1 = findNext(f1)) != -1 && (elemento2 = findNext(f2)) != -1) {
        if (elemento1 != elemento2) {
            return false;
        }
    }

    // Verificar se ambas as filas terminaram simultaneamente
    return findNext(f1) == -1 && findNext(f2) == -1;
}
