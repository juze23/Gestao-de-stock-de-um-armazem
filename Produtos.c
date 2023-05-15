#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void lerProdutosBin(int num_produtos, ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p){       //o programa não anda com isto | rever

    FILE *fp = NULL;
    PRODUTO produtos;

    fp = fopen("produtos.dat", "rb");

    if(fp == NULL){

        printf("Erro ao ler do ficheiro");
        return;
    }

    while(fread(&produtos, sizeof(ELEMENTO_P), 1, fp)==1){

        num_produtos++;
        AdicionarProduto(iniLista_p, fimLista_p, produtos);
    }
    fclose(fp);
}

void AdicionarProduto(ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p, PRODUTO newProduto){    //case 1

    ELEMENTO_P *novo = NULL;    //variável auxiliar para acrescentar novo produto
    

    novo = (ELEMENTO_P *) malloc(sizeof(ELEMENTO_P));       //reservar memória para colocar um produto

    if(novo == NULL){

        printf("Out of memory!\n");         //caso haja um erro a reservar memória sai com erro -1
        exit(-1);
    }

    novo->lista_p = newProduto;               //iguala o apontador do auxiliar "novo" ao novo produto recebido
    novo->anterior = NULL;                  //inicializa o apontador para o produto anterior a NULL
    novo->proximo = NULL;                   //inicializa o apontador para o produto seguinte a NULL

    if(*fimLista_p == NULL){              //se o fim de lista for NULL

        *iniLista_p=novo;
        *fimLista_p=novo;            //o novo produto fica no inicio e fim da lista pois é o primeiro da lista
    }
    else{                                   //se não (else)
        novo->anterior = *fimLista_p;             //o apontador do novo produto para o anterior toma o valor do fim da lista
        (*fimLista_p)->proximo = novo;            //o apontador do fim da lista para o proximo toma o valor do novo produto
        *fimLista_p = novo;                       //iguala o fim da lista ao novo produto
    }


}

int verificarcodigo(ELEMENTO_P **iniLista_p, int *codigo){        //incremento ao case 1

    ELEMENTO_P *aux = *iniLista_p;
    

    while(aux != NULL){
        if(*codigo == aux->lista_p.codigo_produto){          //percorre a lista para verificar se os codigos dos produtos são iguais

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

int pesquisaBinCod(int codigoA, int *num_produtos, ELEMENTO_P *iniLista_p){             //incremento ao case 2

    int ini=0, meio=0, fim=*num_produtos-1;        //pesquisa binária para encontrar a posição do código
    ELEMENTO_P *aux = iniLista_p;

    while(aux !=NULL){

        meio=((ini+fim)/2);

        if(codigoA==aux->lista_p.codigo_produto){

            return meio;
        }
        if(codigoA== aux->lista_p.codigo_produto){

            fim=meio-1;
        }
        else{

            ini=meio+1;
        }
        aux = aux->proximo;
    }
    return -1;
}


void AtualizarProduto(int *num_produtos,ELEMENTO_P *iniLista_p){              //case 2

    int codigoA=0;
    int pos=0;
    int op=0;
    
    ELEMENTO_P *aux = iniLista_p;
    

    printf("Insira o codigo do produto que deseja atualizar:\n");
    scanf("%d", &codigoA);                  //saber que produto deseja alterar através do código

   pos=pesquisaBinCod(codigoA,num_produtos,iniLista_p);        //posição do produto = pesquisaBin

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
            scanf("%d", &aux->lista_p.quantidade);
            break;
        case 2:
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &aux->lista_p.venda);
            break;
        case 3:
            printf("Insira a nova quantidade do produto:\n");
            scanf("%d", &aux->lista_p.quantidade);
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &aux->lista_p.venda);
            break;
        default:
            printf("Nao existe essa opcao");
            break;
        }
}

void removerProduto(ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p, int num){     //case 3

    ELEMENTO_P *aux = NULL;

    if(*iniLista_p == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }else {
        printf("Produto removido!\n");
    }
    
    aux = *iniLista_p;  

    while(aux!=NULL && aux->lista_p.codigo_produto != num){

        aux = aux->proximo;
    }

    if(aux == NULL){

        return;         //se não houver produto a seguir, retorna ao menu
    }
    if(aux->anterior == NULL){
        *iniLista_p = aux->proximo;
        if(*iniLista_p!=NULL){

            (*iniLista_p)->anterior = NULL;
        }
    }
    else{
        aux->proximo->anterior = aux->proximo;
    }
    if(aux->proximo == NULL){

        *fimLista_p = aux->anterior;
        if(*fimLista_p != NULL){

            (*fimLista_p)->proximo=NULL;
        }
    }
    else{
        aux->proximo->anterior = aux->anterior;
        free(aux);
    }
}

void listarProdutosCodigo(int cod, ELEMENTO_P *iniLista_p){                  //case 4

    ELEMENTO_P *aux = NULL;

    if(iniLista_p == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }
                    //acrescentar algo para quando não existe produto com o código pedido printar "Não existe produto com esse código!"
    aux = iniLista_p;
    printf("%-8s %-25s %-18s %-20s %-14s %-20s %-12s\n", "Codigo", "Nome", "Categoria", "Data de validade", "Quantidade", "Preco de compra", "Preco de venda");

    while(aux != NULL){

        if(aux->lista_p.codigo_produto == cod){
            
            printf("%-8d %-25s %-18s %-20s %-14d %-20.2f %-12.2f\n", aux->lista_p.codigo_produto, aux->lista_p.nome_produto, aux->lista_p.categoria, "data de validade", aux->lista_p.quantidade, aux->lista_p.compra, aux->lista_p.venda);

        }
        aux = aux->proximo;     //correr os produtos todos até encontrar o produto com o codigo igual
    }
    
}


