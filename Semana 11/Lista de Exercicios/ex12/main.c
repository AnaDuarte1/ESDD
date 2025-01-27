#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calculadora.h"

int main() {
    char expressao[100];
    char opcao;

    printf("=== Calculadora Pós-Fixada ===\n");
    printf("Insira uma expressão pós-fixada (exemplo: 5 1 2 + 4 * + 3 -):\n");
    printf("Operadores válidos: +, -, *, /\n");
    printf("Digite 'q' para sair.\n");

    do {
        printf("\nDigite a expressão pós-fixada: ");
        fgets(expressao, sizeof(expressao), stdin);
        expressao[strcspn(expressao, "\n")] = '\0';  // Remove o caractere de nova linha

        if (strcmp(expressao, "q") == 0) {
            printf("Encerrando a calculadora...\n");
            break;
        }

        float resultado = calcularPosfixada(expressao);
        printf("Resultado: %.2f\n", resultado);

        printf("\nDeseja calcular outra expressão? (s/n): ");
        scanf(" %c", &opcao);
        getchar();  // Limpa o buffer do teclado
    } while (opcao == 's' || opcao == 'S');

    printf("Programa encerrado.\n");
    return 0;
}
