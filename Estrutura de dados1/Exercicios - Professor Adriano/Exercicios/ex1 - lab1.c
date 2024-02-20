#include<stdio.h>

struct produto
{
    int codigo;
    float preco;
    int estoque;
    struct produto[];

}; typedef struct produto Produto;

void CadastraProd(int x, float y, int z, Produto){
    printf("Digite o codigo do produto: ");
    scanf("%d", &x.codigo);

    printf("Digite o preco do produto: ");
    scanf("%d", &y.preco);

    printf("Digite o estoque do produto: ");
    scanf("%d", &z.estoque);

    return Produto;
}



