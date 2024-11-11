#include <stdio.h>
#include "lista.h"

int main() {
    ListaFuncionarios lista;
    inicializaLista(&lista);

    Funcionario f1 = {"João Silva", "12345678901", "Carro"};
    Funcionario f2 = {"Ana Pereira", "09876543210", "Moto"};
    Funcionario f3 = {"Carlos Souza", "11122233344", "Bicicleta"};

    adicionaFuncionario(&lista, f1);
    adicionaFuncionario(&lista, f2);
    adicionaFuncionario(&lista, f3);

    printf("Lista de Funcionários:\n");
    imprimeLista(lista);

    return 0;
}
