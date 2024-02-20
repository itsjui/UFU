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

    // ID
    int ID;
};
//-------------------- Struct auxiliar cliente ---------------------------
struct auxCad
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

    // ID
    int ID;
};

//-------------------- Struct base produto -------------------------------
struct Est
{
    // Dados sobre produto
    char nome[30];
    char SKU[30];
    char nicho[30];
    int qtd;
    char cor[30];
    float custo, preco;

    // ID
    int ID;
};
//-------------------- Struct backup produto -----------------------------
struct auxEst
{
    // Dados sobre produto
    char nome[30];
    char SKU[30];
    char nicho[30];
    int qtd;
    char cor[30];
    float custo, preco;

    // ID
    int ID;
};

//-------------------- Struct base Pedidos -------------------------------
struct Ped
{
    // Indices para pedido.
    int cadID;
    int numped;
    int qtd;
    int loc;

    // Dados pessoais
    char nomeCad[30];
    char idade[30];
    char cpf[30];
    char telefone[30];
    char gen[5];

    // Endereco
    char log[30];
    char bairro[30];
    char cidade[30];
    char uf[30];

    // Dados sobre produto
    char nomeProd[30];
    char SKU[30];
    char nicho[30];
    char cor[30];
    float custo;
    float preco;

    // Passando a struct para mais de um produto
    struct Est est[100];

    // Produtos a serem utilizados
    int ped;
    char pedidoSKU[10][30];
};
//-------------------- Struct auxiliar Pedidos ---------------------------
struct auxPed
{
    // Indices para pedido.
    int cadID;
    int numped;
    int qtd;
    int loc;

    // Dados pessoais
    char nomeCad[30];
    char idade[30];
    char cpf[30];
    char telefone[30];
    char gen[5];

    // Endereco
    char log[30];
    char bairro[30];
    char cidade[30];
    char uf[30];

    // Dados sobre produto
    char nomeProd[30];
    char SKU[30];
    char nicho[30];
    char cor[30];
    float custo;
    float preco;

    // Passando a struct para mais de um produto
    struct Est est[100];

    // Produtos a serem utilizados
    int ped;
    char pedidoSKU[10][30];
};

// DECLARAÇÕES

// ============== FUNÇÕES DE ARQUIVO ==============
void carregaArq(struct Cad P[], struct Est E[], struct Ped T[]);
void salvaArq(struct Cad P[], struct Est E[], struct Ped T[]);

// ============== FUNÇÕES DE CLIENTE ==============
void cadastroCli(struct Cad cad[]);
void alteraCli(struct Cad cad[]);
void excluiCli(struct Cad cad[]);
void consultaCli(struct Cad cad[]);
int buscaCPF(char cpf[], struct Cad cad[]);
int buscaID(struct Cad P[], int ID);

// ============== FUNÇÕES DE PEDIDO ==============
int geraNumPed(struct Ped ped[]);
int buscaPed(int numped, struct Ped ped[]);
void geraPed(int loc, int i, int j, int ID, struct Est est[], struct Ped ped[], struct Cad cad[]);
void mostraPed(int ID, int j, struct Ped ped[]);
void criaPed(struct Est est[], struct Ped ped[], struct Cad cad[]);
void alteraPed(struct Est est[], struct Ped ped[], struct Cad cad[]);

// ============== FUNÇÕES DE PRODUTO ==============
void cadastroProd(struct Est prod[]);
void alteraProd(struct Est prod[]);
void excluiProd(struct Est prod[]);
void consultaProd(struct Est prod[]);
int pesquisaSKU(char s[], struct Est prod[]);

// ============== FUNÇÕES DE ARQUIVO ==============
//-------------------- FUNNCAO QUE CARREGA DADOS DOS ARQUIVOS ---------------
void salvaArq(struct Cad, struct Est, struct Ped)
{
    struct Cad C;
    struct auxCad Pes;
    int i = 0;

    remove("clientes.bin");
    FILE *clientes = fopen("clientes.bin", "ab");
    for (i = 0; i <= 30; i++)
        fwrite(&C, sizeof(struct Cad), 1, clientes);
    
    fclose(clientes);

    struct Est E;
    struct auxEst Prod;

    remove("produtos.bin");
    FILE *produtos = fopen("produtos.bin", "ab");
    for (i = 0; i<=30; i++)
        fwrite(&E, sizeof(struct Est), 1, produtos);
    fclose(produtos);
    
    struct Ped T;
    struct auxPed Ped;

    remove("pedidos.bin");
    FILE *pedidos = fopen("pedidos.bin", "ab");
    for (i = 0; i<=30; i++)
        fwrite(&T, sizeof(struct Ped), 1, pedidos);
    fclose(pedidos);
}
void carregaArq(Cad C[], Est E[], Ped T[])
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

