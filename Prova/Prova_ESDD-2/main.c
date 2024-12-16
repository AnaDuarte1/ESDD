#include <stdio.h>
#include <stdlib.h>
#include "sala.h"

int main() {
    Lista* lista_salas = criaLista();
    carregarDados(lista_salas);
    int opcao;

    do {
        exibirMenu();
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                taxaOcupacaoTodasSalas(lista_salas);
                break;
            case 2:
                calculaPC(lista_salas);
                break;
            case 3:
                listarSalasPorBloco(lista_salas);
                break;
            case 4:
                listarSalasPorTipo(lista_salas);
                break;
            case 5:
                listarTodasAsSalas(lista_salas);
                break;
            case 6:
                cadastrarSala(lista_salas);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    free(lista_salas);
    return 0;
}
