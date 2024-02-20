#include <stdio.h>
#include <math.h>
int main (){
    double A, B, C, delta, X1, X2;
    scanf("%lf %lf %lf", &A, &B, &C);
    delta = pow(B,2) - 4 *A*C;
    if (A == 0 || delta < 0){
        printf("Impossivel calcular");  
    }else{ 
        X1 = (-B + sqrt(delta))/(2*A);
        X2 = (-B - sqrt(delta))/(2*A);
        printf("R1 = %.5lf\nR2 =%.5lf\n", X1, X2);
    }
  return (0);  
}