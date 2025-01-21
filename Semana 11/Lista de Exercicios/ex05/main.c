#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void exibirProduto(Produto p) {
    printf("Código: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Descrição: %s\n", p.descricao);
    printf("Valor: %.2f\n", p.valor);
    printf("Quantidade em Estoque: %d\n", p.qtdEstoque);
    printf("Data da Última Compra: %s\n", p.data);
}

int main() {
    Lista* lista = criarLista(); 

    Produto p1 = {1, "Produto A", "Descrição do Produto A", 10.50, 5, "20/01/2025"};
    Produto p2 = {2, "Produto B", "Descrição do Produto B", 25.75, 15, "15/12/2024"};
    Produto p3 = {3, "Produto C", "Descrição do Produto C", 5.30, 3, "10/01/2025"};
    
    lista = cadastrarProduto(lista, p1);
    lista = cadastrarProduto(lista, p2);
    lista = cadastrarProduto(lista, p3);
    
    printf("Lista de Produtos após cadastro:\n");
    Lista* temp = lista;
    while (temp != NULL) {
        exibirProduto(temp->produto);
        temp = temp->prox;
    }

    Produto* menorPreco = buscarProdutoPreco(lista);
    if (menorPreco != NULL) {
        printf("\nProduto com o menor preço:\n");
        exibirProduto(*menorPreco);
    }

    Lista* produtosBaixoEstoque = buscarProdutoValor(lista, 10);
    if (produtosBaixoEstoque != NULL) {
        printf("\nProdutos com estoque inferior a 10:\n");
        temp = produtosBaixoEstoque;
        while (temp != NULL) {
            exibirProduto(temp->produto);
            temp = temp->prox;
        }
    }

    gerarRelatorioCres(lista);
    gerarRelatorioDesc(lista);

    lista = apagarProduto(lista, 2);

    printf("\nRelatório após apagar produto de código 2:\n");
    gerarRelatorioCres(lista);

    Produto p4 = {3, "Produto C", "Descrição Atualizada do Produto C", 6.00, 10, "20/01/2025"};
    lista = atualizarProduto(lista, p4);

    
    printf("\nRelatório após atualização do produto de código 3:\n");
    gerarRelatorioCres(lista);

    return 0;
}
