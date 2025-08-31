#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    Grafo* g = criaGrafo(10000, 0);  // Capacidade grande e grafo não-direcionado

    if (!carregarGrafoDeArquivo(g, "univ.edges")) {
        printf("Erro ao carregar o grafo do arquivo.\n");
        liberaGrafo(g);
        return 1;
    }

    printf("Grafo carregado com sucesso!\n");
    printf("Numero de vertices: %d\n", grauMax(g, NULL));
    printf("Grau medio: %.2lf\n", grauMedio(g));
    printf("Menor caminho medio: %.2f\n", menorCaminhoMedio(g));
    printf("Assortatividade: %.2f\n", assortatividade(g));

    liberaGrafo(g);
    return 0;
}
