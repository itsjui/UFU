//Acompanhar entrega: 
//1 - Acompanhar remessa.
//2 - Alterar endereço.
//3 - Cancelar remessa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct de endereço//
typedef struct{
  int numped;
  char log[30];
  char bairro[30];
  char cidade [30];
  char uf[5];
  char comp[30];
}End;

int main(){

  int op, op1, numped;
  End endereco;

  printf("Selecione a opção desejada:\n");
  printf("\n1- Acompanhar remessa\n");
  printf("2- Alterar Endereço\n");
  printf("3- Cancelar remessa\n");

  scanf("%d", &op);

  if(op == 1){
    while(1){
      printf("\nSelecionado: Acompanhar remessa\n");
      
      printf("\nDigite o número do pedido: ");
      scanf("%d", &numped);
  
      if(numped == endereco.numped){
        /*
          Realizar consulta com ponteiro do pedido.
        */
        printf("Deu bom!\n");

        printf("Pressione 1 para finalizar consulta: ");
        scanf("%d", &op1);        
        
        if(op1 == 1) break; 
        
        break;    
    
      }
  
      else{
        printf("\nPedido não encotrado!\n");
        printf("Vamos tentar novamente...\n");
        continue;
      } 
    }
  }
  
  if(op == 2){
    while(1){

      printf("\nSelecionado: Alterar endereco\n");
      
      printf("\nDigite o número do pedido: ");
      scanf("%d", &numped);
      
      if(numped == endereco.numped){
        printf("\nLogradouro: \n");
        fflush(stdin);
        scanf("%[^\n]s", endereco.log);
        
        printf("Bairro: \n");
        fflush(stdin);
        scanf("%[^\n]s", endereco.bairro);
        
        printf("Cidade: \n");
        fflush(stdin);
        scanf("%[^\n]s", endereco.cidade);
       
        printf("UF: \n");
        fflush(stdin);
        scanf("%[^\n]s", endereco.uf);

        printf("Selecione uma opcao: \n");
        printf("1 - Corrigir dados. \n");
        printf("2 - Finalizar alteracao. \n");
        scanf("%d", &op1);        
        
        if(op1 == 1) continue; 
        if(op1 == 2) break; 
      }


      
      else{
        printf("\nLogradouro: \n");
        setbuf(stdin, NULL)
        gets(endereco.log);
        
        printf("Bairro: \n");
        setbuf(stdin, NULL)
        gets(endereco.bairro);
        
        printf("Cidade: \n");
        setbuf(stdin, NULL)
        gets(endereco.cidade);
       
        printf("UF: \n");
        setbuf(stdin, NULL)
        gets(endereco.uf);

        printf("Selecione uma opcao: \n");
        printf("1 - Corrigir dados. \n");
        printf("2 - Finalizar alteracao. \n");
        scanf("%d", &op1);        
        
        if(op1 == 1) continue; 
        if(op1 == 2) break; 

        /*
        printf("\nPedido não encotrado!\n");
        printf("Vamos tentar novamente...\n");
        continue;
        */
      } 
      
    
    
  }
  
  if(op == 3){
        printf("dados apagados!\n");
    
  }

  printf("\nDeseja realizar outra ação?\n");
  printf("\n1 - Realizar uma nova pesquisa: ");
  printf("\n2 - Voltar para o menu principal: \n");

  scanf("%d", &op1);
  
  if(op1 == 1) return 0;        
  if(op1 == 2) return 0;    
  }
}