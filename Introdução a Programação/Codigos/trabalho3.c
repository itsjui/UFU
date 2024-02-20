//questão 3//
#include <stdio.h>
#include <stdlib.h>

void leitura(int numeros[], int n);
void resolve(int numeros[], int n);

int main()
{
    int n;
    scanf("%i", &n);
    int numeros[n];
    leitura(numeros, n);
    resolve(numeros,n);
    return 0;
}



void leitura(int numeros[], int n){
    for(int i=0;i<n;i++){
        scanf("%i", &numeros[i]);
    }

}

void resolve(int numeros[], int n){
    int cont_par = 0, cont_impar = 0;
    for(int i=0;i<n;i++){
        if(numeros[i]%2==0){
            cont_par = cont_par + 1;
        }
        else
            cont_impar = cont_impar + 1;
    }
    printf("\nNumeros pares:%i", cont_par);
    printf("\nNumeros impares:%i", cont_impar);
}