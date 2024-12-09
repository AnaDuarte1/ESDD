#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "prova.h"

Lista* criaLista() {
    Lista *espacosF = (Lista*) malloc(sizeof(struct espacosF)); 
    return espacosF;
}

Lista* carregarDados(){
    Lista *espacosF = criaLista();

    struct salaT array_salaT[MAX_TEORICA] = {
        {"D", 101, 27, 40},
        {"D", 102, 35, 40},
        {"D", 103, 35, 40},
        {"D", 104, 35, 40},
        {"D", 105, 35, 40},
        {"D", 106, 35, 40},
        {"E", 101, 27, 40},
        {"E", 102, 35, 40},
        {"E", 103, 35, 40},
        {"E", 104, 35, 40},
        {"F", 101, 35, 40},
        {"F", 102, 35, 40},
        {"F", 103, 35, 40}, 
    };

    struct laboratoriosI array_laboratoriosI[MAX_LABORATORIOS] = {
        {"I", 101, 30, 30},
        {"I", 101, 30, 40},
        {"I", 102, 30, 40},
        {"I", 103, 30, 40},
        {"I", 104, 30, 40},
        {"I", 105, 30, 40},
        {"I", 106, 30, 40},
        {"I", 107, 30, 40},
        {"I", 111, 30, 40},
        {"I", 112, 30, 40},
        {"I", 113, 30, 40},
    };

    struct salaAdm array_salaAdm[MAX_SALAADM] = {
        {"C", 101, 30, 40},
        {"C", 102, 30, 40},
        {"C", 103, 30, 40},
        {"C", 104, 30, 40},
        {"C", 105, 30, 40},
        {"C", 106, 30, 40},
        {"C", 108, 30, 40},
        {"C", 109, 40, 40},
        {"G", 101, 30, 40},
        {"G", 102, 30, 40},
    }
    
    struct laboratorioM array_laboratorioM[MAX_LABORATORIOSM]{
        {"J", 101, 30, 40},
        {"J", 102, 30, 40},
        {"J", 103, 30, 40},
        {"J", 105, 30, 40},
        {"J", 106, 30, 40},
        {"J", 107, 30, 40},
        {"J", 108, 30, 40},
        {"J", 109, 30, 40},
        {"J", 110, 30, 40},
        {"J", 111, 30, 40},
        {"J", 112, 30, 40},

    }

    struct biblioteca array_biblioteca[MAX_BIBLIOTECA]{
        {"A", 101, 30, 40},
        {"A", 102, 30, 40},
        {"A", 103, 30, 40},
        {"A", 104, 30, 40},
        {"A", 105, 30, 40},
        {"A", 106, 30, 40},
    }

    struct auditorio array_auditorio[MAX_AUDITORIO]{
        {"B", 101, 250, 250},
        {"B", 105, 30, 40},
        {"B", 109, 30, 40},
        {"B", 110, 30, 40},
        {"B", 111, 30, 40},
        {"B", 112, 30, 40},
        {"B", 113, 30, 40},
    }

    struct patio array_patio[MAX_PATIO]{
        {"G", 103, 30, 40},
        {"G", 106, 30, 40},

    }

    struct salaProfessores array_salaP[MAX_SALAPROFE]{
        {"J", 201, 30, 40},
        {"J", 202, 30, 40},
        {"J", 203, 30, 40},
        {"J", 204, 30, 40},
        {"J", 205, 30, 40},
        {"J", 207, 30, 40},
        {"J", 207, 30, 40},
        {"J", 209, 30, 40},
        {"J", 210, 30, 40},
        {"J", 211, 30, 40},
        {"J", 212, 30, 40},
        {"J", 213, 30, 40},
        {"J", 214, 30, 40},
        {"J", 215, 30, 40},
    }

    struct manutencao array_manutencao[MAX_MANUTENCAO]{
        {"H", 101, 30, 40},
        {"H", 102, 30, 40},
        {"H", 103, 30, 40},
        {"H", 104, 30, 40},
    }

    struct OutrosLab array_outrosLab[MAX_LABORATORIOS]{
        {"E", 105, 30, 40},
        {"I", 108, 30, 40},
        {"I", 109, 30, 40},
        {"F", 104, 30, 40},
        {"G", 107, 30, 40},
    }

    for(int i = 0; i < MAX_TEORICA; i++){
        espacosF->salaT[i] = array_salaT[i];
    }

    for(int i = 0; i < MAX_LABORATORIOS; i++){
        espacosF->laboratoriosI[i] = array_laboratoriosI[i];
    }

    return espacosF;
}

