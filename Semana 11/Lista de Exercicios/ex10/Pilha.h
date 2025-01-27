#ifndef PILHA_H
#define PILHA_H
#endif 

typedef struct No {
    int dado; 
    struct No* proximo; 
} No;

typedef struct {
    No* topo; 
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha* pilha, int dado);
int desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void exibirPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);

