#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "lista.h"

#define MAX_LINHA 100

typedef struct {
    ListaTexto* linhas;
    Pilha* pilhaDesfazer;
    Pilha* pilhaRefazer;
} Texto;

Texto criarTexto() {
    Texto texto;
    texto.linhas = criar_lista();
    texto.pilhaDesfazer = criar(); //Cria pilha
    texto.pilhaRefazer = criar(); //Cria pilha
    return texto;
}

// Adiciona uma linha no final do texto
void adicionarLinha(Texto* texto, char* linha) {
    LinhaTexto novaLinha;
    novaLinha.numeroLinha = tamanho_lista(texto->linhas);
    strcpy(novaLinha.conteudoLinha, linha);
    insere_inicio(texto->linhas, novaLinha);
    empilhar(texto->pilhaDesfazer, 'A', novaLinha.numeroLinha);
}


// Edita a linha especificada pelo número da linha
void editarLinha(Texto* texto, int numeroLinha, char* linha) {
    LinhaTexto aux;
    aux.numeroLinha = numeroLinha;
    strcpy(aux.conteudoLinha, linha);
    insere_inicio(texto->linhas, aux);
    empilhar(texto->pilhaDesfazer, 'E', aux.numeroLinha);
}


// Deleta a linha especificada pelo número da linha
void deletarLinha(Texto* texto, int numeroLinha) {
    int i;
    LinhaTexto aux;

    aux.numeroLinha = numeroLinha;
    strcpy(aux.conteudoLinha, texto->linhas->dados[numeroLinha].conteudoLinha);
    desempilhar(texto->pilhaDesfazer, NULL, NULL);
    insere_inicio(texto->linhas, aux);

    for (i = numeroLinha + 1; i < tamanho_lista(texto->linhas); i++) {
        strcpy(texto->linhas->dados[i - 1].conteudoLinha, texto->linhas->dados[i].conteudoLinha);
    }

    texto->linhas->qtd--;
}

// Mostra o texto completo, enumerando as linhas
void mostrarTexto(Texto* texto) {
    int i;
    for (i = 0; i < tamanho_lista(texto->linhas); i++) {
        printf("%d: %s\n", i, texto->linhas->dados[i].conteudoLinha);
    }
}

// Desfaz a última operação realizada no texto
void desfazer(Texto* texto) {
    char operacao;
    int numeroLinha;
    char linha[MAX_LINHA];

    desempilhar(texto->pilhaDesfazer, &operacao, &numeroLinha);

    if (operacao == 'A') {
        deletarLinha(texto, numeroLinha);
        empilhar(texto->pilhaRefazer, 'A', &numeroLinha);
    } else if (operacao == 'E') {
        deletarLinha(texto, numeroLinha);
        empilhar(texto->pilhaRefazer, 'E', texto->linhas->dados[numeroLinha].conteudoLinha);
    }
}

// Refaz a última operação desfeita no texto
void refazer(Texto* texto) {
    char operacao;
    int numeroLinha;
    char linha[MAX_LINHA];

    desempilhar(texto->pilhaRefazer, &operacao, &numeroLinha);

    if (operacao == 'A') {
        adicionarLinha(texto, linha);
        empilhar(texto->pilhaDesfazer, 'A', numeroLinha);
    } else if (operacao == 'E') {
        editarLinha(texto, numeroLinha, linha);
        empilhar(texto->pilhaDesfazer, 'E', numeroLinha);
    }
}

// Salva o texto em um arquivo
void salvarTextoEmArquivo(Texto* texto, char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    int i;
    for (i = 0; i < tamanho_lista(texto->linhas); i++) {
        fputs(texto->linhas->dados[i].conteudoLinha, arquivo);
        fputc('\n', arquivo);
    }

    fclose(arquivo);
}

int main() {
    Texto texto = criarTexto();

    int opcao;
    char linha[MAX_LINHA];
    int numeroLinha;

    do {
        printf("\n1 - Adicionar linha\n");
        printf("2 - Editar linha\n");
        printf("3 - Deletar linha\n");
        printf("4 - Desfazer\n");
        printf("5 - Refazer\n");
        printf("6 - Mostrar texto\n");
        printf("7 - Salvar em arquivo\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a linha a ser adicionada: ");
                scanf(" %[^\n]", linha);
                adicionarLinha(&texto, linha);
                break;
            case 2:
                printf("Digite o numero da linha a ser editada: ");
                scanf("%d", &numeroLinha);
                printf("Digite a nova linha: ");
                scanf(" %[^\n]", linha);
                editarLinha(&texto, numeroLinha, linha);
                break;
            case 3:
                printf("Digite o numero da linha a ser deletada: ");
                scanf("%d", &numeroLinha);
                deletarLinha(&texto, numeroLinha);
                break;
            case 4:
                desfazer(&texto);
                break;
            case 5:
                refazer(&texto);
                break;
            case 6:
                mostrarTexto(&texto);
                break;
            case 7:
                printf("Digite o nome do arquivo: ");
                scanf(" %[^\n]", linha);
                salvarTextoEmArquivo(&texto, linha);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    liberar_lista(texto.linhas);
    destruir_pilha(texto.pilhaDesfazer);
    destruir_pilha(texto.pilhaRefazer);

    return 0;
}