float taxaOcupacaoT(Lista *espacosF){
    float totalM = 0;
    float totalA = 0;

    for (int i = 0; i < MAX_TEORICA; i++) {
        totalA = espacosF->salaT[i].capacidadeA;
        totalM = espacosF->salaT[i].capacidadeM;

        float ocupacao =  (totalA / totalM) * 100;

        printf("Taxa de ocupação total das salas teóricas: %.2f%%\n", ocupacao);
    }

}

float taxaOcupacaoI(Lista *espacosF){
    float totalM = 0;
    float totalA = 0;

    for (int i = 0; i < MAX_LABORATORIOS; i++) {
        totalA = espacosF->laboratoriosI[i].capacidadeA;
        totalM = espacosF->laboratoriosI[i].capacidadeM;

        float ocupacao =  (totalA / totalM) * 100;

        printf("Taxa de ocupação total das salas de laboratorios: %.2f%%\n", ocupacao);
    }
}

float computadoresN(Lista *espacosF){
    float falta = 0;

    for (int i = 0; i < MAX_LABORATORIOS; i++) {
        falta = espacosF->laboratoriosI[i].capacidadeM - espacosF->laboratoriosI[i].capacidadeA;
        
        printf("Computadores necessários para ocupar 100%% de ocupação: %.2f\n", falta);

    }

}


void filtrarPorBloco(Lista *espacosF, const char *bloco) {
    printf("Salas do Bloco %s:\n", bloco);
    
    // Filtrando salas teóricas
    for (int i = 0; i < MAX_TEORICA; i++) {
        if (strcmp(espacosF->salaT[i].bloco, bloco) == 0) {
            printf("Sala Teórica %d, Capacidade Atual: %d, Capacidade Máxima: %d\n", 
                   espacosF->salaT[i].indentificacao, espacosF->salaT[i].capacidadeA, espacosF->salaT[i].capacidadeM);
        }
    }

    // Filtrando laboratórios
    for (int i = 0; i < MAX_LABORATORIOS; i++) {
        if (strcmp(espacosF->laboratoriosI[i].bloco, bloco) == 0) {
            printf("Laboratório %d, Capacidade Atual: %d, Capacidade Máxima: %d\n", 
                   espacosF->laboratoriosI[i].indentificacao, espacosF->laboratoriosI[i].capacidadeA, espacosF->laboratoriosI[i].capacidadeM);
        }
    }
}

float espacosFisicosT(Lista *espacosF) {
    void *espacos[MAX_TEORICA + MAX_LABORATORIOS];
    
    for (int i = 0; i < MAX_TEORICA; i++) {
        espacos[i] = &espacosF->salaT[i];
    }
    
    for (int i = 0; i < MAX_LABORATORIOS; i++) {
        espacos[MAX_TEORICA + i] = &espacosF->laboratoriosI[i];
    }
    
    for (int i = 0; i < MAX_TEORICA + MAX_LABORATORIOS - 1; i++) {
        int indexMaior = i;
        
        // Comparar a capacidade máxima de cada espaço
        for (int j = i + 1; j < MAX_TEORICA + MAX_LABORATORIOS; j++) {
            int capacidadeA = 0, capacidadeB = 0;
            
            // Obter a capacidade máxima dos espaços comparados
            if (i < MAX_TEORICA) {
                capacidadeA = espacosF->salaT[i].capacidadeM;
            } else {
                capacidadeA = espacosF->laboratoriosI[i - MAX_TEORICA].capacidadeM;
            }

            if (j < MAX_TEORICA) {
                capacidadeB = espacosF->salaT[j].capacidadeM;
            } else {
                capacidadeB = espacosF->laboratoriosI[j - MAX_TEORICA].capacidadeM;
            }

            if (capacidadeB > capacidadeA) {
                indexMaior = j;
            }
        }

        // Troca os espaços
        void *temp = espacos[i];
        espacos[i] = espacos[indexMaior];
        espacos[indexMaior] = temp;
    }

    printf("Espacos fisicos ordenados pela capacidade maxima:\n");
    for (int i = 0; i < MAX_TEORICA + MAX_LABORATORIOS; i++) {
        if (i < MAX_TEORICA) {
            struct salaT *sala = (struct salaT *)espacos[i];
            printf("Sala Teórica: Bloco %s, ID %d, Capacidade Atual %d, Capacidade Máxima %d\n", 
                    sala->bloco, sala->indentificacao, sala->capacidadeA, sala->capacidadeM);
        } else {
            struct laboratoriosI *lab = (struct laboratoriosI *)espacos[i];
            printf("Laboratório: Bloco %s, ID %d, Capacidade Atual %d, Capacidade Máxima %d\n", 
                    lab->bloco, lab->indentificacao, lab->capacidadeA, lab->capacidadeM);
        }
    }
}

