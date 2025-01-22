#include "racional.h"
#include <stdio.h>

// calcular o MDC (Máximo Divisor Comum)
static int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

// simplificar um racional
static Racional simplificar(Racional r) {
    int divisor = mdc(r.numerador, r.denominador);
    r.numerador /= divisor;
    r.denominador /= divisor;
    if (r.denominador < 0) { // Garante que o denominador seja positivo
        r.numerador = -r.numerador;
        r.denominador = -r.denominador;
    }
    return r;
}

Racional criarRacional(int numerador, int denominador) {
    if (denominador == 0) {
        printf("Erro: denominador não pode ser zero.\n");
        denominador = 1; 
    }
    Racional r = {numerador, denominador};
    return simplificar(r);
}

Racional somaRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return simplificar(resultado);
}

Racional multiplicaRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.denominador;
    return simplificar(resultado);
}

int racionaisIguais(Racional r1, Racional r2) {
    r1 = simplificar(r1);
    r2 = simplificar(r2);
    return (r1.numerador == r2.numerador) && (r1.denominador == r2.denominador);
}
