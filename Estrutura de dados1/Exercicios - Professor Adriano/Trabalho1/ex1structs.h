#include <stdio.h>
#include <stdlib.h>
#define MAX [10]

typedef struct fila
{
  int elemento[MAX];
  int inicio, fim;
};

typedef struct Produto
{
  char codigo;
  char nome;
  int fila[MAX];
}

void cria_fila(fila *p);
int insere_fila(fila*,  Produto elemento);
int remove_elemento(fila *p);
