#ifndef structs_h
#define structs_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{

    int codigo_produto;
    char nome_produto[32];
    char categoria[32];
    char data_validade[15];
    int quantidade;
    float compra;
    float venda;
    

}PRODUTO;

typedef struct elemento_p{

    PRODUTO lista_p;
    struct elemento_p *proximo;
    struct elemento_p *anterior;
    
}ELEMENTO_P;

void lerProdutosBin(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista);
void AdicionarProduto(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista, PRODUTO newProduto);
void AtualizarProduto(ELEMENTO_P *iniLista);
void removerProduto(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista, int num);
void listarProdutosCodigo(int cod, ELEMENTO_P *iniLista);
void bubbleSortP(ELEMENTO_P *iniLista);
void listarProdutosAlfabetica(ELEMENTO_P *iniLista);
void listarProdutosCategoria(char categoriaA[], ELEMENTO_P *iniLista);
void valordostockatual(ELEMENTO_P *iniLista);
void verificarDataValidade(ELEMENTO_P *iniLista_p);
void relatorioProdutos(int stock, ELEMENTO_P *iniLista_p);
int verificarcodigo(ELEMENTO_P **iniLista, int *codigo);
void guardarProdutosBin(ELEMENTO_P *iniLista);
void libertarListaProdutos(ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p);

//Clientes

typedef struct cliente{

    char nome[50];
    char morada[50];
    char email[50];
    int NIF;
    int n_telefone;
    int numero;

}CLIENTE;

typedef struct elemento_c{

    CLIENTE lista_c;
    struct elemento_c *proximo;
    struct elemento_c *anterior;
    
}ELEMENTO_C;

void lerClientesBin(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c);
void AdicionarCliente(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c, CLIENTE newCliente);
int verificarNIF(ELEMENTO_C **iniLista_c, int *nif);
int vereficarNtelefone(ELEMENTO_C **iniLista_c, int *n_telefone);
int numeroclientes(ELEMENTO_C *iniLista_c);
void AtualizarCliente(ELEMENTO_C *iniLista_c);
void bubbleSortC(ELEMENTO_C *iniLista_c);
void listarClientesAlfabetica(ELEMENTO_C *iniLista_c);
void listarClientesNIF(int nif, ELEMENTO_C *iniLista_c);
void guardarClientesBin(ELEMENTO_C *iniLista_c);
void libertarListaClientes(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c);


typedef struct vendas{

    int numero_cliente;
    int numero_produto;
    int quantidade_vendida;
    char data_venda[15];

}VENDAS;

typedef struct elemento_v{

    VENDAS lista_v;
    struct elemento_v *proximo;
    struct elemento_v *anterior;

}ELEMENTO_V;

void lerVendasBin(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v);

void registarVendas(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v, VENDAS novaVenda);
void relatorioDiario(ELEMENTO_V *iniLista_v);
void relatorioMensal(ELEMENTO_V *iniLista_v);
void relatorioAnual(ELEMENTO_V *iniLista_v);
void guardarVendasBin(ELEMENTO_V *iniLista_v);
void libertarListaVendas(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v);
int decrementarQuantidade(ELEMENTO_P *iniLista_p, int codigo_produto, int quantidade_vendida);
int verificarCliente(ELEMENTO_C *iniLista_c, int num_cliente);
int verificarProduto(ELEMENTO_P *iniLista_p, int codigo_produto);

#endif