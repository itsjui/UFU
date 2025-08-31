#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define MAX_ALTURA 256

// nó da árvore de Huffman
typedef struct Node {
    unsigned char ch;
    int freq;
    struct Node *esq, *dir;
} Node;

// lista simples para organizar os nós por frequência
typedef struct Lista {
    Node* no;
    struct Lista* prox;
} Lista;

// cria nó
Node* criaNo(unsigned char ch, int freq) {
    Node* no = (Node*) malloc(sizeof(Node));
    no->ch = ch;
    no->freq = freq;
    no->esq = no->dir = NULL;
    return no;
}

// insere ordenado por frequência
Lista* insereOrdenado(Lista* lista, Node* no) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->no = no;
    novo->prox = NULL;

    if (!lista || no->freq < lista->no->freq) {
        novo->prox = lista;
        return novo;
    }
    Lista* aux = lista;
    while (aux->prox && aux->prox->no->freq <= no->freq)
        aux = aux->prox;
    novo->prox = aux->prox;
    aux->prox = novo;
    return lista;
}

// monta a árvore de Huffman
Node* montaArvore(int freq[MAX]) {
    Lista* lista = NULL;
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0)
            lista = insereOrdenado(lista, criaNo((unsigned char)i, freq[i]));
    }

    while (lista && lista->prox) {
        Lista* l1 = lista;
        Lista* l2 = lista->prox;
        lista = l2->prox;

        Node* pai = criaNo('*', l1->no->freq + l2->no->freq);
        pai->esq = l1->no;
        pai->dir = l2->no;

        lista = insereOrdenado(lista, pai);

        free(l1);
        free(l2);
    }

    Node* raiz = lista->no;
    free(lista);
    return raiz;
}

// gera códigos de Huffman em tabela
void geraCodigos(Node* raiz, char* caminho, int topo, char tabela[MAX][MAX_ALTURA]) {
    if (raiz->esq) {
        caminho[topo] = '0';
        geraCodigos(raiz->esq, caminho, topo + 1, tabela);
    }
    if (raiz->dir) {
        caminho[topo] = '1';
        geraCodigos(raiz->dir, caminho, topo + 1, tabela);
    }
    if (!raiz->esq && !raiz->dir) {
        caminho[topo] = '\0';
        strcpy(tabela[raiz->ch], caminho);
    }
}

// compacta arquivo
void compactar(char* entrada, char* saida) {
    FILE* in = fopen(entrada, "rb");
    if (!in) { printf("Erro ao abrir arquivo.\n"); return; }

    int freq[MAX] = {0};
    int c;
    while ((c = fgetc(in)) != EOF) freq[c]++;
    rewind(in);

    Node* raiz = montaArvore(freq);

    char tabela[MAX][MAX_ALTURA] = {{0}};
    char codigo[MAX_ALTURA];
    geraCodigos(raiz, codigo, 0, tabela);

    FILE* out = fopen(saida, "wb");
    if (!out) { printf("Erro ao criar arquivo.\n"); return; }

    // salva as frequências
    fwrite(freq, sizeof(int), MAX, out);

    // escreve os bits
    unsigned char buffer = 0;
    int bits = 0;
    while ((c = fgetc(in)) != EOF) {
        char* code = tabela[c];
        for (int i = 0; code[i]; i++) {
            buffer <<= 1;
            if (code[i] == '1') buffer |= 1;
            bits++;
            if (bits == 8) {
                fputc(buffer, out);
                buffer = 0;
                bits = 0;
            }
        }
    }
    if (bits > 0) {
        buffer <<= (8 - bits);
        fputc(buffer, out);
    }

    fclose(in);
    fclose(out);
    printf("Arquivo compactado em %s\n", saida);
}

// descompacta arquivo
void descompactar(char* entrada, char* saida) {
    FILE* in = fopen(entrada, "rb");
    if (!in) { printf("Erro ao abrir arquivo.\n"); return; }

    int freq[MAX];
    fread(freq, sizeof(int), MAX, in);

    Node* raiz = montaArvore(freq);

    FILE* out = fopen(saida, "wb");
    if (!out) { printf("Erro ao criar arquivo.\n"); return; }

    int total = 0;
    for (int i = 0; i < MAX; i++) total += freq[i];

    Node* atual = raiz;
    int lidos = 0;
    int c;
    while ((c = fgetc(in)) != EOF && lidos < total) {
        for (int i = 7; i >= 0 && lidos < total; i--) {
            int bit = (c >> i) & 1;
            if (bit == 0) atual = atual->esq;
            else atual = atual->dir;
            if (!atual->esq && !atual->dir) {
                fputc(atual->ch, out);
                atual = raiz;
                lidos++;
            }
        }
    }

    fclose(in);
    fclose(out);
    printf("Arquivo descompactado em %s\n", saida);
}

// mostra tamanhos
void estatisticas(char* arq1, char* arq2) {
    FILE* f1 = fopen(arq1, "rb");
    FILE* f2 = fopen(arq2, "rb");
    if (!f1 || !f2) { printf("Erro ao abrir.\n"); return; }

    fseek(f1, 0, SEEK_END);
    fseek(f2, 0, SEEK_END);
    long s1 = ftell(f1);
    long s2 = ftell(f2);
    fclose(f1);
    fclose(f2);

    printf("Original: %ld bytes, Compactado: %ld bytes\n", s1, s2);
}

int main() {
    int op;
    char arq1[100], arq2[100];

    do {
        printf("\n1-Compactar\n2-Descompactar\n3-Estatisticas\n0-Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("Entrada: "); scanf("%s", arq1);
            printf("Saida: "); scanf("%s", arq2);
            compactar(arq1, arq2);
        } else if (op == 2) {
            printf("Compactado: "); scanf("%s", arq1);
            printf("Saida: "); scanf("%s", arq2);
            descompactar(arq1, arq2);
        } else if (op == 3) {
            printf("Original: "); scanf("%s", arq1);
            printf("Compactado: "); scanf("%s", arq2);
            estatisticas(arq1, arq2);
        }
    } while (op != 0);

    return 0;
}
