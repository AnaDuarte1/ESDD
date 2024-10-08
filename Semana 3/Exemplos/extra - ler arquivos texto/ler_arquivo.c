#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ler_arquivo.h"


#define TAM_LINHA 100
#define TAM_ALUNO 20

typedef struct{
    char nome[40]; // nome do aluno
    char ra[20]; // registro academico
} Aluno;

int main() {
    FILE *arquivo;
    char linha[TAM_LINHA];
    Aluno alunos[TAM_ALUNO];

    // Abre o arquivo CSV
    arquivo = fopen("/home/aluno/htdocs/Ana - Estrutura de Dados/ESDD/Semana 3/Exemplos/extra - ler arquivos texto/dados.csv", "r");
    if (arquivo == NULL) {
        printf("\n Erro ao abrir o arquivo");
        return 0;
    }

    // lê o arquivo linha por linha
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char *token = strtok(linha, ";");
        if (token != NULL) {
            strncpy(alunos[i].nome, token, 40);
            token = strtok(NULL, ";");
            if (token != NULL) {
                strncpy(alunos[i].ra, token, 20);
            }
            i++;
        }
    }
   
   // exibe o vetor dos alunos
   for(int j=0; j<TAM_ALUNO; j++){
       printf("\n %s \n %s", alunos[j].nome, alunos[j].ra);
   }
   
   // sorteio do aluno
   srand((unsigned)time(NULL));
   int numero = rand() % 19;
   printf("\n aluno sorteado %d - %s %s", numero, alunos[numero].nome, alunos[numero].ra);

    // fecha o arquivo
    fclose(arquivo);
    return 0;
}