#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <time.h>

void lerVendasBin(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v){

    FILE *fp = NULL;
    VENDAS vendas;

    fp = fopen("vendas.dat", "rb");

    if(fp == NULL){
        return;
    }

    while(fread(&vendas, sizeof(VENDAS), 1, fp)==1){

        registarVendas(iniLista_v, fimLista_v, vendas);
    }
    fclose(fp);
}

int verificarCliente(ELEMENTO_C *iniLista_c, int num_cliente){

    ELEMENTO_C *aux = iniLista_c;
    char resposta[3];

    while(aux != NULL && aux->lista_c.numero != num_cliente){
        aux = aux->proximo;
    }
     
    if(aux == NULL){
        printf("Numero nao encontrado\n");
        printf("Deseja inserir outro numero?(S/N)");
        scanf("%s", resposta);

        if (strcasecmp(resposta, "S") == 0 || strcasecmp(resposta, "sim") == 0)
        { // se o utilizador que resporder que sim ele pode introduzir um novo codigo
            return -1;
        }
        else if (strcasecmp(resposta, "N") == 0 || strcasecmp(resposta, "nao") || strcasecmp(resposta, "não") == 0)
        { // se responder que não ele volta para o menu
            return -2;
        }
        else
        {
            printf("Opção inválida! A voltar ao menu"); // se o utilizador  não responder uma das quatro opções, volta para o menu
            return -2;
        }
    }
    return 0;
}

int verificarProduto(ELEMENTO_P *iniLista_p, int codigo_produto){
    ELEMENTO_P *aux = iniLista_p;
    char resposta[3];

    
    while (aux != NULL && aux->lista_p.codigo_produto != codigo_produto)
    {
    aux = aux->proximo;
    }
       
    if (aux == NULL)
    {
        printf("Codigo de produto nao encontrado\n");
        printf("Deseja inserir outro numero?(S/N)");
        scanf("%s", resposta);

        if (strcasecmp(resposta, "S") == 0 || strcasecmp(resposta, "sim") == 0)
        { // se o utilizador que resporder que sim ele pode introduzir um novo codigo
            return -1;
        }
        else if (strcasecmp(resposta, "N") == 0 || strcasecmp(resposta, "nao") || strcasecmp(resposta, "não") == 0)
        { // se responder que não ele volta para o menu
            return -2;
        }
        else
        {
            printf("Opção inválida! A voltar ao menu"); // se o utilizador  não responder uma das quatro opções, volta para o menu
            return -2;
        }
    }
    return 0;
}

void decrementarQuantidade(){



}

void registarVendas(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v, VENDAS novaVenda){

    ELEMENTO_V *novo = NULL;

    novo = (ELEMENTO_V *) malloc(sizeof(ELEMENTO_V));

    if(novo == NULL){

        printf("Out of memory!\n");
        exit(-1);
    }

    novo->lista_v = novaVenda;
    novo->anterior=NULL;
    novo->proximo=NULL;

    if(*fimLista_v == NULL){

        *iniLista_v = novo;
        *fimLista_v = novo;
    }
    else{
        novo->anterior = *fimLista_v;
        (*fimLista_v)->proximo = novo;
        *fimLista_v = novo;
    }

}

void relatorioDiario(ELEMENTO_V *iniLista_v){

    time_t mytime = time(NULL);                   //time.h
    struct tm *dataAtual = localtime(&mytime);
    int diaAtual = dataAtual->tm_mday;
    int mesAtual = dataAtual->tm_mon+1;
    int anoAtual = dataAtual->tm_year+1900;

    ELEMENTO_V *aux = iniLista_v;
    FILE *fp = NULL;
    int vendasEncontradas = 0;
    int dia=0, mes=0, ano=0;

    fp = fopen("relatorioDiario","w");

    if(fp == NULL){

        printf("Erro a guardar no ficheiro");
        return;
    }

    fprintf(fp, "%-15s %-15s %-15s %-20s\n", "Cliente", "Produto", "Quantidade", "Data de venda");

    while(aux != NULL){

        if(sscanf(aux->lista_v.data_venda, "%d/%d/%d", &dia, &mes, &ano) != 3){

            printf("Erro!\n");
            return;
        }

        if(ano == anoAtual && mes == mesAtual && dia == diaAtual){
            
            fprintf(fp, "%-15d %-15d %-15d %-20s\n", aux->lista_v.numero_cliente, aux->lista_v.numero_produto, aux->lista_v.quantidade_vendida, aux->lista_v.data_venda);
            vendasEncontradas = 1;

        }    
        aux = aux->proximo;
    }
    if (!vendasEncontradas) {

        printf("Nao existem produtos com stock abaixo do do nivel minimo inserido!\n");
        fprintf(fp, "\nNao existem produtos com stock abaixo do do nivel minimo inserido.\n");
    }

    if(vendasEncontradas == 1){

        printf("Relatorio criado!\n");
    }

    fclose(fp);
}




void guardarVendasBin(ELEMENTO_V *iniLista_v){

    FILE *fp = NULL;
    ELEMENTO_V *aux = iniLista_v;

    fp = fopen("vendas.dat", "wb");

    if(fp == NULL){

        printf("Erro ao guardar no ficheiro");
        
        return;
    }

    while(aux != NULL){

        fwrite(&aux->lista_v, sizeof(VENDAS), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);
}

void libertarListaVendas(ELEMENTO_V **iniLista_v, ELEMENTO_V **fimLista_v){       //case 0

    ELEMENTO_V *aux = *iniLista_v, *proximo = NULL;
    *iniLista_v = NULL;
    *fimLista_v = NULL;
    while(aux!=NULL){

        proximo = aux->proximo;
        free(aux);
        aux=proximo;
    }
}