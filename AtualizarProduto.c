#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int pesquisaBin(int codigoA, PRODUTO *produtos, int *num_produtos){

     int ini=0, meio=0, fim=*num_produtos-1;           //pesquisa binária para encontrar a posição do código

    while(ini<=fim){

        meio=((ini+fim)/2);

        if(codigoA==produtos[meio].product_code){

            return meio;
        }
        if(codigoA<produtos[meio].product_code){

            fim=meio-1;
        }
        else{

            ini=meio+1;
        }
    }
    return -1;
}


int AtualizarProduto(int *num_produtos, PRODUTO *produtos){

    int codigoA=0;
    int pos=0;
    int op=0;
    int i=0;

    printf("Insira o codigo do produto que deseja atualizar:\n");
    scanf("%d", &codigoA);                  //saber que produto deseja alterar através do código

   pos=pesquisaBin(codigoA, produtos, num_produtos);        //posição do produto = pesquisaBin

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
            scanf("%d", &produtos[pos].quantidade);
            break;
        case 2:
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &produtos[pos].venda);
            break;
        case 3:
            printf("Insira a nova quantidade do produto:\n");
            scanf("%d", &produtos[pos].quantidade);
            printf("Insira o novo preco de venda do produto:\n");
            scanf("%f", &produtos[pos].venda);
            break;
        default:
            printf("Nao existe essa opcao");
            break;
        }
    printf("Atualizacao feita!\n");
    system("pause");
}