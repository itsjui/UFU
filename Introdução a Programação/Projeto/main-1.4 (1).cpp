#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------- Struct base cliente -------------------------------
struct Cad
{

	// Dados pessoais.
	char nome[30];
	char idade[30];
	char cpf[30];
	char telefone[30];
	char gen[5];

	// Endereço.
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[5];

	char end[100];
	int ID;
};
//-------------------- Struct auxiliar cliente ---------------------------
struct auxCad
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

//-------------------- Struct base produto -------------------------------
struct Est
{
	// Dados sobre produto
	int ID;
	char nome[30];
	char SKU[30];
	char nicho[30];
	int qtd;
	char cor[30];
	float custo, preco;
};
//-------------------- Struct backup produto -----------------------------
struct auxEst
{
	int ID;
	char nome[30];
	char SKU[30];
	char nicho[30];
	int qtd;
	char cor[30];
	float custo, preco;
};

//-------------------- Struct base Pedidos -------------------------------
struct Ped
{
	// Indices para pedido.
	int numped;
	int qtd;

	// Endereco
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[30];
	char comp[30];
};
//-------------------- Struct auxiliar Pedidos ---------------------------
struct auxPed
{
	// Indices para pedido.
	int numped;
	int qtd;

	// Endereco
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[30];
	char comp[30];
};

void cadastroCli(struct Cad cad, FILE *cadastro);
void alteraProd(struct Est prod, FILE *estoque);
void cadastroProd(struct Est prod, FILE *estoque);
void estoqueProd(struct Est prod, FILE *estoque);
void gerenciaPed(struct Est prod, struct Ped ped, FILE *estoque, FILE *pedidos, FILE *cadastro);
void imprime_cadastro(struct Cad cad, FILE *cadastro);

//-------------------- FUNNCAO QUE CARREGA DADOS DOS ARQUIVOS ---------------
void carregar(Cad C[], Est E[], Ped T[])
{
	int i;
	struct auxCad Pes;
	struct auxEst Prod;
	struct auxPed Ped;

	for (i = 0; i < 100; i++)
		C[i].ID = 0;

	FILE *clientes = fopen("clientes.bin", "rb");

	i = 1;
	while (fread(&Pes, sizeof(auxCad), 1, clientes))
	{
		C[i].ID = Pes.ID;
		strcpy(C[i].nome, Pes.nome);
		strcpy(C[i].idade, Pes.idade);
		strcpy(C[i].cpf, Pes.cpf);
		strcpy(C[i].telefone, Pes.telefone);
		strcpy(C[i].end, Pes.end);
		strcpy(C[i].gen, Pes.gen);
		i++;
	}
	fclose(clientes);

	FILE *produtos = fopen("produtos.bin", "rb");
	i = 1;
	while (fread(&Prod, sizeof(auxEst), 1, produtos))
	{
		E[i].ID = Prod.ID;
		strcpy(E[i].nome, Prod.nome);
		strcpy(E[i].SKU, Prod.SKU);
		strcpy(E[i].nicho, Prod.nicho);
		strcpy(E[i].cor, Prod.cor);
		E[i].qtd = Prod.qtd;
		E[i].preco = Prod.preco;
		E[i].custo = Prod.custo;
		i++;
	}
	fclose(produtos);

	FILE *pedidos = fopen("pedidos.bin", "rb");
	i = 1;
	while (fread(&Ped, sizeof(Ped), 1, pedidos))
	{
		T[i].numped = Ped.numped;
		T[i].qtd = Ped.qtd;
		strcpy(T[i].log, Ped.log);
		strcpy(T[i].bairro, Ped.bairro);
		strcpy(T[i].cidade, Ped.cidade);
		strcpy(T[i].uf, Ped.uf);
		i++;
	}
	fclose(pedidos);
}

//-------------------- FUNNCAO QUE BUSCA SKU ---------------
// Função retorna SKU Desejado
int pesquisaSKU(char s[100], struct Est est[])
{
	int i, j = 0;

	// RESOLVER O FUNCIONAMENTO DESSA FUNCAO
	// NAO ACHA NADA.

	for (j = 0; j < 30; j++)
	{
		if (strcmp(s, est[j].SKU) == 0)
		{
			return j;
		}
	}
	return 0;
}

