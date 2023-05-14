#ifndef structs_h
#define structs_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{

    int codigo_produto;
    char nome_produto[32];
    char categoria[32];
    //data de validade
    int quantidade;
    float compra;
    float venda;
    

}PRODUTO;

typedef struct elemento_p{

    PRODUTO lista_p;
    struct elemento_p *proximo;
    struct elemento_p *anterior;
    
}ELEMENTO_P;

void lerProdutosBin(int num_produtos, ELEMENTO_P **iniLista, ELEMENTO_P **fimLista);
void AdicionarProduto(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista, PRODUTO newProduto);
void AtualizarProduto(int *num_produtos,ELEMENTO_P *iniLista);
void removerProduto(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista, int num);
void listarProdutosCodigo(int cod, ELEMENTO_P *iniLista);
void bubbleSortP(ELEMENTO_P *iniLista);
void listarProdutosAlfabetica(ELEMENTO_P *iniLista);
void listarProdutosCategoria(char categoriaA, ELEMENTO_P *iniLista);
void valordostockatual(ELEMENTO_P *iniLista);
int verificarcodigo(ELEMENTO_P **iniLista, int *codigo);
void guardarProdutosBin(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista);
void libertarLista(ELEMENTO_P **iniLista, ELEMENTO_P **fimLista);

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

void AdicionarCliente(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c, CLIENTE newCliente);
void bubbleSortC(ELEMENTO_C *iniLista_c);
void listarClientesAlfabetica(ELEMENTO_C *iniLista_c);
void listarClientesNIF(int nif, ELEMENTO_C *iniLista_c);

#endif