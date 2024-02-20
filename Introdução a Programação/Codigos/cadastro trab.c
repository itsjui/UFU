#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
  int o;
  int o1;
  char nome[30]; 
  char idade[30];
  char cpf[30];
  char cnpj[30];
  char telefone[30];
  char end[100];
  char gen[1];
}Cad;


int main(){  
  setlocale(LC_ALL, "Portuguese");
    
  Cad cad;

  while(1){
  printf("Ok, vamos fazer o seu cadastro!\n");

  printf("\nQual o seu Nome? \n");
  scanf("%[^\n]s", cad.nome);
 
  printf("\nQual sua data de nascimento?\n");
  scanf("%s[\n]", cad.idade);

  printf("\nVocê é CPF ou CNPJ? \n");
  printf("CPF - Digite 1 \n");
  printf("CNPJ - Digite 2 \n");
  scanf("%d", &cad.o);

  if(cad.o!=1 || cad.o!=2){
    while(1){
      printf("\nOpção desconhecida, por favor digite novamente.\n");
      scanf("%d", &cad.o);

      if(cad.o == 1 || cad.o == 2) break; 
      else continue; 
    }
  }
    
  if(cad.o == 1 || cad.o == 2){
   
    if(cad.o == 1){
    printf("\nDigite seu CPF: \n");
    scanf("%s[\n]", cad.cpf);
    
    printf("\nQual seu telefone para contato? \n");
    scanf("%s[\n]", cad.telefone);
  
    printf("\nQual seu endereço? \n");
    scanf("%[^\n]s", cad.end);
      
    printf("\nQual genero voce se identifica?\n");
    printf("F-Feminino\nM-Masculino\nB-Não Binario\nO-       Outros.\n");
    scanf("%s[\n]", cad.gen);  
  
      printf("\nNome: %s\n", cad.nome);
      printf("Idade: %s\n", cad.idade);
      printf("CPF: %s\n", cad.cpf);
      printf("Telefone: %s\n", cad.telefone);
      printf("Endereço: %s\n", cad.end);
      printf("Genero: %s\n", cad.gen);
    }
    
    if(cad.o == 2){  
    printf("Digite seu CNPJ: \n");
    scanf("%s[\n]", cad.cnpj);
    
    printf("Qual seu telefone para contato? \n");
    scanf("%s[\n]", cad.telefone);
  
    printf("Qual seu endereço? \n");
    scanf("%[^\n]s", cad.end);      
    
      printf("Nome: %s\n", cad.nome);
      printf("Idade: %s\n", cad.idade);
      printf("CNPJ: %s\n", cad.cnpj);
      printf("Telefone: %s\n", cad.telefone);
      printf("Endereço: %s\n", cad.end);
      }
    }
    
  break;  
  }

  printf("\n Tudo certo? \n");
  printf("Corrigir dados - 1 \n");
  printf("Continuar - 2 \n");
  scanf("%d", &cad.o1);

  if(cad.o1 == 1) return main();
  if(cad.o1 == 2) return 0;
  
}
