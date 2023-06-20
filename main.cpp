#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define ESC 27
#define CIMA 72
#define BAIXO 80
#define ENTER 13
#define QNT_IMOVEIS 101
int escolha;

void imprimeImovel(int numero, char letra){           //recebe como parâmetro o numero onde se localiza o imóvel e seu tipo
    switch(letra){
        case 'c':                                     //caso o imóvel seja uma casa
            printf("\tInformacoes sobre o imovel: %s\n\n", casas[numero].tituloImovel);
            printf("Casa disponivel para %s com %d pavimentos e %d quartos\nLocalizada no endereco: %s, %d - %d\n%s em %s\n", (casas[numero].tipoPagamento == 1) ? "venda" : "aluguel", casas[numero].pavimentos, casas[numero].numeroQuartos, casas[numero].endereco, casas[numero].numero, casas[numero].CEP, casas[numero].bairro, casas[numero].cidade);
			printf("Area do terreno: %.3lf(m²)        Area construida: %.3lf(m²)\n", casas[numero].areaTerreno, casas[numero].areaConstruida);
            printf("Valor %s: R$%.2lf\n\n",(casas[numero].tipoPagamento == 1) ? "Total" : "do aluguel", casas[numero].valor);
			break;
        case 'a':                                    //caso o imóvel seja um apartamento
            printf("\tInformacoes sobre o imovel: %s\n\n", apartamentos[numero].tituloImovel);
			printf("Apartamento disponivel para %s na posicao %s\nLocalizada no endereco: %s, %d - %d\n%s em %s\n", (apartamentos[numero].tipoPagamento == 1) ? "venda" : "aluguel",  apartamentos[numero].posicao, apartamentos[numero].endereco, apartamentos[numero].numero, apartamentos[numero].CEP, apartamentos[numero].bairro, apartamentos[numero].cidade);
			printf("Este imovel esta no %d andar e possui tamanho %.3lf (m²), tendo %d quartos\n", apartamentos[numero].andar, apartamentos[numero].areaTerreno, apartamentos[numero].numeroQuartos);
			printf("Valor %s: R$%.2lf     ",(apartamentos[numero].tipoPagamento == 1) ? "Total" : "do aluguel", apartamentos[numero].valor);
			printf("Valor do condominio: R$%.2lf\n", apartamentos[numero].valorCondominio);
			printf("Quantidade de vagas na garagem: %d\n\n", apartamentos[numero].numVagasGaragem);
			break;
        case 't':                                    //caso o imóvel seja um terreno
            printf("\tInformacoes sobre o imovel: %s\n\n", terrenos[numero].tituloImovel);
			printf("Terreno disponivel para %s\nLocalizado no endereco: %s, %d - %d\n %s em %s\n", (terrenos[numero].tipoPagamento == 1) ? "venda" : "aluguel", terrenos[numero].endereco, terrenos[numero].numero, terrenos[numero].CEP, terrenos[numero].bairro, terrenos[numero].cidade);
            printf("Tamanho: %.3lf(m²)\n", terrenos[numero].areaTerreno);
            printf("Valor: R$%.2lf\n\n", terrenos[numero].valor);
            break;
        default:
            break;
    }
}

void tipo(char letra){
    int variavelConsulta=1, flag=0;

	while(flag==0){
		system("cls");
		switch(variavelConsulta){
			case 1:
				printf("---------========Imoveis Disponiveis========-------------\n"
					   "\t\tVenda\n"
					   "\tAluguel\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
					    switch(letra){
					        case 'c':
                                mostrarCasa('v');
                                break;
                            case 'a':
                                mostrarApt('v');
                                break;
                            default:
                                mostrarTerreno('v');
                                break;
					    }
                        variavelConsulta=0;
						break;
					case CIMA:
						variavelConsulta=3;
						break;
					case BAIXO:
						variavelConsulta=2;
						break;
					case ESC:
						variavelConsulta=0;
						break;
					default:
						continue;
				}
				break;
            case 2:
				printf("---------========Imoveis Disponiveis========-------------\n"
					   "\tVenda\n"
					   "\t\tAluguel\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
					    switch(letra){
					        case 'c':
                                mostrarCasa('a');
                                break;
                            case 'a':
                                mostrarApt('a');
                                break;
                            default:
                                mostrarTerreno('a');
                                break;
					    }
                        variavelConsulta=0;
						break;
					case CIMA:
						variavelConsulta=1;
						break;
					case BAIXO:
						variavelConsulta=3;
						break;
					case ESC:
						variavelConsulta=0;
						break;
					default:
						continue;
				}
				break;
           default:
				flag=1;
				break;
		}
	}
}

