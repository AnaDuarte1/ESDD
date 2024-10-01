/*Escreva uma função para trocar os valores de duas
variáveis do tipo inteiro.*/

#include<stdio.h>
int trocar(int *a, int *b);

int main(){
    int x, y;

    printf("Digite o valor de A:");
    scanf("%d", &x);    
    printf("Digite o valor de B:");
    scanf("%d",&y);   
    printf("Valores Antes: %d e %d\n", x , y);
    trocar(&x, &y);
    printf("Valores depois: %d e %d\n", x, y);

    return 0;

}

int trocar(int *a, int *b){
    int c;

     c = *a;
    *a = *b;
    *b = c;

    return 0;
}