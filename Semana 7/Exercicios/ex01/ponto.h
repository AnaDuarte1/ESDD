typedef struct ponto Ponto;

Ponto* criaPto (float x, float y);

void liberaPto (Ponto* p);

Ponto* acessaPto (Ponto* p, float* x, float* y);

Ponto* atribuiPto (Ponto* p , float x, float y);

float distanciaPto (Ponto* p1, Ponto* p2);

float colineares (Ponto* p1, Ponto* p2, Ponto* p3);