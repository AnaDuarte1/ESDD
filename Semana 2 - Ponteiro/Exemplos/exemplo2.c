#include<stdio.h>

int main(){
    int x = 0;
    int *ponteiro;

    printf("Digite valor de X:");
    scanf("%d", &x);

    ponteiro = &x;

    printf("Valor de X: %d Endereço de X: %p\n",x,ponteiro);
    printf("Valor de X: %d Endereço de X: %p\n",x,&x);
}