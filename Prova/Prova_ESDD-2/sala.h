#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
#define MAX_SALAS 50

struct salas_adm{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max; 
};

struct salas_mec{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct salas_prof{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct patios{
    char bloco[3];
    char desc[50];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct bibliotecas{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct auditorios{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct salas_manutencao{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct salas_teo{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
}; 

struct lab_info{
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
}; 

struct labs_extra{
    char bloco[3];
    char desc[50];
    int identificacao;
    int capacidade_atual;
    int capacidade_max;
};

struct lista_salas {
    struct salas_teo salas_teo[MAX_SALAS];
    struct lab_info lab_info[MAX_SALAS];
    struct salas_adm salas_adm[MAX_SALAS];
    struct salas_mec salas_mec[MAX_SALAS];
    struct salas_prof salas_prof[MAX_SALAS];
    struct bibliotecas bibliotecas[MAX_SALAS];
    struct salas_manutencao salas_manutencao[MAX_SALAS];
    struct labs_extra labs_extra[MAX_SALAS];
    struct auditorios auditorios[MAX_SALAS];
    struct patios patios[MAX_SALAS];
};

typedef struct lista_salas Lista;

Lista* criaLista();
Lista* carregarDados(Lista* lista_salas);
void taxaOcupacaoTodasSalas(Lista *lista_salas);
void calculaPC(Lista *lista_salas);
void listarSalasPorBloco(Lista *lista_salas);
void listarSalasPorTipo(Lista *lista_salas);
void exibirMenu();

void listarTodasAsSalas(Lista *lista_salas);
void cadastrarSala(Lista* lista_salas);
#endif
