#include <stdio.h>

int main(){
    int x;
    int *p, *q;
    int **r;

    printf("Digiote o valor de X:");
    scanf("%d",&x);

    p = &x;
    q = p;
    r = &p;

    printf("\nValor de X: %d\n", x);
    printf("Endereço de X ->> Guardado P: %p Guardado Q: %p\n",p,q);
    printf("Endereço de X ->> Guardado P: %p Guardado Q: %p\n",&p,&q);
    printf("Endereço do P guardado em R: %p\n",r);

}