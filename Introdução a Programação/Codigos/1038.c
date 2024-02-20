#include <stdio.h>
int main (){
   float valores[5] = {4.00, 4.50, 5.00, 2.00, 1.50};
   int C, Q;
   float T;
   scanf("%d %d", &C, &Q);
   T = valores[C - 1] * Q;
   printf("Total: R$ %.2f\n", T);

return 0;
}