typedef struct ponto Ponto;

Ponto* criaPto (float x, float y);

void liberaPto (Ponto* p);

float distanciaPto (Ponto* p1, Ponto* p2);

float colineares (Ponto* p1, Ponto* p2, Ponto* p3);