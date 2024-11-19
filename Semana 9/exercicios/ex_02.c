#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 1000
#define MAX_LEN 21

void ordenar(char *itens[], int num_itens);


int main() {
    int N;
    scanf("%d", &N); 
    
    char *listas[N][MAX_ITENS]; 
    int num_itens_por_lista[N]; 
    
    getchar();  // Para consumir o '\n' após ler o número de casos de teste
    for (int i = 0; i < N; i++) {
        char buffer[MAX_LEN];
        int num_itens = 0;
        
        // Lê os itens da lista i
        while (scanf("%s", buffer) == 1) {
            // Quando encontrar a linha vazia, vai parar de ler os itens dessa lista
            if (getchar() == '\n') {
                break;
            }
            
            // Verifica se o item já está na lista para evitar duplicatas
            int existe = 0;
            for (int j = 0; j < num_itens; j++) {
                if (strcmp(listas[i][j], buffer) == 0) {
                    existe = 1;
                    break;
                }
            }
            
            // Se o item não existir na lista, adiciona
            if (!existe) {
                listas[i][num_itens] = (char *)malloc(strlen(buffer) + 1);
                if (listas[i][num_itens] != NULL) {
                    strcpy(listas[i][num_itens], buffer);  // Copia o item para a lista
                    num_itens++;
                }
            }
        }
        
        num_itens_por_lista[i] = num_itens;  // Armazena o número de itens dessa lista
    }

     for (int i = 0; i < N; i++) {
        ordenar(listas[i], num_itens_por_lista[i]);  // Ordena a lista
        for (int j = 0; j < num_itens_por_lista[i]; j++) {
            printf("%s", listas[i][j]);
            if (j < num_itens_por_lista[i] - 1) {
                printf(" ");
            }
            free(listas[i][j]);  // Libera a memória alocada para o item
        }
        printf("\n");
    }
    
    return 0;
}


void ordenar(char *itens[], int num_itens) {
    for (int i = 0; i < num_itens - 1; i++) {
        for (int j = i + 1; j < num_itens; j++) {
            // Realiza a comparação diretamente aqui
            if (strcmp(itens[i], itens[j]) > 0) {
                // Troca os itens[i] e itens[j]
                char *temp = itens[i];
                itens[i] = itens[j];
                itens[j] = temp;
            }
        }
    }
}