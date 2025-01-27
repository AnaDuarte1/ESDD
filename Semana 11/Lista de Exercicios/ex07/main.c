#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

#define MAX_RETANGULOS 100

int main() {
    Retangulo retangulos[MAX_RETANGULOS];
    int count = 0;
    float base, altura;

    while (count < MAX_RETANGULOS) {
        printf("Digite a base do retângulo (ou um valor negativo para sair): ");
        scanf("%f", &base);
        if (base < 0) {
            break;
        }
        printf("Digite a altura do retângulo: ");
        scanf("%f", &altura);

        retangulos[count] = criarRetangulo(base, altura);
        count++;
    }

    printf("\nLista de Retângulos:\n");
    for (int i = 0; i < count; i++) {
        imprimirRetangulo(retangulos[i]);
    }

    return 0;
}