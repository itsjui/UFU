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
    float custo;
    float preco;

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
    float custo;
    float preco;

    // ID
    int ID;
};

//-------------------- Struct base Pedidos -------------------------------
struct Ped
{
    // Indices para pedido.
    int cadID;
    int numped;
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
    char ProdID[30];
    char SKU[30];
    char nicho[30];
    char cor[30];
    int qtd;

    // VALORES
    float custo;
    float preco;
    float soma;
    float custo1;
    float preco1;

    // Passando a struct para mais de um produto
    struct Est est[100];

    // Produtos a serem utilizados
    int ped;
};
//-------------------- Struct auxiliar Pedidos ---------------------------
struct auxPed
{
    // Indices para pedido.
    int cadID;
    int numped;
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
    char ProdID[30];
    char SKU[30];
    char nicho[30];
    char cor[30];
    int qtd;

    // VALORES
    float custo;
    float preco;
    float custo1;
    float preco1;

    // Passando a struct para mais de um produto
    struct Est est[100];

    // Produtos a serem utilizados
    int ped;
};

// ============== FUNÇÕES DE ARQUIVO ==============
//-------------------- FUNNCAO QUE CARREGA DADOS DOS ARQUIVOS ---------------
void carregaArq(struct auxCad pes, struct auxEst prod, struct auxPed ped, struct Cad C[], struct Est E[], struct Ped T[])
{
    int i;
    int j;
    int loc;
    int x = 10;

    for (j = 0; j <= 100; j++)
    {
        C[j].ID = 0;
        E[j].ID = 0;
        T[j].numped = 0;
    }

    // CLIENTES
    FILE *clientes = fopen("clientes.bin", "rb");

    i = 1;
    while (fread(&pes, sizeof(struct auxCad), 1, clientes))
    {
        // ID
        C[i].ID = pes.ID;

        // DADOS CLIENTE
        strcpy(C[i].nome, pes.nome);
        strcpy(C[i].idade, pes.idade);
        strcpy(C[i].cpf, pes.cpf);
        strcpy(C[i].telefone, pes.telefone);
        strcpy(C[i].gen, pes.gen);

        // DADOS ENDEREÇO
        strcpy(C[i].log, pes.log);
        strcpy(C[i].bairro, pes.bairro);
        strcpy(C[i].cidade, pes.cidade);
        strcpy(C[i].uf, pes.uf);

        i++;
    }
    fclose(clientes);

    // PRODUTOS
    FILE *produtos = fopen("produtos.bin", "rb");

    i = 1;
    while (fread(&prod, sizeof(struct auxEst), 1, produtos))
    {
        // ID
        E[i].ID = prod.ID;

        // DADOS PRODUTO
        strcpy(E[i].nome, prod.nome);
        strcpy(E[i].SKU, prod.SKU);
        strcpy(E[i].nicho, prod.nicho);
        strcpy(E[i].cor, prod.cor);
        E[i].qtd = prod.qtd;
        E[i].custo = prod.custo;
        E[i].preco = prod.preco;

        i++;
    }
    fclose(produtos);

    // PEDIDOS
    FILE *pedidos = fopen("pedidos.bin", "rb");

    i = 1;
    while (fread(&ped, sizeof(struct auxPed), 1, pedidos))
    {
        // INDICES
        T[i].cadID = ped.cadID;
        T[i].numped = ped.numped;
        T[i].qtd = ped.qtd;
        T[i].loc = ped.loc;

        // DADOS CLIENTES
        strcpy(T[i].nomeCad, ped.nomeCad);
        strcpy(T[i].idade, ped.idade);
        strcpy(T[i].cpf, ped.cpf);
        strcpy(T[i].telefone, ped.telefone);
        strcpy(T[i].gen, ped.gen);

        // DADOS ENDEREÇOS
        strcpy(T[i].log, ped.log);
        strcpy(T[i].bairro, ped.bairro);
        strcpy(T[i].cidade, ped.cidade);
        strcpy(T[i].uf, ped.uf);

        // DADOS PRODUTOS
        strcpy(T[i].nomeProd, ped.nomeProd);
        strcpy(T[i].SKU, ped.SKU);
        strcpy(T[i].nicho, ped.nicho);
        strcpy(T[i].cor, ped.cor);
        T[i].custo1 = ped.custo1;
        T[i].preco1 = ped.preco1;

        T[i].custo = ped.custo;
        T[i].preco = ped.preco;

        i++;
    }
    fclose(pedidos);
}

