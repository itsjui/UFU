#include <stdio.h>
int main (){
    int A, B, C, A1, B1, C1, temp;
    scanf("%d %d %d", &A, &B, &C);
    A1 = A;
    B1 = B;
    C1 = C;
    if (A > B){
        temp = A;
        A = B;
        B = temp;
        
    }if (A > C){
        temp = A;
        A = C;
        C = temp;

    }if (B > C){
        temp = B;
        B = C;
        C = temp;
    }
    printf("%d\n%d\n%d\n\n", A, B, C);
    printf("%d\n%d\n%d\n", A1, B1, C1);     

return 0;
}