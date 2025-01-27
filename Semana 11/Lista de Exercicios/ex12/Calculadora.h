#ifndef CALCULADORA_H
#define CALCULADORA_H
#endif
typedef struct Nodo {
    float valor;
    struct Nodo* proximo;
} Nodo;

typedef struct Pilha {
    Nodo* topo;
} Pilha;

// Funções para manipulação da pilha
Pilha* criarPilha();
void empilhar(Pilha* pilha, float valor);
float desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void liberarPilha(Pilha* pilha);

// Funções da calculadora pós-fixada
float calcularPosfixada(const char* expressao);


