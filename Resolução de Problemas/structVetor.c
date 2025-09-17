#include <stdio.h>
#include <string.h>

// Definindo a struct para armazenar informações de uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declarando um vetor de 3 structs do tipo Pessoa
    struct Pessoa pessoas[3];

    // Preenchendo as informações para o primeiro elemento do vetor
    strcpy(pessoas[0].nome, "João Silva");
    pessoas[0].idade = 30;
    pessoas[0].altura = 1.75;

    // Preenchendo as informações para o segundo elemento do vetor
    strcpy(pessoas[1].nome, "Maria Souza");
    pessoas[1].idade = 25;
    pessoas[1].altura = 1.65;

    // Preenchendo as informações para o terceiro elemento do vetor
    strcpy(pessoas[2].nome, "Carlos Oliveira");
    pessoas[2].idade = 40;
    pessoas[2].altura = 1.80;

    // Exibindo as informações de todas as pessoas no vetor
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Altura: %.2f metros\n\n", pessoas[i].altura);
    }

    return 0;
}
