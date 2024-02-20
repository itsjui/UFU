#include "lista.h"
#include <stdlib.h>

struct no {
    void* elemento;
    struct no* proximo;
};

struct lista {
    struct no* cabeca;
    int tamanho;
};

Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

void destruir_lista(Lista* lista) {
    while (lista->cabeca != NULL) {
        struct no* proximo_no = lista->cabeca->proximo;
        free(lista->cabeca);
        lista->cabeca = proximo_no;
    }
    free(lista);
}

void inserir_elemento(Lista* lista, int posicao, void* elemento) {
    if (posicao < 0 || posicao > lista->tamanho) {
        return;
    }
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->elemento = elemento;
    if (posicao == 0) {
        novo_no->proximo = lista->cabeca;
        lista->cabeca = novo_no;
    } else {
        struct no* no_anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            no_anterior = no_anterior->proximo;
        }
        novo_no->proximo = no_anterior->proximo;
        no_anterior->proximo = novo_no;
    }
    lista->tamanho++;
}

void remover_elemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return;
    }
    struct no* no_removido;
    if (posicao == 0) {
        no_removido = lista->cabeca;
        lista->cabeca = no_removido->proximo;
    } else {
        struct no* no_anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            no_anterior = no_anterior->proximo;
        }
        no_removido = no_anterior->proximo;
        no_anterior->proximo = no_removido->proximo;
    }
    free(no_removido);
    lista->tamanho--;
}

void* obter_elemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return NULL;
    }
    struct no* no_atual = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        no_atual = no_atual->proximo;
    }
    return no_atual->elemento;
}

int tamanho_lista(Lista* lista) {
    return lista->tamanho;
}
