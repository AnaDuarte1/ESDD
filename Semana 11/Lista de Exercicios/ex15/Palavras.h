#ifndef PALAVRAS_H
#define PALAVRAS_H

#define TAM_MAX 1000 
#define TAM_PALAVRA 100 

typedef struct {
    char palavra[TAM_PALAVRA];
} Palavra;

void inverterPalavra(Palavra* p);
void processarTexto(char* texto);

#endif
