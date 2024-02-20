#include <stdio.h>
#include <string.h>

// Definindo uma estrutura para armazenar as informações dos jogadores
typedef struct {
    char nome[50];
    char posicao[20];
    char clube[50];
    int idade;
} Jogador;

// Inicializando alguns jogadores da seleção brasileira
Jogador jogadores[4] = {
    {"Alisson", "goleiro", "Liverpool", 28},
    {"Marquinhos", "zagueiro", "Paris Saint-Germain", 26},
    {"Casemiro", "meio-campista", "Real Madrid", 29},
    {"Neymar Jr.", "atacante", "Paris Saint-Germain", 29}
};

int main() {
    printf("Pense em um jogador da selecao brasileira e responda as perguntas a seguir:\n\n");

    char resposta[10];
    char nome_jogador[50];
    int i;

    // Perguntando sobre a posição do jogador
    printf("Qual a posicao do jogador? (goleiro, zagueiro, lateral, meio-campista, atacante)\n");
    scanf("%s", resposta);

    for (i = 0; i < 4; i++) {
        if (strcmp(jogadores[i].posicao, resposta) == 0) {
            strcpy(nome_jogador, jogadores[i].nome);
            break;
        }
    }

    // Perguntando sobre o clube do jogador
    printf("O jogador joga em algum time brasileiro ou estrangeiro? (digite o nome do clube ou 'nenhum')\n");
    scanf("%s", resposta);

    if (strcmp(resposta, "nenhum") != 0) {
        for (i = 0; i < 4; i++) {
            if (strcmp(jogadores[i].clube, resposta) == 0) {
                strcpy(nome_jogador, jogadores[i].nome);
                break;
            }
        }
    }

    // Perguntando sobre as habilidades do jogador
    printf("O jogador eh habilidoso em chutes de longa distancia ou mais em passes e jogadas individuais? (chutes, passes, ambos)\n");
    scanf("%s", resposta);

    if (strcmp(resposta, "chutes") == 0) {
        if (strcmp(nome_jogador, "Neymar Jr.") != 0) {
            strcpy(nome_jogador, jogadores[3].nome);
        }
    } else if (strcmp(resposta, "passes") == 0) {
        if (strcmp(nome_jogador, "Casemiro") != 0) {
            strcpy(nome_jogador, jogadores[2].nome);
        }
    }

    // Perguntando sobre as habilidades defensivas do jogador
    printf("O jogador eh mais conhecido por suas habilidades defensivas? (sim, nao)\n");
    scanf("%s", resposta);

    if (strcmp(resposta, "sim") == 0) {
        if (strcmp(nome_jogador, "Neymar Jr.") != 0) {
            strcpy(nome_jogador, jogadores[1].nome);
        }
    }

    // Perguntando sobre a idade do jogador
    printf("O jogador eh experiente ou esta apenas com fome de bola?!");
    scanf("%s", resposta);

    if (strcmp(resposta, "experiente") == 0) {
    if (strcmp(nome_jogador, "Neymar Jr.") != 0) {
        strcpy(nome_jogador, jogadores[1].nome);
    }
} else if (strcmp(resposta, "jovem") == 0) {
    if (strcmp(nome_jogador, "Alisson") != 0) {
        strcpy(nome_jogador, jogadores[1].nome);
    }
}

// Imprimindo o nome do jogador
printf("O jogador que voce pensou eh o %s\n", nome_jogador);

return 0;
}
