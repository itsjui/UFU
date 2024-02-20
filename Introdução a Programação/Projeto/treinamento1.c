#include<stdio.h>
#include<stdlib.h>

int main(){
  int nome;
  float salario, vendas, x, soma_total;

  printf("Nome: \n");
  scanf("%d", &nome);
  printf("Salario: \n");
  scanf("%f", &salario);
  printf("total de vendas acumuladas: \n");
  scanf("%f", &vendas);

  x = vendas - 15%;
  soma_total = x + salario;

  printf("Total = R$%2lf\n", soma_total);
  
return 0;
}