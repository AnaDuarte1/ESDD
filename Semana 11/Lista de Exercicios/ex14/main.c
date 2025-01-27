#include <stdio.h>
#include "ListaLigacoes.h"

int main() {
    ListaCircular* lista = criarLista();
    int opcao, id = 1;
    float custo;

    do {
        printf("\n=== Sistema de Ligações 0800 ===\n");
        printf("1. Inserir ligação\n");
        printf("2. Remover ligação mais cara\n");
        printf("3. Imprimir lista de ligações\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Informe o custo da ligação: ");
            scanf("%f", &custo);
            inserirLigacao(lista, custo, id++);
            break;
        case 2:
            removerLigacao(lista);
            break;
        case 3:
            imprimirLista(lista);
            break;
        case 4:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    liberarLista(lista);
    return 0;
}