//------------------- FUNCAO GERA NUMERO DE PEDIDO --------------------
int geraNumPed(Ped ped[])
{
	int i, aux = 1;

	// verifica se existe posição.
	for (i = 1; i < 10; i++)
	{
		if (ped[i].numped == 0)
		{
			ped[i].numped = aux;
			break;
		}
		aux++;
	}
	return i;
}

//-------------------- Funcao de ACHAR o produto e mostra seus dados ---------------
void aplicaSKU(struct Est prod, FILE *estoque)
{
	char sku[20];
	int j;
	Est E[30];

	printf("\n\t\tDigite o sku: ");
	setbuf(stdin, NULL);
	scanf("%s", sku);

	j = pesquisaSKU(sku, E);

	printf("\nPRODUTO ENCONTRADO!");
	printf("\nSKU Encontrado: %s\n", j);

	return;
}

//-------------------- Funcao de CADASTRAR produto ------------
void cadastroProd(Est est[], FILE *estoque)
{
	int op = 0;
	int i;

	// variáveis a serem passadas.
	char nome[50];
	char SKU[50];
	char nicho[50];
	char cor[50];
	int qtd;
	float custo;
	float preco;

	printf("\nDigite o ID deste novo produto: ");
	scanf("%d", &i);

	while (1)
	{
		if (op == 2)
			break;
		else
		{

			while (1)
			{
				printf("Cadastrar produto\n");

				printf("\nDigite o nome do produto:\n");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", nome);

				// copiando da variavel até a struct
				strcpy(est[i].nome, nome);

				printf("\nDigite o SKU do produto:\n");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", SKU);

				// copiando da variavel até a struct
				strcpy(est[i].SKU, SKU);
				// testando o strcpy.
				printf("\n\tId: %d | SKU: %s\n", i, est[i].SKU);

				printf("\nDigite o nicho do produto: \n");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", nicho);

				// copiando da variavel até a struct
				strcpy(est[i].nicho, nicho);

				printf("\nDigite a cor do produto: \n");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", cor);

				// copiando da variavel até a struct
				strcpy(est[i].cor, cor);

				printf("\nDigite a quantidade de produtos no estoque: \n");
				scanf("%d", &qtd);

				// copiando da variavel até a struct
				est[i].qtd = qtd;

				printf("\nDigite o custo do produto: \nR$");
				scanf("%f", &custo);

				// copiando da variavel até a struct
				est[i].custo = custo;

				printf("\nDigite o preço do produto: \nR$");
				scanf("%f", &preco);

				// copiando da variavel até a struct
				est[i].preco = preco;

				printf("\nNome: %s\n", est[i].nome);
				printf("SKU: %s\n", est[i].SKU);
				printf("Nicho: %s\n", est[i].nicho);
				printf("Cor: %s\n", est[i].cor);
				printf("Quantidade: %d\n", est[i].qtd);
				printf("Custo: R$%.2f\n", est[i].custo);
				printf("Preço: R$%.2f\n", est[i].preco);

				break;
			}
		}
		printf("\nRefazer Cadastro? \n");
		printf("SIM - 1 \n");
		printf("NAO - 2\n");
		scanf("%d", &op);
	}
}

//-------------------- Busca CPF no arquivo Cadastro -----------------------------
// finalizar implementação e fazer testes.
int buscaCPF(char cpf[], Cad cad[], FILE *clientes)
{
	int i, id, aux = 1;
	Cad p[10];

	for (i = 1; i < 10; i++)
	{
		if (strcmp(cpf, cad[i].cpf) == 0)
			return i;
	}

	return 0;
}

