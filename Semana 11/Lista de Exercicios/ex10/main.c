#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main() {
    Pilha* pilha = criarPilha();
    int opcao, dado;

    while (1) {
        printf("\nControle de Pilha\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Exibir Pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número para empilhar: ");
                scanf("%d", &dado);
                empilhar(pilha, dado);
                break;
            case 2:
                dado = desempilhar(pilha);
                if (dado != -1) {
                    printf("Desempilhado: %d\n", dado);
                }
                break;
            case 3:
                exibirPilha(pilha);
                break;
            case 4:
                liberarPilha(pilha);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}