//-------------------- FUNNCAO QUE SALVA DADOS NOS ARQUIVOS ---------------
int salvaArq(struct Cad C[], struct Est E[], struct Ped T[])
{
    int i = 1;

    remove("clientes.bin");
    remove("produtos.bin");
    remove("pedidos.bin");

    // CLIENTES
    FILE *clientes = fopen("clientes.bin", "ab");
    i = 1;
    while (1)
    {
        if (i == 100)
        {
            printf("\n\t\tFim da escrita de CLIENTES!");
            break;
        }
        fwrite(&C[i], sizeof(struct Cad), 1, clientes);
        i++;
    }
    fclose(clientes);

    // PRODUTOS
    FILE *produtos = fopen("produtos.bin", "ab");
    i = 1;
    while (1)
    {
        if (i == 100)
        {
            printf("\n\t\tFim da escrita de PRODUTOS!");
            break;
        }
        fwrite(&E[i], sizeof(struct Est), 1, produtos);
        i++;
    }
    fclose(produtos);

    // PEDIDOS
    FILE *pedidos = fopen("pedidos.bin", "ab");
    i = 1;
    while (1)
    {
        if (i == 100)
        {
            printf("\n\t\tFim da escrita de PEDIDOS!");
            break;
        }
        fwrite(&T[i], sizeof(struct Ped), 1, pedidos);
        i++;
    }
    fclose(pedidos);
}

// ============== FUNÇÕES DE PRODUTO ==============

int geraNumProd(struct Est est[])
{
    int i;

    // verifica se existe posição.
    for (i = 1; i <= 100; i++)
    {
        if (est[i].ID == 0)
        {
            est[i].ID = i;
            break;
        }
    }
    return i;
}

//-------------------- Funcao de CADASTRAR produto ------------
void cadastroProd(struct Est est[])
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

    // SALVA ARQUIVOS PRODUTOS
    FILE *produtos = fopen("produtos.bin", "ab");

    while (1)
    {
        if (op == 2)
            break;
        else
        {
            while (1)
            {

                // Verifica SKU
                printf("\nDigite o SKU do produto: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", SKU);

                if (pesquisaSKU(SKU, est) != 0)
                {
                    printf("\n\n\tERRO! SKU JA CADASTRADO!");

                    // CASO EXISTA MANDA RETURN!
                    return;
                }

                else
                {

                    i = geraNumProd(est);

                    printf("ID: %d\n", i);
                    est[i].ID = i;
                    // Passando o id para a struct.

                    printf("Cadastrar produto\n");

                    printf("\nDigite o nome do produto: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", nome);

                    // copiando da variavel até a struct
                    strcpy(est[i].SKU, SKU);
                    strcpy(est[i].nome, nome);

                    // copiando da variavel até a struct

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

                    printf("\nDigite o preco do produto: R$");
                    scanf("%f", &preco);

                    // copiando da variavel até a struct
                    est[i].preco = preco;

                    printf("\nNome: %s\n", est[i].nome);
                    printf("SKU: %s\n", est[i].SKU);
                    printf("Nicho: %s\n", est[i].nicho);
                    printf("Cor: %s\n", est[i].cor);
                    printf("Quantidade: %d\n", est[i].qtd);
                    printf("Custo: R$%.2f\n", est[i].custo);
                    printf("Preco: R$%.2f\n", est[i].preco);
                }

                break;
            }
        }

        fwrite(&est[i], sizeof(struct Est), 1, produtos);
        fclose(produtos);

        // VERIFICAÇÃO
        printf("\nDeseja cadastrar outro Produto?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
    }
}

