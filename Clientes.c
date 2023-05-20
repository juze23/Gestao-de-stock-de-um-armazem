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

int numeroclientes(ELEMENTO_C *iniLista_c){

    ELEMENTO_C *aux = iniLista_c;
    int cont = 0;


    while(aux != NULL){
        cont++;
        aux=aux->proximo;
    }

    return cont;
}

int verificarNIF(ELEMENTO_C **iniLista_c, int *nif){

    ELEMENTO_C *aux = *iniLista_c;
    int digitos = 9;

    //Verificação se o NIF já existe

    while(aux != NULL){
        if(*nif == aux->lista_c.NIF){          //percorre a lista para verificar se os codigos dos produtos são iguais

            printf("Esse NIF ja existe.\n");
            printf("Deseja inserir outro NIF?(S/N) \n");
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

    //Verificação se o NIF tem 9 digitos
    
    int temp = *nif;
    int digitos_lidos = 0;
    char resposta2[3];

    while (temp != 0)
    { // O loop while divide repetidamente o valor de temp por 10 até que o valor se torne zero
        temp /= 10;
        digitos_lidos++;
    }

    if (digitos_lidos != digitos)
    { // Esta linha verifica se o número de dígitos lidos  é diferente do número desejado de dígitos que é 9
        printf("O NIF inserido nao possui 9 digitos!\n");
        system("pause");
        printf("Deseja introduzir outro(S/N)?");
        scanf("%s", resposta2);
        if (strcasecmp(resposta2, "S") == 0 || strcasecmp(resposta2, "sim") == 0) {  // se o utilizador que resporder que sim ele pode introduzir um novo codigo
                return -1;
            }else if(strcasecmp(resposta2, "N") == 0 || strcasecmp(resposta2, "nao") || strcasecmp(resposta2, "não")== 0){  // se responder que não ele volta para o menu
                return -2;
            }else{
                printf("Opção inválida! A voltar ao menu");     // se o utilizador  não responder uma das quatro opções, volta para o menu 
                return -2;
            }
    }

    return 0;
}

void AtualizarCliente(ELEMENTO_C *iniLista_c) {
    int nif;
    int op = 0;
    
    ELEMENTO_C *aux = iniLista_c;

    printf("Insira o NIF do cliente que deseja atualizar:\n");
    scanf("%d", &nif);

    while (aux != NULL && aux->lista_c.NIF != nif) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        printf("NIF nao encontrado\n");
        return;
    }

    printf("O que deseja atualizar do cliente?");
    printf("\n1 - Morada do cliente");
    printf("\n2 - Numero de telefone do cliente");
    printf("\n3 - Email do cliente");
    printf("\n4 - Todas as anteriores");
    printf("\n> ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Insira a nova morada do cliente:\n");
            fflush(stdin);
            scanf(" %[^\n]s", aux->lista_c.morada);
            break;
        case 2:
            printf("Insira o novo numero de telefone do cliente:\n");
            fflush(stdin);
            scanf("%d", &aux->lista_c.n_telefone);
            break;
        case 3:
            printf("Insira o novo email do cliente:\n");
            fflush(stdin);
            scanf(" %[^\n]s", aux->lista_c.email);
            break;
        case 4:
            printf("Insira a nova morada do cliente:\n");
            fflush(stdin);
            scanf(" %[^\n]s", aux->lista_c.morada);

            printf("Insira o novo numero de telefone do cliente:\n");
            fflush(stdin);
            scanf("%d", &aux->lista_c.n_telefone);

            printf("Insira o novo email do cliente:\n");
            fflush(stdin);
            scanf(" %[^\n]s", aux->lista_c.email);
            break;
        default:
            printf("Nao existe essa opcao!\n");
            return;             //tem que retornar para o switch case aq
            break;
    }
    if(op == 1 || op == 2 || op == 3 || op == 4 || op == 5){
        printf("Cliente atualizado!\n");
    }
}



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

                   
    if(iniLista_c == NULL){

        printf("Lista vazia!\n");       //caso ocorra um erro na lista, retornar ao menu
        return;
    }

    aux = iniLista_c;                   //chama a função bubbleSort(depois temos que trocar para quickSort-algortimo cansado)

    bubbleSortC(iniLista_c);

    printf("Lista de todos os clientes ordenados por ordem alfabetica: \n");
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