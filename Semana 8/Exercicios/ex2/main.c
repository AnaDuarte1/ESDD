#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int comparaFuncionarios(const void *a, const void *b) {
    Funcionario *funcA = (Funcionario *)a;
    Funcionario *funcB = (Funcionario *)b;
    return strcmp(funcA->nome, funcB->nome);
}

void ordenaLista(ListaFuncionarios *lista) {
    qsort(lista->funcionarios, lista->prox, sizeof(Funcionario), comparaFuncionarios);
}

int main() {
    ListaFuncionarios listaA, listaB;
    criaLista(&listaA);
    criaLista(&listaB);

    // Adicionando alguns funcionários a listaA (exemplo)
    Funcionario f1 = {"João", "12345678901", "Carro"};
    Funcionario f2 = {"Ana", "09876543210", "Moto"};
    Funcionario f3 = {"Carlos", "11122233344", "Bicicleta"};

    adicionaFuncionario(&listaA, f1);
    adicionaFuncionario(&listaA, f2);
    adicionaFuncionario(&listaA, f3);

    // Copia listaA para listaB e ordena
    listaB = listaA;
    ordenaLista(&listaB);

    printf("Lista A (desordenada):\n");
    imprimeLista(listaA);
    printf("\nLista B (ordenada):\n");
    imprimeLista(listaB);

    return 0;
}
