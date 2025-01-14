#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#endif 

#define MAX 100

typedef struct {
    int itens[MAX];  
    int tamanho;     
} Lista1;

typedef struct {
    int itens[MAX];  
    int tamanho;     
} Lista2;

typedef Lista1* Lista;

Lista criaLista(); 
int insereElemento(Lista lista, int valor);  
int verificaOrdenada(Lista lista);       
void imprimeLista(Lista lista);