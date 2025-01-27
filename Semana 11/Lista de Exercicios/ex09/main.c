#include <stdio.h>
#include <stdlib.h>
#include "Aviao.h"

int main() {
    Avião* fila = NULL;
    int opcao;
    char nome[20];
    float nivelCombustivel;

    while (1) {
        printf("\nControle de Pouso de Aviões\n");
        printf("1. Adicionar Avião\n");
        printf("2. Remover Avião\n");
        printf("3. Exibir Fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do avião: ");
                scanf("%s", nome);
                printf("Digite o nível de combustível (em litros): ");
                scanf("%f", &nivelCombustivel);
                adicionarAvião(&fila, criarAvião(nome, nivelCombustivel));
                break;
            case 2:
                {
                    Avião* removido = removerAvião(&fila);
                    if (removido != NULL) {
                        printf("Avião %s removido da fila.\n", removido->nome);
                        free(removido);
                    } else {
                        printf("Nenhum avião para remover.\n");
                    }
                }
                break;
            case 3:
                exibirFila(fila);
                break;
            case 4:
                liberarLista(fila);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}