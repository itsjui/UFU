/*struct a_definir{
	//inserir código aqui
};

void cadastro(struct a_definir T[]){
	//inserir código aqui
}

void mostra(struct a_definir T[]){
	//inserir código aqui
}

void mostra1(struct a_definir T[]){
	//inserir código aqui
}

*/

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
//-------------------- Struct estoque ------------------------------------
struct Est
{
	int q;
	char SKU[30];
	char cor[30];
	char nicho[30];
	int qtd;
};
//-------------------- Struct produto ------------------------------------
struct Prod
{
	int p;
	char nome[30];
	char SKU[30];
	char nicho[30];
	int qtd;
	char cor[30];
	float custo, preco;
};
//-------------------- Funcao Cadastra Cliente ------------------------------------

void cadastroCli(struct Cad cad, FILE *cadastro)
{
	int i, op = 0;

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
				scanf("%[^\n]s", cad.o);
				printf("%s", cad.o);

				if (strcmp(cad.o, "1") != 0 || strcmp(cad.o, "2") != 0)
				{
					while (1)
					{
						setbuf(stdin, NULL);
						printf("\nOpcao desconhecida, por favor digite novamente.\n");
						scanf("%[^\n]s", cad.o);

						if (strcmp(cad.o, "1") == 0 || strcmp(cad.o, "2") == 0)
							break;
						else
							continue;
					}
				}

				if (strcmp(cad.o, "1") == 0 || strcmp(cad.o, "2") == 0)
				{
					if (strcmp(cad.o, "1") == 0)
					{
						setbuf(stdin, NULL);
						printf("\nDigite seu CPF: \n");
						scanf("%[^\n]s", cad.cpf);

						setbuf(stdin, NULL);
						printf("\nQual seu telefone para contato? \n");
						scanf("%[^\n]s", cad.telefone);

						setbuf(stdin, NULL);
						printf("\nQual seu endereco? \n");
						scanf("%[^\n]s", cad.end);

						setbuf(stdin, NULL);
						printf("\nQual genero voce se identifica?\n");
						printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
						scanf("%[^\n]s", cad.gen);

						printf("\nNome: %s\n", cad.nome);
						printf("Idade: %s\n", cad.idade);
						printf("CPF: %s\n", cad.cpf);
						printf("Telefone: %s\n", cad.telefone);
						printf("Endereco: %s\n", cad.end);
						printf("Genero: %s\n", cad.gen);
					}

					if (strcmp(cad.o, "2") == 0)
					{
						setbuf(stdin, NULL);
						printf("Digite seu CNPJ: \n");
						scanf("%[^\n]s", cad.cnpj);

						setbuf(stdin, NULL);
						printf("Qual seu telefone para contato? \n");
						scanf("%[^\n]s", cad.telefone);

						setbuf(stdin, NULL);
						printf("Qual seu endereco? \n");
						scanf("%[^\n]s", cad.end);

						printf("\n Nome: %s\n", cad.nome);
						printf("Idade: %s\n", cad.idade);
						printf("CNPJ: %s\n", cad.cnpj);
						printf("Telefone: %s\n", cad.telefone);
						printf("Endereco: %s\n", cad.end);
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

//-------------------- Funcao que adiministra o estoque ---------------------------------------------

void estoqueProd(struct Est est, FILE *estoque)
{
	int op = 0;
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
					printf("Estoque de produto\n");

					setbuf(stdin, NULL);
					printf("\nDigite o SKU:\n");
					scanf("%s", est.SKU);

					setbuf(stdin, NULL);
					printf("\nDigite a cor: \n");
					scanf("%s", est.cor);

					setbuf(stdin, NULL);
					printf("\nDigite a quantidade: \n");
					scanf("%d", &est.qtd);

					setbuf(stdin, NULL);
					printf("\nDigite o nicho: \n");
					scanf("%s", est.nicho);

					printf("SKU: %s\n", est.SKU);
					printf("Nicho: %s\n", est.nicho);
					printf("Cor: %s\n", est.cor);
					printf("Quantidade: %d\n", est.qtd);

					fwrite(&est, sizeof(struct Est), 1, estoque);
					fclose(estoque);
					break;
				}
			}
			printf("\n Tudo certo? \n");
			printf("Cadastrar outro produto - 1 \n");
			printf("Continuar - 2\n");
			scanf("%d", &op);
		}
	}
}

//-------------------- Funcao Cadastrar produto ------------------------------------

void cadastroProd(struct Prod prod, FILE *produto)
{
	int op = 0;
	produto = fopen("produto.txt", "a+b");
	if (produto == NULL)
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

					fwrite(&prod, sizeof(struct Prod), 1, produto);
					fclose(produto);
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
void menu()
{
	int opcao = 0;
	struct Cad P;
	struct Est E;
	struct Prod C;

	FILE *cadastro;
	FILE *estoque;
	FILE *produto;
	while (1)
	{
		printf("\nBem vindo ao Sistema Gestão de Ecommerce");
		printf("\n1- Cadastrar cliente");
		printf("\n2- Consultar estoque");
		printf("\n3- Cadastrar produto");
		printf("\n9- Sair ");

		printf("\nDigite opção: ");
		scanf("%d", &opcao);

		if (opcao == 1)
			cadastroCli(P, cadastro);
		if (opcao == 2)
			estoqueProd(E, estoque);
		if (opcao == 3)
			cadastroProd(C, produto);
		if (opcao == 9)
			return;
	}
}

int main()
{
	menu();
}