//-------------------- Funcao de ALTERAR produto ------------
void alteraProd(struct Est est[])
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
                    printf("\nDigite o preco do produto: R$");
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

    for (j = 1; j < 100; j++)
    {
        if (strcmp(s, est[j].SKU) == 0)
        {
            printf("\nEncontrado produto ID: #%d", j);

            // PRODUTO JA EXISTE
            return j;
        }
    }

    // PRODUTO NÃO EXISTE
    return 0;
}

//-------------------- FUNÇÃO QUE CONSULTA PRPODUTOS ---------------
void consultaProd(struct Est est[])
{

    // Dados Função
    int op;
    int op1;
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

        printf("\n\nFazer nova consulta?");
        printf("\n1- Buscar produto por SKU");
        printf("\n2- Mostrar Todos os produtos");
        printf("\n\n9- SAIR\n");
        printf("\nDigite a opcao desejada: ");

        scanf("%d", &op);
    }
}

//============================ FUNÇÕES DE PEDIDO =============================

//------------------- FUNCAO GERA NUMERO DE PEDIDO --------------------
int geraNumPed(struct Ped ped[])
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
int buscaPed(int numped, struct Ped ped[])
{
    int i;

    // Busca id pelo for rodando pelo STRUCT
    for (i = 1; i <= 100; i++)
    {
        // RETORNA O NUMERO  DO PEDIDO
        if (ped[numped].numped == i)
            return i;
    }

    return 0;
}

//------------------- FUNCAO GERA PEDIDO DE FATO --------------------
void geraPed(int qtd, int loc, int i, int j, int ID, struct Est est[], struct Ped ped[], struct Cad cad[])
{
    // Utilizada no laço For para preenchimento dos
    // dados de vários produtos.
    int x = 0;

    // CUSTO & PREÇO
    float custo = 0;
    float preco = 0;
    float custo1 = 0;
    float preco1 = 0;

    FILE *pedidos = fopen("pedidos.bin", "ab");

    if (pedidos == NULL)
        printf("\n\t\tERRO AO CARREGAR ARQUIVO!\n");

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
    // Coleta realizada pelas SKU's Armazenadas no pedido.
    printf("SKU: %s | ID: %d\n", ped[ID].SKU, j);

    // Copia dado selecionado pra cada posição
    //  de cada produto.
    strcpy(ped[ID].nomeProd, est[j].nome);
    strcpy(ped[ID].SKU, est[j].SKU);

    // TESTE DA PASSADA
    printf("\n\t\tSKU: %s\n", ped[ID].SKU);
    strcpy(ped[ID].nicho, est[j].nicho);
    strcpy(ped[ID].cor, est[j].cor);

    // GERA CUSTO & PREÇO
    // FAZER OS DEVIDOS TESTE
    custo = est[j].custo * qtd;
    preco = est[j].preco * ped[ID].qtd;

    ped[ID].custo = custo;
    ped[ID].preco = preco;

    // MOSTRANDO TODO O PEDIDO NA TELA.
    printf("\n\t\tNumero do Pedido: #%d\n", ped[ID].numped);
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
    printf("\n\n\t\tNome do Produto:  %s", ped[ID].nomeProd);
    printf("\n\t\tSKU:  %s", ped[ID].SKU);
    printf("\n\t\tNicho:  %s", ped[ID].nicho);
    printf("\n\t\tCor:  %s", ped[ID].cor);

    printf("\n\t\tQuantidade:  %d", ped[ID].qtd);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Valores ---------------");

    printf("\n\t\tCusto:  R$%.2f", ped[ID].custo);
    printf("\n\t\tPreco:  R$%.2f", ped[ID].preco);

    // ESCREVE NO ARQUIVO
    fwrite(&ped[ID], sizeof(struct Ped), 1, pedidos);
    fclose(pedidos);
}

