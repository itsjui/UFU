#include<stdio.h>
#define MAX 5

struct Retangulo{
    float comprimento;
    float altura;
};
typedef struct Retangulo Retangulo;

Retangulo recebeRetangulo(){
    Retangulo retangulo1;

    printf("Digite o comprimento do retangulo: \n");
    scanf("%f", &retangulo1.comprimento);

    printf("Agora digite a altura do retangulo: \n");
    scanf("%f", &retangulo1.altura);

    return retangulo1;
}

float calculaArea(Retangulo retangulo1){
    float resultado;
    resultado = retangulo1.altura * retangulo1.comprimento;

    return resultado;
}

int main(){
    int i;
    int op;
    Retangulo retangulo1[MAX];


    for(i = 0; i < MAX; i++){
        retangulo1[i] = recebeRetangulo();
    }

    printf("Deseja calcular a area do retangulo?\n");
    printf("1. sim.\n2. nao\n");

    scanf("%d", &op);

    if(op == 1){
        for(i = 0; i < MAX; i++){
            float area = calculaArea(retangulo1[i]);
            printf("Area do retangulo %d: %.2f\n", i+1, area);
        }
    }

    return 0;
}