#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------- Struct cliente ------------------------------------
struct Cad
{
	char o[5];
	char nome[30];
	char idade[30];
	char cpf[30];
	char cnpj[30];
	char telefone[30];
	char end[100];
	char gen[1];
};

//-------------------- Struct produto ------------------------------------
struct Est
{
	int p;
	char nome[30];
	char SKU[30];
	char nicho[30];
	int qtd;
	char cor[30];
	float custo, preco;
};
//-------------------- Struct Pedidos ------------------------------------
struct Ped
{
	int numped;
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[5];
	char comp[30];
	int qtd;
};

void cadastroCli(struct Cad cad, FILE *cadastro);
void alteraProd(struct Est prod, FILE *estoque);
void cadastroProd(struct Est prod, FILE *estoque);
void estoqueProd(struct Est prod, FILE *estoque);
void gerenciaPed(struct Est prod, struct Ped ped[200], FILE *estoque, FILE *pedidos, FILE *cadastro);
void alteraCli(struct Cad cad, FILE *cadastro);
// IMPLEMENTAR FUNCAO BUSCA SKU que retorna a SKU.

//-------------------- Funcao Cadastra Cliente ------------------------------------
void cadastroCli(struct Cad cad, FILE *cadastro)
{
	int op = 0, x = 0;

	while (1)
	{
		cadastro = fopen("clientes.txt", "a+b");
		if (cadastro == NULL)
		{
			printf("ERRO NA ABERTURA DO ARQUIVO \n");
		}

		if (op == 2)
			break;

		else
		{
			while (1)
			{
				printf("Ok, vamos fazer o seu cadastro!\n");

				setbuf(stdin, NULL);
				printf("\nQual o seu Nome? \n");
				scanf("%[^\n]s", cad.nome);

				setbuf(stdin, NULL);
				printf("\nQual sua data de nascimento?\n");
				scanf("%[^\n]s", cad.idade);

				setbuf(stdin, NULL);
				printf("\nVoce eh CPF ou CNPJ? \n");
				printf("CPF - Digite 1 \n");
				printf("CNPJ - Digite 2 \n");
				scanf("%d", &x);
				printf("\n");

				if (x == 1 || x == 2)
				{
					if (x == 1)
					{
						setbuf(stdin, NULL);
						printf("\nDigite seu CPF: \n");
						scanf("%s", cad.cpf);

						setbuf(stdin, NULL);
						printf("\nQual seu telefone para contato? \n");
						scanf("%s", cad.telefone);

						setbuf(stdin, NULL);
						printf("\nQual seu endereco? \n");
						scanf("%s", cad.end);

						setbuf(stdin, NULL);
						printf("\nQual genero voce se identifica?\n");
						printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
						scanf("%s", cad.gen);

						printf("\nNome: %s\n", cad.nome);
						printf("Idade: %s\n", cad.idade);
						printf("CPF: %s\n", cad.cpf);
						printf("Telefone: %s\n", cad.telefone);
						printf("Endereco: %s\n", cad.end);
						printf("Genero: %s\n", cad.gen);

						break;
					}

					if (x == 2)
					{
						setbuf(stdin, NULL);
						printf("Digite seu CNPJ: \n");
						scanf("%s", cad.cnpj);

						setbuf(stdin, NULL);
						printf("Qual seu telefone para contato? \n");
						scanf("%s", cad.telefone);

						setbuf(stdin, NULL);
						printf("Qual seu endereco? \n");
						scanf("%s", cad.end);

						printf("\n Nome: %s\n", cad.nome);
						printf("Idade: %s\n", cad.idade);
						printf("CNPJ: %s\n", cad.cnpj);
						printf("Telefone: %s\n", cad.telefone);
						printf("Endereco: %s\n", cad.end);

						break;
					}
				}

				else
				{
					while (1)
					{
						setbuf(stdin, NULL);
						printf("\nOpcao desconhecida, por favor digite novamente.\n");
						scanf("%d", &x);

						if (x == 1 || x == 2)
							break;
						else
							continue;
					}
				}

				fwrite(&cad, sizeof(struct Cad), 1, cadastro);
				fclose(cadastro);
				break;
			}
		}
		printf("\n Tudo certo? \n");
		printf("Cadastrar outro cliente - 1 \n");
		printf("Continuar - 2 \n");
		scanf("%d", &op);
	}
}

