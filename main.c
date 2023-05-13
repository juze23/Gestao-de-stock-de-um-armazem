#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*int menu(){

    int op = 0;
    printf("\n*** Gestao de Stock de um armazem de distribuicao de alimentos ***\n\n");
    printf("\nEscolha a opção relativa a area na qual pretende trabalhar:\n");
    printf("\n1 - Gestao de produtos");         //por fazer
    printf("\n2 - Gestao de clientes");         //por fazer
    printf("\n3 - Gestao de vendas");           //por fazer
    printf("\n0 - Sair");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}*/

/*int menuCliente(){

    int op = 0;
    printf("\n*** Gestao da informacao dos clientes do armazem ***\n\n");
    printf("\n1 - Adicionar um novo cliente");
    printf("\n2 - Alterar as informações de um cliente");
    printf("\n3 - Listar todos os clientes por ordem alfabética");
    printf("\n4 - Apresentar as informacoes de um cliente");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}*/

/*int menuVendas(){

    int op = 0;
    printf("\n*** Registo de vendas do armazem ***\n\n")
    printf("\n1 - Registar vendas de produtos");
    printf("\n2 - Criacao de relatorios de vendas");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}*/

int menu(){

    int op = 0;
    printf("\n*** Gestao de Stock de um armazem de distribuicao de alimentos ***\n\n");
    printf("\n1 - Adicionar produto ao stock");     //por completar
    printf("\n2 - Atualizar as informacoes de um produto existente");       //muito incompleto
    printf("\n3 - Remover um produto do stock");        //incompleto
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

    PRODUTO produtos_aux;     //variável da struct produtos
    
    ELEMENTO_P *iniLista=NULL;
    ELEMENTO_P *fimLista=NULL;
    
    int num_produtos = 0;           //variável do número de produtos
    int op = 0;                     //variável da opção
    int res;
    int voltar_menu = 0;               

    do{
        system("cls");          //clear screen para limpar o ecrã depois de chamar a função desejada
        //lerProdutosBin(num_produtos, &iniLista, &fimLista);
        op = menu();            //dá o valor que recebe da função menu à variável opção
        switch(op){

            case 1:
                do{
                printf("Insira o codigo do produto:\n");
                scanf("%d", &produtos_aux.codigo_produto);
                fflush(stdin);
                res = verificarcodigo(&iniLista, &produtos_aux.codigo_produto);   
                if(res == -2){                                               // se o res for igual a -2 altera a variavel voltar_menu para 1
                    voltar_menu =1;                                          // o res é igual a -2 quando a resposta é não ou quando a respostas não é uma das quatro opções pedidas
                    break;
                }
                }while(res!=0);                                              // quando o res for igual a 0, ele para de fazer o ciclo
                if (voltar_menu) {                                           // se o voltar_menu for igual a 1, volta para o menu
                break; // retorna ao menu
                }
                printf("Insira o nome do produto:\n");
                scanf("%[^\n]s", produtos_aux.nome_produto);
                fflush(stdin);

                //printf("Insira a data de validade do produto: ")
                //scanf("%?", produtos.data);
                //fflush(stdin);

                printf("Insira a categoria do produto:\n");
                scanf("%[^\n]s", produtos_aux.categoria);
                fflush(stdin);

                printf("Insira a quantidade: ");
                scanf("%d", &produtos_aux.quantidade);
                fflush(stdin);

                printf("Insira o preco de compra do produto (sem usar virgulas): ");
                scanf("%f", &produtos_aux.compra);
                fflush(stdin);

                printf("Insira o preco de venda do produto (sem usar virgulas): ");
                scanf("%f", &produtos_aux.venda);
                fflush(stdin);

                num_produtos++;

                AdicionarProduto(&iniLista, &fimLista, produtos_aux);

                printf("Produto adicionado\n");
                system("pause");

                break;
            case 2:
                AtualizarProduto(&num_produtos, iniLista);  //envia as variáveis utilizadas
                printf("Produto atualizado!\n");
                system("pause");
                break;
            case 3:
                int num=0;
                printf("Insira o codigo do produto que deseja remover:\n");
                scanf("%d", &num);
                num_produtos--;
                removerProduto(&iniLista, &fimLista, num);
                printf("Produto removido!\n");
                system("pause");
                break;
            case 4:
                int cod=0;
                printf("Insira o codigo do produto que deseja ver:\n");
                scanf("%d", &cod);
                listarProdutosCodigo(cod, iniLista);
                system("pause");
                break;
            case 5:
                printf("Lista de todos os produtos ordenador por ordem alfabetica: \n");
                listarProdutosAlfabetica(iniLista);
                system("pause");
                break;
            case 6:
                char categoriaA[50];
                printf("Insira a categoria de produtos que deseja listar:\n");
                scanf("%s", categoriaA);
                listarProdutosCategoria(*categoriaA, iniLista);
                system("pause");
                break;
            case 8:
                valordostockatual(iniLista);
                system("pause");
                break;
            case 0:
                //guardarProdutosBin(&iniLista, &fimLista);
                libertarLista(&iniLista, &fimLista);
                printf("Saiu!\n");
                return 0;
                break;
            default:
                printf("Opcao invalida");
        }
        
    }while(op != 0);

}
