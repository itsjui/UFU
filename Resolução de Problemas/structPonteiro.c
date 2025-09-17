#include <stdio.h>
#include <string.h>

// Definindo a struct para armazenar informações de uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declarando uma variável do tipo struct Pessoa
    struct Pessoa pessoa1;

    // Declarando um ponteiro para struct Pessoa
    struct Pessoa *ponteiro;

    // Atribuindo o endereço de p1 ao ponteiro ptr
    ponteiro = &pessoa1;

    // Usando o ponteiro para atribuir valores aos membros da struct
    strcpy(ponteiro->nome, "João Silva");
    ponteiro->idade = 30;
    ponteiro->altura = 1.75;

    // Exibindo as informações usando o ponteiro
    printf("Nome: %s\n", ponteiro->nome);
    printf("Idade: %d\n", ponteiro->idade);
    printf("Altura: %.2f metros\n", ponteiro->altura);

    return 0;
}
