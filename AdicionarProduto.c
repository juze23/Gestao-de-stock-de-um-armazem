#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void AdicionarProduto(ELEMENTO **iniLista, ELEMENTO **fimLista, PRODUTO newProduto, int *num_produtos){

    int codigo;         //variável para receber novo código
    int i=0;            //variável para usar no for
    PRODUTO aux;
    ELEMENTO *novo = NULL;

    printf("Insira o codigo do produto: ");     //pede o código do novo produto
    scanf("%d", &codigo);                       //guarda o código do novo produto

    for(i = 0; i < *num_produtos; i++){      //correr os produtos todos já inseridos com a variável i e o ponteiro para o numero de produtos
        if(produtos[i].product_code == codigo){       //se o codigo do produto for igual a um codigo já inserido
            
            printf("Ja existe um produto com esse codigo!\n");      //já existe esse produto
            system("pause");                                        //system pause pq se não o programa limpa logo e não se vê a mensagem
            return;                                             //retorna à main
        }
    }

    aux.product_code = codigo;    //se não, o codigo da variavel PRODUTO toma o valor do novo codigo e são pedidos os restantes dados do produto

    printf("Insira o nome do produto: ");
    scanf("%[^\n]s", aux.product_name);
    fflush(stdin);

    printf("Insira a categoria do produto: ");
    fflush(stdin);
    scanf("%[^\n]s", aux.categoria);

    //  printf("Insira a data de validade do produto: ")
    //  scanf("%?", novo_produto.data de validae)
    
    printf("Insira a quantidade: ");
    scanf("%d", &aux.quantidade);
    fflush(stdin);

    printf("Insira o preco de compra do produto (sem usar virgulas): ");
    scanf("%f", &aux.compra);
    fflush(stdin);

    printf("Insira o preco de venda do produto (sem usar virgulas): ");
    scanf("%f", &aux.venda);
    fflush(stdin);

    //são utilizados apontadores para o numero de produtos para receber os dados pois estes apontam para a variável criada na main

    (*num_produtos)++;             //acréscimo no ponteiro do numero de produtos para que este incremente 1 na variável da main

    printf("Produto adicionado!\n");
    system("pause");
}