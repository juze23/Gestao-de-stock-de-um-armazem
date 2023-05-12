#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void AdicionarProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, PRODUTO newProduto){    //case 1

    ELEMENTO *novo = NULL;    //variável auxiliar para acrescentar novo produto
    

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

int verificarcodigo(ELEMENTO **iniLista, int *codigo){

    ELEMENTO *aux = *iniLista;
    

    while(aux != NULL){
        if(*codigo == aux->lista.product_code){          //percorre a lista para verificar se os codigos dos produtos são iguais

            printf("Esse codigo ja existe.\n");
            printf("Deseja inserir outro codigo?(S/N)\n");
            char resposta[3];
            scanf("%s", resposta);

            if (strcasecmp(resposta, "S") == 0 || strcasecmp(resposta, "sim") == 0) {  // se o utilizador que resporder que sim ele pode introduzir um novo codigo
                return -1;
            }else if(strcasecmp(resposta, "N") == 0 || strcasecmp(resposta, "nao") || strcasecmp(resposta, "não")== 0){  // se responder que não ele volta para o menu
                return -2;
            }else{
                printf("Opção inválida! A voltar ao menu");     // se o utilizador  não responder uma das quatro opções, volta para o menu 
                return -2;
            }
        }
        aux = aux->proximo;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int pesquisaBin(int codigoA, int *num_produtos, ELEMENTO *iniLista){

    int ini=0, meio=0, fim=*num_produtos-1;        //pesquisa binária para encontrar a posição do código
    ELEMENTO *aux = iniLista;

    while(aux !=NULL){

        meio=((ini+fim)/2);

        if(codigoA==aux->lista.product_code){

            return meio;
        }
        if(codigoA== aux->lista.product_code){

            fim=meio-1;
        }
        else{

            ini=meio+1;
        }
        aux = aux->proximo;
    }
    return -1;
}


void AtualizarProduto(int *num_produtos,ELEMENTO *iniLista){

    int codigoA=0;
    int pos=0;
    int op=0;
    
    ELEMENTO *aux = iniLista;
    

    printf("Insira o codigo do produto que deseja atualizar:\n");
    scanf("%d", &codigoA);                  //saber que produto deseja alterar através do código

   pos=pesquisaBin(codigoA,num_produtos,iniLista);        //posição do produto = pesquisaBin

   if(pos==-1){

    printf("Produto nao encontrado\n");   //se a função pesquisaBin devolver -1 não encontrou produto com o numero inserido
    system("pause");
    return;
   }

    printf("O que deseja atualizar do produto?");
    printf("\n1 - Quantidade do produto");
    printf("\n2 - Preco de venda");
    printf("\n3 - Ambos");
    printf("\n> ");
    scanf("%d", &op);

    switch (op){            //opções para substituir informações já existentes

        case 1:
            printf("Insira a nova quantidade do produto:\n");
            scanf("%d", &aux->lista.quantidade);
            break;
        case 2:
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &aux->lista.venda);
            break;
        case 3:
            printf("Insira a nova quantidade do produto:\n");
            scanf("%d", &aux->lista.quantidade);
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &aux->lista.venda);
            break;
        default:
            printf("Nao existe essa opcao");
            break;
        }
    printf("Atualizacao feita!\n");
    system("pause");
}

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


void bubbleSort(ELEMENTO *iniLista) {                           // depois precisamos mudar para quickSort
    int troca = 1;

    while (troca) {                                             // só pára o while quando não houver mais nenhuma troca

        ELEMENTO *atual = iniLista;                             //  Cria um ponteiro atual que aponta para o início da lista ligada
        troca = 0;                                              // defina troca como 0 para indicar que nenhuma troca foi realizada até o momento

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

    
    ELEMENTO *aux = NULL;

    bubbleSort(iniLista);               //chama a função bubbleSort(depois temos que trocar para quickSort-algortimo cansado)

    if(iniLista == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    aux = iniLista;
    printf("%-8s %-25s %-12s %-20s %-14s %-20s %-12s\n", "Codigo", "Nome", "Categoria", "Data de validade", "Quantidade", "Preco de compra", "Preco de venda");

    while(aux != NULL){
        
        printf("%-8d %-25s %-12s %-20s %-14d %-20.2f %-12.2f\n", aux->lista.product_code, aux->lista.product_name, aux->lista.categoria, "data de validade", aux->lista.quantidade, aux->lista.compra, aux->lista.venda);
        aux = aux->proximo; // percorrer todos os produtos
    }

}

void valordostockatual(ELEMENTO *iniLista){

    ELEMENTO *aux =iniLista;
    float soma = 0;

    while(aux != NULL){                                       //percorre a lista
        soma += aux->lista.quantidade*aux->lista.compra;      //faz a soma do valor atual do stock multiplicando a quantidade do produto com o preço de compra
        aux = aux->proximo; 
    }

    printf("O valor total do stock e de %.2f\n", soma);

   aux =iniLista;                                             //volta ao inicio da lista

    while(aux != NULL){
        
        printf("%-25s %-12s %-14d %-12.2f\n", aux->lista.product_name, aux->lista.categoria, aux->lista.quantidade, aux->lista.quantidade*aux->lista.compra);
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