void remover(void){
    int variavelRemover=1, flag=0;

	while(flag==0){
		system("cls");
		switch(variavelRemover){
			case 1:
				printf("-----------------Remover---------------------\n"
					   "\t\tCasa\n"
					   "\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        remocao('c');
                        variavelRemover=0;
						break;
					case CIMA:
						variavelRemover=3;
						break;
					case BAIXO:
						variavelRemover=2;
						break;
					case ESC:
						variavelRemover=0;
						break;
					default:
						continue;
				}
				break;
            case 2:
				printf("-----------------Remover---------------------\n"
					   "\tCasa\n"
					   "\t\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        remocao('a');
                        variavelRemover=0;
						break;
					case CIMA:
						variavelRemover=1;
						break;
					case BAIXO:
						variavelRemover=3;
						break;
					case ESC:
						variavelRemover=0;
						break;
					default:
						continue;
				}
				break;
            case 3:
				printf("-----------------Remover---------------------\n"
					   "\tCasa\n"
					   "\tApartamento\n"
					   "\t\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        remocao('t');
                        variavelRemover=0;
						break;
					case CIMA:
						variavelRemover=2;
						break;
					case BAIXO:
						variavelRemover=1;
						break;
					case ESC:
						variavelRemover=0;
						break;
					default:
						continue;
				}
				break;
            default:
				flag=1;
				break;
		}
	}
}
void editar(void){
    int variavelEditar=1, flag=0;

	while(flag==0){
		system("cls");
		switch(variavelEditar){
			case 1:
				printf("-----------------Editar---------------------\n"
					   "\t\tCasa\n"
					   "\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        edicaoCasa();
                        variavelEditar=0;
						break;
					case CIMA:
						variavelEditar=3;
						break;
					case BAIXO:
						variavelEditar=2;
						break;
					case ESC:
						variavelEditar=0;
						break;
					default:
						continue;
				}
				break;
            case 2:
				printf("-----------------Editar---------------------\n"
					   "\tCasa\n"
					   "\t\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        edicaoApt();
                        variavelEditar=0;
						break;
					case CIMA:
						variavelEditar=1;
						break;
					case BAIXO:
						variavelEditar=3;
						break;
					case ESC:
						variavelEditar=0;
						break;
					default:
						continue;
				}
				break;
            case 3:
				printf("-----------------Editar---------------------\n"
					   "\tCasa\n"
					   "\tApartamento\n"
					   "\t\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        edicaoTer();
                        variavelEditar=0;
						break;
					case CIMA:
						variavelEditar=2;
						break;
					case BAIXO:
						variavelEditar=1;
						break;
					case ESC:
						variavelEditar=0;
						break;
					default:
						continue;
				}
				break;
            default:
				flag=1;
				break;
		}
	}
}
void consultar(void){
    int variavelConsulta=1, flag=0;

	while(flag==0){
		system("cls");
		switch(variavelConsulta){
			case 1:
				printf("-----------------Imoveis Disponiveis---------------------\n"
					   "\t\tCasa\n"
					   "\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        tipo('c');
                        variavelConsulta=0;
						break;
					case CIMA:
						variavelConsulta=3;
						break;
					case BAIXO:
						variavelConsulta=2;
						break;
					case ESC:
						variavelConsulta=0;
						break;
					default:
						continue;
				}
				break;
            case 2:
				printf("-----------------Imoveis Disponiveis---------------------\n"
					   "\tCasa\n"
					   "\t\tApartamento\n"
					   "\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        tipo('a');
                        variavelConsulta=0;
						break;
					case CIMA:
						variavelConsulta=1;
						break;
					case BAIXO:
						variavelConsulta=3;
						break;
					case ESC:
						variavelConsulta=0;
						break;
					default:
						continue;
				}
				break;
            case 3:
				printf("-----------------Imoveis Disponiveis---------------------\n"
					   "\tCasa\n"
					   "\tApartamento\n"
					   "\t\tTerreno\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        tipo('t');
                        variavelConsulta=0;
						break;
					case CIMA:
						variavelConsulta=2;
						break;
					case BAIXO:
						variavelConsulta=1;
						break;
					case ESC:
						variavelConsulta=0;
						break;
					default:
						continue;
				}
				break;
            default:
				flag=1;
				break;
		}
	}
}
void buscar(void){
	int variavelBusca=1, flag=0;

	while(flag==0){
		system("cls");
		switch(variavelBusca){
			case 1:
				printf("----------------------Busca-------------------------\n"
					   "\t\tBairro\n"
					   "\tTitulo\n"
					   "\tValor\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						buscaBairro();
                        variavelBusca=0;
						break;
					case CIMA:
						variavelBusca=3;
						break;
					case BAIXO:
						variavelBusca=2;
						break;
					case ESC:
						variavelBusca=0;
						break;
					default:
						continue;
				}
				break;
			case 2:
				printf("----------------------Busca-------------------------\n"
					   "\tBairro\n"
					   "\t\tTitulo\n"
					   "\tValor\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						buscaTitulo();
						variavelBusca=0;
						break;
					case CIMA:
						variavelBusca=1;
						break;
					case BAIXO:
						variavelBusca=3;
						break;
					case ESC:
						variavelBusca=0;
						break;
					default:
						continue;
				}
				break;
			case 3:
				printf("----------------------Busca-------------------------\n"
					   "\tBairro\n"
					   "\tTitulo\n"
					   "\t\tValor\n\n\n"
					   "\tPara voltar ao MENU pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						buscaValor();
						variavelBusca=0;
						break;
					case CIMA:
						variavelBusca=2;
						break;
					case BAIXO:
						variavelBusca=1;
						break;
					case ESC:
						variavelBusca=0;
						break;
					default:
						continue;
				}
				break;
			default:
				flag=1;
				break;
		}
	}
}
void cadastrar(void){
    int variavelCadastro=1,flag=0;

    while(flag==0){
        system("cls");
        switch(variavelCadastro){     //switch para navegar no menu 'cadastro', sendo 'variavelCadastro' o comando
           case 1:
                printf("-------------------Cadastrar----------------------\n\n"
                    "\t\tCasa\n"
                    "\tTerreno\n"
                    "\tApartamento\n\n\n"
                    "\tAperte ESC para voltar ao MENU\n");

                escolha=getch();
                switch(escolha){
					case ENTER:
						cadastraCasa();
						variavelCadastro=0;
						break;
					case CIMA:
						variavelCadastro=3;
						break;
					case BAIXO:
						variavelCadastro=2;
						break;
					case ESC:
						variavelCadastro=0;
						break;
					default:
						continue;
				}

                break;
            case 2:
                printf("-------------------Cadastrar----------------------\n\n"
                    "\tCasa\n"
                    "\t\tTerreno\n"
                    "\tApartamento\n\n\n"
                    "\tAperte ESC para voltar ao MENU\n");

                escolha=getch();
                switch(escolha){
                    case ENTER:
						cadastraTer();
						variavelCadastro=0;
						break;
					case CIMA:
						variavelCadastro=1;
						break;
					case BAIXO:
						variavelCadastro=3;
						break;
					case ESC:
						variavelCadastro=0;
						break;
					default:
						continue;
				}
                break;
            case 3:
                printf("-------------------Cadastrar----------------------\n\n"
                    "\tCasa\n"
                    "\tTerreno\n"
                    "\t\tApartamento\n\n\n"
                    "\tAperte ESC para voltar ao MENU\n");

                escolha=getch();
                switch(escolha){
                    case ENTER:
						cadastraApt();
						variavelCadastro=0;
						break;
					case CIMA:
						variavelCadastro=2;
						break;
					case BAIXO:
						variavelCadastro=1;
						break;
					case ESC:
						variavelCadastro=0;
						break;
					default:
						continue;
				}
                break;
            default:
                flag=1;
                break;
        }
    }
}
int Menu(char *a){
	int variavelMenu=1, flag=0;
	printf("\a");


	while(flag==0){                        //enquanto a bandeira permanecer em 0, significa que o usuário não pediu para sair do programa
		system("cls");
		switch(variavelMenu){              //navegar pelo 'MENU'
			case 1:
				printf("\t\t\t\tMenu\n"
					   "\t\tCadastrar\n"
					   "\tListar\n"
					   "\tBuscar imovel\n"
					   "\tRemover\n"
					   "\tEditar\n"
					   "\tSalvar\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:                 //Caso clique em ENTER,sse dirige para a função 'CADASTRO'
                        *a=1;
                        flag=1;
						break;
					case CIMA:
						variavelMenu=5;
						break;
					case BAIXO:
						variavelMenu=2;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;
			case 2:
				printf("\t\t\t\tMenu\n"
					   "\tCadastrar\n"
					   "\t\tListar\n"
					   "\tBuscar imovel\n"
					   "\tRemover\n"
					   "\tEditar\n"
					   "\tSalvar\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						*a=2;                   //Caso clique em ENTER,sse dirige para a função 'LISTAR'
						flag=1;
						break;
					case CIMA:
						variavelMenu=1;
						break;
					case BAIXO:
						variavelMenu=3;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;
			case 3:
				printf("\t\t\t\tMenu\n"
					   "\tCadastrar\n"
					   "\tListar\n"
					   "\t\tBuscar imovel\n"
					   "\tRemover\n"
					   "\tEditar\n"
					   "\tSalva\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						*a=3;                   //Caso clique em ENTER,sse dirige para a função 'BUSCA'
						flag=1;
						break;
					case CIMA:
						variavelMenu=2;
						break;
					case BAIXO:
						variavelMenu=4;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;
			case 4:
				printf("\t\t\t\tMenu\n"
					   "\tCadastrar\n"
					   "\tListar\n"
					   "\tBuscar imovel\n"
					   "\t\tRemover\n"
					   "\tEditar\n"
					   "\tSalvar\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
                        *a=4;                      //Caso clique em ENTER,sse dirige para a função 'REMOVER'
                        flag=1;
						break;
					case CIMA:
						variavelMenu=3;
						break;
					case BAIXO:
						variavelMenu=5;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;
			case 5:
				printf("\t\t\t\tMenu\n"
					   "\tCadastrar\n"
					   "\tListar\n"
					   "\tBuscar imovel\n"
					   "\tRemover\n"
					   "\t\tEditar\n"
					   "\tSalvar\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						*a=5;
						flag=1;
						break;
					case CIMA:
						variavelMenu=4;
						break;
					case BAIXO:
						variavelMenu=6;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;

            case 6:
				printf("\t\t\t\tMenu\n"
					   "\tCadastrar\n"
					   "\tListar\n"
					   "\tBuscar imovel\n"
					   "\tRemover\n"
					   "\tEditar\n"
					   "\t\tSalvar\n\n\n"
					   "\tPara encerrar o programa, pressione ESC\n");

				escolha= getch();
				switch(escolha){
					case ENTER:
						*a=6;
						flag=1;
						break;
					case CIMA:
						variavelMenu=5;
						break;
					case BAIXO:
						variavelMenu=1;
						break;
					case ESC:
						variavelMenu=0;
						break;
					default:
						continue;
				}
				break;
			default:
			    *a=7;
				flag=1;
				break;
		}
	}
	return 0;
}
int main(void){

	if(!Menu())

    return 0;
}
