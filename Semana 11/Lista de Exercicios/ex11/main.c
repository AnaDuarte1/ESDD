#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {
    Lista* lista = criarLista();
    int opcao, valor;

    while (1) {
        printf("\nControle de Lista Dinâmica\n");
        printf("1. Adicionar Elemento\n");
        printf("2. Remover Elemento\n");
        printf("3. Exibir Lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para adicionar: ");
                scanf("%d", &valor);
                adicionarElemento(lista, valor);
                break;
            case 2:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                removerElemento(lista, valor);
                break;
            case 3:
                exibirLista(lista);
                break;
            case 4:
                liberarLista(lista);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}