#ifndef PROVA_H
#define PROVA_H


#define MAX_TEORICA 3
#define MAX_LABORATORIOS 2

typedef struct salaT{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

typedef struct laboratoriosI{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

typedef struct espacosF{
    struct salaT salaT[MAX_TEORICA];
    struct laboratoriosI laboratoriosI[MAX_LABORATORIOS];
};


typedef struct espacosF Lista;

Lista* criaLista();
Lista* carregarDados();

float taxaOcupacaoT(Lista *espacosF);
float taxaOcupacaoI(Lista *espacosF);
float computadoresN(Lista *espacosF);
float espacosFisicosT(Lista *espacosF);

#endif







