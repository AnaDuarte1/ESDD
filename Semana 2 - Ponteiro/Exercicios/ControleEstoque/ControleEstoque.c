#include <stdio.h>
#include <string.h>
#include "ControleEstoque.h"

#define MAXC 100
#define MAXP 100

// Estrutura para clientes
typedef struct {
    char nome[50];
    char cpf[12];
    char endereco[100];
    char telefone[15];
    char dataNascimento[11];
} Cliente;

// Estrutura para produtos
typedef struct {
    int codigo;
    char descricao[50];
    float valor;
    char validade[11];
    int quantidade;
} Produto;

int controleEstoque() {
    Cliente clientes[MAXC];
    Produto produtos[MAXP];
    int totalClientes = 0, totalProdutos = 0;
    int opcao;

    do {
        printf("\n------------Menu:------------\n");
        printf("1. Cadastro de clientes\n");
        printf("2. Cadastro de produtos\n");
        printf("3. Consulta de clientes\n");
        printf("4. Consulta de produtos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            if (totalClientes >= MAXC) {
                printf("Capacidade máxima de clientes atingida.\n");
                continue;  // Continue to next iteration
            }

            Cliente novoCliente;
            printf("Nome: ");
            scanf(" %[^\n]", novoCliente.nome);
            printf("CPF: ");
            scanf(" %s", novoCliente.cpf);
            printf("Endereço: ");
            scanf(" %[^\n]", novoCliente.endereco);
            printf("Telefone: ");
            scanf(" %s", novoCliente.telefone);
            printf("Data de nascimento: ");
            scanf(" %s", novoCliente.dataNascimento);

            // Verifica se já existe cliente com o mesmo CPF
            for (int i = 0; i < totalClientes; i++) {
                if (strcmp(clientes[i].cpf, novoCliente.cpf) == 0) {
                    printf("Cliente já cadastrado.\n");
                    continue;  // Continue to next iteration
                }
            }

            clientes[totalClientes] = novoCliente;
            totalClientes++;
            printf("Cliente cadastrado com sucesso!\n");

        } else if(opcao == 2) {
            if (totalProdutos >= MAXP) {
                printf("Capacidade máxima de produtos atingida.\n");
                continue;  // Continue to next iteration
            }

            Produto novoProduto;
            printf("Código: ");
            scanf("%d", &novoProduto.codigo);
            printf("Descrição: ");
            scanf(" %[^\n]", novoProduto.descricao);
            printf("Valor: ");
            scanf("%f", &novoProduto.valor);
            printf("Validade: ");
            scanf(" %s", novoProduto.validade);
            printf("Quantidade: ");
            scanf("%d", &novoProduto.quantidade);

            // Verifica se já existe produto com o mesmo código
            for (int i = 0; i < totalProdutos; i++) {
                if (produtos[i].codigo == novoProduto.codigo) {
                    printf("Produto já cadastrado.\n");
                    continue;  // Continue to next iteration
                }
            }

            produtos[totalProdutos] = novoProduto;
            totalProdutos++;
            printf("Produto cadastrado com sucesso!\n");

        } else if(opcao == 3) {
            printf("Clientes cadastrados:\n");
            for (int i = 0; i < totalClientes; i++) {
                printf("Nome: %s\n CPF: %s\n", clientes[i].nome, clientes[i].cpf);
            }

        } else if(opcao == 4) {
            printf("Produtos cadastrados:\n");
            for (int i = 0; i < totalProdutos; i++) {
                printf("Código: %d\n Descrição: %s\n Valor: %.2f\n Quantidade: %d\n",
                    produtos[i].codigo, produtos[i].descricao, produtos[i].valor, produtos[i].quantidade);
            }

        } else if(opcao == 5) {
            printf("Encerrando o programa.\n");
        } else {
            printf("Opção inválida.\n");
        }

    } while (opcao != 5);

    return 0;
}
