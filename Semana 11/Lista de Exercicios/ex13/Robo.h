#ifndef ROBO_H
#define ROBO_H
#endif

typedef struct Nodo {
    char comando;
    struct Nodo* proximo;
} Nodo;

typedef struct Pilha {
    Nodo* topo;
} Pilha;

// Funções para manipulação da pilha
Pilha* criarPilha();
void empilhar(Pilha* pilha, char comando);
char desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void liberarPilha(Pilha* pilha);

// Funções relacionadas ao robô
void imprimirCaminhoIda(Pilha* pilha);
void imprimirCaminhoVolta(Pilha* pilha);