//-------------------- Funcao altera cliente ---------------------------------------------
void alteraCli(struct Cad cad, FILE *cadastro)
{
	char CPF[30];
	int x = 0;

	cadastro = fopen("cadastro.txt", "r+b");

	if (cadastro == NULL)
		printf("Erro na abertura do arquivo cadastro.txt!\n");

	else
	{
		printf("Digite o CPF do cliente: \n");
		setbuf(stdin, NULL);
		scanf("%s", CPF[30]);
		while (fread(&cad, sizeof(cad), 1, cadastro))
		{
			if ((CPF[30] == ' ') && (strcmp(CPF[30], cad.cpf))
			{
				printf("Cliente encontrado!\nAtualizar: \n");
				printf("1- Nome\n2-Idade\n3-CPF\n4-Telefone\n5-Endereco\n6-Genero\n");
				printf("\nCaso não queira realizar alteração digite 9 para voltar ao menu.\n");
				setbuf(stdin, NULL);
				scanf("%d", &x);

				if (x == 1)
				{
					printf("Digite o nome: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.nome);
				}

				if (x == 2)
				{
					printf("Digite a idade: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.idade);
				}

				if (x == 3)
				{
					printf("Digite o CPF: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.cpf);
				}

				if (x == 5)
				{
					printf("Digite o novo endereco: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.end);
				}

				if (x == 6)
				{
					printf("Digite o genero: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.gen);
				}

				printf("\nNome: %s\n", cad.nome);
				printf("Idade: %s\n", cad.idade);
				printf("CPF: %s\n", cad.cpf);
				printf("Telefone: %s\n", cad.telefone);
				printf("Endereco: %s\n", cad.end);
				printf("Genero: %s\n", cad.gen);

				fseek(cad, sizeof(struct Cad) * -1, SEEK_CUR);
				fwrite(&cad, sizeof(struct Cad), 1 cadastro);
				break;
			}
			else
			{
				fwrite(&cad, sizeof(struct Cad), 1, cadastro);
				fclose(cadastro);
				break;
			}
		}

		//-------------------- Funcao busca produto pelo SKU no estoque ---------------------------------------------
		int alteraProd1(char sku[30], struct Est E, FILE *estoque)
		{
			char SKU[30], op = 0;
			int i, j;

			// fazer com que ele leia o dado e armazene no arquivo
			estoque = fopen("estoque.txt", "a+b");
			if (estoque == NULL)
				printf("ERRO!!! O arquivo não abriu.\n");

			// printf("\nDigite o SKU: ");
			// setbuf(stdin, NULL);
			// scanf("%s", SKU);

			while (fread(&E, sizeof(struct Est), 1, estoque))
			{
				j = strcmp(sku, E.SKU);

				if (j == 0)
				{
					while (1)
					{
						printf("Nome: %s\n", E.nome);
						printf("Nicho: %s\n", E.nicho);
						printf("Quantidade: %d\n", E.qtd);
						printf("Cor: %s\n", E.cor);
						printf("Custo: %.2f\n", E.custo);
						printf("Preco: %.2f\n", E.preco);

						printf("\nSelecione a opção desejada:");
						printf("\nAlterar cor - 1");
						printf("\nAlterar quantidade - 2");
						printf("\nAlterar preco - 3");
						printf("\nAlterar custo - 4");
						printf("\nAlterar nicho - 5");
						printf("\nDigite sua opcao: ");
						scanf("%d", &op);

						if (op == 1)
						{
							setbuf(stdin, NULL);
							printf("\nDigite a nova cor para este produto: ");
							scanf("%s", E.cor);

							fwrite(&E, sizeof(struct Est), 1, estoque);

							printf("Nome: %s\n", E.nome);
							printf("Nicho: %s\n", E.nicho);
							printf("Quantidade: %d\n", E.qtd);
							printf("Cor: %s\n", E.cor);
							printf("Custo: %.2f\n", E.custo);
							printf("Preco: %.2f\n", E.preco);

							return 0; // Produto encontrado
						}

						if (op == 2)
						{
							setbuf(stdin, NULL);
							printf("\nDigite a nova quantidade para este produto: ");
							scanf("%d", &E.qtd);

							fwrite(&E, sizeof(struct Est), 1, estoque);

							printf("Nome: %s\n", E.nome);
							printf("Nicho: %s\n", E.nicho);
							printf("Quantidade: %d\n", E.qtd);
							printf("Cor: %s\n", E.cor);
							printf("Custo: %.2f\n", E.custo);
							printf("Preco: %.2f\n", E.preco);

							return 0; // Produto encontrado
						}

						if (op == 3)
						{
							setbuf(stdin, NULL);
							printf("\nDigite o novo preco para este produto: ");
							scanf("%f", &E.preco);

							fwrite(&E, sizeof(struct Est), 1, estoque);

							printf("Nome: %s\n", E.nome);
							printf("Nicho: %s\n", E.nicho);
							printf("Quantidade: %d\n", E.qtd);
							printf("Cor: %s\n", E.cor);
							printf("Custo: %.2f\n", E.custo);
							printf("Preco: %.2f\n", E.preco);

							return 0; // Produto encontrado
						}

						if (op == 4)
						{
							setbuf(stdin, NULL);
							printf("\nDigite o novo custo para este produto: ");
							scanf("%f", &E.custo);

							fwrite(&E, sizeof(struct Est), 1, estoque);

							printf("Nome: %s\n", E.nome);
							printf("Nicho: %s\n", E.nicho);
							printf("Quantidade: %d\n", E.qtd);
							printf("Cor: %s\n", E.cor);
							printf("Custo: %.2f\n", E.custo);
							printf("Preco: %.2f\n", E.preco);

							return 0; // Produto encontrado
						}

						if (op == 5)
						{
							setbuf(stdin, NULL);
							printf("\nDigite o novo nicho para este produto: ");
							scanf("%s", E.nicho);

							fwrite(&E, sizeof(struct Est), 1, estoque);

							printf("Nome: %s\n", E.nome);
							printf("Nicho: %s\n", E.nicho);
							printf("Quantidade: %d\n", E.qtd);
							printf("Cor: %s\n", E.cor);
							printf("Custo: %.2f\n", E.custo);
							printf("Preco: %.2f\n", E.preco);

							return 0; // Produto encontrado
						}
						else
							printf("\nOPCAO INCORRETA! Vamos tentar novamente...\n\n");
					}
				}
				else
					continue; // Produto não encontrado
			}
			printf("PRODUTO NAO ENCONTRADO!\n");
			return 1;

			fclose(estoque);
		}

		//-------------------- Funcao que altera o produto no estoque ---------------------------------------------
		void alteraProd(struct Est prod, FILE * estoque)
		{
			int op = 0, op1 = 0;
			char sku[30];

			estoque = fopen("estoque.txt", "a+b");
			if (estoque == NULL)
				printf("ERRO NA ABERTURA DO ARQUIVO!\n");

			else
			{
				while (1)
				{
					if (op1 == 1)
						break;

					else
					{
						while (1)
						{
							printf("\nOPCAO SELECIONADA: Alterar Produto.\n");

							printf("\nDigite o SKU: ");
							setbuf(stdin, NULL);
							scanf("%s", sku);

							if (alteraProd1(sku, prod, estoque) == 0)
							{
								printf("\nProduto alterado com sucesso!\n");

								// Produto alterado após a chamada da função
								// no if em alteraProd1.

								while (1)
								{
									printf("\nContinuar alterando?");
									printf("\nSIM - 1");
									printf("\nNAO - 2");
									printf("\nDigite sua opcao: ");
									scanf("%d", &op1);

									if (op1 == 1)
										alteraProd1(sku, prod, estoque);
									if (op1 == 2)
										break;
								}
							}

							else
							{
								printf("\nProduto não encontrado! Deseja cadastra-lo?\n");
								printf("\nSIM - 1");
								printf("\nNAO - 2");
								printf("\nDigite sua opcao: ");

								scanf("%d", &op1);

								if (op1 == 1)
									cadastroProd(prod, estoque);
								if (op1 == 2)
									break;
							}

							fwrite(&prod, sizeof(struct Est), 1, estoque);
							fclose(estoque);
							break;
						}
					}

					printf("\n Tudo certo? \n");
					printf("\nVoltar para o Menu - 1");
					printf("\nRealizar outra consulta - 2");
					printf("\nDigite sua opcao: ");
					scanf("%d", &op1);
				}
			}
		}

		//-------------------- Funcao Cadastrar produto ------------------------------------!
		void cadastroProd(struct Est prod, FILE * estoque)
		{
			int op = 0;
			estoque = fopen("estoque.txt", "a+b");
			if (estoque == NULL)
			{
				printf("ERRO!!! Arquivo não encontrado.\n");
			}
			else
			{
				while (1)
				{
					if (op == 2)
						break;
					else
					{

						while (1)
						{
							printf("Cadastrar produto\n");

							setbuf(stdin, NULL);
							printf("\nDigite o nome do produto:\n");
							scanf("%[^\n]s", prod.nome);

							setbuf(stdin, NULL);
							printf("\nDigite o SKU do produto:\n");
							scanf("%s", prod.SKU);

							setbuf(stdin, NULL);
							printf("\nDigite o nicho do produto: \n");
							scanf("%s", prod.nicho);

							setbuf(stdin, NULL);
							printf("\nDigite a cor do produto: \n");
							scanf("%s", prod.cor);

							setbuf(stdin, NULL);
							printf("\nDigite a quantidade de produtos no estoque: \n");
							scanf("%d", &prod.qtd);

							setbuf(stdin, NULL);
							printf("\nDigite o custo do produto: \nR$");
							scanf("%f", &prod.custo);

							setbuf(stdin, NULL);
							printf("\nDigite o preço do produto: \nR$");
							scanf("%f", &prod.preco);

							printf("\nNome: %s\n", prod.nome);
							printf("SKU: %s\n", prod.SKU);
							printf("Nicho: %s\n", prod.nicho);
							printf("Cor: %s\n", prod.cor);
							printf("Quantidade: %d\n", prod.qtd);
							printf("Custo: R$%.2f\n", prod.custo);
							printf("Preço: R$%.2f\n", prod.preco);

							fwrite(&prod, sizeof(struct Est), 1, estoque);
							fclose(estoque);
							break;
						}
					}
					printf("\n Tudo certo? \n");
					printf("Cadastrar outro produto? - 1 \n");
					printf("Continuar - 2\n");
					scanf("%d", &op);
				}
			}
		}

		//-------------------- Funcao que adiministra o estoque ---------------------------------------------
		void estoqueProd(struct Est prod, FILE * estoque)
		{
			int op = 0, op1 = 1;

			estoque = fopen("estoque.txt", "a+b");

			if (estoque == NULL)
			{
				printf("Erro na abertura do arquivo\n");
			}
			else
			{
				while (1)
				{
					if (op == 2)
						break;
					else
					{
						while (1)
						{
							printf("\nDigite a função a ser realizada: \n");
							printf("\nAlterar Item - 1");
							printf("\nExcluir Item - 2"); // fazer
							printf("\nCadastrar Item - 3");
							printf("\nListar todos os Produtos - 4"); // fazer
							printf("\nSair - 9");
							printf("\nDigite sua opcao: ");
							scanf("%d", &op1);

							if (op1 == 1)
								alteraProd(prod, estoque);
							if (op1 == 2)
								alteraProd(prod, estoque);
							if (op1 == 3)
								cadastroProd(prod, estoque);
							if (op1 == 4)
								cadastroProd(prod, estoque);
							if (op1 == 9)
								break;
							else
							{
								printf("OPCAO INCORRETA! Vamos tentar novamente.");
								continue;
							}
						}
					}
					printf("\n Tudo certo? \n");
					printf("Tentar Novamente - 1 \n");
					printf("Continuar - 2\n");
					scanf("%d", &op);
				}
			}
		}
		//--------------------Funcao acompanhar pedidos----------------------------------------
		void gerenciaPed(struct Est prod, struct Ped ped[200], FILE * estoque, FILE * cadastro, FILE * pedidos)
		{

			int op, op1, numped, i = 0, qtd, ;
			char cpf, sku[30];

			pedidos = fopen("pedidos.txt", "a+b");

			printf("Selecione a opção desejada:\n");
			printf("\n1- Acompanhar remessa\n");
			printf("2- Alterar Endereço\n");
			printf("3- Cancelar remessa\n");
			printf("4- Novo Pedido\n");

			scanf("%d", &op);

			if (op == 1)
			{
				while (1)
				{
					printf("\nSelecionado: Acompanhar remessa\n");

					printf("\nDigite o número do pedido: ");
					scanf("%d", &numped);

					if (numped == ped[i].numped)
					{
						/*
						  Realizar consulta com ponteiro do pedido.
						*/
						printf("Deu bom!\n");

						printf("Pressione 1 para finalizar consulta: ");
						scanf("%d", &op1);

						if (op1 == 1)
							break;

						break;
					}

					else
					{
						printf("\nPedido não encotrado!\n");
						printf("Vamos tentar novamente...\n");
						continue;
					}
				}
			}

			if (op == 2)
			{
				while (1)
				{

					printf("\nSelecionado: Alterar Endereço.\n");

					printf("\nDigite o número do pedido: ");
					scanf("%d", &numped);

					if (numped == ped[i].numped)
					{
						printf("\nLogradouro: \n");
						scanf("%[^\n]s", ped[i].log);

						printf("Bairro: \n");
						scanf("%[^\n]s", ped[i].bairro);

						printf("Cidade: \n");
						scanf("%[^\n]s", ped[i].cidade);

						printf("UF: \n");
						scanf("%[^\n]s", ped[i].uf);

						printf("Selecione uma opcao: \n");
						printf("1 - Corrigir dados. \n");
						printf("2 - Finalizar alteracao. \n");
						scanf("%d", &op1);

						if (op1 == 1)
							continue;
						if (op1 == 2)
							break;
					}

					else
					{
						printf("\nPedido não encotrado!\n");
						printf("Vamos tentar novamente...\n");
						continue;
					}
				}

				printf("\nDeseja realizar outra ação?\n");
				printf("\n1 - Realizar uma nova pesquisa: ");
				printf("\n2 - Voltar para o menu principal: \n");

				scanf("%d", &op1);
			}
			if (op == 3)
			{
				printf("dados apagados!\n");
			}

			if (op == 4)
			{
				printf("Opção selecionada: Novo Pedido!\n");
				printf("Digite o SKU do pedido:\n");
				setbuf(stdin, NULL);
				scanf("%s", sku); // criar função busca SKU.
				printf("Digite o cpf do cliente:\n");
				scanf("%s", cpf);
				// criar função verifica cpf
				if (verificaCPF(cpf) == 0)
				{
					printf("Cliente não cadastrado!");
					printf("Deseja cadastrar cliente?\n1 - Sim\n2 - Não\n");
				}

				printf("Digite a quantidade de produto: \n");
				setbuf(stdin, NULL);
				scanf("%d", qtd);
				// implementar função chama cliente e verificar se cliente existe.
				// caso cliente não exista solicitar cadastro de cliente.
				ped[i].qtd = qtd;
				printf("Pedido realizado!");
				printf("Endereço: ")
			}
		}
		void menu()
		{
			int opcao = 0;
			struct Cad C;
			struct Est prod;
			struct Ped ped[200];

			FILE *cadastro;
			FILE *estoque;
			FILE *pedidos;
			while (1)
			{
				printf("\nBem vindo ao Sistema Gestão de Ecommerce");
				printf("\n1- Cadastrar cliente");
				printf("\n2- Consultar estoque");
				printf("\n3- Cadastrar produto");
				printf("\n4- Gerenciar pedidos");
				printf("\n9- Sair ");

				printf("\nDigite opção: ");
				scanf("%d", &opcao);

				if (opcao == 1)
					cadastroCli(C, cadastro);
				if (opcao == 2)
					estoqueProd(prod, estoque);
				if (opcao == 3)
					cadastroProd(prod, estoque);
				if (opcao == 4)
					gerenciaPed(prod, ped, estoque, cadastro, pedidos);
				if (opcao == 9)
					return;
			}
		}

		int main()
		{
			menu();
		}