//-------------------- Busca ID registrado na struct cadastro -----------------------------
int buscaID(Cad P[], int ID)
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
	int op = 0;
	int x = 0, i, j;

	// Dados Pessoais
	char nome[30];
	char idade[30];
	char cpf[30];
	char telefone[30];
	char gen[5];

	// Endereço.
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[5];

	printf("\nDigite o ID do novo cliente a ser cadastrado: ");
	scanf("%d", &i);

	while (1)
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
				scanf("%[^\n]s", nome);
				// \copiando da variável para o item da struct.
				strcpy(cad[i].nome, nome);

				setbuf(stdin, NULL);
				printf("\nQual sua data de nascimento?\n");
				scanf("%[^\n]s", idade);
				// copiando da variável para o item da struct.
				strcpy(cad[i].idade, idade);

				setbuf(stdin, NULL);
				printf("\nDigite seu CPF: \n");
				scanf("%[^\n]s", cpf);
				// copiando da variável para o item da struct.
				strcpy(cad[i].cpf, cpf);

				setbuf(stdin, NULL);
				printf("\nQual seu telefone para contato? \n");
				scanf("%[^\n]s", telefone);
				// copiando da variável para o item da struct.
				strcpy(cad[i].telefone, telefone);

				setbuf(stdin, NULL);
				printf("\nQual genero voce se identifica?\n");
				printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
				scanf("%[^\n]s", gen);
				// copiando da variável para o item da struct.
				strcpy(cad[i].gen, gen);

				printf("\nDigite o logradouro: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", log);
				// Copia a variável para a struct.
				strcpy(cad[i].log, log);

				printf("\nDigite o bairro: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", bairro);
				// Copia a variável para a struct.
				strcpy(cad[i].bairro, bairro);

				printf("\nDigite a cidade: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", cidade);
				// Copia a variável para a struct.
				strcpy(cad[i].cidade, cidade);

				printf("\nDigite o estado: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", uf);
				// Copia a variável para a struct.
				strcpy(cad[i].uf, uf);


				//Mostra todos os itens digitados na tela.
				printf("\nNome: %s\n", cad[i].nome);
				printf("Idade: %s\n", cad[i].idade);
				printf("CPF: %s\n", cad[i].cpf);
				printf("Telefone: %s\n", cad[i].telefone);
				printf("Genero: %s\n", cad[i].gen);
				printf("Logradouro: %s\n", cad[i].log);
				printf("Bairro: %s\n", cad[i].bairro);
				printf("Cidade: %s\n", cad[i].cidade);
				printf("Estado: %s\n", cad[i].uf);


				//Por fim, mostra o ID do cliente cadastrado.
				cad[i].ID = i;
				printf("\n ID: %d\n", cad[i].ID);

				break;
			}
		}
		printf("\n Tudo certo? \n");
		printf("Cadastrar outro cliente - 1 \n");
		printf("Continuar - 2 \n");
		scanf("%d", &op);
	}
}