//------------------- FUNCAO MOSTRA PEDIDO --------------------
void mostraPed(int ID, struct Ped ped[])
{

    // MOSTRANDO TODO O PEDIDO NA TELA.
    printf("\n\n\n\t\tNumero do Pedido: %d\n", ped[ID].numped);
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
    printf("\n\t\t---- Dados do Produto ----");

    // MOSTRA A SEÇÃO PRODUTOS DA MANEIRA CORRETA.
    printf("\n\n\t\tNome do Produto:  %s", ped[ID].nomeProd);
    printf("\n\t\tSKU:  %s", ped[ID].SKU);
    printf("\n\t\tNicho:  %s", ped[ID].nicho);
    printf("\n\t\tCor:  %s", ped[ID].cor);

    printf("\n\t\tQuantidade:  %d", ped[ID].qtd);

    printf("\n\t\t--------------------------------");
    printf("\n\t\t-------- Valores ---------------");

    printf("\n\t\tCusto:  R$%.2f", ped[ID].custo);
    printf("\n\t\tPreco:  R$%.2f", ped[ID].preco);
}

//------------------- FUNCAO MOSTRA PEDIDO --------------------
void mostraPed1(struct Ped ped[])
{
    int op;
    int ID = 0;
    int i = 0;

    printf("\nDigite a opcao: ");
    printf("\n1 - ID: ");
    printf("\n2- Mostrar todos: ");
    scanf("%d", &op);

    if (op == 1)
    {
        printf("\nDigite o ID do pedido: ");
        scanf("%d", &ID);

        printf("\n\t\tDETALHES DO PEDIDO #%d", ID);
        mostraPed(ID, ped);
        return;

    }

    if(op == 2){
        printf("\n\t\tDETALHES DO PEDIDO");

        for(i = 1; i<=100; i++){
            if(buscaPed(i, ped) == i){
                mostraPed(i, ped);
            }
        }
        return;

    }
}

//-------------------- FUNCAO CRIA NOVO PEDIDO --------------------------
void criaPed(struct Est est[], struct Ped ped[], struct Cad cad[])
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

    // SALVA ARQUIVOS PEDIDOS.
    FILE *pedidos = fopen("pedidos.bin", "ab");

    // Gera numero do pedido de acordo com
    // a existencia de pedido na própria struct
    while (1)
    {
        if (op == 2)
            break;

        if (op == 1)
        {
            ID = geraNumPed(ped);
            ped[ID].numped = ID;

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

            while (1)
            {
                printf("\n\nDigite o SKU do produto: ");

                // Limpa Buffer.
                setbuf(stdin, NULL);

                // Captura o SKU e passa para a struct.
                // ped[ID].pedidoSKU[aux] -> Variável que recebe multiplos SKU.
                scanf("%[^\n]", ped[ID].SKU);

                j = pesquisaSKU(ped[ID].SKU, est); // Retorna o ID do produto.
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
                                ped[ID].qtd = qtd;
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
                    printf("\nPRODUTO NAO LOCALIZADO!\n");

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

            // ESCREVE NO ARQUIVO
            fwrite(&ped[ID], sizeof(struct Ped), 1, pedidos);
            fclose(pedidos);
        }

        printf("\n\t\tGerando pedido...\n\n");
        geraPed(qtd, loc, i, j, ID, est, ped, cad);

        // PERGUNTA DE VERIFICAÇÃO.
        printf("\n\nDeseja fazer outro pedido?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");

        scanf("%d", &op);
    }
}

