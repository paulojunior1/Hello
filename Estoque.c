#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    char descricao[20];
    int codigo_barra;
    int quantidade;
    float preco_compra;
    float preco_venda;
};

int main (){

    int i,j,codigoalteracao, codigoBusca, quantidadeatual=0, quantidademaxproduto=10, cx, cdgBarra, quantvenda, quantPcompra;

    float  caixa=400.0, somaV=0.0,somaC=0.0;

    struct Produto clProdutos[10];

    int continueS, op;

    {
        do{
            printf(" ----------ESCOLHA UMA OPCAO----------\n\n");
            printf(" 1 - NOVO CADASTRO\n");
            printf(" 2 - ALTERAR CADASTRO\n");
            printf(" 3 - LISTAR PRODUTOS\n");
            printf(" 4 - BUSCAR PRODUTOS POR CODIGO DE BARRA\n");
            printf(" 5 - CONTROLE DE CAIXA\n");
            printf(" 9 - SAIR \n\n");
            scanf("%d",&op);

            switch(op){
                case 1:
                    printf(" -------------NOVO CADASTRO-----------\n");
                    printf("\n");
                    printf("\n");

                    for( i = quantidadeatual; i < quantidademaxproduto; i++ )
                    {
                        printf(" DESCRICAO DO PRODUTO: ");
                        scanf("%s", &clProdutos[i].descricao);

                        printf(" CODIGO DE BARRAS: ");
                        scanf("%d", &clProdutos[i].codigo_barra);

                        printf(" QUANTIDADE: ");
                        scanf("%d", &clProdutos[i].quantidade);

                        printf(" PRECO DE COMPRA: ");
                        scanf("%f", &clProdutos[i].preco_compra);

                        printf(" PRECO DE VENDA: ");
                        scanf("%f", &clProdutos[i].preco_venda);

                        printf("\n");
                        printf("\n");

                        quantidadeatual++;

                        printf(" DESEJA CADASTRAR MAIS UM PRODUTO? (SIM=1/NAO=0)");
                        scanf("%d",&continueS);
                        printf("\n");

                        if( continueS == 0){
                            break;
                        }
                        system("cls");

                    }
                    system("cls");
                    break;
                case 2:
                    printf(" -------------ALTERAR CADASTRO-----------\n");
                    printf("\n");
                    printf("\n");

                    printf("INFORME O CODIGO DO PRODUTO QUE DESEJA ALTERAR?");
                    scanf("%d",&codigoalteracao);

                    for(i=0;i<quantidademaxproduto;i++){

                        if(clProdutos[i].codigo_barra==codigoalteracao){

                            printf("- DESCRICAO: %s\n", clProdutos[i].descricao);
                            printf("- CODIGO DE BARRA: %d\n", clProdutos[i].codigo_barra);
                            printf("- QUANTIDADE: %d\n", clProdutos[i].quantidade);
                            printf("- PRECO DE COMPRA: %.2f\n", clProdutos[i].preco_compra);
                            printf("- PRECO DE VENDA: %.2f\n", clProdutos[i].preco_venda);

                            printf("\n");
                            printf("\n");

                            printf("NOVA DESCRICAO: \n");

                            printf("- DESCRICAO:");
                            scanf("%s", &clProdutos[i].descricao);
                            printf("- CODIGO DE BARRA:");
                            scanf("%d", &clProdutos[i].codigo_barra);
                            printf("- QUANTIDADE:");
                            scanf("%d", &clProdutos[i].quantidade);
                            printf("- PRECO DE COMPRA:");
                            scanf("%f", &clProdutos[i].preco_compra);
                            printf("- PRECO DE VENDA:");
                            scanf("%f", &clProdutos[i].preco_venda);



                            system("pause");
                            system("cls");
                            break;

                        }

                    }


                    printf(" -------------PRODUTO ALTERADO COM SUCESSO-----------\n");
                    printf("\n");
                    printf("\n");
                    system("pause");
                    system("cls");

                    break;
                case 3:
                    printf(" -------------LISTAR PRODUTOS-----------\n");
                    printf("\n");
                    printf("\n");

                    for(j = 0; j < quantidadeatual; j++){
                        printf("DESCRICAO: %s\n", clProdutos[j].descricao);
                        printf("CODIGO DE BARRAS: %d\n", clProdutos[j].codigo_barra);
                        printf("PRECO DE VENDA: %.2f\n", clProdutos[j].preco_venda);

                        printf("\n");
                    }

                    system("pause");
                    system("cls");
                    break;
                case 4:
                    printf(" -------------BUSCAR PRODUTOS POR CODIGO DE BARRA-----------\n");
                    printf("\n");
                    printf("\n");


                    printf("INFORME O CODIGO DO PRODUTO QUE DESEJA BUSCAR?");
                    scanf("%d",&codigoBusca);

                    for(i=0;i<quantidademaxproduto;i++){

                        if(clProdutos[i].codigo_barra==codigoBusca){
                            printf(" - DESCRICAO: %s\n", clProdutos[i].descricao);
                            printf(" - QUANTIDADE: %d\n", clProdutos[i].quantidade);
                            printf(" - VALOR VENDA: %.2f\n", clProdutos[i].preco_venda);


                            printf("\n");
                            break;
                        }
                    }

                    system("pause");
                    system("cls");
                    break;
                case 5:

                    do{

                                printf(" -------------CONTROLE DE CAIXA-------------\n");
                                printf("\n");
                                printf(" -------------ESCOLHA UMA OPCAO-------------\n\n");
                                printf(" 1 - SAIDA DE PRODUTO\n");
                                printf(" 2 - ENTRADA DE PRODUTO\n");
                                printf(" 3 - LISTAR PRODUTOS\n");
                                printf(" 9 - SAIR\n");
                                scanf("%d",&cx);

                       // Se existe o produto, vender e aumentar o dinheiro no caixa (preço de venda);
                       // Se o produto não existe, enviar mensagem: 'Produto não existe'
                       // Se o produto existe mas quantidade insuficiente, enviar mensagem: 'Quantidade Não suficiente'

                       // Comprar produtos (Aumentar Produtos no Estoque e Reduzir dinheiro do Caixa)

                    switch(cx){

                        case 1:

                                printf("-------------VENDA DE PRODUTOS-------------\n");
                                printf("\n");
                                printf("\n");
                                printf("DIGITE O CODIGO DE BARRA: ");
                                scanf("%d", &cdgBarra);
                                printf("QUANTOS %s VENDER?",clProdutos[i].descricao);
                                scanf("%d",&quantvenda);


                                if(cdgBarra==clProdutos[i].codigo_barra && quantvenda<=clProdutos[i].quantidade){

                                    clProdutos[i].quantidade=clProdutos[i].quantidade-quantvenda;
                                    somaV=quantvenda*clProdutos[i].preco_venda;
                                    caixa=somaV+caixa;

                                    printf("%d PRODUTOS FORAM VENDIDOS. \n",quantvenda);
                                    printf("RESTA %d EM ESTOQUE.\n", clProdutos[i].quantidade);
                                    printf("VALOR EM CAIXA: %.2f \n",caixa);
                                    printf("\n");


                                    break;
                                }
                                else if(cdgBarra==clProdutos[i].codigo_barra && quantvenda>clProdutos[i].quantidade){
                                        printf("QUANTIDADE NAO SUFICIENTE.");
                                        printf("\n");
                                        printf("\n");
                                    break;
                                }
                                else{
                                    printf("PRODUTO NAO EXISTE.");
                                    printf("\n");
                                    printf("\n");
                                    break;
                                }

                                printf("\n");
                                printf("\n");
                                system("pause");
                                system("cls");
                                break;
                        case 2:
                                printf("-------------COMPRA DE PRODUTOS-------------\n");
                                printf("\n");
                                printf("\n");
                                printf("DIGITE O CODIGO DE BARRA PARA COMPRA DO PRODUTO: ");
                                scanf("%d", &cdgBarra);
                                printf("QUANTA(O)S %s COMPRAR?",clProdutos[i].descricao);
                                scanf("%d",&quantPcompra);

                                    if(cdgBarra==clProdutos[i].codigo_barra){
                                        somaC=quantPcompra*clProdutos[i].preco_compra;
                                        caixa=caixa-somaC;
                                        clProdutos[i].quantidade=quantPcompra+clProdutos[i].quantidade;


                                        printf("FORAM COMPRADOS %d PRODUTOS.\n", quantPcompra);
                                        printf("RESTA %.2f EM CAIXA\n", caixa);
                                        printf("ESTOQUE ATUAL: %d\n",clProdutos[i].quantidade);
                                                                            }

                                break;

                        case 3:
                                printf(" -------------LISTAR PRODUTOS-----------\n");
                                printf("\n");
                                printf("\n");

                                for(j = 0; j < quantidadeatual; j++){
                                        printf("DESCRICAO: %s\n", clProdutos[j].descricao);
                                        printf("CODIGO DE BARRAS: %d\n", clProdutos[j].codigo_barra);
                                        printf("QUANTIDADE: %d\n", clProdutos[j].quantidade);
                                        printf("PRECO DE COMPRA: %2.f\n", clProdutos[j].preco_compra);
                                        printf("PRECO DE VENDA: %.2f\n", clProdutos[j].preco_venda);
                                        printf("\n");
                                    }

                                system("pause");
                                system("cls");
                                break;
                        case 9:
                                system("cls");
                                break;
                        default:
                                system("cls");
                                printf(" OPCAO INVALIDA");
                                break;
                            }
                    }while(cx<9);
                    break;

                case 9:
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf(" OPCAO INVALIDA");
                    break;
            }
            printf("\n");
            printf("\n");
       }while(op<9);
    }

    return 0;


}
