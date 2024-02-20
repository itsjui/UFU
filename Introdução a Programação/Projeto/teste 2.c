#include <stdio.h>
#include <stdlib.h>
/* #include "grafo.h" */

int main(void)
{
    int v, a, i, j, peso;
    printf("Informe o numero de vertice: ");
    scanf("%d", &v);
    printf("Informe o numero de arestas: ");
    scanf("%d", &a);
    int tmp = a;
    int matriz[v][a];
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < a; j++)
        {
            matriz[i][j] = 0;
        }
    }
    for (i = 0; j < tmp; i++)
    {
        scanf("%d", &v);
        scanf("%d", &a);
        scanf("%d", &peso);
        matriz[i][j] = peso;
    }
    printf("\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}