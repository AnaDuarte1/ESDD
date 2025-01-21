#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

// Cria uma lista vazia
Lista* criarLista() {
    return NULL; // Lista vazia
}

// Função para cadastrar um produto na lista
Lista* cadastrarProduto(Lista* lista, Produto produto) {
    Lista* novo = (Lista*)malloc(sizeof(Lista)); // Aloca um novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return lista; // Retorna a lista sem alterações em caso de erro
    }

    novo->produto = produto;
    novo->prox = lista; // Insere o novo produto no início da lista
    return novo; // Retorna a nova cabeça da lista
}

// Função para buscar o produto com menor preço
Produto* buscarProdutoPreco(Lista* lista) {
    if (lista == NULL) {
        return NULL; // Lista vazia
    }

    Produto* menorPreco = &lista->produto; // Assume que o primeiro produto é o de menor preço
    Lista* temp = lista->prox;

    while (temp != NULL) {
        if (temp->produto.valor < menorPreco->valor) {
            menorPreco = &temp->produto;
        }
        temp = temp->prox;
    }

    return menorPreco; // Retorna o produto com menor preço
}

// Função para buscar produtos com estoque inferior a determinado valor
Lista* buscarProdutoValor(Lista* lista, int estoqueMin) {
    Lista* resultado = NULL;
    Lista* temp = lista;

    while (temp != NULL) {
        if (temp->produto.qtdEstoque < estoqueMin) {
            Lista* novo = (Lista*)malloc(sizeof(Lista)); // Aloca um novo nó
            novo->produto = temp->produto;
            novo->prox = resultado; // Insere no início da lista de resultados
            resultado = novo; // Atualiza a cabeça da lista de resultados
        }
        temp = temp->prox;
    }

    return resultado; // Retorna a lista de produtos com estoque abaixo do mínimo
}

// Função para apagar um produto pelo código
Lista* apagarProduto(Lista* lista, int codigo) {
    Lista* temp = lista;
    Lista* ant = NULL;

    // Caso o produto esteja no início da lista
    if (temp != NULL && temp->produto.codigo == codigo) {
        lista = temp->prox; // Atualiza a cabeça da lista
        free(temp); // Libera o nó
        return lista;
    }

    // Procurando o produto
    while (temp != NULL && temp->produto.codigo != codigo) {
        ant = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        return lista; // Produto não encontrado
    }

    ant->prox = temp->prox; // Desconecta o produto da lista
    free(temp); // Libera o nó
    return lista; // Retorna a nova cabeça da lista
}

// Função para atualizar um produto
Lista* atualizarProduto(Lista* lista, Produto produto) {
    Lista* temp = lista;

    while (temp != NULL) {
        if (temp->produto.codigo == produto.codigo) {
            temp->produto = produto; // Atualiza o produto
            return lista; // Retorna a lista com o produto atualizado
        }
        temp = temp->prox;
    }

    return lista; // Produto não encontrado
}

// Função para gerar o relatório de produtos em ordem crescente de estoque
void gerarRelatorioCres(Lista* lista) {
    if (lista == NULL) {
        printf("Nenhum produto em estoque.\n");
        return;
    }

    Lista* i, *j;
    // Ordenação por quantidade crescente
    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->produto.qtdEstoque > j->produto.qtdEstoque) {
                Produto temp = i->produto;
                i->produto = j->produto;
                j->produto = temp;
            }
        }
    }

    // Imprime o relatório
    Lista* temp = lista;
    printf("Relatório de Produtos - Ordem Crescente da Quantidade em Estoque:\n");
    while (temp != NULL) {
        printf("Código: %d, Nome: %s, Descrição: %s, Valor: %.2f, Quantidade: %d, Data: %s\n",
               temp->produto.codigo, temp->produto.nome, temp->produto.descricao,
               temp->produto.valor, temp->produto.qtdEstoque, temp->produto.data);
        temp = temp->prox;
    }
}

// Função para gerar o relatório de produtos em ordem decrescente de estoque
void gerarRelatorioDesc(Lista* lista) {
    if (lista == NULL) {
        printf("Nenhum produto em estoque.\n");
        return;
    }

    Lista* i, *j;
    // Ordenação por quantidade decrescente
    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->produto.qtdEstoque < j->produto.qtdEstoque) {
                Produto temp = i->produto;
                i->produto = j->produto;
                j->produto = temp;
            }
        }
    }

    // Imprime o relatório
    Lista* temp = lista;
    printf("Relatório de Produtos - Ordem Decrescente da Quantidade em Estoque:\n");
    while (temp != NULL) {
        printf("Código: %d, Nome: %s, Descrição: %s, Valor: %.2f, Quantidade: %d, Data: %s\n",
               temp->produto.codigo, temp->produto.nome, temp->produto.descricao,
               temp->produto.valor, temp->produto.qtdEstoque, temp->produto.data);
        temp = temp->prox;
    }
}
