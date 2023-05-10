#ifndef structs_h
#define structs_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{

    int product_code;
    char product_name[32];
    char categoria[32];
    //data de validade
    int quantidade;
    float compra;
    float venda;
    

}PRODUTO;

typedef struct elemento{

    PRODUTO lista;
    struct elemento *proximo;
    struct elemento *anterior;
    
}ELEMENTO;

void AdicionarProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, PRODUTO newProduto);
void AtualizarProduto(int *num_produtos, PRODUTO *produtos);
void removerProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, int num);
void listarProdutosCodigo(int cod, ELEMENTO *iniLista);
void libertarLista(ELEMENTO **iniLista, ELEMENTO **fimLista);
void bubbleSort(ELEMENTO *iniLista);
void listarProdutosAlfabetica(ELEMENTO *iniLista);
void quickSort(ELEMENTO *esquerda, ELEMENTO *direita);

#endif