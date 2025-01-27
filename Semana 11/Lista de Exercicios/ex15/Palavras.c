#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Palavras.h"

// Função para inverter as letras de uma palavra
void inverterPalavra(Palavra* p) {
    int inicio = 0;
    int fim = strlen(p->palavra) - 1;

    while (inicio < fim) {
        char temp = p->palavra[inicio];
        p->palavra[inicio] = p->palavra[fim];
        p->palavra[fim] = temp;
        inicio++;
        fim--;
    }
}

// Função para processar o texto, invertendo as letras de cada palavra
void processarTexto(char* texto) {
    Palavra palavraAtual;
    int indice = 0; // Índice da palavra atual

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) { // Adicionar caractere à palavra atual
            palavraAtual.palavra[indice++] = texto[i];
        } else { // Palavra concluída
            if (indice > 0) {
                palavraAtual.palavra[indice] = '\0'; // Finaliza a palavra
                inverterPalavra(&palavraAtual); // Inverte a palavra
                printf("%s", palavraAtual.palavra); // Imprime a palavra invertida
                indice = 0; // Reseta o índice da palavra
            }
            printf("%c", texto[i]); // Imprime o caractere separador (espaço, ponto, etc.)
        }
    }
}
