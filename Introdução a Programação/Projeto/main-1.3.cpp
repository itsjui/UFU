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
	int ID;
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
};

void cadastroCli(struct Cad cad, FILE *cadastro);
void alteraProd(struct Est prod, FILE *estoque);
void cadastroProd(struct Est prod, FILE *estoque);
void estoqueProd(struct Est prod, FILE *estoque);
void gerenciaPed(struct Est prod, struct Ped ped, FILE *estoque, FILE *pedidos, FILE *cadastro);
void imprime_cadastro(struct Cad cad, FILE *cadastro);

//-------------------- FUNNCAO QUE BUSCA SKU ---------------
// Função retorna SKU Desejado
char *pesquisaSKU(char s[100], struct Est est, FILE *estoque)
{
	int i;

	estoque = fopen("estoque.txt", "rb");

	while (fread(&est, sizeof(struct Est), 1, estoque))
	{
		i = strcmp(s, est.SKU);

		if (i == 0)
		{
			printf("\n\t\tPRODUTO ENCONTRADO: %s\t\t\n", est.nome);
			printf("\n\t\tNicho: %s", est.nicho);
			printf("\n\t\tCor: %s", est.cor);
			printf("\n\t\tPreco: %.2f", est.preco);
			printf("\n\t\tCusto: %.2f\n\n", est.custo);
		}

		else
			continue;
	}

	fclose(estoque);
	if (i == 0)
	{
		return s;
	}

	else
		return 0;
}

//-------------------- Funcao de ACHAR o produto e mostra seus dados ---------------
void aplicaSKU(struct Est prod, FILE *estoque)
{
	char sku[20], j[20];

	printf("\n\t\tDigite o sku: ");
	setbuf(stdin, NULL);
	scanf("%s", sku);

	strcpy(j, pesquisaSKU(sku, prod, estoque));

	printf("\nPRODUTO ENCONTRADO!");
	printf("\nSKU Encontrado: %s\n", j);

	return;
}

//-------------------- Busca CPF no arquivo Cadastro -----------------------------
// finalizar implementação e fazer testes.
char *buscaCPF(struct Cad cad, FILE *clientes)
{
	char cpf[20];
	int i;

	clientes = fopen("clientes.txt", "r");

	if (clientes == NULL)
		printf("\n\t\t\tERROR NA ABERTURA DO ARQUIVO!");

	setbuf(stdin, NULL);
	printf("\nDigite seu CPF desejado para a busca: ");
	scanf("%[^\n]s", cpf);

	while (fread(&cad, sizeof(struct Cad), 1, clientes))
	{
		i = strcmp(cpf, cad.cpf);

		if (i == 0)
		{
			printf("\n\n\t\t\tCPF ENCONTRADO COM SUCESSO!\n\n");
			fclose(clientes);
			return cpf;
		}
		else
			fclose(clientes);
		continue;
	}
}

//-------------------- Busca ID registrado na struct cadastro -----------------------------
int buscaID( struct Cad P[], int ID)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (ID == P[i].ID)
			return i;
	}

	return 0;
}

