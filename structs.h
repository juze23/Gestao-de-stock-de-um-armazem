#ifndef structs_h
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
    struct Elem *proximo;
    struct Elem *anterior;
    
}ELEMENTO;

void AdicionarProduto(int *num_produtos, PRODUTO *produtos);    //recebe o ponteiro para o numero de produtos, da struct e do tamanho máximo da struct
void AtualizarProduto(int *num_produtos, PRODUTO *produtos);

#endif