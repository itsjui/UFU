#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int q;
  char SKU[30];
  char cor[30];
  char nicho[30];
  int qtd;

} Est;

int main() {

  Est est;

  while (1) {
    printf("Estoque de produto\n");

    printf("\nDigite o SKU:\n");
    scanf("%s", est.SKU);

    printf("\nDigite a cor: \n");
    scanf("%s", est.cor);

    printf("\nDigite a quantidade: \n");
    scanf("%d", &est.qtd);

    printf("\nDigite o nicho: \n");
    scanf("%s", est.nicho);

    printf("SKU: %s\n", est.SKU);
    printf("Nicho: %s\n", est.nicho);
    printf("Cor: %s\n", est.cor);
    printf("Quantidade: %d\n", est.qtd);

    break;
  }

  printf("\n Tudo certo? \n");
  printf("Corrigir dados - 1 \n");
  // printf("Deseja cadastrar outro produto? - 2\n");//
  printf("Continuar - 2\n");
  scanf("%d", &est.q);

  if (est.q == 1)
    return main();
  if (est.q == 2)
    return 0;
}