//-------------------- FUncao que altera dados do Cliente --------------------------
void alteraCli(struct Cad cad[], FILE *clientes)
{
	char CPF[30];
	int x = 0, j, i;

	// Dados Pessoais
	char nome[30];
	char idade[30];
	char cpf[30];
	char telefone[30];
	char gen[5];

	// Endereço.
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[5];

	while (1)
	{

		printf("Digite o CPF do cliente: \n");
		setbuf(stdin, NULL);
		scanf("%s", CPF);

		i = buscaCPF(CPF, cad, clientes);
		printf("\n\ni = %d\n", i);

		if (i != 0)
		{
			printf("\n\t\tCliente encontrado!\nAtualizar: \n");
			printf("\n1- Nome\n2-Idade\n3-CPF\n4-Telefone\n5-Genero\n6-Logradouro\n7-Bairro\n8-Cidade\n9-Estado\n");
			printf("\n10 - Voltar ao menu.\n");
			printf("\nDigite a sua opcao: ");
			setbuf(stdin, NULL);
			scanf("%d", &x);

			// NOME
			if (x == 1)
			{
				printf("\nDigite o nome: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", nome);

				// Copia a variável para a struct.
				strcpy(cad[i].nome, nome);
			}

			// IDADE
			if (x == 2)
			{
				printf("\nDigite a idade: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", idade);

				// Copia a variável para a struct.
				strcpy(cad[i].idade, idade);
			}

			// CPF
			if (x == 3)
			{
				printf("\nDigite o CPF: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", cpf);

				// Copia a variável para a struct.
				strcpy(cad[i].cpf, cpf);
			}

			// TELEFONE
			if (x == 4)
			{
				printf("\nDigite o telefone: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", telefone);

				// Copia a variável para a struct.
				strcpy(cad[i].telefone, telefone);
			}

			// GENERO
			if (x == 5)
			{
				printf("\nDigite o genero: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", gen);

				// Copia a variável para a struct.
				strcpy(cad[i].gen, gen);
			}

			// LOGRADOURO
			if (x == 6)
			{
				printf("\nDigite o logradouro: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", log);

				// Copia a variável para a struct.
				strcpy(cad[i].log, log);
			}

			// BAIRRO
			if (x == 7)
			{
				printf("\nDigite o bairro: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", bairro);

				// Copia a variável para a struct.
				strcpy(cad[i].bairro, bairro);
			}

			// CIDADE
			if (x == 8)
			{
				printf("\nDigite a cidade: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", cidade);

				// Copia a variável para a struct.
				strcpy(cad[i].cidade, cidade);
			}

			// ESTADO
			if (x == 9)
			{
				printf("\nDigite o estado: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]s", uf);

				// Copia a variável para a struct.
				strcpy(cad[i].uf, uf);
			}

			if (x == 10)
				break;

			printf("\nNome: %s\n", cad[i].nome);
			printf("Idade: %s\n", cad[i].idade);
			printf("CPF: %s\n", cad[i].cpf);
			printf("Telefone: %s\n", cad[i].telefone);
			printf("Genero: %s\n", cad[i].gen);
			printf("Logradouro: %s\n", cad[i].log);
			printf("Bairro: %s\n", cad[i].bairro);
			printf("Cidade: %s\n", cad[i].cidade);
			printf("Estado: %s\n", cad[i].uf);

			break;
		}

		else
		{
			printf("\nCPF INVALIDO.\nDigite Novamente: ");
			scanf("%s", CPF);
			break;
		}
	}
}

/*/--------------------Funcao acompanhar pedidos----------------------------------------
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
*/

