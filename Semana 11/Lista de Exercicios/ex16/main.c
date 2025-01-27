#include <stdio.h>
#include "Fila.h"

int main() {
    Fila* fila1 = criaFila();
    Fila* fila2 = criaFila();

    insereFila(fila1, 1);
    insereFila(fila1, 2);
    insereFila(fila1, 3);

    insereFila(fila2, 1);
    insereFila(fila2, 2);
    insereFila(fila2, 3);

    // Comparar as filas
    if (comparaFilas(fila1, fila2)) {
        printf("As filas são iguais.\n");
    } else {
        printf("As filas são diferentes.\n");
    }

    destroiFila(fila1);
    destroiFila(fila2);

    return 0;
}
