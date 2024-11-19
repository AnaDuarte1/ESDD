#include <stdio.h>
#include <string.h>

#define MAX_NOMES 100
#define MAX_TAMANHO_NOME 20

void bubbleSort(char nome[MAX_NOMES][MAX_TAMANHO_NOME], int n);

int main(){
    int n;
    char comportamento;
    char nome[MAX_NOMES][MAX_TAMANHO_NOME];
    int auxC = 0;
    int auxN = 0;

    scanf("%d", &n);

   for (int i = 0; i < n; i++) {
        scanf(" %c %s", &comportamento, nome[i]);

        if (comportamento == '+') {
            auxC++;
        } else if (comportamento == '-') {
            auxN++;
        }
    } 
    
    bubbleSort(nome, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", nome[i]);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d\n", auxC, auxN);
    

}


void bubbleSort(char nome[MAX_NOMES][MAX_TAMANHO_NOME], int n) {
    char temp[MAX_TAMANHO_NOME];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(nome[j], nome[j + 1]) > 0) {
                // Troca os nomes
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
            }
        }
    }
}