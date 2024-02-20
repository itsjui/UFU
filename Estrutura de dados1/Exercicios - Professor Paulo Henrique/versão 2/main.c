#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

typedef struct {
    int linha;
    char* texto;
} LinhaTexto;

void editar_linha(Lista* texto, Pilha* pilha_desfazer, int linha, char* novo_texto) {
    if (linha >= 0 && linha < tamanho_lista(texto)) {
        LinhaTexto* linha_atual = (LinhaTexto*)obter_elemento(texto, linha);
        push(pilha_desfazer, linha_atual);
        linha_atual->texto = novo_texto;
    }
}

void desfazer(Pilha* pilha_desfazer, Pilha* pilha_refazer, Lista* texto) {
    if (!pilha_vazia(pilha_desfazer)) {
        LinhaTexto* linha_atual = (LinhaTexto*)pop(pilha_desfazer);
        push(pilha_refazer, linha_atual);
        // Restaurar o texto original
        editar_linha(texto, NULL, linha_atual->linha, linha_atual->texto);
    }
}

void refazer(Pilha* pilha_desfazer, Pilha* pilha_refazer, Lista* texto) {
    if (!pilha_vazia(pilha_refazer)) {
        LinhaTexto* linha_atual = (LinhaTexto*)pop(pilha_refazer);
        push(pilha_desfazer, linha_atual);
        // Restaurar o texto atualizado
        editar_linha(texto, NULL, linha_atual->linha, linha_atual->texto);
    }
}

void exibir_menu() {
    printf("===== Editor de Texto =====\n");
    printf("1. Editar linha\n");
    printf("2. Desfazer\n");
    printf("3. Refazer\n");
    printf("4. Sair\n");
    printf("===========================\n");
}

int ler_opcao() {
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    Lista* texto = criar_lista();
    Pilha* pilha_desfazer = criar_pilha();
    Pilha* pilha_refazer = criar_pilha();

    int opcao = 0;

    while (opcao != 4) {
        exibir_menu();
        printf("Escolha uma opção: ");
        opcao = ler_opcao();

        switch (opcao) {
            case 1: {
                int linha;
                char novo_texto[100];

                printf("Informe o número da linha: ");
                scanf("%d", &linha);
                getchar();

                printf("Digite o novo texto: ");
                fgets(novo_texto, sizeof(novo_texto), stdin);
                novo_texto[strcspn(novo_texto, "\n")] = '\0'; // Remover o caractere de nova linha

                editar_linha(texto, pilha_desfazer, linha - 1, novo_texto);
                printf("Linha editada com sucesso.\n");
                break;
            }
            case 2: {
                desfazer(pilha_desfazer, pilha_refazer, texto);
                printf("Ação desfeita.\n");
                break;
            }
            case 3: {
                refazer(pilha_desfazer, pilha_refazer, texto);
                printf("Ação refeita.\n");
                break;
            }
            case 4:
                printf("Encerrando o editor de texto.\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }

        printf("\n");
    }

    // Limpeza de memória
    destruir_lista(texto);
    destruir_pilha(pilha_desfazer);
    destruir_pilha(pilha_refazer);

    return 0;
}