// ============== FUNÇÕES DE PRODUTO ==============
//-------------------- Funcao de CADASTRAR produto ------------
void cadastroProd(Est est[])
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

    while (1)
    {
        if (op == 2)
            break;
        else
        {
            while (1)
            {

                printf("\nDigite o ID deste novo produto: ");
                scanf("%d", &i);

                printf("Cadastrar produto\n");

                // Passando o id para a struct.
                est[i].ID = i;

                printf("\nDigite o nome do produto: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", nome);

                // copiando da variavel até a struct
                strcpy(est[i].nome, nome);

                printf("\nDigite o SKU do produto: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", SKU);

                // copiando da variavel até a struct
                strcpy(est[i].SKU, SKU);

                // testando o strcpy.
                printf("\n\tId: %d | SKU: %s\n", i, est[i].SKU);

                printf("\nDigite o nicho do produto: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", nicho);

                // copiando da variavel até a struct
                strcpy(est[i].nicho, nicho);

                printf("\nDigite a cor do produto: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", cor);

                // copiando da variavel até a struct
                strcpy(est[i].cor, cor);

                printf("\nDigite a quantidade de produtos no estoque: ");
                scanf("%d", &qtd);

                // copiando da variavel até a struct
                est[i].qtd = qtd;

                printf("\nDigite o custo do produto: R$");
                scanf("%f", &custo);

                // copiando da variavel até a struct
                est[i].custo = custo;

                printf("\nDigite o preço do produto: R$");
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
        printf("\nDeseja cadastrar outro Produto?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
    }
}

//-------------------- Funcao de ALTERAR produto ------------
void alteraProd(Est est[])
{

    // Dados da Função
    int op = 1;
    int x;
    int i;

    // Dados do Produto no estoque.
    char nome[50];
    char SKU[50];
    char nicho[50];
    char cor[50];
    int qtd;
    float custo;
    float preco;

    while (1)
    {
        if (op == 2)
            break;

        if (op == 1)
        {
            printf("\nDigite o SKU do produto: \n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", SKU);

            i = pesquisaSKU(SKU, est);
            printf("\n\t\ti: %d | sku: %s\n", i, est[i].SKU);

            if (i != 0)
            {
                printf("\n\t\tProduto encontrado!\nAtualizar: \n");
                printf("\n1- Nome\n2- SKU\n3- Nicho\n4- Cor\n5- Quantidade\n6- Custo\n7- Preco\n");
                printf("\n10 - Voltar ao menu.\n");

                printf("\nDigite a sua opcao: ");
                setbuf(stdin, NULL);
                scanf("%d", &x);

                // NOME
                if (x == 1)
                {
                    printf("\nDigite o nome do produto: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", nome);
                    // copiando da variavel até a struct
                    strcpy(est[i].nome, nome);
                }

                // SKU
                if (x == 2)
                {
                    printf("\nDigite o SKU do produto: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", SKU);
                    // copiando da variavel até a struct
                    strcpy(est[i].SKU, SKU);
                }

                // NICHO
                if (x == 3)
                {
                    printf("\nDigite o nicho do produto: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", nicho);
                    // copiando da variavel até a struct
                    strcpy(est[i].nicho, nicho);
                }

                // COR
                if (x == 4)
                {
                    printf("\nDigite a cor do produto: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", cor);
                    // copiando da variavel até a struct
                    strcpy(est[i].cor, cor);
                }

                // QUANTIDADE
                if (x == 5)
                {
                    printf("\nDigite a quantidade: ");
                    scanf("%d", &qtd);
                    // copiando da variavel até a struct
                    est[i].qtd = qtd;
                }

                // CUSTO
                if (x == 6)
                {
                    printf("\nDigite o custo do produto: R$");
                    scanf("%f", &custo);
                    // copiando da variavel até a struct
                    est[i].custo = custo;
                }

                // PRECO
                if (x == 7)
                {
                    printf("\nDigite o preço do produto: R$");
                    scanf("%f", &preco);
                    // copiando da variavel até a struct
                    est[i].preco = preco;
                }

                // VOLTAR AO MENU
                if (x == 10)
                    break;

                printf("\nNome: %s\n", est[i].nome);
                printf("SKU: %s\n", est[i].SKU);
                printf("Nicho: %s\n", est[i].nicho);
                printf("Cor: %s\n", est[i].cor);
                printf("Quantidade: %d\n", est[i].qtd);
                printf("Custo: R$%.2f\n", est[i].custo);
                printf("Preco: R$%.2f\n", est[i].preco);

                break;
            }

            else
                printf("\n\t\tSKU INVALIDO!\n");
        }

        printf("\nDeseja realizar outra consulta?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
    }
}

//-------------------- FUNNCAO QUE BUSCA SKU ---------------
// Função retorna INDICE do SKU Desejado
int pesquisaSKU(char s[100], struct Est est[])
{
    int j = 0;

    for (j = 0; j < 100; j++)
    {
        if (strcmp(s, est[j].SKU) == 0)
        {
            return j;
        }
    }
    return 0;
}

//-------------------- FUNÇÃO QUE CONSULTA PRPODUTOS ---------------
void consultaProd(struct Est est[])
{

    // Dados Função
    int op;
    int i;
    char sku[30];

    while (1)
    {
        printf("\nO que voce deseja?");
        printf("\n1- Buscar produto por SKU");
        printf("\n2- Mostrar Todos os produtos");
        printf("\n\n9- SAIR\n");

        printf("\nDigite a opcao desejada: ");

        scanf("%d", &op);

        // Busca pelo SKU existente
        if (op == 1)
        {
            printf("\n\t\tOPCAO SELECIONADA: Buscar por SKU.\n");
            printf("\nDigite o SKU desejado: ");

            setbuf(stdin, NULL);
            scanf("%[^\n]s", sku);

            i = pesquisaSKU(sku, est);

            if (i != 0)
            {
                printf("\nNome: %s\n", est[i].nome);
                printf("SKU: %s\n", est[i].SKU);
                printf("Nicho: %s\n", est[i].nicho);
                printf("Cor: %s\n", est[i].cor);
                printf("Quantidade: %d\n", est[i].qtd);
                printf("Custo: R$%.2f\n", est[i].custo);
                printf("Preco: R$%.2f\n", est[i].preco);
                break;
            }

            else
            {
                printf("\nSKU NAO CADASTRADO!");
                break;
            }
        }

        // Mostra TODOS os produtos existentes
        if (op == 2)
        {
            printf("\n\t\tOPCAO SELECIONADA: Mostrar Todos os produtos.\n");

            for (i = 1; i <= 100; i++)
            {
                if (est[i].ID == i)
                {
                    printf("\nNome: %s\n", est[i].nome);
                    printf("SKU: %s\n", est[i].SKU);
                    printf("Nicho: %s\n", est[i].nicho);
                    printf("Cor: %s\n", est[i].cor);
                    printf("Quantidade: %d\n", est[i].qtd);
                    printf("Custo: R$%.2f\n", est[i].custo);
                    printf("Preco: R$%.2f\n", est[i].preco);
                }

                else
                    continue;
            }

            break;
        }

        if (op == 9)
            break;

        else
            printf("OPCAO DESCONHECIDA! Vamos tentar denovo...");
    }
}

//============================ FUNÇÕES DE PEDIDO =============================

//------------------- FUNCAO GERA NUMERO DE PEDIDO --------------------
int geraNumPed(Ped ped[])
{
    int i;

    // verifica se existe posição.
    for (i = 1; i < 100; i++)
    {
        if (ped[i].numped == 0)
        {
            ped[i].numped = i;
            break;
        }
    }
    return i;
}

//------------------- FUNCAO BUSCA PEDIDO DE FATO --------------------
int buscaPed(int numped, Ped ped[])
{
    int i;

    // Busca id pelo for rodando pelo STRUCT
    for (i = 1; i <= 100; i++)
    {
        if (ped[numped].numped == i)
            return i;
    }

    return 0;
}

//------------------- FUNCAO GERA PEDIDO DE FATO --------------------
void geraPed(int loc, int i, int j, int ID, Est est[], Ped ped[], Cad cad[])
{
    // Utilizada no laço For para preenchimento dos
    // dados de vários produtos.
    int x = 0;

    // CUSTO & PREÇO
    float custo = 0;
    float preco = 0;
    float custo1 = 0;
    float preco1 = 0;

    // Uni todos os dados em uma unica Struct Pedidos.
    // PASSANDO DADOS DO CADASTRO PESSOA.
    ped[ID].cadID = cad[i].ID;
    strcpy(ped[ID].nomeCad, cad[i].nome);
    strcpy(ped[ID].idade, cad[i].idade);
    strcpy(ped[ID].cpf, cad[i].cpf);
    strcpy(ped[ID].telefone, cad[i].telefone);
    strcpy(ped[ID].gen, cad[i].gen);

    // PASSANDO DADOS DO CADASTRO ENDEREÇO.
    strcpy(ped[ID].log, cad[i].log);
    strcpy(ped[ID].bairro, cad[i].bairro);
    strcpy(ped[ID].cidade, cad[i].cidade);
    strcpy(ped[ID].uf, cad[i].uf);

    // PASSANDO DADOS DO PRODUTO.
    for (x = 1; x <= loc; x++)
    {
        // Função que retorna o INDICE do SKU.
        // Coleta realizada pelas SKU's Armazenadas no pedido.
        j = pesquisaSKU(ped[ID].pedidoSKU[x], est);

        // Copia dado selecionado pra cada posição
        //  de cada produto.
        ped[ID].est[j].ID = est[j].ID;
        strcpy(ped[ID].est[j].nome, est[j].nome);
        strcpy(ped[ID].est[j].SKU, est[j].SKU);
        strcpy(ped[ID].est[j].nicho, est[j].nicho);
        strcpy(ped[ID].est[j].cor, est[j].cor);

        // Gera Custo & Preço
        ped[ID].est[j].custo = est[j].custo * ped[ID].est[j].qtd;
        ped[ID].est[j].preco = est[j].preco * ped[ID].est[j].qtd;
    }

    // GERA CUSTO & PREÇO
    // FAZER OS DEVIDOS TESTE

    for (x = 1; x <= loc; x++)
    {

        // Função que retorna o INDICE do SKU.
        j = pesquisaSKU(ped[ID].pedidoSKU[x], est);

        custo1 = ped[ID].est[j].custo;
        preco1 = ped[ID].est[j].preco;

        custo = custo1 + custo;
        preco = preco1 + preco;
    }
    ped[ID].custo = custo;
    ped[ID].preco = preco;

    // MOSTRANDO TODO O PEDIDO NA TELA.
    printf("\n\t\tNumero do Pedido: %d\n", ped[ID].numped);
    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Dados Cadastrais ------");

    printf("\n\t\tID do Cliente:  %d", ped[ID].cadID);
    printf("\n\t\tNome do Cliente:  %s", ped[ID].nomeCad);
    printf("\n\t\tIdade:  %s", ped[ID].idade);
    printf("\n\t\tCPF:  %s", ped[ID].cpf);
    printf("\n\t\tGenero:  %s", ped[ID].gen);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Endereco --------------");

    printf("\n\t\tLogradouro:  %s", ped[ID].log);
    printf("\n\t\tBairro:  %s", ped[ID].bairro);
    printf("\n\t\tCidade:  %s", ped[ID].cidade);
    printf("\n\t\tEstado:  %s", ped[ID].uf);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t---- Dados do(s) Produto(s) ----");

    // MOSTRA A SEÇÃO PRODUTOS DA MANEIRA CORRETA.
    for (x = 1; x <= loc; x++)
    {
        j = pesquisaSKU(ped[ID].pedidoSKU[x], est);

        printf("\n\n\t\tID do Produto:  %d", ped[ID].est[j].ID);
        printf("\n\t\tNome do Produto:  %s", ped[ID].est[j].nome);
        printf("\n\t\tSKU:  %s", ped[ID].est[j].SKU);
        printf("\n\t\tNicho:  %s", ped[ID].est[j].nicho);
        printf("\n\t\tCor:  %s", ped[ID].est[j].cor);
        printf("\n\t\tQuantidade:  %d", ped[ID].est[j].qtd);
    }

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Valores ---------------");

    printf("\n\t\tCusto:  R$%.2f", ped[ID].custo);
    printf("\n\t\tPreco:  R$%.2f", ped[ID].preco);
}

//------------------- FUNCAO MOSTRA PEDIDO --------------------
void mostraPed(int ID, int j, Ped ped[], Est est[])
{

    // MOSTRANDO TODO O PEDIDO NA TELA.
    printf("\n\t\tNumero do Pedido: %d\n", ped[ID].numped);
    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Dados Cadastrais ------");

    printf("\n\t\tID do Cliente:  %d", ped[ID].cadID);
    printf("\n\t\tNome do Cliente:  %s", ped[ID].nomeCad);
    printf("\n\t\tIdade:  %s", ped[ID].idade);
    printf("\n\t\tCPF:  %s", ped[ID].cpf);
    printf("\n\t\tGenero:  %s", ped[ID].gen);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Endereco --------------");

    printf("\n\t\tLogradouro:  %s", ped[ID].log);
    printf("\n\t\tBairro:  %s", ped[ID].bairro);
    printf("\n\t\tCidade:  %s", ped[ID].cidade);
    printf("\n\t\tEstado:  %s", ped[ID].uf);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t---- Dados do(s) Produto(s) ----");

    // MOSTRA A SEÇÃO PRODUTOS DA MANEIRA CORRETA.
    for (int x = 1; x <= ped[ID].loc; x++)
    {
        j = pesquisaSKU(ped[ID].pedidoSKU[x], est);

        printf("\n\n\t\tID do Produto:  %d", ped[ID].est[j].ID);
        printf("\n\t\tNome do Produto:  %s", ped[ID].est[j].nome);
        printf("\n\t\tSKU:  %s", ped[ID].est[j].SKU);
        printf("\n\t\tNicho:  %s", ped[ID].est[j].nicho);
        printf("\n\t\tCor:  %s", ped[ID].est[j].cor);
        printf("\n\t\tQuantidade:  %d", ped[ID].est[j].qtd);
    }

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Valores ---------------");

    printf("\n\t\tCusto:  R$%.2f", ped[ID].custo);
    printf("\n\t\tPreco:  R$%.2f", ped[ID].preco);
}

//-------------------- FUNCAO CRIA NOVO PEDIDO --------------------------
void criaPed(Est est[], Ped ped[], Cad cad[])
{
    // Dados Função operantes
    int ID;

    // Indices do Cadastro e Estoque
    int i = 0;
    int j = 0;

    // Produtos para gerar pedido.
    int loc = 0;

    // Opções
    int op = 1;
    int op1 = 0;

    // Dados p/ pesquisa
    char cpf[30];
    int qtd;

    // Gera numero do pedido de acordo com
    // a existencia de pedido na própria struct

    while (1)
    {
        if (op == 2)
            break;

        if (op == 1)
        {
            ID = geraNumPed(ped);
            printf("\t\t\nNumero do pedido: #%d\n", ID);

            // Acha o Cliente por meio do CPF.
            // Cliente vai ser sempre 1.
            while (1)
            {
                setbuf(stdin, NULL);
                printf("\nDigite seu CPF desejado para a busca: ");
                scanf("%[^\n]s", cpf);

                i = buscaCPF(cpf, cad);

                if (i != 0)
                {
                    printf("\nEste CPF: %s foi localizado.\n", cad[i].cpf);

                    // printa as informações do usuario com base no CPF.

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
                    printf("\nCPF NAO CADASTRADO!\n");

                    printf("\nDeseja sair?");
                    printf("\n1- SIM.");
                    printf("\n2- NAO");
                    printf("\nDigite sua opcao: ");

                    scanf("%d", &op1);

                    if (op1 == 1)
                    {
                        ped[ID].numped = 0;
                        return;
                    }

                    if (op1 == 2)
                    {
                        printf("\nVamos tentar novamente...");
                        continue;
                    }
                }

                break;
            }

            // Questiona a quantidade de produtos diferentes.
            printf("\nDigite quantos produtos diferentes serao incluidos: ");
            scanf("%d", &loc);
            ped[ID].loc = loc;

            // Captura os produtos.
            for (int i = 1, aux = 1; i <= loc; i++, aux++)
            {
                printf("\n\nDigite o SKU do #%d produto: ", aux);

                // Limpa Buffer.
                setbuf(stdin, NULL);

                // Captura o SKU e passa para a struct.
                // ped[ID].pedidoSKU[aux] -> Variável que recebe multiplos SKU.
                scanf("%[^\n]", ped[ID].pedidoSKU[aux]);

                j = pesquisaSKU(ped[ID].pedidoSKU[aux], est); // Retorna o ID do produto.
                if (j != 0)
                {
                    printf("\nEsse foi o SKU localizado: %s.\n", est[j].SKU);

                    printf("\nNome: %s.", est[j].nome);
                    printf("\nSKU: %s.", est[j].SKU);
                    printf("\nNicho: %s.", est[j].nicho);
                    printf("\nCor: %s.", est[j].cor);
                    printf("\nCusto: R$%.2f.", est[j].custo);
                    printf("\nPreco: R$%.2f.", est[j].preco);

                    printf("\n\n\nQuantidade disponivel: %d.\n", est[j].qtd);

                    // Verifica a quantidade.
                    while (1)
                    {

                        // Aviso de UMA UN. RESTANTE.
                        if (est[j].qtd == 1)
                        {
                            printf("\n\t\tResta Apenas 1 item!!!");
                        }

                        // Aviso de 0 ITENS NO ESTOQUE.
                        if (est[j].qtd == 0)
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

                            if (qtd > est[j].qtd && est[j].qtd > 0)
                            {
                                printf("\nQuantidade indisponivel!");
                                printf("\nDigite um valor abaixo de: %d", est[j].qtd);
                            }

                            else
                            {
                                // PASSAR VARIAVEL, DUPLA STRUCT.
                                ped[ID].est[j].qtd = qtd;
                                est[j].qtd = est[j].qtd - qtd;
                                printf("\nQuantidade valida!");
                                printf("\nProsseguindo com pedido...\n");
                                break;
                            }
                        }

                        break;
                    }
                }

                else
                {
                    printf("\nPRODUTO NÃO LOCALIZADO!\n");

                    printf("\nDeseja sair?");
                    printf("\n1- SIM.");
                    printf("\n2- NAO");
                    printf("\nDigite sua opcao: ");

                    scanf("%d", &op1);

                    if (op1 == 1)
                    {
                        ped[ID].numped = 0;
                        return;
                    }

                    if (op1 == 2)
                    {
                        printf("\nVamos tentar novamente...");
                        continue;
                    }
                }
            }

            geraPed(loc, i, j, ID, est, ped, cad);
        }

        // PERGUNTA DE VERIFICAÇÃO.
        printf("\n\nDeseja fazer outro pedido?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opção: ");

        scanf("%d", &op);
    }
}

//-------------------- FUNCAO ALTERA PEDIDO --------------------------
void alteraPed(Est est[], Ped ped[])
{
    // Variaveis OP.
    int op = 0;
    int op1 = 1;
    int numped = 0;
    int j = 0;
    int i = 0;
    int x = 0;
    int y;
    char novoSKU[30];

    // Dados Pessoais
    char nomeCad[30];
    char idade[30];
    char cpf[30];
    char telefone[30];
    char gen[5];

    // Dados Endereço.
    char log[30];
    char bairro[30];
    char cidade[30];
    char uf[5];

    // Dados Produtos.
    char SKU[50];
    int qtd;

    // Custo & Preco
    float custo;
    float preco;
    float custo1;
    float preco1;

    while (1)
    {
        if (op1 == 2)
            break;

        if (op1 == 1)
        {
            printf("\nDigite o Numero do pedido: \n");
            setbuf(stdin, NULL);
            scanf("%d", &numped);

            j = buscaPed(numped, ped);
            printf("\n\t\tID: #%d | Numero Pedido: %d\n", j, ped[j].numped);

            if (j != 0)
            {
                printf("\n\t\tPedido encontrado!");
                printf("\nAtualizar: \n");

                // Dados Cadastrais.
                printf("\n1- Nome");
                printf("\n2- Idade");
                printf("\n3- CPF");
                printf("\n4- Telefone");
                printf("\n5- Genero");

                // Endereço
                printf("\n6- Logradouro");
                printf("\n7 - Bairro.");
                printf("\n8 - Cidade.");
                printf("\n9 - Estado.");

                printf("\n10 - Produto.");
                printf("\n11 - Quantidade.\n");

                printf("\nDigite a sua opcao: ");
                setbuf(stdin, NULL);
                scanf("%d", &op);

                // NOME
                if (op == 1)
                {
                    printf("\nDigite o nome do cliente: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", nomeCad);
                    // copiando da variavel até a struct
                    strcpy(ped[j].nomeCad, nomeCad);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // IDADE
                if (op == 2)
                {
                    printf("\nDigite a data de nascimento do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", idade);
                    // copiando da variavel até a struct
                    strcpy(ped[j].idade, idade);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // CPF
                if (op == 3)
                {
                    printf("\nDigite o CPF do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", cpf);
                    // copiando da variavel até a struct
                    strcpy(ped[j].cpf, cpf);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // TELEFONE
                if (op == 4)
                {
                    printf("\nDigite o Telefone do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", telefone);
                    // copiando da variavel até a struct
                    strcpy(ped[j].telefone, telefone);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // GENERO
                if (op == 5)
                {
                    printf("\nDigite o Genero do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", gen);
                    // copiando da variavel até a struct
                    strcpy(ped[j].gen, gen);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // LOGRADOURO
                if (op == 6)
                {
                    printf("\nDigite o Logradouro do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", log);
                    // copiando da variavel até a struct
                    strcpy(ped[j].log, log);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // BAIRRO
                if (op == 7)
                {
                    printf("\nDigite o Bairro do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", bairro);
                    // copiando da variavel até a struct
                    strcpy(ped[j].bairro, bairro);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // CIDADE
                if (op == 8)
                {
                    printf("\nDigite a Cidade do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", cidade);
                    // copiando da variavel até a struct
                    strcpy(ped[j].cidade, cidade);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // ESTADO
                if (op == 9)
                {
                    printf("\nDigite o Estado do cliento: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", uf);
                    // copiando da variavel até a struct
                    strcpy(ped[j].uf, uf);

                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                }

                // PRODUTO
                if (op == 10 || op == 11)
                {
                    printf("\nDigite o SKU DO PRODUTO: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", SKU);

                    // RETRONA ID DO PRODUTO
                    i = pesquisaSKU(SKU, est);

                    // VERIFICA SE CONSTA PRODUTO NO ESTOQUE
                    if (i != 0)
                    {

                        // VERIFICA SE CONSTA PRODUTO NO PEDIDO
                        for (x = 1; x <= 10; x++)
                        {
                            y = strcmp(SKU, ped[j].pedidoSKU[i]);
                            if (y == 0)
                            {
                                break;
                            }
                        }

                        // SELECIONA A OPÇÃO DIGITADA.
                        if (y == 0)
                        {

                            // ALTERAR O PRODUTO.
                            if (op == 10)
                            {
                                printf("\nDigite o novo SKU para o novo produto: ");

                                // Limpar o BUFFER
                                setbuf(stdin, NULL);
                                scanf("[^\n]s", novoSKU);

                                if (pesquisaSKU(SKU, est) != 0)
                                {
                                    ped[j].est[i].ID = est[i].ID;
                                    strcpy(ped[j].est[i].nome, est[i].nome);
                                    strcpy(ped[j].est[i].SKU, est[i].SKU);
                                    strcpy(ped[j].est[i].nicho, est[i].nicho);
                                    strcpy(ped[j].est[i].cor, est[i].cor);

                                    // Passa Custo & Preço
                                    ped[j].est[i].custo = est[i].custo * ped[j].est[i].qtd;
                                    ped[j].est[i].preco = est[i].preco * ped[j].est[i].qtd;

                                    // Gera Custo & Preço
                                    for (x = 1; x <= 10; x++)
                                    {
                                        // Função que retorna o INDICE do SKU.
                                        i = pesquisaSKU(ped[j].pedidoSKU[x], est);

                                        custo1 = ped[j].est[i].custo;
                                        preco1 = ped[j].est[i].preco;

                                        custo = custo1 + custo;
                                        preco = preco1 + preco;
                                    }

                                    ped[j].custo = custo;
                                    ped[j].preco = preco;

                                    printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                                }

                                else
                                    printf("\nERRO! Produto não cadastrado no estoque...");
                            }

                            // ALTERAR A QUANTIDADE.
                            if (op == 11)
                            {
                                printf("\nDigite a nova Quantidade: ");

                                // Limpar o BUFFER
                                setbuf(stdin, NULL);
                                scanf("%d", &qtd);

                                // Atualiza quantidade no pedido.
                                ped[j].est[i].qtd = qtd;

                                // Atualiza quantidade na struct.
                                est[i].qtd = est[i].qtd - qtd;

                                printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                            }
                        }

                        else
                            printf("ERRO! Produto não consta no pedido...");
                    }

                    else
                        printf("\nERRO! Produto não cadastrado no estoque...");
                }

                // SAIR
                if (op == 12)
                {
                    break;
                }
            }

            else
                break;

            mostraPed(j, i, ped, est);
        }

        printf("\nDeseja fazer outra consulta?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op1);
    }
}

//============================ FUNÇÕES DE CLIENTE =================================

//-------------------- Busca CPF no arquivo Cadastro -----------------------------
// finalizar implementação e fazer testes.
int buscaCPF(char cpf[], Cad cad[])
{
    // Dados da função.
    int i;

    for (i = 1; i < 100; i++)
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
void cadastroCli(struct Cad cad[])
{
    int op = 0;
    int i;

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

    // Fazer Verificação do ID.
    // Fazer criação automática do ID.

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
                printf("\nDigite o seu Nome: ");
                scanf("%[^\n]s", nome);
                // \copiando da variável para o item da struct.
                strcpy(cad[i].nome, nome);

                setbuf(stdin, NULL);
                printf("\nDigite sua data de nascimento: ");
                scanf("%[^\n]s", idade);
                // copiando da variável para o item da struct.
                strcpy(cad[i].idade, idade);

                setbuf(stdin, NULL);
                printf("\nDigite seu CPF (APENAS NUMEROS): ");
                scanf("%[^\n]s", cpf);
                // copiando da variável para o item da struct.
                strcpy(cad[i].cpf, cpf);

                setbuf(stdin, NULL);
                printf("\nDigite seu Telefone p/ Contato (APENAS NUMEROS): ");
                scanf("%[^\n]s", telefone);
                // copiando da variável para o item da struct.
                strcpy(cad[i].telefone, telefone);

                setbuf(stdin, NULL);
                printf("\nDigite o Genero que se indentifica!\n");
                printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
                printf("\nDigite a sua opcao: ");
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

                printf("\nDigite o estado (UF): ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", uf);
                // Copia a variável para a struct.
                strcpy(cad[i].uf, uf);

                // Mostra todos os itens digitados na tela.
                printf("\nNome: %s\n", cad[i].nome);
                printf("Idade: %s\n", cad[i].idade);
                printf("CPF: %s\n", cad[i].cpf);
                printf("Telefone: %s\n", cad[i].telefone);
                printf("Genero: %s\n", cad[i].gen);
                printf("Logradouro: %s\n", cad[i].log);
                printf("Bairro: %s\n", cad[i].bairro);
                printf("Cidade: %s\n", cad[i].cidade);
                printf("Estado: %s\n", cad[i].uf);

                // Por fim, mostra o ID do cliente cadastrado.
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

//-------------------- Funcao que altera dados do Cliente --------------------------
void alteraCli(struct Cad cad[])
{
    char CPF[30];
    int x = 0, i;
    int op = 1;

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
        if (op == 2)
            break;

        if (op == 1)
        {

            printf("\nDigite o CPF do cliente: \n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", CPF);

            i = buscaCPF(CPF, cad);
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
                printf("\n\tCPF INVALIDO!\n");
        }

        printf("\nDeseja realizar outra consulta?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
    }
}

//-------------------- Funcao que consulta Clientes no sistema -------------------
void consultaCli(struct Cad cad[])
{
    // Dados Função
    int op;
    int i;
    char cpf[30];

    while (1)
    {
        printf("\nO que voce deseja?");
        printf("\n1- Buscar Cliente por CPF");
        printf("\n2- Mostrar Todos os clientes");
        printf("\n\n9- SAIR\n");

        printf("\nDigite a opcao desejada: ");

        scanf("%d", &op);

        // Busca pelo CPF cadastrado
        if (op == 1)
        {
            printf("\n\t\tOPCAO SELECIONADA: Buscar por CPF.\n");
            printf("\nDigite o CPF desejado: ");

            setbuf(stdin, NULL);
            scanf("%[^\n]s", cpf);

            i = buscaCPF(cpf, cad);

            if (i != 0)
            {
                printf("\nNome: %s\n", cad[i].nome);
                printf("Idade: %s\n", cad[i].idade);
                printf("CPF: %s\n", cad[i].cpf);
                printf("Telefone: %s\n", cad[i].telefone);
                printf("Genero: %s\n", cad[i].gen);
                printf("Logradouro: %s\n", cad[i].log);
                printf("Bairro: %s\n", cad[i].bairro);
                printf("Cidade: %s\n", cad[i].cidade);
                printf("Estado: %s\n", cad[i].uf);
                printf("\nId: #%d\n", cad[i].ID);

                break;
            }

            else
            {
                printf("\nCPF NAO CADASTRADO!");
                break;
            }
        }

        // Mostra TODOS os clientes existentes
        if (op == 2)
        {
            for (i = 1; i <= 100; i++)
            {
                if (cad[i].ID == i)
                {
                    printf("\nNome: %s\n", cad[i].nome);
                    printf("Idade: %s\n", cad[i].idade);
                    printf("CPF: %s\n", cad[i].cpf);
                    printf("Telefone: %s\n", cad[i].telefone);
                    printf("Genero: %s\n", cad[i].gen);
                    printf("Logradouro: %s\n", cad[i].log);
                    printf("Bairro: %s\n", cad[i].bairro);
                    printf("Cidade: %s\n", cad[i].cidade);
                    printf("Estado: %s\n", cad[i].uf);
                    printf("\nId: #%d\n", cad[i].ID);
                }

                else
                    continue;
            }

            break;
        }

        if (op == 9)
            break;

        else
            printf("OPCAO DESCONHECIDA! Vamos tentar denovo...");
    }
}

void menu()
{
    int opcao = 0;

    struct Cad P[100];
    struct Est E[100];
    struct Ped T[100];

    // FAZER FUNÇÕES QUE GERAM ID's AUTOMATICAMENTE.
    // ARMAZENAR TUDO.
    // CARREGAR TUDO.

    // carregaArq(P, E, T);

    while (1)
    {
        printf("\n\nBem vindo ao Sistema Gestão de Pedidos");
        printf("\n1- Cadastrar Cliente");      // Feito
        printf("\n2- Alterar Cliente");        // Feito
        printf("\n3- Consultar Clientes");     // Feito
        printf("\n4- Cadastrar novo Produto"); // Feito
        printf("\n5- Alterar Produto");        // Feito
        printf("\n6- Consultar Produtos");     // Feito
        printf("\n7- Criar novo Pedido");      // Feito
        printf("\n8- Alterar Pedido");         // ANDAMENTO - CORRIGIR FINAL
        printf("\n9- Mostrar Todos Pedidos");

        printf("\n10- Sair ");

        printf("\nDigite opção: ");
        scanf("%d", &opcao);

        if (opcao == 1)
            cadastroCli(P);

        if (opcao == 2)
            alteraCli(P);

        if (opcao == 3)
            consultaCli(P);

        if (opcao == 4)
            cadastroProd(E);

        if (opcao == 5)
            alteraProd(E);

        if (opcao == 6)
            consultaProd(E);

        if (opcao == 7)
            criaPed(E, T, P);

        if (opcao == 8)
            alteraPed(E, T);

        // if (opcao == 9)
        //     mostraPed(P);

        if (opcao == 10)
        {
            // salvaArq(P, E, T);
            return;
        }
    }
}

int main()
{
    menu();
}
