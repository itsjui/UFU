//questão 1//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[30], cidade[30];
    int idade;
    float altura;
    int peso;
    int CPF;
    int telefone;
};


// Não vai ser direcionado para cadastrar pois não tem a função cadastro incluída.

// Função que mostrar todos os cadastrados com base no telefone
void mostrar_telefone(int total_cadastrados, struct pessoa cadastrados[]){
    char nome_aux[30];
    printf("\nTodos cadastrados.\n\n");

    for(int i=0;i<total_cadastrados;i++){
        printf("\n\nNome:%s", cadastrados[i].nome);
        printf("Cidade:%s", cadastrados[i].cidade);
        printf("Idade:%i", cadastrados[i].idade);
        printf("Telefone:%i", cadastrados[i].telefone);
        }
    }

// Função que mostrar todos os cadastrados com base no telefone
void mostrar_cpf(int total_cadastrados, struct pessoa cadastrados[]){
    char nome_aux[30];
    printf("\nTodos cadastrados.\n\n");

    for(int i=0;i<total_cadastrados;i++){
        printf("\n\nNome:%s", cadastrados[i].nome);
        printf("Cidade:%s", cadastrados[i].cidade);
        printf("Idade:%i", cadastrados[i].idade);
        printf("CPF:%i", cadastrados[i].CPF);
    }
}


void cadastro(struct pessoa T[]){
    //inserir código aqui
}



void menu(){
    int opcao;
    int total_cadastros = 0;
    struct pessoa P[30];

    while(1){
        printf("\nBem vindo ao Sistema de... ");
        printf("\n1- Cadastrar ");
        printf("\n2- Mostrar cadastros com base no Telefone");
        printf("\n3- Mostrar cadastros com base no CPF");
        printf("\n9- Sair ");
        printf("\nDigite opção: ");
        scanf("%d", &opcao);

        if(opcao == 1) cadastro(P);
        if(opcao == 2) mostrar_telefone(total_cadastros, P);
        if(opcao == 3) mostrar_cpf(total_cadastros, P);
        if(opcao == 9) return;
    }
}

int main(){
  menu();
  return 0;
}

