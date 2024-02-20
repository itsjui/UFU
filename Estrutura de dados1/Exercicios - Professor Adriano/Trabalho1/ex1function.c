#define ex1structs.h

void cria_fila(fila *p)
{
    p->inicio = p->fim = 0;
}
int insere_fila(fila*, Produto elemento)
{
    if (p->fim < MAX)
    {
        p->int elemento = p->fim;
    }
    else
    {
        printf("Fila cheia\n");
        return 0;
    }
}
int remove_elemento(fila *p)
{
    if (p->inicio == p->fim)
    {
        printf("fila vazia\n");
        return 0;
    }
    else
    {
        return p->elemento = p->inicio;
    }
}
