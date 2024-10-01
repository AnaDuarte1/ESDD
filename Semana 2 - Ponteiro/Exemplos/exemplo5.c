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
    *p = 30;
    printf("\nValor de X: %d\n", x);
    printf("Valor armazenado na variavel apontada por P: %i Q: %i\n", *p, *q);

}