#include <stdlib.h>
#include <stdio.h>

#define MAX 10

/*                IMPORTANTE!

  - Em todas as funções que retornam int, considerar:

  - 0 = false
  - 1 = true

  - Ao longo do projeto, será utilizado o padrão de camelCase

*/

// ---------------------------- TAD Pilha ---------------------------------------

// Registro da pilha
struct pilha
{
    int topo;
    int elementos[MAX][MAX];
};

typedef struct pilha Pilha;

// Função para criar a pilha
Pilha *criar(int *deuCerto)
{
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));

    if (p == NULL)
        *deuCerto = 0;
    else
    {
        p->topo = -1;
        *deuCerto = 1;
    }

    return p;
}

// Função para destruir a pilha
void destruir(Pilha *p)
{
    if (p != NULL)
        free(p);
}

// Função para verificar se a pilha está vazia
int vazia(Pilha *p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

// Função para verificar se a pilha está cheia
int cheia(Pilha *p)
{
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

// Função para empilhar um elemento
void empilhar(Pilha *p, int x, int *deuCerto)
{
    if (cheia(p))
        *deuCerto = 0;
    else
    {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = x;
        *deuCerto = 1;
    }
}

// Função para desempilhar um elemento
void desempilhar(Pilha *p, char *x, int *deuCerto)
{
    if (vazia(p))
        *deuCerto = 0;
    else
    {
        *x = p->elementos[p->topo];
        p->topo = p->topo - 1;
        *deuCerto = 1;
    }
}
void montagrafo(Pilha *p, int valor, int v, int a)
{   
        scanf("%d", &v);
        scanf("%d", &a);
        for (int i = 0; i < v; i++)
        {
            for(int j = 0; j < a; j++){
            if (p->elementos[i][j] == 0)
            {
                p->elementos[i][j] = valor;
            }
        }
    }
}
int main()
{
    Pilha *p;
    int DeuCerto, v, a;
    char c;

    p = criar(&DeuCerto);
    if (DeuCerto == 0)
    { // tratar o erro aqui...
        printf("Nao foi possivel criar a pilha");
        exit(1);
    }
    scanf("%d", &v);
    scanf("%d", &a);

    empilhar(p, 'a', &DeuCerto);
    empilhar(p, 'b', &DeuCerto);
    empilhar(p, 'c', &DeuCerto);
    empilhar(p, 'd', &DeuCerto);
    empilhar(p, 'e', &DeuCerto);
    empilhar(p, 'f', &DeuCerto);
    empilhar(p, 'g', &DeuCerto);
    empilhar(p, 'h', &DeuCerto);
    empilhar(p, 'i', &DeuCerto);
    empilhar(p, 'j', &DeuCerto);
    desempilhar(p, &c, &DeuCerto);
    empilhar(p, 'k', &DeuCerto);

    if (cheia(p) == 1)
        printf("pilha cheia\n");

    desempilhar(p, &c, &DeuCerto);
    printf("   %c\n", c);

    destruir(p);

    return 0;
}