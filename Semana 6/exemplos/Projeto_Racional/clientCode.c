#include "racional.h"
#include <stdio.h>

int main(){

    T_Racional soma, number, media;
    int n = 0;
    char continuar;
    soma = criarRacional(0, 1);

    do{
        printf("Digite valor:");
        number = entradaRacional();
        soma = somaRacional(soma, number);
        destroiRacional(number);

        printf("Digite S para continuar:");
        scanf("%c", &continuar);
        n+=1;

    }while(continuar == 's' || continuar == 'S');

    number = criarRacional(1, n);
    media = multiplicaRacional(soma, number);
    printf("Media: ");
    imprimeRacional(media);
    printf("\n");


    destroiRacional(soma);
    destroiRacional(number);
    destroiRacional(media);

    return 0;
}