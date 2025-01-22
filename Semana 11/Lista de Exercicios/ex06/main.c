#include <stdio.h>
#include "racional.h"

int main() {
    int num1, den1, num2, den2;

    printf("Digite o numerador e o denominador do primeiro racional (separados por espaço): ");
    scanf("%d %d", &num1, &den1);
    Racional r1 = criarRacional(num1, den1);

    printf("Digite o numerador e o denominador do segundo racional (separados por espaço): ");
    scanf("%d %d", &num2, &den2);
    Racional r2 = criarRacional(num2, den2);

    printf("Racional 1: %d/%d\n", r1.numerador, r1.denominador);
    printf("Racional 2: %d/%d\n", r2.numerador, r2.denominador);

    Racional soma = somaRacional(r1, r2);
    printf("Soma: %d/%d\n", soma.numerador, soma.denominador);

    Racional produto = multiplicaRacional(r1, r2);
    printf("Produto: %d/%d\n", produto.numerador, produto.denominador);

    if (racionaisIguais(r1, r2)) {
        printf("Os racionais são iguais.\n");
    } else {
        printf("Os racionais são diferentes.\n");
    }

    return 0;
}
