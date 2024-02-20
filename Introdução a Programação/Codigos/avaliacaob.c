#include <stdio.h>



int main(){
    float valor_multa;
    int dias_atraso;
    scanf("%d", &dias_atraso);

    if(dias_atraso <= 30) valor_multa = dias_atraso*1.00;
    else valor_multa = dias_atraso*2.00;

printf("valor total da multa = %.2f", valor_multa);

    return 0;
}