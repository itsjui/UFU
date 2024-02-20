#include <stdlib.h> // malloc, free, exit
#include <stdio.h>  // printf, scanf
#include "pilha.h"

Pilha* criar()
{
    Pilha* p;

    p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL)
        p->topo = -1;

    return p;
}

void destruir(Pilha *p)
{
    if (p != NULL) free(p);

}

int vazia(Pilha *p)
{
    if (p->topo == -1) // a pilha esta vazia
        return 1;   // 1 == true
    else return 0;  // 0 == false
}

int cheia(Pilha *p)
{
    if (p->topo == MAXP-1) // a pilha esta cheia
        return 1;   // 1 == true
    else return 0;  // 0 == false
}

void empilhar(Pilha *p, char x)
{
    if (cheia(p) == 1)
        return 0;
    else {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = x;
        return 1;
    }
}

void desempilhar(Pilha *p, char *x)
{
    if (vazia(p) == 1)
        return 0;
    else {
        *x = p->elementos[p->topo];
        p->topo = p->topo - 1;
        return 1;
    }
}
