#include <stdio.h>
int main (){
    int X;
    float Y, valor;
    scanf("%d %f", &X, &Y);
    valor = X/Y;
    printf("%.3f km/l\n", valor);
    
    return 0;

}