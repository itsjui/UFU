#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, y, resultado;
    scanf("%d", &x);
    scanf("%d", &y);

    if(0<= x && y <= 7){
        resultado = 7 - (x + y);
        printf("%d", resultado);
    }
    return (0);
}