void bubbleSortP(ELEMENTO_P *iniLista_p) {                           //incremento ao case 5
    int troca = 1;                              // depois precisamos mudar para quickSort  <----------

    while (troca) {                                             // só pára o while quando não houver mais nenhuma troca

        ELEMENTO_P *atual = iniLista_p;                             //  Cria um ponteiro atual que aponta para o início da lista ligada
        troca = 0;                                              // defina troca como 0 para indicar que nenhuma troca foi realizada até o momento

        while (atual->proximo != NULL) {                        // percorre a lista ligada
            if (strcasecmp(atual->lista_p.nome_produto, atual->proximo->lista_p.nome_produto) > 0) { // compara o nome do produto atual com o proximo
                PRODUTO aux = atual->lista_p;                     //cria uma varivel aux para armazenar o produto atual.
                atual->lista_p = atual->proximo->lista_p;           //substitui o produto atual pelo próximo produto na lista.
                atual->proximo->lista_p = aux;                    //substitui o próximo produto na lista pelo produto temporário armazenado em aux.
                troca = 1;                                      //define troca como 1 para indicar que uma troca foi feita
            }
            atual = atual->proximo;                             //move o "atual" para o proximo elemento da lista
        }
    }
}

 

void listarProdutosAlfabetica(ELEMENTO_P *iniLista_p){        //case 5

    
    ELEMENTO_P *aux = NULL;

    bubbleSortP(iniLista_p);               //chama a função bubbleSort(depois temos que trocar para quickSort-algortimo cansado)

    if(iniLista_p == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    aux = iniLista_p;
    printf("%-8s %-25s %-18s %-20s %-14s %-20s %-12s\n", "Codigo", "Nome", "Categoria", "Data de validade", "Quantidade", "Preco de compra", "Preco de venda");

    while(aux != NULL){
        
        printf("%-8d %-25s %-18s %-20s %-14d %-20.2f %-12.2f\n", aux->lista_p.codigo_produto, aux->lista_p.nome_produto, aux->lista_p.categoria, "data de validade", aux->lista_p.quantidade, aux->lista_p.compra, aux->lista_p.venda);
        aux = aux->proximo; // percorrer todos os produtos
    }

}

void listarProdutosCategoria(char categoriaA[], ELEMENTO_P *iniLista_p){      //case 6 | já está a funcinar

    ELEMENTO_P *aux = NULL;

    if(iniLista_p == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    aux = iniLista_p;

    printf("Lista dos produtos da categoria \"%s\":\n", categoriaA);

    printf("%-8s %-25s %-18s %-20s %-14s %-20s %-12s\n", "Codigo", "Nome", "Categoria", "Data de validade", "Quantidade", "Preco de compra", "Preco de venda");

    while(aux!=NULL){ 
        if(strcasecmp(aux->lista_p.categoria, categoriaA)==0){
        
        printf("%-8d %-25s %-18s %-20s %-14d %-20.2f %-12.2f\n", aux->lista_p.codigo_produto, aux->lista_p.nome_produto, aux->lista_p.categoria, "data de validade", aux->lista_p.quantidade, aux->lista_p.compra, aux->lista_p.venda);
        }
        aux = aux->proximo; // percorrer todos os produtos
    }
}

void valordostockatual(ELEMENTO_P *iniLista_p){               //case 8

    ELEMENTO_P *aux =iniLista_p;
    float soma = 0;

    while(aux != NULL){                                       //percorre a lista
        soma += aux->lista_p.quantidade*aux->lista_p.compra;      //faz a soma do valor atual do stock multiplicando a quantidade do produto com o preço de compra
        aux = aux->proximo; 
    }

    printf("O valor total do stock e de %.2f\n", soma);

   aux =iniLista_p;                                             //volta ao inicio da lista

    while(aux != NULL){
        
        printf("%-25s %-18s %-14d %-12.2f\n", aux->lista_p.nome_produto, aux->lista_p.categoria, aux->lista_p.quantidade, aux->lista_p.quantidade*aux->lista_p.compra);
        aux = aux->proximo; // percorrer todos os produtos
    }
}

void guardarProdutosBin(ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p){          //o programa não anda com isto | rever

    FILE *fp = NULL;
    ELEMENTO_P *aux = *iniLista_p;

    fp = fopen("produtos.dat", "wb");

    if(fp == NULL){

        printf("Erro ao guardar no ficheiro");
        return;
    }

    while(aux != NULL){

        fwrite(&aux->lista_p, sizeof(ELEMENTO_P), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);
}

void libertarLista(ELEMENTO_P **iniLista_p, ELEMENTO_P **fimLista_p){       //case 0

    ELEMENTO_P *aux = *iniLista_p, *proximo = NULL;
    *iniLista_p = NULL;
    *fimLista_p = NULL;
    while(aux!=NULL){

        proximo = aux->proximo;
        free(aux);
        aux=proximo;
    }
}


