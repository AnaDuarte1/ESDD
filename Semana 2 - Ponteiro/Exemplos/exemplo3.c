#include <stdio.h>

int main(){
    int x;
    int *p, *q;

    printf("Digiote o valor de X:");
    scanf("%d",&x);

    p = &x; // ponteiro recebe endereço de X
    q = p; // Q recebe endereço de p

    printf("\nValor de X: %d\n", x);
    printf("Endereço de X ->> Guardado P: %p Guardado Q: %p\n",p,q);
    printf("Endereço de X ->> Guardado P: %p Guardado Q: %p\n",&p,&q);

}