#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include <math.h>

float calcularAreaRetangulo(Retangulo* r) {
    return r->base * r->altura;
}

void imprimirRetangulo(Retangulo* r) {
    printf("Retângulo: Base = %.2f, Altura = %.2f, Área = %.2f\n",
           r->base, r->altura, calcularAreaRetangulo(r));
}

float calcularAreaTriangulo(Triangulo* t) {
    return (t->base * t->altura) / 2.0;
}

void imprimirTriangulo(Triangulo* t) {
    printf("Triângulo: Base = %.2f, Altura = %.2f, Área = %.2f\n",
           t->base, t->altura, calcularAreaTriangulo(t));
}

float calcularAreaCirculo(Circulo* c) {
    return M_PI * c->raio * c->raio;
}

void imprimirCirculo(Circulo* c) {
    printf("Círculo: Raio = %.2f, Área = %.2f\n",
           c->raio, calcularAreaCirculo(c));
}

Forma criarRetangulo(float base, float altura) {
    Forma f;
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    strcpy(r->tipo.nome, "Retângulo");
    r->base = base;
    r->altura = altura;
    f.tipo = r->tipo;
    f.forma = r;
    return f;
}

Forma criarTriangulo(float base, float altura) {
    Forma f;
    Triangulo* t = (Triangulo*)malloc(sizeof(Triangulo));
    strcpy(t->tipo.nome, "Triângulo");
    t->base = base;
    t->altura = altura;
    f.tipo = t->tipo;
    f.forma = t;
    return f;
}

Forma criarCirculo(float raio) {
    Forma f;
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    strcpy(c->tipo.nome, "Círculo");
    c->raio = raio;
    f.tipo = c->tipo;
    f.forma = c;
    return f;
}

float calcularAreaForma(Forma f) {
    if (strcmp(f.tipo.nome, "Retângulo") == 0) {
        return calcularAreaRetangulo((Retangulo*)f.forma);
    } else if (strcmp(f.tipo.nome, "Triângulo") == 0) {
        return calcularAreaTriangulo((Triangulo*)f.forma);
    } else if (strcmp(f.tipo.nome, "Círculo") == 0) {
        return calcularAreaCirculo((Circulo*)f.forma);
    }
    return 0.0;
}

void imprimirForma(Forma f) {
    if (strcmp(f.tipo.nome, "Retângulo") == 0) {
        imprimirRetangulo((Retangulo*)f.forma);
    } else if (strcmp(f.tipo.nome, "Triângulo") == 0) {
        imprimirTriangulo((Triangulo*)f.forma);
    } else if (strcmp(f.tipo.nome, "Círculo") == 0) {
        imprimirCirculo((Circulo*)f.forma);
    }
}