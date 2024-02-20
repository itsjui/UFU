#include "pilha.h"
#include <stdlib.h>

struct no {
    void* elemento;
    struct no* proximo;
};

struct pilha {
    struct no* topo;
    int tamanho;
};

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void destruir_pilha(Pilha* pilha) {
    while (!pilha_vazia(pilha)) {
        pop(pilha);
    }
    free(pilha);
}

void push(Pilha* pilha, void* elemento) {
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->elemento = elemento;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
    pilha->tamanho++;
}

void* pop(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        return NULL;
    }
    struct no* no_removido = pilha->topo;
    void* elemento = no_removido->elemento;
    pilha->topo = no_removido->proximo;
    free(no_removido);
    pilha->tamanho--;
    return elemento;
}

void* top(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        return NULL;
    }
    return pilha->topo->elemento;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int tamanho_pilha(Pilha* pilha) {
    return pilha->tamanho;
}
