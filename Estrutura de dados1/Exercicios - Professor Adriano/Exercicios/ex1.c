// Lista de Exercícios 3
// Exercício 1
// Gabriel Pimentel Arantes - 12111BSI287

#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float media;
};

void imprimeAlunos(struct Aluno alunosCadastrados[10], int contador) {
    for (int i = 0; i < contador; ++i) {
        printf("Nome: %s\n", alunosCadastrados[i].nome);
        printf("Idade: %d\n", alunosCadastrados[i].idade);
        printf("Media: %.2f\n\n", alunosCadastrados[i].media);
    }
};

int main() {

    struct Aluno alunos[10];
    int opcao, contador = 0;

    printf("Insira os dados de ate 10 alunos\n");

    for (int i = 0; i < 10; ++i) {

        printf("Digite o nome do aluno:");
        scanf("%s", &alunos[i].nome);
        printf("Digite a idade do aluno:");
        scanf("%d", &alunos[i].idade);
        printf("Digite o media do aluno:");
        scanf("%f", &alunos[i].media);
        contador++;

        printf("Deseja adicionar mais um aluno?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &opcao);

        if (opcao == 2) {
            break;
        }

    }

    printf("\nLista de alunos:\n");

    imprimeAlunos(alunos, contador);

    return 0;
}
