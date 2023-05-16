#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void lerClientesBin(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c){       //o programa não anda com isto | rever

    FILE *fp = NULL;
    CLIENTE clientes;

    fp = fopen("clientes.dat", "rb");

    if(fp == NULL){
        return;
    }

    while(fread(&clientes, sizeof(CLIENTE), 1, fp)==1){

        AdicionarCliente(iniLista_c, fimLista_c, clientes);
    }
    fclose(fp);
}

void AdicionarCliente(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c, CLIENTE newCliente){    //case 1

    ELEMENTO_C *novo = NULL;    //variável auxiliar para acrescentar novo produto
    

    novo = (ELEMENTO_C *) malloc(sizeof(ELEMENTO_C));       //reservar memória para colocar um produto

    if(novo == NULL){

        printf("Out of memory!\n");         //caso haja um erro a reservar memória sai com erro -1
        exit(-1);
    }

    novo->lista_c = newCliente;               //iguala o apontador do auxiliar "novo" ao novo produto recebido
    novo->anterior = NULL;                  //inicializa o apontador para o produto anterior a NULL
    novo->proximo = NULL;                   //inicializa o apontador para o produto seguinte a NULL

    if(*fimLista_c == NULL){              //se o fim de lista for NULL

        *iniLista_c=novo;
        *fimLista_c=novo;            //o novo produto fica no inicio e fim da lista pois é o primeiro da lista
    }
    else{                                   //se não (else)
        novo->anterior = *fimLista_c;             //o apontador do novo produto para o anterior toma o valor do fim da lista
        (*fimLista_c)->proximo = novo;            //o apontador do fim da lista para o proximo toma o valor do novo produto
        *fimLista_c = novo;                       //iguala o fim da lista ao novo produto
    }

}

// void AtualizarCliente()

void bubbleSortC(ELEMENTO_C *iniLista_c) {                           //incremento ao case 3
    int troca = 1;                              // depois precisamos mudar para quickSort  <----------

    while (troca) {                                             // só pára o while quando não houver mais nenhuma troca

        ELEMENTO_C *atual = iniLista_c;                             //  Cria um ponteiro atual que aponta para o início da lista ligada
        troca = 0;                                              // defina troca como 0 para indicar que nenhuma troca foi realizada até o momento

        while (atual->proximo != NULL) {                        // percorre a lista ligada
            if (strcasecmp(atual->lista_c.nome, atual->proximo->lista_c.nome) > 0) { // compara o nome do produto atual com o proximo
                CLIENTE aux = atual->lista_c;                     //cria uma varivel aux para armazenar o produto atual.
                atual->lista_c = atual->proximo->lista_c;           //substitui o produto atual pelo próximo produto na lista.
                atual->proximo->lista_c = aux;                    //substitui o próximo produto na lista pelo produto temporário armazenado em aux.
                troca = 1;                                      //define troca como 1 para indicar que uma troca foi feita
            }
            atual = atual->proximo;                             //move o "atual" para o proximo elemento da lista
        }
    }
}

void listarClientesAlfabetica(ELEMENTO_C *iniLista_c){        //case 5

    
    ELEMENTO_C *aux = NULL;

    bubbleSortC(iniLista_c);               //chama a função bubbleSort(depois temos que trocar para quickSort-algortimo cansado)

    if(iniLista_c == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    aux = iniLista_c;
    printf("%-8s %-25s %-18s %-20s %-14s %-20s\n", "Numero", "Nome", "Morada", "NIF","Telefone", "Email");

    while(aux != NULL){
        
        printf("%-8d %-25s %-18s %-20d %-14d %-20s\n", aux->lista_c.numero, aux->lista_c.nome, aux->lista_c.morada, aux->lista_c.NIF, aux->lista_c.n_telefone, aux->lista_c.email);
        aux = aux->proximo; // percorrer todos os produtos
    }

}

void listarClientesNIF(int nif, ELEMENTO_C *iniLista_c){                  //case 4

    ELEMENTO_C *aux = NULL;
    int cont = 0;
    

    if(iniLista_c == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }
                    //acrescentar algo para quando não existe produto com o código pedido printar "Não existe produto com esse código!"
    aux = iniLista_c;

    while(aux != NULL){

        if(aux->lista_c.NIF == nif){
            cont++;    
        }
        aux= aux->proximo;
    }

    if(cont == 0){
        printf("NIF nao encontrado\n");
        return;
    }

    aux = iniLista_c;

    printf("%-8s %-25s %-18s %-20s %-14s %-20s\n", "Numero", "Nome", "Morada", "NIF","Telefone", "Email");

    while(aux != NULL){

        if(aux->lista_c.NIF == nif){
            
        printf("%-8d %-25s %-18s %-20d %-14d %-20s\n", aux->lista_c.numero, aux->lista_c.nome, aux->lista_c.morada, aux->lista_c.NIF, aux->lista_c.n_telefone, aux->lista_c.email);

        }else {
            
        }
        aux = aux->proximo;     //correr os produtos todos até encontrar o produto com o codigo igual
    }
    
}

void guardarClientesBin(ELEMENTO_C *iniLista_c){          //o programa não anda com isto | rever

    FILE *fp = NULL;
    ELEMENTO_C *aux = iniLista_c;

    fp = fopen("clientes.dat", "wb");

    if(fp == NULL){

        printf("Erro ao guardar no ficheiro");
        
        return;
    }

    while(aux != NULL){

        fwrite(&aux->lista_c, sizeof(CLIENTE), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);
}

void libertarListaClientes(ELEMENTO_C **iniLista_c, ELEMENTO_C **fimLista_c){       //case 0

    ELEMENTO_C *aux = *iniLista_c, *proximo = NULL;
    *iniLista_c = NULL;
    *fimLista_c = NULL;
    while(aux!=NULL){

        proximo = aux->proximo;
        free(aux);
        aux=proximo;
    }
}