//-------------------- Funcao Cadastra Cliente ------------------------------------
void cadastroCli(struct Cad cad[], FILE *cadastro)
{
	int op = 0, x = 0, ID, j;

	cadastro = fopen("clientes.txt", "a");
	if (cadastro == NULL)
	{
		printf("ERRO NA ABERTURA DO ARQUIVO \n");
	}

	while (1)
	{
		printf("Digite o ID do novo cliente a ser cadastrado: ");
		scanf("%d", &ID);

		j = buscaID(cad, ID); 

		if(j != 0){
			printf("ID já cadastrado no sistema!\n");
			continue;
		}

		else
		{
			if (op == 2)
				break;

			else
			{
				while (1)
				{
					printf("Ok, vamos fazer o seu cadastro!\n");

					setbuf(stdin, NULL);
					printf("\nQual o seu Nome? \n");
					scanf("%[^\n]s", cad[ID].nome);

					setbuf(stdin, NULL);
					printf("\nQual sua data de nascimento?\n");
					scanf("%[^\n]s", cad[ID].idade);

					setbuf(stdin, NULL);
					printf("\nVoce eh CPF ou CNPJ? \n");
					printf("CPF - Digite 1 \n");
					printf("CNPJ - Digite 2 \n");
					scanf("%d", &x);

					if (x == 1 || x == 2)
					{
						if (x == 1)
						{
							setbuf(stdin, NULL);
							printf("\nDigite seu CPF: \n");
							scanf("%[^\n]s", cad[ID].cpf);

							setbuf(stdin, NULL);
							printf("\nQual seu telefone para contato? \n");
							scanf("%[^\n]s", cad[ID].telefone);

							setbuf(stdin, NULL);
							printf("\nQual seu endereco? \n");
							scanf("%[^\n]s", cad[ID].end);

							setbuf(stdin, NULL);
							printf("\nQual genero voce se identifica?\n");
							printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
							scanf("%[^\n]s", cad[ID].gen);

							printf("\nNome: %s\n", cad[ID].nome);
							printf("Idade: %s\n", cad[ID].idade);
							printf("CPF: %s\n", cad[ID].cpf);
							printf("Telefone: %s\n", cad[ID].telefone);
							printf("Endereco: %s\n", cad[ID].end);
							printf("Genero: %s\n", cad[ID].gen);

							break;
						}

						if (x == 2)
						{
							setbuf(stdin, NULL);
							printf("Digite seu CNPJ: \n");
							scanf("%[^\n]s", cad[ID].cnpj);

							setbuf(stdin, NULL);
							printf("Qual seu telefone para contato? \n");
							scanf("%[^\n]s", cad[ID].telefone);

							setbuf(stdin, NULL);
							printf("Qual seu endereco? \n");
							scanf("%[^\n]s", cad[ID].end);

							printf("\n Nome: %s\n", cad[ID].nome);
							printf("Idade: %s\n", cad[ID].idade);
							printf("CNPJ: %s\n", cad[ID].cnpj);
							printf("Telefone: %s\n", cad[ID].telefone);
							printf("Endereco: %s\n", cad[ID].end);

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
				}
			}
		}

		printf("\n Tudo certo? \n");
		printf("Cadastrar outro cliente - 1 \n");
		printf("Continuar - 2 \n");
		scanf("%d", &op);
	}
	// printf("vou fechar o arquivo agora====== passei por aqui");
	fwrite(&cad[ID], sizeof(struct Cad), 1, cadastro);
	fclose(cadastro);
}

//-------------------- FUncao que altera dados do Cliente --------------------------
void alteraCli(struct Cad cad, FILE *cadastro)
{
	char CPF[30];
	int x = 0, j;

	cadastro = fopen("cadastro.txt", "a+b");

	if (cadastro == NULL)
		printf("Erro na abertura do arquivo cadastro.txt!\n");

	while (fread(&cad, sizeof(cad), 1, cadastro))
	{

		printf("Digite o CPF do cliente: \n");
		setbuf(stdin, NULL);
		scanf("%s", CPF);

		j = strcmp(CPF, cad.cpf);

		if (j == 0)
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

			if (x == 9)
				break;

			printf("\nNome: %s\n", cad.nome);
			printf("Idade: %s\n", cad.idade);
			printf("CPF: %s\n", cad.cpf);
			printf("Telefone: %s\n", cad.telefone);
			printf("Endereco: %s\n", cad.end);
			printf("Genero: %s\n", cad.gen);

			fseek(cadastro, (-1) * sizeof(struct Cad), SEEK_CUR);
			fwrite(&cad, sizeof(struct Cad), 1, cadastro);
			break;
		}

		else
		{
			printf("\nCPF INVALIDO.\nDigite Novamente: ");
			scanf("%s", CPF);
		}
	}
	fwrite(&cad, sizeof(struct Cad), 1, cadastro);
	fclose(cadastro);
}

//-------------------- Funcao busca produto pelo SKU no estoque ---------------------------------------------
int alteraProd1(char sku[30], struct Est E, FILE *estoque)
{
	char SKU[30], op = 0;
	int i, j;

	// fazer com que ele leia o dado e armazene no arquivo
	estoque = fopen("estoque.txt", "a");
	if (estoque == NULL)
		printf("ERRO!!! O arquivo não abriu.\n");

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
					fclose(estoque);
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
					fclose(estoque);
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
					fclose(estoque);
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
					fclose(estoque);
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
	fclose(estoque);
	return 1;
}

//-------------------- Funcao que altera o produto no estoque ---------------------------------------------
void alteraProd(struct Est prod, FILE *estoque)
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
void cadastroProd(struct Est prod, FILE *estoque)
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
					scanf("%[^\n]s", prod.SKU);

					setbuf(stdin, NULL);
					printf("\nDigite o nicho do produto: \n");
					scanf("%[^\n]s", prod.nicho);

					setbuf(stdin, NULL);
					printf("\nDigite a cor do produto: \n");
					scanf("%[^\n]s", prod.cor);

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
void estoqueProd(struct Est prod, FILE *estoque)
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
void gerenciaPed(struct Est prod, struct Ped ped, FILE *estoque, FILE *cadastro, FILE *pedidos)
{

	int op, op1, numped;

	pedidos = fopen("pedidos.txt", "a+b");

	printf("Selecione a opção desejada:\n");
	printf("\n1- Acompanhar remessa\n");
	printf("2- Alterar Endereço\n");
	printf("3- Cancelar remessa\n");

	scanf("%d", &op);

	if (op == 1)
	{
		while (1)
		{
			printf("\nSelecionado: Acompanhar remessa\n");

			printf("\nDigite o número do pedido: ");
			scanf("%d", &numped);

			if (numped == ped.numped)
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

			if (numped == ped.numped)
			{
				printf("\nLogradouro: \n");
				scanf("%[^\n]s", ped.log);

				printf("Bairro: \n");
				scanf("%[^\n]s", ped.bairro);

				printf("Cidade: \n");
				scanf("%[^\n]s", ped.cidade);

				printf("UF: \n");
				scanf("%[^\n]s", ped.uf);

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

		if (op == 3)
		{
			printf("dados apagados!\n");
		}

		printf("\nDeseja realizar outra ação?\n");
		printf("\n1 - Realizar uma nova pesquisa: ");
		printf("\n2 - Voltar para o menu principal: \n");

		scanf("%d", &op1);
	}
}

void menu()
{
	int opcao = 0, subopcao = 0;
	struct Cad C;
	struct Cad P[30];
	struct Est prod;
	struct Ped ped;

	FILE *cadastro;
	FILE *estoque;
	FILE *pedidos;
	while (1)
	{
		printf("\nBem vindo ao Sistema de Gestão de Ecommerce");
		printf("\n1- Cadastrar cliente");
		printf("\n2- Consultar estoque");
		printf("\n3- Cadastrar produto");
		printf("\n4- Gerencia Pedidos");
		printf("\n5- Alterar dados Clientes");
		printf("\n6- Buscar CPF (TESTE)");
		printf("\n7- Buscar Produto (TESTE)");
		printf("\n8- leitura Arquivo");
		printf("\n9- Sair ");

		printf("\nDigite opção: ");
		scanf("%d", &opcao);

		if (opcao == 1)
			cadastroCli(P, cadastro);
		if (opcao == 2)
			estoqueProd(prod, estoque);
		if (opcao == 3)
			cadastroProd(prod, estoque);
		if (opcao == 4)
			gerenciaPed(prod, ped, estoque, cadastro, pedidos);
		if (opcao == 5)
			alteraCli(C, cadastro);
		if (opcao == 6)
			printf("%s", buscaCPF(C, cadastro));
		if (opcao == 7)
			aplicaSKU(prod, estoque);
		// if (opcao == 8)
		// {
		// 	printf("Informe qual relatorio deseja imprimir:");
		// 	printf("\n1- Imprime Cadastro");
		// 	printf("\n2- Imprime Estoque");
		// 	printf("\n9- Sair ");
		// 	scanf("%d", &subopcao);
		// 	if (subopcao == 1)
		// 		imprime_cadastro(C, cadastro);
		// 	// if (subopcao == 2)
		// 	// imprime_estoque(prod, estoque);
		// }
		if (opcao == 9)
			return;
	}
}

// void imprime_cadastro(struct Cad C, FILE *cadastro)
// {

// 	cadastro = fopen("clientes.txt", "rb");

// 	/*
// 	while (fscanf(cadastro, "%[^\n] ", malloc(sizeof(struct Cad))) != EOF) {
// 		printf("> %s\n", sizeof(struct Cad));
// 	}
// 	*/

// 	while (fread(&C, sizeof(struct Cad), 1, cadastro))
// 	{
// 		printf("\n\tO %s\t\t\n", C.o);
// 		printf("\n\tcliente %s\t\t\n", C.nome);
// 		printf("\n\tIdade: %s", C.idade);
// 		printf("\n\tCPF: %s", C.cpf);
// 		printf("\n\tCNPJ: %s", C.cnpj);
// 		printf("\n\ttelefone: %.2f", C.telefone);
// 		printf("\n\tEnd: %.2f\n\n", C.end);
// 		printf("\n\tGen: %.2f\n\n", C.gen);
// 	}
// 	/*
// 	char o[5];
// 	char nome[30];
// 	char idade[30];
// 	char cpf[30];
// 	char cnpj[30];
// 	char telefone[30];
// 	char end[100];
// 	char gen[1];
// */
// 	fclose(cadastro);
// 	return;
// }
// /*
// void imprime_estoque(struct Est prod,FILE *estoque)
// {


// }
// */

int main()
{
	menu();
}