//--------------------Funcao que cria novo pedido--------------------------------
void criaPed(Est E[], Ped ped[], Cad cad[], FILE *clientes)
{
	int ID, j = 0, id;
	char cpf[30], SKU[30];
	struct Cad c;
	int qtd;

	FILE *estoque;

	ID = geraNumPed(ped);
	printf("\t\t\nNumero do pedido: #%d\n\n", ID);

	// Acha o Cliente por meio do CPF.
	while (1)
	{
		setbuf(stdin, NULL);
		printf("\nDigite seu CPF desejado para a busca: ");
		scanf("%[^\n]s", cpf);

		id = buscaCPF(cpf, cad, clientes);

		if (id != 0)
		{
			printf("\nEste CPF: %s foi localizado.\n", cad[id].cpf);

			// printa as informações do usuario com base no CPF.

			printf("\nNome: %s\n", cad[id].nome);
			printf("Idade: %s\n", cad[id].idade);
			printf("CPF: %s\n", cad[id].cpf);
			printf("Telefone: %s\n", cad[id].telefone);
			printf("Genero: %s\n", cad[id].gen);
			printf("Logradouro: %s\n", cad[id].log);
			printf("Bairro: %s\n", cad[id].bairro);
			printf("Cidade: %s\n", cad[id].cidade);
			printf("Estado: %s\n", cad[id].uf);

			break;
		}

		else
		{
			printf("\nCPF NÂO CADASTRADO!");
			break;
		}

		break;
	}

	// Acha o Produto por meio do SKU e Valida a Quantidade.
	while (1)
	{
		setbuf(stdin, NULL);

		setbuf(stdin, NULL);
		printf("\n\nDigite o SKU do produto: ");
		scanf("%[^\n]s", SKU);

		j = pesquisaSKU(SKU, E); // Retorna o ID do produto.
		if (j != 0)
		{
			printf("\nEsse foi o SKU localizado: %s.\n", E[j].SKU);

			printf("\nNome: %s.", E[j].nome);
			printf("\nSKU: %s.", E[j].SKU);
			printf("\nNicho: %s.", E[j].nicho);
			printf("\nCor: %s.", E[j].cor);
			printf("\nPreco: R$%.2f.", E[j].preco);
			printf("\nCusto: R$%.2f.", E[j].custo);

			printf("\n\n\nQuantidade disponivel: %d.\n", E[j].qtd);

			// Verifica a quantidade.
			while (1)
			{

				// Aviso de uma unidade restante.
				if (E[j].qtd == 1)
				{
					printf("\n\t\tResta Apenas 1 item!!!");
				}

				// Aviso de uma unidade restante.
				if (E[j].qtd == 0)
				{
					printf("\n\t\tSem itens no Estoque!!!");
					break;
				}

				// Insercao de quantidade para realizacao do pedido.
				while (1)
				{
					printf("\n\n\tRealizando Pedido: #%d\n\n", ID);
					printf("\nDigite a quantidade desejada: ");
					scanf("%d", &qtd);

					if (qtd > E[j].qtd > 0)
					{
						printf("\nQuantidade indisponivel!");
						printf("\nDigite um valor abaixo de: %d", E[j].qtd);
					}

					else
					{
						E[j].qtd = E[j].qtd - qtd;
						printf("\nQuantidade valida!\nProsseguindo com pedido...");
						break;
					}
				}
				break;
			}
			break;
		}

		else
		{
			printf("\nPRODUTO NÃO LOCALIZADO!\n");
			break;
		}
	}

	// Uni todos os dados em uma unica Struct Pedidos.

	// DAR UM JEITO EM CRIAR UM MESMO PEDIDO COM OUTROS PRODUTOS.
}
void cancelaPed (struct Ped ped[], FILE *pedidos)
{
    int op, numped;

printf("Digite o numero do pedido: \n");
scanf("%d", &numped);

strcmp(numped, ped.numper)

if(numped == ped.numped){
    while(1){    
    printf("Pedido encontrado!\n");
    printf("Confirmar cancelamento?\n1- Sim\n2- Não.");
    scanf("%d", &op);
    
    if(op == 1){ped.numped = NULL}

        else break;
    }
    
else{
    printf("Pedido não encontrado!\n");
    printf("Digite novamente o numero do pedido ou caso preferir digite 9 para retornar ao menu principal.\n");
    scanf("%d", &op);
if(op == 9) return (1);

}    
 fwrite(&ped, sizeof(Ped),1 pedidos);
 fclose(pedidos);
    
}
void menu()
{
	int opcao = 0, subopcao = 0;

	char cpf[30];

	struct Cad c;
	struct Cad P[30];
	struct Est prod;
	struct Est E[30];
	struct Ped p;
	struct Ped T[30];
	struct Ped ped[]

	FILE *clientes;
	FILE *estoque;
	FILE *pedidos;
	while (1)
	{
		printf("\n\nBem vindo ao Sistema Gestão de Pedidos");
		printf("\n1- Cadastrar cliente");
		printf("\n2- Gerenciar Pedidos existentes");
		printf("\n3- Criar novo Pedido");
		printf("\n4- Criar novo Produto");
		printf("\n9- Sair ");

		printf("\nDigite opção: ");
		scanf("%d", &opcao);

		if (opcao == 1)
			cadastroCli(P, clientes);

		if (opcao == 2)
			gerenciaPed(prod, p, estoque, clientes, pedidos);

		if (opcao == 3)
			criaPed(T, P, clientes);

		if (opcao == 4)
			cadastroProd(E, estoque);

		if(opcao == 5)
			cancelaPed(ped, pedidos);

		if (opcao == 9)
			return;
	}
}

int main()
{
	menu();
}

