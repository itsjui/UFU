#include <stdio.h>
int main (){
    int A, B, C, E, M;
    scanf("%d %d %d", &A, &B, &C);
    E = (A+B+abs(A-B))/2;
    M = (E+C+abs(E-C))/2;
    printf("%d eh o maior\n", M);

    return 0; 

}