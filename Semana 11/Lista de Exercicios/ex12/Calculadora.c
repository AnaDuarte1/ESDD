#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Calculadora.h"

// Função para criar uma pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

// Função para empilhar um valor na pilha
void empilhar(Pilha* pilha, float valor) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->valor = valor;
    novoNodo->proximo = pilha->topo;
    pilha->topo = novoNodo;
}

// Função para desempilhar um valor da pilha
float desempilhar(Pilha* pilha) {
    Nodo* nodoRemovido = pilha->topo;
    float valor = nodoRemovido->valor;
    pilha->topo = nodoRemovido->proximo;
    free(nodoRemovido);
    return valor;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Libera a memória da pilha
void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}

// Função para calcular uma expressão pós-fixada
float calcularPosfixada(const char* expressao) {
    Pilha* pilha = criarPilha();
    char token[50];
    int i = 0, j = 0;

    while (expressao[i] != '\0') {
        if (isdigit(expressao[i]) || expressao[i] == '.') {
            token[j++] = expressao[i];
        } else if (isspace(expressao[i])) {
            if (j > 0) {
                token[j] = '\0';
                empilhar(pilha, atof(token));
                j = 0;
            }
        } else {
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float resultado = 0;

            switch (expressao[i]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': resultado = a / b; break;
            }
            empilhar(pilha, resultado);
        }
        i++;
    }

    if (j > 0) {
        token[j] = '\0';
        empilhar(pilha, atof(token));
    }

    float resultadoFinal = desempilhar(pilha);
    liberarPilha(pilha);
    return resultadoFinal;
}
