#ifndef RETANGULO_H
#define RETANGULO_H
#endif

typedef struct {
    float base;
    float altura;
} Retangulo;

Retangulo criarRetangulo(float base, float altura);
float calcularArea(Retangulo r);
void imprimirRetangulo(Retangulo r);

 