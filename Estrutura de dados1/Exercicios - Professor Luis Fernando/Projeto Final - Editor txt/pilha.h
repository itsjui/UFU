#ifndef PILHA_H
#define PILHA_H

#define MAXP 10 //Max da pilha

struct pilha {
    int topo;
    char elementos[MAXP];
};

typedef struct pilha Pilha;

Pilha* criar();
void destruir(Pilha* p);
int vazia(Pilha* p);
int cheia(Pilha* p);
void empilhar(Pilha* p, char x, int* DeuCerto);
void desempilhar(Pilha* p, char* x, int* DeuCerto);

#endif