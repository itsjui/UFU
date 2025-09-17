#include <stdio.h>
#include <string.h>

// Definindo a struct para armazenar informações de uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declarando e inicializando uma variável do tipo struct Pessoa
    struct Pessoa p1;

    // Atribuindo valores aos membros da struct
    strcpy(p1.nome, "João Silva");
    p1.idade = 30;
    p1.altura = 1.75;

    // Exibindo as informações armazenadas na struct
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Altura: %.2f metros\n", p1.altura);

    return 0;
}
