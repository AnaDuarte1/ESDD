/*Escreva uma função que dobre o valor de uma
variável.*/

#include<stdio.h>

int CalcularSoma(int *array, int tam);

int main(){
    int tam, i, soma = 0;

    printf("Digite o tamanho do array:");
    scanf("%d", &tam);

    int numeros[tam];

    for(i = 0; i < tam; i++){
        printf("\n[%d]: ", i);
        scanf("%d", &numeros[i]);
    }

    soma = CalcularSoma(numeros , tam);
    printf("Soma: %d\n", soma);

    return 0;

}

int CalcularSoma(int *array, int tam){
    int i,soma = 0;

    for(i = 0; i < tam; i++){
        soma += *(array + i);
    }
    
    return soma;

}