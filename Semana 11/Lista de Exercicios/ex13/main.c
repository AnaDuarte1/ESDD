#include <stdio.h>
#include <string.h>
#include "Robo.h"

int main() {
    Pilha* pilha = criarPilha();
    char comando;
    char continuar;

    printf("=== Controle do Robô Móvel ===\n");
    printf("Comandos válidos:\n");
    printf("  F - Frente\n");
    printf("  D - Direita\n");
    printf("  E - Esquerda\n");
    printf("  R - Retornar (gera o caminho inverso e encerra)\n");

    do {
        printf("\nDigite o comando (F, D, E ou R): ");
        scanf(" %c", &comando);

        if (comando == 'R') {
            imprimirCaminhoIda(pilha);
            imprimirCaminhoVolta(pilha);
            liberarPilha(pilha);
            printf("\nEncerrando o programa...\n");
            break;
        }

        empilhar(pilha, comando);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