//-------------------- FUNCAO ALTERA PEDIDO --------------------------
void alteraPed(struct Est est[], struct Ped ped[])
{
    // Variaveis OP.
    int op = 0;
    int op1 = 1;
    int numped = 0;
    int j = 0;
    int i = 0;
    int x = 0;
    int y;
    int aux;
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

                // Endereço
                printf("\n6- Logradouro");
                printf("\n7 - Bairro.");
                printf("\n8 - Cidade.");
                printf("\n9 - Estado.");

                printf("\n10 - Quantidade.\n");

                printf("\nDigite a sua opcao: ");
                setbuf(stdin, NULL);
                scanf("%d", &op);

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
                if (op == 10)
                {
                    printf("\nDigite o SKU DO PRODUTO no pedido: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]s", SKU);
                    // RETRONA ID DO PRODUTO
                    i = pesquisaSKU(SKU, est);

                    // VERIFICA SE CONSTA PRODUTO NO ESTOQUE
                    if (i != 0)
                    {

                        // VERIFICA SE CONSTA PRODUTO NO PEDIDO
                        for (x = 1; x <= 100; x++)
                        {
                            y = strcmp(SKU, ped[j].SKU);
                            if (y == 0)
                            {
                                break;
                            }
                        }

                        // SELECIONA A OPÇÃO DIGITADA.
                        if (y == 0)
                        {
                            // ALTERAR A QUANTIDADE.
                            if (op == 10)
                            {
                                printf("\nDigite a nova Quantidade: ");

                                // Limpar o BUFFER
                                setbuf(stdin, NULL);
                                scanf("%d", &qtd);

                                // SOMA A QUANTIDADE ANTERIOR.
                                est[i].qtd = est[i].qtd + ped[j].qtd;

                                // Atualiza quantidade no pedido.
                                ped[j].qtd = qtd;
                                ped[j].preco = 0;
                                ped[j].custo = 0;

                                // QUANTIDADE ATUALIZADA
                                est[i].qtd = est[i].qtd - qtd;

                                // VALORES
                                preco = qtd * est[i].preco;
                                custo = qtd * est[i].custo;

                                // STRUCT ATUALIZADA
                                ped[j].preco = preco;
                                ped[j].custo = custo;

                                printf("\nPEDIDO ALTERADO COM SUCESSO!\n");
                            }
                        }

                        else
                            printf("ERRO! Produto nao consta no pedido...");
                    }

                    else
                        printf("\nERRO! Produto nao cadastrado no estoque...");
                }

                // SAIR
                if (op == 12)
                {
                    break;
                }
            }

            else
                break;

            mostraPed(j, ped);
        }

        printf("\nDeseja fazer outra consulta?");
        printf("\n1- SIM");
        printf("\n2- NAO");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op1);
    }
}

//=========================== FUNÇÕES DE CLIENTE =================================

int geraNumCad(struct Cad cad[])
{
    int i;

    // verifica se existe posição.
    for (i = 1; i < 100; i++)
    {
        if (cad[i].ID == 0)
        {
            cad[i].ID = i;
            break;
        }
    }
    return i;
}

//-------------------- Busca CPF no arquivo Cadastro -----------------------------
// finalizar implementação e fazer testes.
int buscaCPF(char cpf[], struct Cad cad[])
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
int buscaID(struct Cad P[], int ID)
{
    int i;

    // printf("\nDigite o ID: ");
    // scanf("%d", &ID);

    for (i = 1; i < 100; i++)
    {
        if (ID == P[i].ID)
        {
            printf("\nI = %d | ID = %d", i, P[i].ID);
            return i;
        }
    }

    return 0;
}

