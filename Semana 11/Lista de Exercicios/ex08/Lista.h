// Lista.h
#ifndef LISTA_H
#define LISTA_H
#endif 

typedef struct {
    char nome[20];
} TipoForma;

typedef struct {
    TipoForma tipo;
    float base;
    float altura;
} Retangulo;

typedef struct {
    TipoForma tipo;
    float base;
    float altura;
} Triangulo;

typedef struct {
    TipoForma tipo;
    float raio;
} Circulo;

typedef struct {
    TipoForma tipo;
    void* forma;
} Forma;

// Funções para manipular formas
Forma criarRetangulo(float base, float altura);
Forma criarTriangulo(float base, float altura);
Forma criarCirculo(float raio);
float calcularAreaForma(Forma f);
void imprimirForma(Forma f);

