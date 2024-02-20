#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* criar_pilha();
void destruir_pilha(Pilha* pilha);
void push(Pilha* pilha, void* elemento);
void* pop(Pilha* pilha);
void* top(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
int tamanho_pilha(Pilha* pilha);

#endif
