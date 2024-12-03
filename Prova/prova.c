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
            {"E", 1, 27, 40},
            {"F", 1, 35, 40},
            {"F", 2, 40, 40},
    };

    struct laboratoriosI array_laboratoriosI[MAX_LABORATORIOS] = {
        {"I", 111, 30, 30},
        {"I", 112, 30, 40},
    };

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

