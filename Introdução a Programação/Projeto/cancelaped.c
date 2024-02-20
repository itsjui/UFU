#include<stdio.h>
#include<stdlib.h>

struct Ped
{
	int numped;
	int qtd;
	char log[30];
	char bairro[30];
	char cidade[30];
	char uf[5];
	char comp[30];
};

void cancelaPed (struct Ped ped, FILE *pedidos)
{
    int op, numped;

FILE *pedidos = fopen("pessoas.bin", "rb");

printf("Digite o numero do pedido: \n");
scanf("%d", &numped);


if(numped == ped.numped){
    while(1){    
    printf("Pedido encontrado!\n");
    printf("Confirmar cancelamento?\n1- Sim\n2- Não.");
    scanf("%d", &op);
    
    if(op == 1){ped.numped = NULL}

        else break;
    }
    
else{
    printf("Pedido não encontrado!\n");
    printf("Digite novamente o numero do pedido ou caso preferir digite 9 para retornar ao menu principal.\n");
    scanf("%d", &op);
if(op == 9) return (1);

}    
 fwrite(&ped, sizeof(Ped),1 pedidos);
 fclose(pedidos);
    
}