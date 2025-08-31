#ifndef GRAFO_H
#define GRAFO_H

typedef struct Grafo Grafo;

Grafo* criaGrafo(int capacidadeInicial, int ehDigrafo);
void liberaGrafo(Grafo* g);
int insereVertice(Grafo* g, const char* label);
int insereAresta(Grafo* g, int u, int v, float w);
int removeAresta(Grafo* g, int u, int v);
int grau(Grafo* g, int v);
double grauMedio(Grafo* g);
int grauMax(Grafo* g, int* v);
int carregarGrafoDeArquivo(Grafo* g, const char* caminho);
const char* obtemLabel(Grafo* g, int v);
float menorCaminhoMedio(Grafo* g);
float assortatividade(Grafo* g);

#endif
