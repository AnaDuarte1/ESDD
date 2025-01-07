#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

#define qtde 5

int main() {
    elemento aluno;
    Lista *inicio = criaLista(); // Cria a lista
    int opcao;
    int i;
    do {
        printf("--------MENU--------\n");
        printf("1. Insere no Inicio\n");
        printf("2. Insere Ordenado pela matricula\n");
        printf("3. Insere no Final\n");
        printf("4. Remove no Inicio\n");
        printf("5. Remove no final\n");
        printf("6. Remove um elemento informando sua matricula\n");
        printf("7. Exibe a lista\n");
        printf("8. Exibe a quantidade de elementos da lista\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                printf("\nInserindo elemento no inicio.\n");
                    printf("\nDigite o nome do aluno: ");
                    scanf("%s", aluno.nome);
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &aluno.matricula);
                    aluno.n1 = aluno.n2 = aluno.n3 = 0;
                    insereInicio(inicio, aluno);
                
                break;

            case 2:
                printf("\nInserindo elemento ordenado pela matricula.\n");
               
                    printf("\nDigite o nome do aluno: ");
                    scanf("%s", aluno.nome);
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &aluno.matricula);
                    aluno.n1 = aluno.n2 = aluno.n3 = 0;
                    insereOrdenado(inicio, aluno);
              
                break;

            case 3:
                printf("\nInserindo elemento no final.\n");
               
                    printf("\nDigite o nome do aluno: ");
                    scanf("%s", aluno.nome);
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &aluno.matricula);
                    aluno.n1 = aluno.n2 = aluno.n3 = 0;
                    insereFinal(inicio, aluno);
               
                break;

            case 4:
                printf("\nRemovendo elemento do inicio.\n");
                removeInicio(inicio);
                
                break;

            case 5:
                printf("\nRemovendo elemento do final.\n");
                removeFinal(inicio);
                break;

            case 6:
                printf("\nRemovendo uma matricula.\n");
                printf("Digite a matricula: ");
                scanf("%d", &aluno.matricula);
                removeMatricula(inicio, &aluno);
                break;

            case 7:
                printf("\nExibindo a lista.\n");
                imprimeLista(inicio);
                break;

            case 8:
                printf("\nExibindo a quantidade de elementos da lista.\n");
                printf("Quantidade de elementos: %d\n", tamLista(inicio));
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 0);

    apagaLista(inicio);
    return 0;
}
