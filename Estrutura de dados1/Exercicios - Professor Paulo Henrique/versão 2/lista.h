#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista* criar_lista();
void destruir_lista(Lista* lista);
void inserir_elemento(Lista* lista, int posicao, void* elemento);
void remover_elemento(Lista* lista, int posicao);
void* obter_elemento(Lista* lista, int posicao);
int tamanho_lista(Lista* lista);

#endif
