#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

ListaTexto* criar_lista() {
    ListaTexto* li;
    li = (ListaTexto*)malloc(sizeof(ListaTexto));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

void liberar_lista(ListaTexto* li) {
    free(li);
}

int tamanho_lista(ListaTexto* li) {
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(ListaTexto* li) {
    if (li == NULL)
        return -1;
    else {
        return li->qtd == MAXL;
    }
}

int insere_inicio(ListaTexto* li, LinhaTexto aux) {
    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0;
    int i;
    for (i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];

    li->dados[0] = aux;
    li->qtd++;
    return 1;
}
