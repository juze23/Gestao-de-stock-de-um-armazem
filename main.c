#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs.h"

int menu(){

    int op = 0;
    printf("\n*** Gestao de Stock de um armazem de distribuicao de alimentos ***\n\n");
    printf("Escolha a opcao relativa a area na qual pretende trabalhar:\n");
    printf("\n1 - Gestao de produtos");         //por fazer
    printf("\n2 - Gestao de clientes");         //por fazer
    printf("\n3 - Gestao de vendas");           //por fazer
    printf("\n0 - Sair");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}

int menuCliente(){

    int op = 0;
    printf("\n*** Gestao da informacao dos clientes do armazem ***\n\n");
    printf("\n1 - Adicionar um novo cliente");
    printf("\n2 - Alterar as informacoes de um cliente");
    printf("\n3 - Listar todos os clientes por ordem alfabetica");
    printf("\n4 - Apresentar as informacoes de um cliente");
    printf("\n0 - Voltar");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}

int menuVendas(){

    int op = 0;
    printf("\n*** Registo de vendas do armazem ***\n\n");
    printf("\n1 - Registar vendas de produtos");
    printf("\n2 - Criacao de relatorios de vendas");
    printf("\n0 - Voltar");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}

int menuProduto(){

    int op = 0;
    printf("\n*** Gestao de Stock de um armazem de distribuicao de alimentos ***\n\n");
    printf("\n1 - Adicionar produto ao stock");
    printf("\n2 - Atualizar as informacoes de um produto existente - incompleto");
    printf("\n3 - Remover um produto do stock");
    printf("\n4 - Apresentar informacoes de um produto");
    printf("\n5 - Listar todos os produtos em stock por ordem alfabetica");
    printf("\n6 - Listar os produtos em stock por categoria");
    printf("\n7 - Listar os produtos em stock com data de validade vencida");
    printf("\n8 - Calcular o valor do stock atual");
    printf("\n9 - Criar relatorios de produtos que estao com stock abaixo do nivel minimo estabelecido pela empresa");
    printf("\n0 - Voltar");
    printf("\n> ");
    scanf("%d", &op);       //recebe a opção
    return op;              //envia a opção
}

