#include <stdio.h>
#include "Retangulo.h"

Retangulo criarRetangulo(float base, float altura) {
    Retangulo r;
    r.base = base;
    r.altura = altura;
    return r;
}

float calcularArea(Retangulo r) {
    return r.base * r.altura;
}

void imprimirRetangulo(Retangulo r) {
    printf("Retângulo: Base = %.2f, Altura = %.2f, Área = %.2f\n", r.base, r.altura, calcularArea(r));
}