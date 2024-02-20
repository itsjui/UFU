#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int p; 
  char nome[30];
  char SKU[30];
  char nicho[30];
  int qtd;
  char cor [30];
  float custo, preco;

}Prod;


int main(){  
    
  Prod prod;

  while(1){
  printf("Cadastrar produto\n");

  printf("\nDigite o nome do produto:\n");
  scanf("%[^\n]s", prod.nome);
 
  printf("\nDigite o SKU do produto:\n");
  scanf("%s", prod.SKU);

  printf("\nDigite o nicho do produto: \n");
  scanf("%s", prod.nicho);

  printf("\nDigite a cor do produto: \n");
  scanf("%s", prod.cor);

  printf("\nDigite a quantidade de produtos no estoque: \n");
  scanf("%d", &prod.qtd);

  printf("\nDigite o custo do produto: \nR$");
  scanf("%f", &prod.custo);

  printf("\nDigite o preço do produto: \nR$");
  scanf("%f", &prod.preco);

  printf("\nNome: %s\n", prod.nome);
  printf("SKU: %s\n", prod.SKU);
  printf("Nicho: %s\n", prod.nicho);
  printf("Cor: %s\n", prod.cor);
  printf("Quantidade: %d\n", prod.qtd);
  printf("Custo: R$%f\n", prod.custo);
  printf("Preço: R$%f\n", prod.preco);

    
  break;  
  }

  printf("\n Tudo certo? \n");
  printf("Corrigir dados - 1 \n");
  //printf("Deseja cadastrar outro produto? - 2\n");//
  printf("Continuar - 2\n");
  scanf("%d", &prod.p);

  if(prod.p == 1) return main();
  if(prod.p == 2) return 0;
}