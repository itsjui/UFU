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
struct pilha {
    int topo;
    int elementos[MAX];
};

typedef struct pilha Pilha;

// Função para criar a pilha
Pilha* criar(int *deuCerto) {
    Pilha* p;
    p = (Pilha*) malloc(sizeof(Pilha));

    if (p == NULL)
      *deuCerto = 0;
    else {
        p->topo = -1;
        *deuCerto = 1;
    }

    return p;
}

// Função para destruir a pilha
void destruir(Pilha *p) {
    if (p != NULL) free(p);
}

// Função para verificar se a pilha está vazia
int vazia(Pilha *p) {
    if (p->topo == -1)
        return 1;
    else
      return 0;
}

// Função para verificar se a pilha está cheia
int cheia(Pilha *p) {
    if (p->topo == MAX-1)
        return 1;
    else
      return 0;
}

// Função para empilhar um elemento
void empilhar(Pilha *p, int x, int *deuCerto) {
    if (cheia(p))
        *deuCerto = 0;
    else {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = x;
        *deuCerto = 1;
    }
}

// Função para desempilhar um elemento
void desempilhar(Pilha *p, char *x, int *deuCerto) {
    if (vazia(p))
        *deuCerto = 0;
    else {
        *x = p->elementos[p->topo];
        p->topo = p->topo - 1;
        *deuCerto = 1;
    }
}

// --------------------------- Funções extras ----------------------------------

// Função para zerar o grafo
void zera_grafo(int n, int matriz[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }
}

// --------------------------- Usuário do TAD ----------------------------------

int main() {
    Pilha *pilha;
    int qtd_linha, contador, grafo[qtd_linha][qtd_linha], linha, coluna, custo, posInicial, posFinal, deuCerto;

    pilha = criar(&deuCerto);

    zera_grafo(qtd_linha, grafo);

    if (deuCerto) {
        scanf("%d", &qtd_linha);
        scanf("%d", &contador);
        for (int i = 0; i < contador; i++) {
            scanf("%d %d %d", &linha, &coluna, &custo);
            if (linha && coluna && custo)
                grafo[linha][coluna] = custo;
        }
        scanf("%d %d", &posInicial, &posFinal);

        for (int i = 0; i < qtd_linha; i++) {
            for (int j = 0; j < qtd_linha; j++) {
                printf("%d  ", grafo[i][j]);
                if (grafo[i][j] != 0)
                    empilhar(pilha, grafo[i][j], &deuCerto);
            }
            //puts("");
        }

        for (int a = 0; a < MAX; a++) {
            printf("%d ", pilha->elementos[a]);
        }
        puts("");

    }

    destruir(pilha);

    return 0;
}