//-------------------- Funcao Cadastra Cliente ------------------------------------
void cadastroCli(struct Cad cad[])
{
    int op = 0;
    int i = 0;

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

    // SALVA ARQUIVOS CLIENTES.
    FILE *clientes = fopen("clientes.bin", "ab");

    // Fazer Verificação do ID.
    // Fazer criação automática do ID.

    while (1)
    {
        if (op == 2)
            break;

        else
        {
            while (1)
            {
                // printf("\nDigite o ID do novo cliente: ");
                // scanf("%d", &i);

                i = geraNumCad(cad);
                cad[i].ID = i;

                printf("ID: #%d\n", i);

                printf("Ok, vamos fazer o seu cadastro!\n");

                printf("\nDigite o seu Nome: ");

                setbuf(stdin, NULL);
                scanf("%[^\n]s", nome);
                // \copiando da variável para o item da struct.
                strcpy(cad[i].nome, nome);

                printf("\nDigite seu CPF (APENAS NUMEROS): ");

                setbuf(stdin, NULL);
                scanf("%[^\n]s", cpf);
                // copiando da variável para o item da struct.
                strcpy(cad[i].cpf, cpf);

                printf("\nDigite sua Idade: ");

                setbuf(stdin, NULL);
                scanf("%[^\n]s", idade);
                // copiando da variável para o item da struct.
                strcpy(cad[i].idade, idade);

                printf("\nDigite seu Telefone p/ Contato (APENAS NUMEROS): ");

                setbuf(stdin, NULL);
                scanf("%[^\n]s", telefone);
                // copiando da variável para o item da struct.
                strcpy(cad[i].telefone, telefone);

                printf("\nDigite o Genero que se indentifica!\n");
                printf("\nF-Feminino\nM-Masculino\nB-Nao Binario\nO-Outros.\n");
                printf("\nDigite a sua opcao: ");

                setbuf(stdin, NULL);
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
                printf("\nID: %d | i: %d\n", cad[i].ID, i);

                break;
            }
        }

        fwrite(&cad[i], sizeof(struct Cad), 1, clientes);
        fclose(clientes);

        // VERIFICAÇÃO
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
    int verifica = 0;

    while (1)
    {
        printf("\nO que voce deseja?");
        printf("\n1- Buscar Cliente por CPF");
        // printf("\n2- Mostrar Todos os clientes");
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

            // MOSTRANDO DADOS
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

            break;
        }

        // Sair da FUNÇÃO
        if (op == 9)
            break;

        else
        {
            printf("\nOPCAO DESCONHECIDA! Vamos tentar denovo...");
        }
    }
}

int soma(struct Est est[]){
    int i;
    int aux = 0;
    char nicho[30];
    printf("Digite o nicho do produto: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", nicho);

    for(i=1; i<100; i++ ){
        if (strcmp(est[i].nicho, nicho) == 0)
        aux = (est[i].custo * est[i].qtd) + aux;        
    }
    printf("\nA soma de todos os custos: R$ %d", aux);

    return 0;
}

void menu()
{
    int opcao = 0;
    int ID = 0;

    struct Cad P[100];
    struct Est E[100];
    struct Ped T[100];

    struct auxCad pes;
    struct auxCad pes1[100];
    struct auxEst prod;
    struct auxPed ped;

    carregaArq(pes, prod, ped, P, E, T);

    while (1)
    {
        printf("\n\nBem vindo ao Sistema Gestao de Pedidos");
        printf("\n1- Cadastrar Cliente");
        printf("\n2- Alterar Cliente");
        printf("\n3- Consultar Clientes");
        printf("\n4- Cadastrar novo Produto");
        printf("\n5- Alterar Produto");
        printf("\n6- Consultar Produtos");
        printf("\n7- Criar novo Pedido");
        printf("\n8- Alterar Pedido");
        printf("\n9- Exibir Pedido");
        printf("\n11- Mostra total");

        printf("\n\n10- Sair ");

        printf("\nDigite opcao: ");
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

        if (opcao == 9)
            mostraPed1(T);
        
        if (opcao == 11)
            soma(E);

        if (opcao == 10)
        {
            salvaArq(P, E, T);
            printf("\n\n\t\tSaindo...");
            break;
        }
    }
}

int main()
{
    menu();
}
