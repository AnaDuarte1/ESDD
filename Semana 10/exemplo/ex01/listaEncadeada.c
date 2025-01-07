#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Lista* criaLista() {
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if (list != NULL) 
        *list = NULL; 
    return list;
}

int tamLista(Lista* inicio) {
    if (inicio == NULL)
        return 0;
    
    int cont = 0;
    noLista* no = *inicio;
    
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    
    return cont;
}

int listaVazia(Lista* inicio) {
    if (inicio == NULL || *inicio == NULL)
        return 1;
    return 0;
}

int insereFinal(Lista* inicio, elemento aluno) {
    if (inicio == NULL)
        return 0;
    
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if (no == NULL)
        return 0;
    
    no->dado = aluno;
    no->prox = NULL;
    
    if (*inicio == NULL) { // Se a lista está vazia
        *inicio = no;
    } else {
        noLista *aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox; // Percorre até o final
        }
        aux->prox = no;
    }
    
    return 1;
}

int insereInicio(Lista* inicio, elemento aluno) {
    if (inicio == NULL)
        return 0;
    
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if (no == NULL)
        return 0;
    
    no->dado = aluno;
    no->prox = *inicio;
    *inicio = no;
    
    return 1;
}

int insereOrdenado(Lista* inicio, elemento aluno) {
    if (inicio == NULL)
        return 0;
    
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if (no == NULL)
        return 0;
    
    no->dado = aluno; 
    if (*inicio == NULL || (*inicio)->dado.matricula > aluno.matricula) {
        no->prox = *inicio;
        *inicio = no;
        return 1;
    }
    
    noLista *aux = *inicio;
    while (aux->prox != NULL && aux->prox->dado.matricula < aluno.matricula) {
        aux = aux->prox; // Encontra a posição correta para inserção
    }
    
    no->prox = aux->prox;
    aux->prox = no;
    
    return 1;
}

int consultaPosicao(Lista* inicio, int pos, elemento *aluno) {
    if (inicio == NULL || pos <= 0)
        return 0;
    
    noLista *no = *inicio;
    int i = 1;
    
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    
    if (no == NULL)
        return 0;
    
    *aluno = no->dado;
    return 1;
}

int consultaMatricula(Lista* inicio, int mat, elemento *aluno) {
    if (inicio == NULL)
        return 0;
    
    noLista *no = *inicio;
    
    while (no != NULL && no->dado.matricula != mat) {
        no = no->prox;
    }
    
    if (no == NULL)
        return 0;
    
    *aluno = no->dado;
    return 1;
}

int removeInicio(Lista* inicio) {
    if (inicio == NULL || *inicio == NULL) 
        return 0;
    
    noLista *no = *inicio;
    *inicio = no->prox;
    free(no);
    
    return 1;
}

int removeFinal(Lista* inicio) {
    if (inicio == NULL || *inicio == NULL) 
        return 0;
    
    if ((*inicio)->prox == NULL) { // Só tem um nó
        free(*inicio);
        *inicio = NULL;
        return 1;
    }
    
    noLista *aux = *inicio;
    while (aux->prox != NULL && aux->prox->prox != NULL) {
        aux = aux->prox; // Vai até o penúltimo nó
    }
    
    free(aux->prox); // Libera o último nó
    aux->prox = NULL; // O penúltimo nó agora aponta para NULL
    
    return 1;
}

int removeMatricula(Lista* inicio, elemento *aluno) {
    if (inicio == NULL || *inicio == NULL)
        return 0;
    
    noLista *aux = *inicio;
    
    if (aux->dado.matricula == aluno->matricula) {
        *inicio = aux->prox;
        free(aux);
        return 1;
    }
    
    while (aux->prox != NULL && aux->prox->dado.matricula != aluno->matricula) {
        aux = aux->prox;
    }
    
    if (aux->prox != NULL) {
        noLista *temp = aux->prox;
        aux->prox = aux->prox->prox;
        free(temp);
        return 1;
    }
    
    return 0;
}

void imprimeLista(Lista* inicio) {
    if (inicio == NULL || *inicio == NULL)
        return;
    
    noLista *no = *inicio;
    
    while (no != NULL) {
        printf("\tMatricula: %d\n", no->dado.matricula);
        printf("\tNome: %s\n", no->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f; N3 = %4.2f\n",
               no->dado.n1, no->dado.n2, no->dado.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

void apagaLista(Lista* inicio) {
    if (inicio != NULL) {
        noLista* no;
        while (*inicio != NULL) {
            no = *inicio;
            *inicio = (*inicio)->prox;
            free(no);
        }
        free(inicio);
    }
}
