#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define MAX_FORMAS 100

int main() {
    Forma formas[MAX_FORMAS];
    int count = 0;
    int tipo;
    float base, altura, raio;

    while (count < MAX_FORMAS) {
        printf("Escolha o tipo de forma (1 - Retângulo, 2 - Triângulo, 3 - Círculo, 0 - Sair): ");
        scanf("%d", &tipo);
        
        if (tipo == 0) {
            break; // Sair do loop
        }

        switch (tipo) {
            case 1: // Retângulo
                printf("Digite a base do retângulo: ");
                scanf("%f", &base);
                printf("Digite a altura do retângulo: ");
                scanf("%f", &altura);
                formas[count] = criarRetangulo(base, altura);
                break;
            case 2: // Triângulo
                printf("Digite a base do triângulo: ");
                scanf("%f", &base);
                printf("Digite a altura do triângulo: ");
                scanf("%f", &altura);
                formas[count] = criarTriangulo(base, altura);
                break;
            case 3: // Círculo
                printf("Digite o raio do círculo: ");
                scanf("%f", &raio);
                formas[count] = criarCirculo(raio);
                break;
            default:
                printf("Tipo de forma inválido! Tente novamente.\n");
        }
        count++; 
    }

    printf("\nFormas cadastradas:\n");
    for (int i = 0; i < count; i++) {
        imprimirForma(formas[i]);
        printf("Área: %.2f\n", calcularAreaForma(formas[i]));
    }

    for (int i = 0; i < count; i++) {
        free(formas[i].forma);
    }

    return 0;
}