#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(){
   float dist;

    Ponto *p, *q, *r;

    p = criaPto(10,21);
    q = criaPto(7,25);
    r = criaPto(3,10);

    dist = distanciaPto(p,q);

    printf("Distância entre pontos: %f\n",dist);

    if(colineares(p,q,r)){
        printf("Estão na mesma reta!");
    }else{
        printf("Não estão na mesma reta!");
    }

    liberaPto(p);
    liberaPto(q);
    liberaPto(r);
    
    return 0;
}