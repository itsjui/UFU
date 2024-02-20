// Lista de Exercícios 3
// Exercício 3
// Gabriel Pimentel Arantes - 12111BSI287

#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
};


void imprimeMenu() {
    printf("Bem vindo ao sistema de livros!\n");
    printf("Selecione a opcao desejada:\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Buscar Livro\n");
    printf("3. Listar Livros\n");
    printf("0. Sair\n");
}

void imprimeLivros(struct Livro livrosCadastrados[10], int contador) {
    for (int i = 0; i < contador; ++i) {
        printf("Titulo: %s\n", livrosCadastrados[i].titulo);
        printf("Autor: %s\n", livrosCadastrados[i].autor);
        printf("Ano publiocado: %d\n\n", livrosCadastrados[i].anoPublicacao);
    }
};

int main() {

    struct Livro livros[5];
    int opcao, contador = 0;
    char tituloDigitado[100];

    do {
        imprimeMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                opcao = 0;
                printf("Insira os dados de ate 5 livros\n");
                for (int i = 0; i < 5; ++i) {

                    printf("Digite o titulo do livro:");
                    scanf("%s", &livros[i].titulo);
                    printf("Digite a autor do livro:");
                    scanf("%s", &livros[i].autor);
                    printf("Digite o ano de publicacao do livro:");
                    scanf("%d", &livros[i].anoPublicacao);
                    contador++;

                    if (contador == 5) {
                        printf("Limite máximo de livro atingido");
                        break;
                    }

                    printf("\nDeseja adicionar mais um livro?\n");
                    printf("1. Sim\n");
                    printf("2. Nao\n");
                    scanf("%d", &opcao);

                    if (opcao == 2) {
                        break;
                    }
                }
                break;

            case 2:
                printf("Insira o titulo do livro:");
                scanf("%s", tituloDigitado);

                for (int i = 0; i < 5; ++i) {
                    if (strcmp(tituloDigitado, livros[i].titulo) == 0) {
                        printf("Livro encontrado!\n");
                        printf("Titulo: %s\n", livros[i].titulo);
                        printf("Autor: %s\n", livros[i].autor);
                        printf("Ano publicado: %d\n\n", livros[i].anoPublicacao);
                        break;
                    } else {
                        printf("Livro nao encontrado.");
                        break;
                    }
                }
                break;

            case 3:
                printf("\nLista de livros:\n");
                imprimeLivros(livros, contador);
                break;

            default:
                printf("Opcao invalida.");
        }
    } while (opcao != 0);

    return 0;
}
