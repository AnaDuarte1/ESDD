/*Escreva uma função que dobre o valor de uma
variável.*/

#include<stdio.h>

int dobrar(int *a);

int main(){
    int x;

    printf("Digite o valor de A:");
    scanf("%d", &x);    
   
    printf("Valor Antes: %d\n", x);
    dobrar(&x);
    printf("Valor depois: %d\n", x);

    return 0;

}

int dobrar(int *a){
    return  *a = *a * 2;
}