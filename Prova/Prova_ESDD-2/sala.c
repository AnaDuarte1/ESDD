#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sala.h" 
#include <ctype.h>

Lista* criaLista(){
    Lista* lista_salas; 
    lista_salas = (Lista*) malloc(sizeof(Lista)); 
    return lista_salas;
}
Lista* carregarDados(Lista* lista_salas) {

    struct salas_teo array_salasTeo[MAX_SALAS] = {
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

    struct lab_info array_labInfo[MAX_SALAS] = {
        {"I", 101, 30, 30},
        {"I", 102, 30, 40},
        {"I", 103, 30, 30},
        {"I", 104, 30, 40},
        {"I", 105, 30, 30},
        {"I", 106, 30, 40},
        {"I", 111, 30, 30},
        {"I", 112, 30, 40},
    };

    struct salas_adm array_salasAdm[MAX_SALAS] = {
        {"C", 101, 30, 30},
        {"C", 102, 30, 30},
        {"C", 103, 30, 30},
        {"C", 104, 30, 30},
        {"C", 105, 30, 30},
        {"C", 106, 30, 30},
        {"C", 107, 30, 30},
        {"C", 108, 30, 30},
        {"C", 109, 30, 30},
        {"I", 107, 30, 30},
        {"I", 113, 30, 40},
        {"G", 101, 30, 40},
        {"G", 102, 30, 40},
    };

    struct salas_mec array_salasMec[MAX_SALAS] = {
        {"J", 101, 30, 30},
        {"J", 102, 30, 30},
        {"J", 103, 30, 30},
        {"J", 105, 30, 30},
        {"J", 106, 30, 30},
        {"J", 107, 30, 30},
        {"J", 108, 30, 30},
        {"J", 109, 30, 30},
        {"J", 110, 30, 30},
        {"J", 111, 30, 30},
    };

    struct salas_prof array_salasProf[MAX_SALAS] = {
        {"J", 201, 30, 30},
        {"J", 202, 30, 30},
        {"J", 203, 30, 30},
        {"J", 204, 30, 30},
        {"J", 205, 30, 30},
        {"J", 207, 30, 30},
        {"J", 208, 30, 30},
        {"J", 209, 30, 30},
        {"J", 210, 30, 30},
        {"J", 211, 30, 30},
        {"J", 212, 30, 30},
        {"J", 213, 30, 30},
        {"J", 214, 30, 30},
        {"J", 215, 30, 30},

    };

    struct bibliotecas array_bibliotecas[MAX_SALAS] = {
        {"A", 101, 30, 30},
        {"A", 102, 30, 30},
        {"A", 103, 30, 30},
        {"A", 104, 30, 30},
        {"A", 105, 30, 30},
        {"A", 106, 30, 30},
    };

    struct salas_manutencao array_Manutencao[MAX_SALAS] = {
        {"H", 101, 30, 30},
        {"H", 102, 30, 30},
        {"H", 103, 30, 30},
        {"H", 104, 30, 30},
    };

    struct labs_extra array_extra[MAX_SALAS] = {
        {"E", "Matemática", 105, 30, 30},
        {"F", "Audiovisual", 104, 30, 30},
        {"I", "Química e Biologia", 109, 30, 30},
        {"I", "Física", 108, 30, 30},
        {"G", "Iniciação Científica", 107, 30, 30},
        {"J", "Iniciação Científica", 112, 30, 30},
    };
    
    struct auditorios array_auditorios[MAX_SALAS] = {
        {"B", 101, 30, 30},
        {"B", 109, 30, 30},
        {"B", 110, 30, 30},
        {"B", 111, 30, 30},
        {"B", 112, 30, 30},
        {"B", 113, 30, 30},
    };

    struct patios array_patios[MAX_SALAS] = {
        {"G", "Cantina", 105, 30, 30},
    };

    for (int i = 0; i < MAX_SALAS; i++) {
        lista_salas->salas_teo[i] = array_salasTeo[i];
        lista_salas->lab_info[i] = array_labInfo[i];
        lista_salas->salas_adm[i] = array_salasAdm[i];
        lista_salas->salas_mec[i] = array_salasMec[i];
        lista_salas->salas_prof[i] = array_salasProf[i];
        lista_salas->bibliotecas[i] = array_bibliotecas[i];
        lista_salas->salas_manutencao[i] = array_Manutencao[i];
        lista_salas->labs_extra[i] = array_extra[i];
        lista_salas->auditorios[i] = array_auditorios[i];
        lista_salas->patios[i] = array_patios[i];
    }
    
   
    return lista_salas;
}

void taxaOcupacaoTodasSalas(Lista *lista_salas) {
    struct salas_teo* salasTeo = lista_salas->salas_teo;
    struct lab_info* salasLab = lista_salas->lab_info;
    struct salas_adm* salasAdm = lista_salas->salas_adm;
    struct salas_mec* salasMec = lista_salas->salas_mec;
    struct salas_prof* salasProf = lista_salas->salas_prof;
    struct bibliotecas* salasBibliotecas = lista_salas->bibliotecas;
    struct salas_manutencao* salasManutencao = lista_salas->salas_manutencao;
    struct labs_extra* salasExtra = lista_salas->labs_extra;
    struct auditorios* salasAuditorios = lista_salas->auditorios;
    struct patios* salasPatio = lista_salas->patios;

    printf("\n===== Salas Teóricas =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasTeo[i].capacidade_max > 0) { 
            printf("Ocupação da Sala Teórica %d (Bloco %s): %.1f%%\n", 
                salasTeo[i].identificacao, salasTeo[i].bloco, 
                ((float) salasTeo[i].capacidade_atual / salasTeo[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Laboratórios =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasLab[i].capacidade_max > 0) {  
            printf("Ocupação do Laboratório %d (Bloco %s): %.1f%%\n", 
                salasLab[i].identificacao, salasLab[i].bloco, 
                ((float) salasLab[i].capacidade_atual / salasLab[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Salas Administrativas =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasAdm[i].capacidade_max > 0) {  
            printf("Ocupação da Sala Administrativa %d (Bloco %s): %.1f%%\n", 
                salasAdm[i].identificacao, salasAdm[i].bloco, 
                ((float) salasAdm[i].capacidade_atual / salasAdm[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Salas Mecânicas =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasMec[i].capacidade_max > 0) {  
            printf("Ocupação da Sala Mecânica %d (Bloco %s): %.1f%%\n", 
                salasMec[i].identificacao, salasMec[i].bloco, 
                ((float) salasMec[i].capacidade_atual / salasMec[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Salas de Professor =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasProf[i].capacidade_max > 0) { 
            printf("Ocupação da Sala de Professor %d (Bloco %s): %.1f%%\n", 
                salasProf[i].identificacao, salasProf[i].bloco, 
                ((float) salasProf[i].capacidade_atual / salasProf[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Bibliotecas =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasBibliotecas[i].capacidade_max > 0) { 
            printf("Ocupação da Biblioteca %d (Bloco %s): %.1f%%\n", 
                salasBibliotecas[i].identificacao, salasBibliotecas[i].bloco, 
                ((float) salasBibliotecas[i].capacidade_atual / salasBibliotecas[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Salas de Manutenção =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasManutencao[i].capacidade_max > 0) {  
            printf("Ocupação da Sala de Manutenção %d (Bloco %s): %.1f%%\n", 
                salasManutencao[i].identificacao, salasManutencao[i].bloco, 
                ((float) salasManutencao[i].capacidade_atual / salasManutencao[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Laboratórios Extras =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasExtra[i].capacidade_max > 0) { 
            printf("Ocupação do Laboratório Extra %d (Bloco %s): %.1f%%\n", 
                salasExtra[i].identificacao, salasExtra[i].bloco, 
                ((float) salasExtra[i].capacidade_atual / salasExtra[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Auditórios =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasAuditorios[i].capacidade_max > 0) {  
            printf("Ocupação do Auditório %d (Bloco %s): %.1f%%\n", 
                salasAuditorios[i].identificacao, salasAuditorios[i].bloco, 
                ((float) salasAuditorios[i].capacidade_atual / salasAuditorios[i].capacidade_max) * 100);
        }
    }

    printf("\n===== Pátios =====\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salasPatio[i].capacidade_max > 0) {  
            printf("Ocupação do Pátio %d (Bloco %s): %.1f%%\n", 
                salasPatio[i].identificacao, salasPatio[i].bloco, 
                ((float) salasPatio[i].capacidade_atual / salasPatio[i].capacidade_max) * 100);
        }
    }
}


void calculaPC(Lista *lista_salas){
    int i = 0;
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->lab_info[i].capacidade_max > 0) {  
            int falta = lista_salas->lab_info[i].capacidade_max - lista_salas->lab_info[i].capacidade_atual;
            printf("No laboratório de Informática %d (Bloco %s), faltam %d computadores para 100%% de taxa de ocupação.\n", 
                   lista_salas->lab_info[i].identificacao, 
                   lista_salas->lab_info[i].bloco, 
                   falta);
        }
    }
}

void listarSalasPorBloco(Lista *lista_salas) {
    char bloco[3];
    printf("Digite o bloco: ");
    scanf(" %2s", bloco); 

    for (int i = 0; bloco[i] != '\0'; i++) {
        bloco[i] = toupper(bloco[i]);
    }

    struct salas_teo* salasTeo = lista_salas->salas_teo;
    struct lab_info* salasLab = lista_salas->lab_info;
    struct salas_adm* salasAdm = lista_salas->salas_adm;
    struct salas_mec* salasMec = lista_salas->salas_mec;
    struct salas_prof* salasProf = lista_salas->salas_prof;
    struct bibliotecas* salasBibliotecas = lista_salas->bibliotecas;
    struct salas_manutencao* salasManutencao = lista_salas->salas_manutencao;
    struct labs_extra* salasExtra = lista_salas->labs_extra;
    struct auditorios* salasAuditorio = lista_salas->auditorios;
    struct patios* salasPatio = lista_salas->patios;

    int encontrado = 0; 

    printf("\nSalas no bloco %s:\n", bloco);

    for (int i = 0; i < MAX_SALAS; i++) {
        if (strcmp(salasTeo[i].bloco, bloco) == 0) {
            printf("Sala Teórica %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasTeo[i].identificacao, bloco, 
                ((float) salasTeo[i].capacidade_atual / salasTeo[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasLab[i].bloco, bloco) == 0) {
            printf("Laboratório %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasLab[i].identificacao, bloco, 
                ((float) salasLab[i].capacidade_atual / salasLab[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasAdm[i].bloco, bloco) == 0) {
            printf("Sala Administrativa %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasAdm[i].identificacao, bloco, 
                ((float) salasAdm[i].capacidade_atual / salasAdm[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasMec[i].bloco, bloco) == 0) {
            printf("Sala Mecânica %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasMec[i].identificacao, bloco, 
                ((float) salasMec[i].capacidade_atual / salasMec[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasProf[i].bloco, bloco) == 0) {
            printf("Sala de Professor %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasProf[i].identificacao, bloco, 
                ((float) salasProf[i].capacidade_atual / salasProf[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasBibliotecas[i].bloco, bloco) == 0) {
            printf("Biblioteca %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasBibliotecas[i].identificacao, bloco, 
                ((float) salasBibliotecas[i].capacidade_atual / salasBibliotecas[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasManutencao[i].bloco, bloco) == 0) {
            printf("Sala de Manutenção %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasManutencao[i].identificacao, bloco, 
                ((float) salasManutencao[i].capacidade_atual / salasManutencao[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasExtra[i].bloco, bloco) == 0) {
            printf("Laboratório Extra %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasExtra[i].identificacao, bloco, 
                ((float) salasExtra[i].capacidade_atual / salasExtra[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasAuditorio[i].bloco, bloco) == 0) {
            printf("Auditório %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasAuditorio[i].identificacao, bloco, 
                ((float) salasAuditorio[i].capacidade_atual / salasAuditorio[i].capacidade_max) * 100);
            encontrado = 1;
        } else if (strcmp(salasPatio[i].bloco, bloco) == 0) {
            printf("Pátio %d (Bloco %s) - Ocupação: %.1f%%\n", 
                salasPatio[i].identificacao, bloco, 
                ((float) salasPatio[i].capacidade_atual / salasPatio[i].capacidade_max) * 100);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Bloco %s não encontrado.\n", bloco);
    }
}

void listarSalasPorTipo(Lista *lista_salas) {
    char tipo[20];
    printf("Digite o tipo de sala [teorica, informatica, administrativa, mecanica, manutencao, patios, auditorios, bibliotecas, extras]: ");
    scanf("%s", tipo);
    if (strcmp(tipo, "teorica") == 0) {
        printf("Salas Teóricas:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->salas_teo[i].identificacao != 0) { 
                printf("Sala Teórica %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->salas_teo[i].identificacao, lista_salas->salas_teo[i].bloco, 
                    ((float) lista_salas->salas_teo[i].capacidade_atual / lista_salas->salas_teo[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "informatica") == 0) {
        printf("Laboratórios de Informática:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->lab_info[i].identificacao != 0) { 
                printf("Laboratório %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->lab_info[i].identificacao, lista_salas->lab_info[i].bloco, 
                    ((float) lista_salas->lab_info[i].capacidade_atual / lista_salas->lab_info[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "administrativa") == 0) {
        printf("Salas Administrativas:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->salas_adm[i].identificacao != 0) { 
                printf("Sala Administrativa %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->salas_adm[i].identificacao, lista_salas->salas_adm[i].bloco, 
                    ((float) lista_salas->salas_adm[i].capacidade_atual / lista_salas->salas_adm[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "mecanica") == 0) {
        printf("Salas de Mecânica:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->salas_mec[i].identificacao != 0) { 
                printf("Sala de Mecânica %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->salas_mec[i].identificacao, lista_salas->salas_mec[i].bloco, 
                    ((float) lista_salas->salas_mec[i].capacidade_atual / lista_salas->salas_mec[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "manutencao") == 0) {
        printf("Salas de Manutenção:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->salas_manutencao[i].identificacao != 0) { 
                printf("Sala de Manutenção %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->salas_manutencao[i].identificacao, lista_salas->salas_manutencao[i].bloco, 
                    ((float) lista_salas->salas_manutencao[i].capacidade_atual / lista_salas->salas_manutencao[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "patios") == 0) {
        printf("Pátios:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->patios[i].identificacao != 0) { 
                printf("Pátio %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->patios[i].identificacao, lista_salas->patios[i].bloco, 
                    ((float) lista_salas->patios[i].capacidade_atual / lista_salas->patios[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "auditorios") == 0) {
        printf("Auditórios:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->auditorios[i].identificacao != 0) { 
                printf("Auditório %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->auditorios[i].identificacao, lista_salas->auditorios[i].bloco, 
                    ((float) lista_salas->auditorios[i].capacidade_atual / lista_salas->auditorios[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "bibliotecas") == 0) {
        printf("Bibliotecas:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->bibliotecas[i].identificacao != 0) { 
                printf("Biblioteca %d (Bloco %s) - Ocupação: %.1f%%\n", 
                    lista_salas->bibliotecas[i].identificacao, lista_salas->bibliotecas[i].bloco, 
                    ((float) lista_salas->bibliotecas[i].capacidade_atual / lista_salas->bibliotecas[i].capacidade_max) * 100);
            }
        }
    }
    else if (strcmp(tipo, "extras") == 0) {
        printf("Laboratórios Extras:\n");
        for (int i = 0; i < MAX_SALAS; i++) {
            if (lista_salas->labs_extra[i].identificacao != 0) { 
                printf("Laboratório Extra %d (Bloco %s) - Descrição: %s - Ocupação: %.1f%%\n", 
                    lista_salas->labs_extra[i].identificacao, lista_salas->labs_extra[i].bloco, lista_salas->labs_extra[i].desc,
                    ((float) lista_salas->labs_extra[i].capacidade_atual / lista_salas->labs_extra[i].capacidade_max) * 100);
            }
        }
    }
    else {
        printf("Tipo de sala não encontrado.\n");
    }
}

void listarTodasAsSalas(Lista* lista_salas) {
    printf("\nListando todas as salas:\n");
    
    printf("\nSalas Teóricas:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->salas_teo[i].capacidade_max > 0) {
            
            printf("Sala Teorica %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->salas_teo[i].identificacao,
                   lista_salas->salas_teo[i].bloco,
                   lista_salas->salas_teo[i].capacidade_atual,
                   lista_salas->salas_teo[i].capacidade_max);
        }
    }

    printf("\nLaboratórios de Informática:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->lab_info[i].capacidade_max > 0) {
            
            printf("Laboratorio Informática %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->lab_info[i].identificacao,
                   lista_salas->lab_info[i].bloco,
                   lista_salas->lab_info[i].capacidade_atual,
                   lista_salas->lab_info[i].capacidade_max);
        }
    }

    printf("\nSalas Administrativas:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->salas_adm[i].capacidade_max > 0) {
           
            printf("Sala Administrativa %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->salas_adm[i].identificacao,
                   lista_salas->salas_adm[i].bloco,
                   lista_salas->salas_adm[i].capacidade_atual,
                   lista_salas->salas_adm[i].capacidade_max);
        }
    }

    printf("\nSalas Mecanica:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->salas_mec[i].capacidade_max > 0) {
            
            printf("Sala Mecanica %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->salas_mec[i].identificacao,
                   lista_salas->salas_mec[i].bloco,
                   lista_salas->salas_mec[i].capacidade_atual,
                   lista_salas->salas_mec[i].capacidade_max);
        }
    }

    printf("\nSalas dos Professores:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->salas_prof[i].capacidade_max > 0) {
            printf("Sala de Professor %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->salas_prof[i].identificacao,
                   lista_salas->salas_prof[i].bloco,
                   lista_salas->salas_prof[i].capacidade_atual,
                   lista_salas->salas_prof[i].capacidade_max);
        }
    }

    printf("\nBiblioteca:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->bibliotecas[i].capacidade_max > 0) {
            printf("Biblioteca %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->bibliotecas[i].identificacao,
                   lista_salas->bibliotecas[i].bloco,
                   lista_salas->bibliotecas[i].capacidade_atual,
                   lista_salas->bibliotecas[i].capacidade_max);
        }
    }

   printf("\nSalas Manutencao:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->salas_manutencao[i].capacidade_max > 0) {
            
            printf("Sala de Manutencao %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->salas_manutencao[i].identificacao,
                   lista_salas->salas_manutencao[i].bloco,
                   lista_salas->salas_manutencao[i].capacidade_atual,
                   lista_salas->salas_manutencao[i].capacidade_max);
        }
    }

    printf("\nLaboratórios Extras:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->labs_extra[i].capacidade_max > 0) {
            
            printf("Laboratorio Extra %d (Bloco %s) - Descrição: %s - Capacidade: %d/%d\n",
                   lista_salas->labs_extra[i].identificacao,
                   lista_salas->labs_extra[i].bloco,
                   lista_salas->labs_extra[i].desc,
                   lista_salas->labs_extra[i].capacidade_atual,
                   lista_salas->labs_extra[i].capacidade_max);
        }
    }

   printf("\nAuditorios:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->auditorios[i].capacidade_max > 0) {
            printf("Auditório %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->auditorios[i].identificacao,
                   lista_salas->auditorios[i].bloco,
                   lista_salas->auditorios[i].capacidade_atual,
                   lista_salas->auditorios[i].capacidade_max);
        }
    }

    printf("\nPátio:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (lista_salas->patios[i].capacidade_max > 0) {
           
            printf("Pátio %d (Bloco %s) - Capacidade: %d/%d\n",
                   lista_salas->patios[i].identificacao,
                   lista_salas->patios[i].bloco,
                   lista_salas->patios[i].capacidade_atual,
                   lista_salas->patios[i].capacidade_max);
        }
    }
}



void cadastrarSala(Lista* lista_salas) {
    int tipo_sala;
    printf("Escolha o tipo de sala:\n");
    printf("1 - Sala Teórica\n");
    printf("2 - Laboratório de Informática\n");
    printf("3 - Sala Administrativa\n");
    printf("4 - Sala Mecânica\n");
    printf("5 - Sala de Professor\n");
    printf("6 - Biblioteca\n");
    printf("7 - Sala de Manutenção\n");
    printf("8 - Laboratório Extra\n");
    printf("9 - Auditório\n");
    printf("10 - Pátio\n");
    scanf("%d", &tipo_sala);

    char bloco[3];
    int identificacao, capacidade_atual, capacidade_max;
    char descricao[50] = ""; // Para tipos que têm descrição (e.g., Laboratórios Extra e Pátios)

    printf("Digite o bloco da sala (ex.: A1, B2): ");
    scanf("%s", bloco);

    printf("Digite o número de identificação: ");
    scanf("%d", &identificacao);

    printf("Digite a capacidade atual: ");
    scanf("%d", &capacidade_atual);

    printf("Digite a capacidade máxima: ");
    scanf("%d", &capacidade_max);

    if (tipo_sala == 8 || tipo_sala == 10) {
        printf("Digite uma descrição: ");
        scanf(" %[^\n]", descricao);
    }

    for (int i = 0; i < MAX_SALAS; i++) {
        if (tipo_sala == 1 && lista_salas->salas_teo[i].capacidade_max == 0) {
            strcpy(lista_salas->salas_teo[i].bloco, bloco);
            lista_salas->salas_teo[i].identificacao = identificacao;
            lista_salas->salas_teo[i].capacidade_atual = capacidade_atual;
            lista_salas->salas_teo[i].capacidade_max = capacidade_max;
            printf("Sala Teórica cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 2 && lista_salas->lab_info[i].capacidade_max == 0) {
            strcpy(lista_salas->lab_info[i].bloco, bloco);
            lista_salas->lab_info[i].identificacao = identificacao;
            lista_salas->lab_info[i].capacidade_atual = capacidade_atual;
            lista_salas->lab_info[i].capacidade_max = capacidade_max;
            printf("Laboratório de Informática cadastrado com sucesso!\n");
            return;
        }
        if (tipo_sala == 3 && lista_salas->salas_adm[i].capacidade_max == 0) {
            strcpy(lista_salas->salas_adm[i].bloco, bloco);
            lista_salas->salas_adm[i].identificacao = identificacao;
            lista_salas->salas_adm[i].capacidade_atual = capacidade_atual;
            lista_salas->salas_adm[i].capacidade_max = capacidade_max;
            printf("Sala Administrativa cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 4 && lista_salas->salas_mec[i].capacidade_max == 0) {
            strcpy(lista_salas->salas_mec[i].bloco, bloco);
            lista_salas->salas_mec[i].identificacao = identificacao;
            lista_salas->salas_mec[i].capacidade_atual = capacidade_atual;
            lista_salas->salas_mec[i].capacidade_max = capacidade_max;
            printf("Sala Mecânica cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 5 && lista_salas->salas_prof[i].capacidade_max == 0) {
            strcpy(lista_salas->salas_prof[i].bloco, bloco);
            lista_salas->salas_prof[i].identificacao = identificacao;
            lista_salas->salas_prof[i].capacidade_atual = capacidade_atual;
            lista_salas->salas_prof[i].capacidade_max = capacidade_max;
            printf("Sala de Professor cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 6 && lista_salas->bibliotecas[i].capacidade_max == 0) {
            strcpy(lista_salas->bibliotecas[i].bloco, bloco);
            lista_salas->bibliotecas[i].identificacao = identificacao;
            lista_salas->bibliotecas[i].capacidade_atual = capacidade_atual;
            lista_salas->bibliotecas[i].capacidade_max = capacidade_max;
            printf("Biblioteca cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 7 && lista_salas->salas_manutencao[i].capacidade_max == 0) {
            strcpy(lista_salas->salas_manutencao[i].bloco, bloco);
            lista_salas->salas_manutencao[i].identificacao = identificacao;
            lista_salas->salas_manutencao[i].capacidade_atual = capacidade_atual;
            lista_salas->salas_manutencao[i].capacidade_max = capacidade_max;
            printf("Sala de Manutenção cadastrada com sucesso!\n");
            return;
        }
        if (tipo_sala == 8 && lista_salas->labs_extra[i].capacidade_max == 0) {
            strcpy(lista_salas->labs_extra[i].bloco, bloco);
            strcpy(lista_salas->labs_extra[i].desc, descricao);
            lista_salas->labs_extra[i].identificacao = identificacao;
            lista_salas->labs_extra[i].capacidade_atual = capacidade_atual;
            lista_salas->labs_extra[i].capacidade_max = capacidade_max;
            printf("Laboratório Extra cadastrado com sucesso!\n");
            return;
        }
        if (tipo_sala == 9 && lista_salas->auditorios[i].capacidade_max == 0) {
            strcpy(lista_salas->auditorios[i].bloco, bloco);
            lista_salas->auditorios[i].identificacao = identificacao;
            lista_salas->auditorios[i].capacidade_atual = capacidade_atual;
            lista_salas->auditorios[i].capacidade_max = capacidade_max;
            printf("Auditório cadastrado com sucesso!\n");
            return;
        }
        if (tipo_sala == 10 && lista_salas->patios[i].capacidade_max == 0) {
            strcpy(lista_salas->patios[i].bloco, bloco);
            strcpy(lista_salas->patios[i].desc, descricao);
            lista_salas->patios[i].identificacao = identificacao;
            lista_salas->patios[i].capacidade_atual = capacidade_atual;
            lista_salas->patios[i].capacidade_max = capacidade_max;
            printf("Pátio cadastrado com sucesso!\n");
            return;
        }
    }

    printf("Não foi possível cadastrar a sala. Limite atingido ou erro desconhecido.\n");
}


void exibirMenu() {
    printf("\nEscolha uma opcao:\n");
    printf("1. Ver taxa de ocupacao de todas as salas\n");
    printf("2. Calcular computadores faltando nos laboratorios\n");
    printf("3. Exibir salas por bloco\n");
    printf("4. Exibir salas por tipo\n");
    printf("5. Listar todas as salas\n");
    printf("6. Cadastrar nova sala\n");
    printf("0. Sair\n");
}
