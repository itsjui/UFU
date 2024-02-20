#ifndef LISTA_H
#define LISTA_H

#define MAXL 100 //Max da lista

typedef struct {
    int numeroLinha;
    char conteudoLinha[100];
} LinhaTexto;

typedef struct {
    int qtd;
    LinhaTexto dados[MAXL];
} ListaTexto;

ListaTexto* criar_lista();
void liberar_lista(ListaTexto* li);
int tamanho_lista(ListaTexto* li);
int lista_cheia(ListaTexto* li);
int insere_inicio(ListaTexto* li, LinhaTexto aux);

#endif