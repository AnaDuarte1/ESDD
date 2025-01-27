#include <stdio.h>
#include <string.h>
#include "Palavras.h"

int main() {
    char texto[TAM_MAX];

    printf("Digite um texto terminado por ponto (max %d caracteres):\n", TAM_MAX - 1);
    fgets(texto, TAM_MAX, stdin);

    // Remover o caractere de nova linha ('\n'), se houver
    size_t len = strlen(texto);
    if (texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
        len--;
    }

    // Verificar se o texto termina com um ponto
    if (texto[len - 1] != '.') {
        printf("Erro: O texto deve terminar com um ponto.\n");
        return 1;
    }

    // Processar o texto
    printf("Texto processado:\n");
    processarTexto(texto);

    return 0;
}
