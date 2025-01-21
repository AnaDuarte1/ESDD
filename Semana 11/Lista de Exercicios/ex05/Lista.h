#ifndef LISTA_H
#define LISTA_H
#endif

typedef struct {
    int codigo;
    char descricao[1000];
    char nome[1000];
    float valor;
    int qtdEstoque;
    char data[11]; 
} Produto;

typedef struct Lista {
    Produto produto;
    struct Lista* prox;
} Lista;

Lista* criarLista();
Lista* cadastrarProduto(Lista* lista, Produto produto);
Produto* buscarProdutoPreco(Lista* lista);
Lista* buscarProdutoValor(Lista* lista, int estoqueMin);
Lista* apagarProduto(Lista* lista, int codigo);
Lista* atualizarProduto(Lista* lista, Produto produto);
void gerarRelatorioCres(Lista* lista);
void gerarRelatorioDesc(Lista* lista);


