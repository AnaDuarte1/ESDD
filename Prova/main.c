#include <stdio.h>
#include "prova.h"
#define MAX_TEO 3
#define MAX_LAB 2


int main(){
    int opcao;
    Lista *espacosF = carregarDados();

   do {
        printf("\nMenu de Operações:\n");
        printf("1. Exibir Taxa de Ocupação das Salas Teóricas\n");
        printf("2. Exibir Taxa de Ocupação dos Laboratórios de Informática\n");
        printf("3. Exibir Quantos Computadores Faltam para 100%% de Ocupação\n");
        printf("4. Exibir Todos os Espaços Físicos Ordenados pela Capacidade Máxima\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Realizar a operação escolhida
        switch(opcao) {
            case 1:
                printf("\nExibindo a Taxa de Ocupação das Salas Teóricas:\n");
                taxaOcupacaoT(espacosF);  
                break;
            case 2:
                printf("\nExibindo a Taxa de Ocupação dos Laboratórios de Informática:\n");
                taxaOcupacaoI(espacosF);  
                break;
            case 3:
                printf("\nExibindo a Quantidade de Computadores Faltantes para 100%% de Ocupação:\n");
                computadoresN(espacosF);  
                break;
            case 4:
                printf("\nExibindo Todos os Espaços Físicos Ordenados pela Capacidade Máxima:\n");
                espacosFisicosT(espacosF);  
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while(opcao != 5);  

    
    return 0;
}