int main(){

    PRODUTO produtos_aux;     //variável da struct produtos
    CLIENTE cliente_aux;

    ELEMENTO_P *iniLista_p=NULL;
    ELEMENTO_P *fimLista_p=NULL;

    ELEMENTO_C *iniLista_c=NULL;
    ELEMENTO_C *fimLista_c=NULL;
    
    int op = 0;                     //variável da opção do menu principal
    int opP = 0, opC = 0, opV = 0;              //variável das opções dos menus secundários
    int res;
    int voltar_menu = 0;
    cliente_aux.numero = 0;

    //lerProdutosBin(&iniLista_p, &fimLista_p);

    do{
        system("cls");          //clear screen para limpar o ecrã depois de chamar a função desejada
        op = menu();
        switch(op){
            case 1:
                do{
                    system("cls");
                    opP = menuProduto();
                    switch(opP){
                        case 1:
                            do{
                                printf("Insira o codigo do produto:\n");
                                scanf("%d", &produtos_aux.codigo_produto);
                                fflush(stdin);
                                res = verificarcodigo(&iniLista_p, &produtos_aux.codigo_produto);   
                                    if(res == -2){                                               // se o res for igual a -2 altera a variavel voltar_menu para 1
                                        voltar_menu =1;                                          // o res é igual a -2 quando a resposta é não ou quando a respostas não é uma das quatro opções pedidas
                                        break;
                                    }
                            }while(res!=0);                                              // quando o res for igual a 0, ele para de fazer o ciclo
                            if (voltar_menu) {
                                voltar_menu = 0;                                       // se o voltar_menu for igual a 1, volta para o menu
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

                            printf("Insira a quantidade:\n");
                            scanf("%d", &produtos_aux.quantidade);
                            fflush(stdin);

                            printf("Insira o preco de compra do produto (sem usar virgulas):\n");
                            scanf("%f", &produtos_aux.compra);
                            fflush(stdin);

                            printf("Insira o preco de venda do produto (sem usar virgulas):\n");
                            scanf("%f", &produtos_aux.venda);
                            fflush(stdin);

                            AdicionarProduto(&iniLista_p, &fimLista_p, produtos_aux);

                            printf("Produto adicionado\n");
                            system("pause");

                            break;
                        case 2:
                            //AtualizarProduto(iniLista_p);  //envia as variáveis utilizadas
                            printf("Produto atualizado!\n");
                            system("pause");
                            break;
                        case 3:
                            int num=0;
                            printf("Insira o codigo do produto que deseja remover:\n");
                            scanf("%d", &num);
                            removerProduto(&iniLista_p, &fimLista_p, num);
                            system("pause");
                            break;
                        case 4:
                            int cod=0;
                            printf("Insira o codigo do produto que deseja ver:\n");
                            scanf("%d", &cod);
                            listarProdutosCodigo(cod, iniLista_p);
                            system("pause");
                            break;
                        case 5:
                            printf("Lista de todos os produtos ordenados por ordem alfabetica: \n");
                            listarProdutosAlfabetica(iniLista_p);
                            system("pause");
                            break;
                        case 6:
                            char categoriaA[50];
                            getchar();
                            printf("Insira a categoria de produtos que deseja listar:\n");
                            scanf("%[^\n]s", categoriaA);
                            listarProdutosCategoria(categoriaA, iniLista_p);
                            system("pause");
                            break;
                        case 8:
                            valordostockatual(iniLista_p);
                            system("pause");
                            break;
                        case 0:
                            //guardarProdutosBin(&iniLista_p, &fimLista_p);
                            libertarLista(&iniLista_p, &fimLista_p);
                            printf("A voltar!\n");
                            sleep(1.5);
                            break;
                        default:
                            printf("Opcao invalida!");
                            break;
                    }
                }while(opP != 0);
                break;
            case 2:
                do{
                    system("cls");
                    opC = menuCliente();
                    switch(opC){
                        case 1:
                            fflush(stdin);
                            printf("Insira o nome do cliente:\n");
                            scanf("%[^\n]s", cliente_aux.nome);
                            fflush(stdin);

                            printf("Insira a morada do cliente:\n");
                            scanf("%[^\n]s", cliente_aux.morada);
                            fflush(stdin);

                            printf("Insira o NIF do cliente:\n");
                            scanf("%d", &cliente_aux.NIF);            
                            fflush(stdin);

                            printf("Insira o numero de telefone do cliente:\n");
                            scanf("%d", &cliente_aux.n_telefone);            
                            fflush(stdin);

                            printf("Insira o email do cliente:\n");
                            scanf("%[^\n]s",cliente_aux.email);
                            fflush(stdin);

                            cliente_aux.numero++;

                            AdicionarCliente(&iniLista_c, &fimLista_c, cliente_aux);

                            printf("Cliente adicionado\n");
                            system("pause");

                            break;
                        case 2:
                            break;
                        case 3:
                            printf("Lista de todos os clientes ordenados por ordem alfabetica: \n");
                            listarClientesAlfabetica(iniLista_c);
                            system("pause");
                            break;
                        case 4:
                            int nif=0;
                            printf("Insira o NIF do cliente que deseja ver:\n");
                            scanf("%d", &nif);
                            listarClientesNIF(nif, iniLista_c);
                            system("pause");
                            break;
                        case 0:
                            printf("A voltar!\n");
                            sleep(1.5);
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            system("pause");
                            break;
                    }
                }while(opC != 0);
                break;
            case 3:
                do{
                    system("cls");
                    opV = menuVendas();
                        switch (opV){
                            case 1:
                                break;
                            case 2:
                                break;
                            case 0:
                                printf("A voltar!\n");
                                sleep(1.5);
                                break; 
                            default:
                            printf("Opcao invalida!\n");
                            system("pause");
                                break;
                        }
                    }while(opV != 0);
                    break;
            case 0:
                printf("Saiu!\n");
                return 0;
                break;
            default:
                printf("Opcao invalida");
                system("pause");
                break;
        }
    }while(op != 0);

    guardarProdutosBin(&iniLista_p);
        
    return 0;
}
