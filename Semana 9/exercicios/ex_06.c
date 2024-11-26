#include <stdio.h>
#include <ctype.h>

#define MAX_PALAVRAS 5000
#define TAMANHO_MAX_PALAVRA 201

int eh_letra(char c);
char para_minuscula(char c);
int comparar_palavras(char *a, char *b);
void ordenar_dicionario(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd) ;
int palavra_unica(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd, char *palavra);



// Função principal
int main() {
    char linha[201];
    char palavra[TAMANHO_MAX_PALAVRA];
    char dicionario[MAX_PALAVRAS][TAMANHO_MAX_PALAVRA];
    int qtd_palavras = 0;

    while (fgets(linha, sizeof(linha), stdin)) {
        int i = 0, posicao_palavra = 0;

        while (linha[i] != '\0') {
            if (eh_letra(linha[i])) {
                // Adicionar letra convertida para minúscula na palavra
                palavra[posicao_palavra++] = para_minuscula(linha[i]);
            } else {
                if (posicao_palavra > 0) {
                    // Finalizar a palavra
                    palavra[posicao_palavra] = '\0';
                    if (palavra_unica(dicionario, qtd_palavras, palavra)) {
                        int j = 0;
                        while (palavra[j]) {
                            dicionario[qtd_palavras][j] = palavra[j];
                            j++;
                        }
                        dicionario[qtd_palavras][j] = '\0';
                        qtd_palavras++;
                    }
                    posicao_palavra = 0; // Resetar para a próxima palavra
                }
            }
            i++;
        }
        // Caso a linha termine com uma palavra
        if (posicao_palavra > 0) {
            palavra[posicao_palavra] = '\0';
            if (palavra_unica(dicionario, qtd_palavras, palavra)) {
                int j = 0;
                while (palavra[j]) {
                    dicionario[qtd_palavras][j] = palavra[j];
                    j++;
                }
                dicionario[qtd_palavras][j] = '\0';
                qtd_palavras++;
            }
        }
    }

    // Ordenar o dicionário
    ordenar_dicionario(dicionario, qtd_palavras);

    // Imprimir o dicionário
    for (int i = 0; i < qtd_palavras; i++) {
        printf("%s\n", dicionario[i]);
    }

    return 0;
}

// Função para verificar se o caractere é uma letra
int eh_letra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Função para converter uma letra para minúscula
char para_minuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// Função para comparar duas strings (alfabeticamente)
int comparar_palavras(char *a, char *b) {
    while (*a && *b) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return *a - *b;
}

// Função para verificar se a palavra é única no dicionário
int palavra_unica(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd, char *palavra) {
    for (int i = 0; i < qtd; i++) {
        int comparacao = comparar_palavras(dicionario[i], palavra);
        if (comparacao == 0) {
            return 0; // Palavra já existe no dicionário
        }
    }
    return 1; // Palavra é única
}

// Função para ordenar o dicionário em ordem alfabética
void ordenar_dicionario(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd) {
    char temp[TAMANHO_MAX_PALAVRA];
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (comparar_palavras(dicionario[i], dicionario[j]) > 0) {
                // Trocar as palavras
                int k = 0;
                while (dicionario[i][k] || dicionario[j][k]) {
                    temp[k] = dicionario[i][k];
                    dicionario[i][k] = dicionario[j][k];
                    dicionario[j][k] = temp[k];
                    k++;
                }
            }
        }
    }
}
