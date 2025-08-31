#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "grafo.h"

#define AUMENTO 1.5

typedef struct Aresta {
    int dest;
    float peso;
    struct Aresta* prox;
} Aresta;

typedef struct Vertice {
    char* label;
    Aresta* inicio;
} Vertice;

struct Grafo {
    int numVertices;
    int numArestas;
    int capacidade;
    int ehDigrafo;
    Vertice* vertices;
};

Grafo* criaGrafo(int capacidadeInicial, int ehDigrafo) {
    Grafo* g = malloc(sizeof(Grafo));
    if (!g) return NULL;

    g->vertices = malloc(sizeof(Vertice) * capacidadeInicial);
    if (!g->vertices) {
        free(g);
        return NULL;
    }

    g->numVertices = 0;
    g->numArestas = 0;
    g->capacidade = capacidadeInicial;
    g->ehDigrafo = ehDigrafo;
    return g;
}

void liberaGrafo(Grafo* g) {
    if (!g) return;
    for (int i = 0; i < g->numVertices; i++) {
        Aresta* atual = g->vertices[i].inicio;
        while (atual) {
            Aresta* tmp = atual;
            atual = atual->prox;
            free(tmp);
        }
        free(g->vertices[i].label);
    }
    free(g->vertices);
    free(g);
}

int insereVertice(Grafo* g, const char* label) {
    if (!g || !label) return 0;

    if (g->numVertices >= g->capacidade) {
        int novaCapacidade = (int)(g->capacidade * AUMENTO);
        Vertice* temp = realloc(g->vertices, novaCapacidade * sizeof(Vertice));
        if (!temp) return 0;
        g->vertices = temp;
        g->capacidade = novaCapacidade;
    }

    g->vertices[g->numVertices].label = strdup(label);
    g->vertices[g->numVertices].inicio = NULL;
    return g->numVertices++;
}

int insereAresta(Grafo* g, int u, int v, float w) {
    if (!g || u >= g->numVertices || v >= g->numVertices) return 0;

    Aresta* nova = malloc(sizeof(Aresta));
    if (!nova) return 0;
    nova->dest = v;
    nova->peso = w;
    nova->prox = g->vertices[u].inicio;
    g->vertices[u].inicio = nova;
    g->numArestas++;

    if (!g->ehDigrafo) {
        Aresta* nova2 = malloc(sizeof(Aresta));
        if (!nova2) return 0;
        nova2->dest = u;
        nova2->peso = w;
        nova2->prox = g->vertices[v].inicio;
        g->vertices[v].inicio = nova2;
        g->numArestas++;
    }

    return 1;
}

int removeAresta(Grafo* g, int u, int v) {
    if (!g || u >= g->numVertices || v >= g->numVertices) return 0;

    Aresta** a = &g->vertices[u].inicio;
    while (*a) {
        if ((*a)->dest == v) {
            Aresta* temp = *a;
            *a = (*a)->prox;
            free(temp);
            g->numArestas--;
            break;
        }
        a = &(*a)->prox;
    }

    if (!g->ehDigrafo) {
        a = &g->vertices[v].inicio;
        while (*a) {
            if ((*a)->dest == u) {
                Aresta* temp = *a;
                *a = (*a)->prox;
                free(temp);
                g->numArestas--;
                break;
            }
            a = &(*a)->prox;
        }
    }

    return 1;
}

int grau(Grafo* g, int v) {
    if (!g || v >= g->numVertices) return -1;
    int cont = 0;
    for (Aresta* a = g->vertices[v].inicio; a; a = a->prox) cont++;
    return cont;
}

double grauMedio(Grafo* g) {
    if (!g || g->numVertices == 0) return -1;
    double soma = 0;
    for (int i = 0; i < g->numVertices; i++) {
        soma += grau(g, i);
    }
    return soma / g->numVertices;
}

int grauMax(Grafo* g, int* v) {
    if (!g || g->numVertices == 0) return -1;
    int max = -1;
    for (int i = 0; i < g->numVertices; i++) {
        int gAtual = grau(g, i);
        if (gAtual > max) {
            max = gAtual;
            if (v) *v = i;
        }
    }
    return max;
}

int carregarGrafoDeArquivo(Grafo* g, const char* caminho) {
    FILE* arq = fopen(caminho, "r");
    if (!arq){
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {
        int u, v;
        float w = 1.0;
        int n = sscanf(linha, "%d %d %f", &u, &v, &w);
        if (n >= 2) {
            while (u >= g->numVertices) insereVertice(g, "");
            while (v >= g->numVertices) insereVertice(g, "");
            insereAresta(g, u, v, w);
        }
    }
    fclose(arq);
    return 1;
}

const char* obtemLabel(Grafo* g, int v) {
    if (!g || v < 0 || v >= g->numVertices) return NULL;
    return g->vertices[v].label;
}

float menorCaminhoMedio(Grafo* gr) {
    if (gr == NULL || gr->numVertices == 0) return -1;
    int n = gr->numVertices;
    float soma = 0;
    int pares = 0;

    float* dist = (float*)malloc(n * sizeof(float));
    int* visitado = (int*)malloc(n * sizeof(int));

    for (int orig = 0; orig < n; orig++) {
        for (int i = 0; i < n; i++) {
            dist[i] = FLT_MAX;
            visitado[i] = 0;
        }
        dist[orig] = 0;

        for (int count = 0; count < n; count++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!visitado[i] && (u == -1 || dist[i] < dist[u])) u = i;
            }
            if (u == -1 || dist[u] == FLT_MAX) break;
            visitado[u] = 1;

            Aresta* a = gr->vertices[u].inicio;
            while (a != NULL) {
                if (dist[a->dest] > dist[u] + a->peso)
                    dist[a->dest] = dist[u] + a->peso;
                a = a->prox;
            }
        }

        for (int j = 0; j < n; j++) {
            if (j != orig && dist[j] < FLT_MAX) {
                soma += dist[j];
                pares++;
            }
        }
    }
    free(dist);
    free(visitado);
    return pares > 0 ? soma / pares : -1;
}
float assortatividade(Grafo* gr) {
    if (gr == NULL || gr->numVertices == 0) return -1;

    int m = 0;
    int* grausU = (int*)malloc(sizeof(int) * gr->numVertices * gr->numVertices);
    int* grausV = (int*)malloc(sizeof(int) * gr->numVertices * gr->numVertices);

    for (int u = 0; u < gr->numVertices; u++) {
        Aresta* a = gr->vertices[u].inicio;
        while (a != NULL) {
            int v = a->dest;
            if (gr->ehDigrafo || u < v) {
                grausU[m] = grau(gr, u);
                grausV[m] = grau(gr, v);
                m++;
            }
            a = a->prox;
        }
    }

    float somaU = 0, somaV = 0, somaUU = 0, somaVV = 0, somaUV = 0;
    for (int i = 0; i < m; i++) {
        somaU += grausU[i];
        somaV += grausV[i];
        somaUV += grausU[i] * grausV[i];
        somaUU += grausU[i] * grausU[i];
        somaVV += grausV[i] * grausV[i];
    }

    float num = m * somaUV - somaU * somaV;
    float den = sqrt((m * somaUU - somaU * somaU) * (m * somaVV - somaV * somaV));

    free(grausU);
    free(grausV);
    return den == 0 ? 0 : num / den;
}
