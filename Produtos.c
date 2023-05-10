#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void AdicionarProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, PRODUTO newProduto){    //case 1

    ELEMENTO *novo = NULL;      //variável auxiliar para acrescentar novo produto

    novo = (ELEMENTO *) malloc(sizeof(ELEMENTO));       //reservar memória para colocar um produto

    if(novo == NULL){

        printf("Out of memory!\n");         //caso haja um erro a reservar memória sai com erro -1
        exit(-1);
    }

    novo->lista = newProduto;               //não sei comentar isto, depois comento
    novo->anterior = NULL;
    novo->proximo = NULL;

    if(*fimLista == NULL){

        *iniLista=novo;
        *fimLista=novo;
    }
    else{
        novo->anterior = *fimLista;
        (*fimLista)->proximo = novo;
        *fimLista = novo;
    }

}

//void atualizarProduto(){              //case 2

                            //fazer esta função com listas ligadas

//}

void removerProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, int num){     //case 3

    ELEMENTO *aux = *iniLista;

    while(aux!=NULL && aux->lista.product_code != num){

        aux = aux->proximo;
    }

    if(aux == NULL){

        return;         //se não houver produto a seguir, retorna ao menu
    }
    if(aux->anterior == NULL){
        *iniLista = aux->proximo;
        if(*iniLista!=NULL){

            (*iniLista)->anterior = NULL;
        }
    }
    else{
        aux->proximo->anterior = aux->proximo;
    }
    if(aux->proximo == NULL){

        *fimLista = aux->anterior;
        if(*fimLista != NULL){

            (*fimLista)->proximo=NULL;
        }
    }
    else{
        aux->proximo->anterior = aux->anterior;
        free(aux);
    }
}

void listarProdutosCodigo(int cod, ELEMENTO *iniLista){                  //case 4

    ELEMENTO *aux = NULL;

    if(iniLista == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }
                    //acrescentar algo para quando não existe produto com o código pedido printar "Não existe produto com esse código!"
    aux = iniLista;
    printf("%-8s %-25s %-12s %-20s %-14s %-20s %-12s\n", "Codigo", "Nome", "Categoria", "Data de validade", "Quantidade", "Preco de compra", "Preco de venda");

    while(aux != NULL){

        if(aux->lista.product_code == cod){
            
            printf("%-8d %-25s %-12s %-20s %-14d %-20.2f %-12.2f\n", aux->lista.product_code, aux->lista.product_name, aux->lista.categoria, "data de validade", aux->lista.quantidade, aux->lista.compra, aux->lista.venda);

        }
        aux = aux->proximo;     //correr os produtos todos até encontrar o produto com o codigo igual
    }
    
}


void bubbleSort(ELEMENTO *iniLista) { // depois precisamos mudar para quickSort
    int troca = 1;

    while (troca) {   // só pára o while quando não houver mais nenhuma troca

        ELEMENTO *atual = iniLista; //  Cria um ponteiro atual que aponta para o início da lista ligada
        troca = 0;  // defina troca como 0 para indicar que nenhuma troca foi realizada até o momento

        while (atual->proximo != NULL) {                        // percorre a lista ligada
            if (strcasecmp(atual->lista.product_name, atual->proximo->lista.product_name) > 0) { // compara o nome do produto atual com o proximo
                PRODUTO aux = atual->lista;                     //cria uma varivel aux para armazenar o produto atual.
                atual->lista = atual->proximo->lista;           //substitui o produto atual pelo próximo produto na lista.
                atual->proximo->lista = aux;                    //substitui o próximo produto na lista pelo produto temporário armazenado em aux.
                troca = 1;                                      //define troca como 1 para indicar que uma troca foi feita
            }
            atual = atual->proximo;                             //move o "atual" para o proximo elemento da lista
        }
    }
}

 

void listarProdutosAlfabetica(ELEMENTO *iniLista){        //case 5

    
    ELEMENTO *aux = iniLista;

    bubbleSort(iniLista);               //chama a função bubbleSort(depois temos que trocar para quickSort-algortimo cansado)

    if(iniLista == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    while(aux != NULL){
        
        printf("%-8d %-25s %-12s %-20s %-14d %-20.2f %-12.2f\n", aux->lista.product_code, aux->lista.product_name, aux->lista.categoria, "data de validade", aux->lista.quantidade, aux->lista.compra, aux->lista.venda);
        aux = aux->proximo; // percorrer todos os produtos
    }

}

void libertarLista(ELEMENTO **iniLista, ELEMENTO **fimLista){       //case 0

    ELEMENTO *aux = *iniLista, *proximo = NULL;
    *iniLista = NULL;
    *fimLista = NULL;
    while(aux!=NULL){

        proximo = aux->proximo;
        free(aux);
        aux=proximo;
    }
}

