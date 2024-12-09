#ifndef PROVA_H
#define PROVA_H


#define MAX_TEORICA 15
#define MAX_LABORATORIOI 13
#define MAX_SALAADM 8
#define MAX_LABORATORIOSM 11
#define MAX_BIBLIOTECA 1
#define MAX_AUDITORIO 1
#define MAX_SALAPROFE 14
#define MAX_MANUTENCAO 4
#define MAX_PATIO 8
#define MAX_LABORATORIOS 4

 struct salaT{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct laboratoriosI{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct salaAdm{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct laboratorioM{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
}

 struct biblioteca{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct auditorio{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct patio{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct salaProfessores{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct manutenção{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
};

 struct outrosLab{
  char bloco[1];
  int indentificacao;
  int capacidadeA;
  int capacidadeM;
}

 struct espacosF{
    struct salaT salaT[MAX_TEORICA];
    struct laboratoriosI laboratoriosI[MAX_LABORATORIOI];
    struct salaAdm salaAdm[MAX_SALAADM];
    struct laboratorioM laboratorioM[MAX_LABORATORIOSM];
    struct biblioteca biblioteca[MAX_BIBLIOTECA];
    struct auditorio auditorio[MAX_AUDITORIO];
    struct patio patio[MAX];
    struct salaProfessores[MAX_SALAPROFE];
    struct manutenção manutenção[MAX_MANUTENCAO];
    struct outrosLab outrosLab[MAX_LABORATORIOS];
};


typedef struct espacosF Lista;

Lista* criaLista();
Lista* carregarDados();

float taxaOcupacaoT(Lista *espacosF);
float taxaOcupacaoI(Lista *espacosF);
float computadoresN(Lista *espacosF);
float espacosFisicosT(Lista *espacosF);
void filtrarPorBloco(Lista *espacosF, const char *bloco);

#endif







