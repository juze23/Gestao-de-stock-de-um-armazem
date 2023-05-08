#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int menu(){

    int op = 0;
    printf("\n*** Gestao de Stock de um armazem de distribuicao de alimentos ***\n\n");
    printf("\n1 - Adicionar produto ao stock");     //por completar
    printf("\n2 - Atualizar as informacoes de um produto existente");       //muito incompleto
    printf("\n3 - Remover um produto do stock");        //por fazer
    printf("\n4 - Apresentar informacoes de um produto");       //por fazer
    printf("\n5 - Listar todos os produtos em stock por ordem alfabetica");     //por fazer
    printf("\n6 - Listar os produtos em stock por categoria");      //por fazer
    printf("\n7 - Listar os produtos em stock com data de validade vencida");       //por fazer
    printf("\n8 - Calcular o valor do stock atual");        //por fazer
    printf("\n9 - Criar relatorios de produtos que estao com stock abaixo do nivel minimo estabelecido pela empresa");      //por fazer
    printf("\nParte dos clientes (por fazer)");     //por fazer
    printf("\nParte das vendas do armazem(por fazer)");     //por fazer
    printf("\n0 - Sair");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}

int main(){

    PRODUTO produtos[MAX_produtos];     //variável da struct produtos
    
    ELEMENTO *iniLista=NULL;
    ELEMENTO *fimLista=NULL;
    
    int num_produtos = 0;               //variável do número de produtos
    int op = 0;                         //variável da opção

    do{
        system("cls");          //clear screen para limpar o ecrã depois de chamar a função desejada
        op = menu();            //dá o valor que recebe da função menu à variável opção
        switch(op){

            case 1:
                AdicionarProduto(&num_produtos, &produtos);   //envia o endereço do número de produtos, da struct produtos e do MAX
                break;
            case 2:
                AtualizarProduto(&num_produtos, &produtos);  //envia as variáveis utilizadas
                break;
            case 0:
            printf("Saiu!\n");
            return 0;
            break;
            default:
            printf("Opcao invalida");
        }

    }while(op != 0);

}