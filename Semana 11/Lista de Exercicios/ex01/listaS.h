#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#endif 

#define MAX 100

typedef struct {
    int itens[MAX];  
    int tamanho;     
} ListaSequencial;

typedef ListaSequencial* Lista;

Lista criaLista(); 
int insereElemento(Lista lista, int valor);  
int verificaOrdenada(Lista lista);       
void imprimeLista(Lista lista);